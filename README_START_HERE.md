# The Held: The First Step

Updated 8 September 2026. The First Step v3 replaces the previous game blueprint. The imported package is the creative baseline; the root roadmap defines how this workspace will build it.

## Read in this order

1. [New master blueprint](blueprint/THE_HELD_First_Step_v3/THE_HELD_First_Step_Master_v3.md) — complete story, forty sequences, puzzles and production contracts.
2. [Implementation roadmap](implementation.md) — revision 3.0, **draft for user review**, thirty-seven sequential phases FS00–FS36. No phase has started.
3. [Story and production review](review/v3/Story_and_Production_Review.md) — complete reading, research, twelve contract clarifications and their implementation deadlines.
4. [Original package navigation](blueprint/THE_HELD_First_Step_v3/START_HERE.md) — original PDF, DOCX, workbook, registers, schemas and source-package validation.
5. [Visual reference board](review/visual-references/README.md) — preserved user prototypes and official INSIDE studies, interpreted against v3.

The campaign starts in Ivo and Anja's apartment. FS01 makes the actual kitchen playable; FS11 assembles the first approximately fifteen minutes. Early Laundry and Ward fixtures prove production risks without changing the campaign order.

## Workspace decisions

Unreal, Blender, Visual Studio, C++/Blueprints and Python remain the tools. Final REAPER audio follows gameplay completion; temporary informative cues and audio integration hooks belong in early playable builds. The package's Unity proposal and overlapping staffing schedule do not override these user decisions. See [development direction](DEVELOPMENT_DIRECTION.md).

Existing PH00/PH01 code, art, builds and test evidence are preserved for inspection and possible reuse. They are historical work against the superseded design, not an accepted First Step campaign. No runtime files were changed by this migration. Old blueprint files and registers have been removed from the active checkout; their recovery reference is in [history](history/README.md).

## Package integrity

Source archive: `THE_HELD_First_Step_Production_Package_v3.zip`.

SHA-256: `1e64f6bb4a1d75ecb95d09dbbf301b460afc0ca20539984678b5ce041cfb8f37`.

The imported files are unchanged. [Audit results](review/v3/package_audit.json) cover 45 manifest-listed files, register IDs and document/workbook coverage. [Planning validation](review/v3/planning_validation.json) is data validation, not evidence that the game tests have passed. All 131 supplied game tests remain Not run for v3. Optional JSON Schema validation was unavailable in the current Python runtime.
