# THE HELD / THE FIRST STEP
## Production package v3.0 — 8 September 2026

**Locked creative baseline:** Ivo, 13; nine continuous chapters; 225-minute first-playthrough target; the living-bearer system; swimming and the air bell; paired balance interfaces; the Walking Ward; one ending through prepared release.

This version supersedes the earlier eight-chapter / stationary-network blueprint. Do not merge old sequence, checkpoint or asset IDs without a deliberate migration.

## Open these first

| File | Use |
|---|---|
| [Master PDF](THE_HELD_First_Step_Master_v3.pdf) | 120-page reading / review copy with clickable contents. |
| [Editable Word master](THE_HELD_First_Step_Master_v3.docx) | Design reviews, comments and approved revisions. |
| [Production workbook](THE_HELD_First_Step_Production_Registers_v3.xlsx) | Fifteen tracking sheets, calculated totals, editable status / estimate fields and sources. |
| [Markdown master](THE_HELD_First_Step_Master_v3.md) | Repository-friendly text source, approximately 46,600 words. |

## Team reading map

| Discipline | PDF pages |
|---|---|
| Director, narrative, production scope | 5–11 |
| Gameplay / controller / Hold | 12–17 |
| Level design and complete sequence boards | 18–66 |
| Puzzle framework, physics and threats | 67–71 |
| Art, camera and animation | 72–74 |
| Audio and music | 75–76 |
| Engineering architecture | 77–83 |
| Saves, checkpoints, streaming and recovery | 84–86 |
| Asset commissioning | 87–97 |
| Roadmap and milestone acceptance | 98–110 |
| QA and accessibility | 111–112 |
| First sprint, risks and release | 113–116 |
| Data-contract handoff | 117–118 |
| Research sources and boundaries | 119–120 |

Page references apply to the supplied PDF. Word pagination can change with local software or subsequent edits. The contents links remain the navigation mechanism.

## What the registers contain

Nine chapters, 40 playable sequence cards, 31 puzzle concepts, 164 asset-family work packages, 40 system contracts, 211 initial animation/pose tasks, 52 audio cue families, 21 milestone gates, 131 unexecuted game tests, 18 risks, 20 first-sprint tasks, twelve unique survivor slots, 19 durable narrative facts and 19 research sources.

One asset-family record is a commissionable work package, not necessarily one mesh or file. Animation and audio allocations are provisional scopes to refine using measured slice production; they are not instructions to manufacture filler. Blank person-day estimates mean **unestimated**, not zero.

The `registers/` directory contains fourteen JSON/CSV pairs. The workbook adds a dashboard to those fourteen registers. JSON sequence records retain the full blockout, state, A/B/C storyboard direction, solution, threat, audio, save contract and acceptance text.

## Start production in this order

M00 establishes the repository, compatible engine/package lock, naming and review conventions, and licensed hands-on reference captures. M01–M03 build the controller, one-owner Hold transaction and support-relief puzzle gym. Use rough assets, not commissioned final environments.

M08 proves swimming, breath readability, bell air retention and the tilting retrieval hazard. M09 proves the same paired controls from small carrier to occupied Ward. Both are scope gates, not late-game embellishments.

M13 requires the complete 24-minute Laundry chapter at representative shipping quality **plus a separate 3–6-minute First Step quality benchmark**. Reforecast remaining staffing and content effort from measured results before bulk production. M14 must run from New Game to the actual ending before alpha.

The roadmap is a 120-week scenario for nine sustained core roles plus specialist support. It is not a quote, a universal staffing requirement, or a delivery guarantee. Use milestone evidence rather than dates alone to authorize dependent work.

## Authority and changes

The master is the design contract. The structured registers are its machine-readable mirror. The workbook is an editable tracking surface. They do not synchronize automatically. A scope-changing edit must update the relevant descriptions, IDs, dependencies and tests in all affected sources.

Stable IDs must not be recycled. New game-state facts require migration and recovery tests. Final-release protection, single-owner burdens, finite survivor identity, and the distinction between intact bearer and irreversible root integration must remain consistent across disciplines.

## Implementation aids

The `implementation/` directory contains four JSON Schemas and three matching state/event examples. These specify data shape; they are not a compiled Unity project, a complete importer, or proof of physical solvability.

Run:

```sh
python validate_package.py
```

Core validation uses Python's standard library. When `jsonschema` is installed, schema validation also runs. The validator checks IDs, dependency cycles, references, chapter/sequence totals, content coverage and example shapes. It writes `validation_report.json`. Running it changes that report and therefore invalidates its original manifest checksum.

## Verification and limits

The supplied document was rendered and visually reviewed, all 25 section page references were checked, workbook key formulas and error scans were inspected, and structured package validation passed. Those are **document/data checks**.

The 131 game tests remain **Not run**. No playable game, shipping asset set, recorded soundtrack, rendered storyboard artwork or animatic is included. Sequence boards are detailed written shot/action specifications for the team's blockout and animatic work. Controller feel, emotional effect, safety margins, exact completion time and hardware performance must pass the planned prototype and playtest gates.

Reference research uses official Playdead stills and developer material. Full gameplay replay and controller measurement were not performed here; failed video fetches are disclosed in the master. Proposed tuning is not represented as measured INSIDE data.

## Package integrity

`MANIFEST.json` lists SHA-256 checksums and byte sizes for delivered files other than itself. The archive contains only deliverables, not rendering intermediates or font files.
