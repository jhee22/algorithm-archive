"""Regenerate the browsing index without executing or grading solutions."""
from pathlib import Path
from collections import defaultdict
from urllib.parse import quote

ROOT = Path(__file__).resolve().parents[1]
EXT = {'.java', '.cpp', '.py', '.js', '.ts', '.c'}
STATS_START = '<!-- solution-stats:start -->'
STATS_END = '<!-- solution-stats:end -->'


def render_stats(groups):
    languages = sorted({lang for lang, _ in groups})
    platforms = sorted({platform for _, platform in groups})
    names = {'cpp': 'C++', 'java': 'Java', 'python': 'Python',
             'javascript': 'JavaScript', 'typescript': 'TypeScript', 'c': 'C'}
    sites = {'programmers': '프로그래머스', 'codetree': 'CodeTree',
             'leetcode': 'LeetCode', 'swea': 'SWEA', 'baekjoon': '백준'}
    total = sum(len(paths) for paths in groups.values())
    lines = [STATS_START, f'**전체 풀이 파일: {total}개**', '',
             '| 언어 | ' + ' | '.join(sites.get(p, p) for p in platforms) + ' | 합계 |',
             '|---|' + '---:|' * (len(platforms) + 1)]
    for lang in languages:
        counts = [len(groups.get((lang, p), [])) for p in platforms]
        lines.append('| ' + names.get(lang, lang) + ' | ' + ' | '.join(map(str, counts)) + f' | {sum(counts)} |')
    counts = [sum(len(groups.get((lang, p), [])) for lang in languages) for p in platforms]
    lines.append('| **합계** | ' + ' | '.join(map(str, counts)) + f' | **{total}** |')
    lines.extend(['', '풀이 파일 수 기준입니다. 같은 문제의 여러 구현을 각각 세며, 정답 판정이나 고유 문제 수를 의미하지 않습니다. `syntax/` 연습 파일은 제외합니다.', STATS_END])
    return '\n'.join(lines)


def update_readme(path, groups):
    with path.open(encoding='utf-8', newline='') as readme:
        content = readme.read()
    if content.count(STATS_START) != 1 or content.count(STATS_END) != 1:
        raise ValueError('README must contain exactly one pair of statistics markers')
    start = content.index(STATS_START)
    end = content.index(STATS_END, start) + len(STATS_END)
    newline = '\r\n' if '\r\n' in content else '\n'
    stats = render_stats(groups).replace('\n', newline)
    with path.open('w', encoding='utf-8', newline='') as readme:
        readme.write(content[:start] + stats + content[end:])

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
    update_readme(ROOT / 'README.md', groups)
    print(f'Indexed {sum(map(len, groups.values()))} solution files across {len(groups)} groups')

if __name__ == '__main__':
    main()
