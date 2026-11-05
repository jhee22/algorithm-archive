"""Route BaekjoonHub/CodeTree uploads into language/platform directories.

Run from any directory. Different versions get separate files; no overwrite.
"""
from pathlib import Path
import hashlib
from build_index import main as build_index

ROOT = Path(__file__).resolve().parents[1]
LANG = {'.java': 'java', '.cpp': 'cpp', '.py': 'python', '.js': 'javascript', '.ts': 'typescript', '.c': 'c'}

def organize(root=ROOT):
    roots = [('프로그래머스', 'programmers'), ('백준', 'baekjoon'), ('SWEA', 'swea')]
    roots += [(p.name, 'codetree') for p in root.glob('trail*') if p.is_dir()]
    count = 0
    for folder, platform in roots:
        incoming = root / folder
        if not incoming.exists():
            continue
        for src in sorted(incoming.rglob('*')):
            if not src.is_file() or src.suffix not in LANG:
                continue
            rel = src.relative_to(incoming)
            if platform == 'codetree':
                rel = Path(folder) / rel
            dest = root / 'solutions' / LANG[src.suffix] / platform / rel
            content = src.read_bytes()
            if dest.exists() and dest.read_bytes() != content:
                dest = dest.parent / 'variants' / hashlib.sha256(content).hexdigest() / dest.name
            dest.parent.mkdir(parents=True, exist_ok=True)
            if dest.exists():
                assert dest.read_bytes() == content, f'Conflicting destination: {dest}'
            else:
                dest.write_bytes(content)
            readme = src.parent / 'README.md'
            if readme.exists():
                target_readme = dest.parent / 'README.md'
                if target_readme.exists() and target_readme.read_bytes() != readme.read_bytes():
                    target_readme = dest.parent / ('README-upload-' + hashlib.sha256(readme.read_bytes()).hexdigest()[:12] + '.md')
                target_readme.write_bytes(readme.read_bytes())
            assert dest.read_bytes() == content
            src.unlink()
            count += 1
        # Remove only descriptions whose exact contents were copied, and empty dirs.
        for readme in incoming.rglob('README.md'):
            rel = readme.parent.relative_to(incoming)
            if platform == 'codetree':
                rel = Path(folder) / rel
            candidates = []
            for lang in LANG.values():
                candidates.extend((root / 'solutions' / lang / platform / rel).glob('**/README*.md'))
            if any(p.read_bytes() == readme.read_bytes() for p in candidates):
                readme.unlink()
        for p in sorted(incoming.rglob('*'), key=lambda x: len(x.parts), reverse=True):
            if p.is_dir() and not any(p.iterdir()):
                p.rmdir()
        if not any(incoming.iterdir()):
            incoming.rmdir()
    return count

if __name__ == '__main__':
    print(f'Organized {organize()} uploaded solution files')
    build_index()
