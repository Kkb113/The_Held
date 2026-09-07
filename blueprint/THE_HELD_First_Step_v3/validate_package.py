#!/usr/bin/env python3
"""Validate THE HELD v3 planning data; no engine or third-party modules required."""
from __future__ import annotations
import csv,json,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parent

def load(name:str)->list[dict]:
    with (ROOT/'registers'/f'{name}.json').open(encoding='utf-8') as f:return json.load(f)

def unique(data:list[dict],name:str)->set[str]:
    ids=[r['id'] for r in data]
    if len(ids)!=len(set(ids)):raise ValueError(f'Duplicate ID in {name}')
    return set(ids)

def dag(data:list[dict],field:str,label:str)->None:
    graph={r['id']:r.get(field,[]) for r in data};visiting=set();done=set()
    def visit(n:str)->None:
        if n in visiting:raise ValueError(f'Cycle in {label}: {n}')
        if n in done:return
        if n not in graph:raise ValueError(f'Missing {label} dependency: {n}')
        visiting.add(n)
        for d in graph[n]:visit(d)
        visiting.remove(n);done.add(n)
    for n in graph:visit(n)

def main()->None:
    names=['chapters','sequences','assets','systems','puzzles','animation','audio','sources','cohort','milestones','risks','sprint01','tests','narrative_facts']
    data={n:load(n) for n in names};ids={n:unique(v,n) for n,v in data.items()}
    assert len(data['chapters'])==9 and len(data['sequences'])==40
    assert sum(c['minutes'] for c in data['chapters'])==225
    cursor=0;checkpoints=set()
    for s in data['sequences']:
        assert s['chapter'] in ids['chapters']
        assert s['start_min']==cursor and s['end_min']==cursor+s['minutes'],s['id']
        cursor=s['end_min'];assert s['checkpoint'] not in checkpoints;checkpoints.add(s['checkpoint'])
        assert set(s['actors'])<=ids['assets'],(s['id'],'asset')
        assert set(s['puzzles'])<=ids['puzzles'],(s['id'],'puzzle')
        for k in ['blockout','initial_state','storyboard','solution','threat_and_recovery','narrative','audio','save_contract','exit','acceptance']:
            assert isinstance(s[k],str) and len(s[k])>20,(s['id'],k)
    assert cursor==225
    for c in data['chapters']:assert sum(s['minutes'] for s in data['sequences'] if s['chapter']==c['id'])==c['minutes']
    for p in data['puzzles']:
        assert set(p['sequences'])<=ids['sequences'] and p['sequences']
        assert all(p['id'] in next(s['puzzles'] for s in data['sequences'] if s['id']==sid) for sid in p['sequences'])
    for a in data['assets']:assert a['milestone'] in ids['milestones'] and set(a['sequences'])<=ids['sequences']
    for s in data['systems']:assert s['milestone'] in ids['milestones']
    for a in data['animation']:assert a['actor'] in ids['assets']
    for c in data['cohort']:assert c['asset'] in ids['assets'] and c['final_exit'] in ids['sequences']
    assert len(data['cohort'])==12
    for f in data['narrative_facts']:assert f['sequence'] in ids['sequences']
    validrefs=ids['sequences']|ids['puzzles']|ids['systems']
    for t in data['tests']:assert set(t['references'])<=validrefs,t['id']
    for m in data['milestones']:
        assert 1<=m['start_week']<=m['end_week']<=120
        for k in ['build','assets','systems','playable','tests','problems','exit_gate']:assert len(m[k])>25,(m['id'],k)
    for n,k in [('puzzles','prerequisites'),('systems','dependencies'),('milestones','dependencies'),('sprint01','dependencies'),('narrative_facts','prerequisites')]:dag(data[n],k,n)
    schema_status='not run (optional jsonschema not installed)'
    try:
        import jsonschema
        for stem in ['mechanism_state','event','root_release']:
            jsonschema.validate(json.loads((ROOT/'implementation'/f'{stem}.example.json').read_text()),json.loads((ROOT/'implementation'/f'{stem}.schema.json').read_text()))
        schema=json.loads((ROOT/'implementation'/'sequence.schema.json').read_text())
        for s in data['sequences']:jsonschema.validate(s,schema)
        schema_status='passed for supplied examples and sequence shapes'
    except ImportError:pass
    report={'package':'THE HELD First Step v3','scope':'Planning-data consistency only; all unbuilt game tests remain Not run.','counts':{n:len(v) for n,v in data.items()},'campaign_minutes':cursor,'checkpoint_ids':len(checkpoints),'schema_validation':schema_status,'status':'PASS'}
    (ROOT/'validation_report.json').write_text(json.dumps(report,indent=2))
    print(json.dumps(report,indent=2))
if __name__=='__main__':
    try:main()
    except (AssertionError,ValueError,KeyError,FileNotFoundError) as exc:
        print(f'VALIDATION FAILED: {exc}',file=sys.stderr);sys.exit(1)
