"""Regenerate the browsing index without executing or grading solutions."""
from pathlib import Path
from collections import defaultdict
from urllib.parse import quote

ROOT = Path(__file__).resolve().parents[1]
EXT = {'.java', '.cpp', '.py', '.js', '.ts', '.c'}

def main():
    groups = defaultdict(list)
    for p in sorted((ROOT / 'solutions').rglob('*')):
        if p.is_file() and p.suffix in EXT:
            rel = p.relative_to(ROOT)
            groups[tuple(rel.parts[1:3])].append(rel.as_posix())
    lines = ['# 풀이 찾아보기', '', '파일 수 기준입니다. 같은 문제의 다른 구현도 포함하며, 정답 판정 수를 뜻하지 않습니다.', '', '| 언어 | 플랫폼 | 풀이 파일 |', '|---|---|---:|']
    for (lang, platform), paths in sorted(groups.items()):
        lines.append(f'| {lang} | {platform} | {len(paths)} |')
    for (lang, platform), paths in sorted(groups.items()):
        lines.extend(['', f'## {lang} / {platform}', ''])
        for path in paths:
            label = path.split('/', 3)[3].replace('|', '\\|')
            lines.append(f'- [{label}]({quote(path)})')
    (ROOT / 'INDEX.md').write_text('\n'.join(lines) + '\n', encoding='utf-8')
    print(f'Indexed {sum(map(len, groups.values()))} solution files across {len(groups)} groups')

if __name__ == '__main__':
    main()
