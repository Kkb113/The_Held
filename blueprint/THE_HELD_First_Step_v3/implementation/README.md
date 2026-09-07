# Implementation handoff

These are **data contracts and validation aids**, not a Unity game project. Mechanism coordinates use the units of their family (meters or radians); content definitions supply bounds. JSON Schema checks data shape, not physical solvability or narrative ethics.

`sequence.schema.json` describes the structured sequence cards. `mechanism_state.schema.json`, `event.schema.json` and `root_release.schema.json` describe initial state/event contracts with matching examples. Replace example actor IDs with stable authored GUIDs in the engine.

The gameplay service must additionally enforce owner compatibility, one personal Hold, support validity, state prerequisites, event idempotence and protected final-release input. A syntactically valid snapshot can still be semantically invalid. Read master sections 18–19 before implementing restore logic.

Run the root-level `validate_package.py` with Python 3 to check this package's register references, ID uniqueness, DAGs, chapter totals and sequence coverage. With the optional `jsonschema` package installed it also validates the included schema examples and sequence shapes. It does not test game performance, playability or a future engine importer.
