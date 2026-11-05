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

if __name__ == '__main__':
    unittest.main()
