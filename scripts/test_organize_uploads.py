import tempfile
import unittest
from pathlib import Path
from organize_uploads import organize

class OrganizerTest(unittest.TestCase):
    def test_versions_readme_and_idempotency(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            incoming = root / '백준/Gold/1000. Test'
            incoming.mkdir(parents=True)
            dest = root / 'solutions/java/baekjoon/Gold/1000. Test/Main.java'
            dest.parent.mkdir(parents=True)
            dest.write_bytes(b'old\r\n')
            (incoming / 'Main.java').write_bytes(b'new\r\n')
            (incoming / 'README.md').write_bytes(b'problem\n')
            self.assertEqual(organize(root), 1)
            self.assertEqual(dest.read_bytes(), b'old\r\n')
            versions = list(dest.parent.glob('variants/*/Main.java'))
            self.assertEqual(len(versions), 1)
            self.assertEqual(versions[0].read_bytes(), b'new\r\n')
            self.assertEqual((versions[0].parent / 'README.md').read_bytes(), b'problem\n')
            self.assertFalse((root / '백준').exists())
            self.assertEqual(organize(root), 0)

    def test_multilanguage_and_description_only(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            incoming = root / 'trail1/test'
            incoming.mkdir(parents=True)
            for name in ['Main.java', 'main.cpp', 'README.md']:
                (incoming / name).write_bytes(name.encode())
            notes = root / 'trail1/notes'
            notes.mkdir()
            (notes / 'README.md').write_bytes(b'no solution')
            self.assertEqual(organize(root), 2)
            for lang in ['java', 'cpp']:
                self.assertTrue((root / 'solutions' / lang / 'codetree/trail1/test/README.md').exists())
            self.assertTrue((notes / 'README.md').exists())

    def test_programmers_level_and_unknown_level(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            known = root / '프로그래머스/2/123.\u2005Test\u2005Problem'
            unknown = root / '프로그래머스/456'
            known.mkdir(parents=True)
            unknown.mkdir(parents=True)
            (known / 'Solution.java').write_text('java', encoding='utf-8')
            (unknown / 'solution.py').write_text('python', encoding='utf-8')
            (unknown / 'README.md').write_text('description', encoding='utf-8')
            self.assertEqual(organize(root), 2)
            self.assertTrue((root / 'solutions/java/programmers/2/123.Test Problem/Solution.java').exists())
            self.assertTrue((root / 'solutions/python/programmers/unclassified/456/solution.py').exists())
            self.assertTrue((root / 'solutions/python/programmers/unclassified/456/README.md').exists())
            self.assertFalse((root / '프로그래머스').exists())
            self.assertEqual(organize(root), 0)

    def test_java_class_filenames_and_conflicting_versions(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            problem = root / '프로그래머스/2/123. Test'
            problem.mkdir(parents=True)
            (problem / 'Test.java').write_text('class Solution { int value = 1; }', encoding='utf-8')
            existing = root / 'solutions/java/programmers/2/123.Test/Solution.java'
            existing.parent.mkdir(parents=True)
            existing.write_text('class Solution { int value = 2; }', encoding='utf-8')
            codetree = root / 'trail1/example'
            codetree.mkdir(parents=True)
            (codetree / 'example.java').write_text('public class Main {}', encoding='utf-8')
            self.assertEqual(organize(root), 2)
            self.assertIn('value = 2', existing.read_text(encoding='utf-8'))
            versions = list(existing.parent.glob('variants/*/Solution.java'))
            self.assertEqual(len(versions), 1)
            self.assertIn('value = 1', versions[0].read_text(encoding='utf-8'))
            self.assertTrue((root / 'solutions/java/codetree/trail1/example/Main.java').exists())
            self.assertEqual(organize(root), 0)

if __name__ == '__main__':
    unittest.main()
