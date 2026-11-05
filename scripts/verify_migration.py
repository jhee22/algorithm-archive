"""Run immediately after migration; subsequent study edits may change snapshot hashes."""
from pathlib import Path
import hashlib
import json

root = Path(__file__).resolve().parents[1]
manifest = json.loads((root / 'docs/migration-manifest.json').read_text(encoding='utf-8'))
for row in manifest['files']:
    target = root / row['target']
    assert target.resolve().is_relative_to(root.resolve()), row['target']
    assert target.is_file(), row['target']
    assert hashlib.sha256(target.read_bytes()).hexdigest() == row['sha256'], row['target']
assert all(row['source'].startswith('submissions/jhee22/') for row in manifest['files'] if row['repository'] == 'leetdash')
print(f"PASS: {len(manifest['files'])} source records, exact SHA-256 preservation and leetdash ownership scope")
