import tempfile
import unittest
from pathlib import Path

from build_index import STATS_END, STATS_START, update_readme


class ReadmeStatsTest(unittest.TestCase):
    def test_totals_and_preservation(self):
        groups = {
            ('java', 'programmers'): ['a.java', 'b.java'],
            ('python', 'programmers'): ['a.py'],
            ('java', 'leetcode'): ['a.java'],
        }
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'README.md'
            path.write_text(f'before\n{STATS_START}\nold\n{STATS_END}\nafter\n', encoding='utf-8')
            update_readme(path, groups)
            result = path.read_text(encoding='utf-8')
            self.assertIn('전체 풀이 파일: 4개', result)
            self.assertIn('| Java | 1 | 2 | 3 |', result)
            self.assertIn('| Python | 0 | 1 | 1 |', result)
            self.assertIn('| **합계** | 1 | 3 | **4** |', result)
            self.assertTrue(result.startswith('before\n'))
            self.assertTrue(result.endswith('\nafter\n'))
            update_readme(path, groups)
            self.assertEqual(result, path.read_text(encoding='utf-8'))

    def test_missing_markers_are_rejected(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'README.md'
            path.write_text('keep me', encoding='utf-8')
            with self.assertRaises(ValueError):
                update_readme(path, {})
            self.assertEqual(path.read_text(encoding='utf-8'), 'keep me')


if __name__ == '__main__':
    unittest.main()
