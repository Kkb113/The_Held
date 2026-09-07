"""Check documentation coverage only; this does not execute any game test."""
from pathlib import Path
from collections import Counter
import json
import re
from urllib.parse import unquote

OUT = Path(__file__).resolve().parent
ROOT = OUT.parents[1]
PACKAGE = ROOT / 'blueprint/THE_HELD_First_Step_v3'
roadmap = (ROOT / 'implementation.md').read_text(encoding='utf-8')
phases = re.findall(r'^### (FS\d{2}) — (.+)$', roadmap, re.M)
assert [p[0] for p in phases] == [f'FS{i:02}' for i in range(37)]
required = ['What / why now', 'Gameplay / engineering', 'Assets / animation',
            'Visuals / VFX', 'Audio', 'Playable / visual result',
            'Tests / acceptance / exit']
phase_section = roadmap.split('## 4. Implementation phases\n', 1)[1].split('## 5.', 1)[0]
for section in re.split(r'^### ', phase_section, flags=re.M)[1:]:
    for label in required:
        assert f'**{label}:**' in section, (section[:70], label)
    assert re.search(r'\*\*Physics / (?:puzzles|interactions):\*\*', section), section[:70]

coverage = {}
for key, number, count in [('sequences', 1, 40), ('puzzles', 2, 31),
                           ('systems', 3, 40), ('tests', 4, 131),
                           ('narrative_facts', 5, 19)]:
    records = json.loads((PACKAGE / f'registers/{key}.json').read_text(encoding='utf-8'))
    section = roadmap.split(f'### 6.{number} ', 1)[1].split('### 6.', 1)[0]
    rows = [line.split('|')[1:-1] for line in section.splitlines() if line.startswith('| ')]
    rows = [[cell.strip() for cell in row] for row in rows]
    expected = [row['id'] for row in records]
    actual = [row[0] for row in rows if row[0] in expected]
    assert len(expected) == count and Counter(actual) == Counter(expected), key
    for row in rows[1:]:
        assert row[0] in expected, (key, row)
        assert all(row), (key, row)
        references = re.findall(r'\bFS\d{2}\b', ' '.join(row))
        assert references and all(ref in dict(phases) for ref in references), (key, row)
    coverage[key] = {'expected': count, 'mapped_exactly_once': True}

authored = [ROOT / name for name in ['implementation.md', 'README_START_HERE.md',
    'DEVELOPMENT_DIRECTION.md', 'history/README.md', 'review/visual-references/README.md',
    'review/v3/Story_and_Production_Review.md']]
checked_links = 0
for file in authored:
    text = file.read_text(encoding='utf-8')
    for link in re.findall(r'!?\[[^\]]*\]\(([^\n]+?)\)', text):
        link = link.strip('<>')
        if link.startswith(('http:', 'https:', '#')):
            continue
        path_part = unquote(link.split('#', 1)[0])
        path = Path(path_part)
        if not path.is_absolute():
            path = file.parent / path
        assert path.exists(), (str(file), link)
        checked_links += 1

report = {'scope': 'Roadmap structure, ID coverage and authored local links; no game tests.',
          'phase_count': len(phases), 'required_fields_per_phase': 8,
          'coverage': coverage, 'local_links_checked': checked_links,
          'status': 'PASS'}
(OUT / 'roadmap_validation.json').write_text(json.dumps(report, indent=2), encoding='utf-8')
print(json.dumps(report, indent=2))
