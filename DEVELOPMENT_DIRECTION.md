# The Held — active development direction

User decision recorded 7 September 2026. Read alongside the canonical master blueprint and review documents.

## Technology

- Unreal Engine is the selected runtime and editor, replacing the blueprint's proposed Unity implementation.
- Blender supplies models, environments, rigs, animation and collision authoring.
- Visual Studio / its C++ build tools supply the native compilation and debugging toolchain.
- C++ implements core gameplay contracts; Blueprints assemble and tune rooms, interactions and presentation. Python supports asset and editor automation where available.
- REAPER is reserved for the later audio production phase.

Preserve the existing story, Ivo/Anja/Orren identities, Hold semantics, 48 sequences and original visual identity. Translate Unity-specific implementation details to Unreal equivalents; do not translate gameplay rules into unconstrained physics simulation.

## Production order

The user wants gameplay completed first, followed by audio production. Build movement, interactions, puzzles, enemies, checkpoints and campaign progression before final sound design or music. Do not commission or produce final REAPER assets during this phase.

Use simple temporary feedback when sound conveys a necessary interaction or danger. Expose stable events and parameters for process motion, strain, ownership transfer, relief, footsteps, threats and narrative beats. This is gameplay integration scaffolding, not the final audio phase. Re-test timing, readability and tension after final audio integration.

1. Establish a compiling and packaged Windows Unreal baseline with source control.
2. Prove camera framing, plane-constrained movement, crouch, jump, moving platforms and hand/foot contact in a disposable test level.
3. Prove process stop/resume, one-owner Hold, atomic anchor transfer, support-based relief and save/restart behavior.
4. Test station interaction and final-root interruption protection early, alongside the first puzzle fixtures; do not defer ending mechanics until the final chapter.
5. Build and test the Laundry gameplay slice, then expand the campaign through the existing sequence dependencies. Use the user's two prototypes as visual guidance throughout grayboxing and implementation.
6. Reach a complete start-to-finish gameplay build: all 48 sequences, puzzles, encounters, traversal, narrative interactions, checkpoints, death/retry and final release operate without development commands or progression blockers.
7. Produce and integrate final audio in REAPER, then complete audiovisual pacing, performance and release QA. Gameplay completion is not equivalent to a release-ready game.

The blueprint's original M11 full audiovisual quality gate cannot be reported as passed by a gameplay-only slice. Record gameplay acceptance separately; retain final presentation validation for the later polish phase. No existing milestone or test status changes merely because this direction was selected.

## Setup evidence

- Epic Launcher records Unreal Engine 5.8.2 at `C:/Program Files/Epic Games/UE_5.8`.
- Visual Studio discovery reports a C++ Build Tools installation at `C:/Program Files (x86)/Microsoft Visual Studio/18/BuildTools`. This does not establish that the full Visual Studio IDE is installed or that a project compiles successfully.
- No `.uproject` or `.sln` was found in this workspace during this check.
- Blender MCP tools are exposed to this task; a live connection has not yet been exercised.
- Unreal MCP tools are not exposed to this task. Direct editor automation through that connection remains unverified. Local Unreal command-line workflows can be evaluated independently.

## Design references

- [Canonical blueprint](<C:/THE HELD/THE_HELD_Master_Blueprint_v1.md>)
- [User prototypes and INSIDE reference board](<C:/THE HELD/review/visual-references/README.md>)
- [Production review](<C:/THE HELD/review/THE_HELD_Blueprint_and_INSIDE_Production_Review.md>)
- [Sequence review](<C:/THE HELD/review/THE_HELD_Sequence_Review.md>)

This decision record documents the user's current technology and sequencing preferences. It does not claim implementation, testing, staffing commitments or full production feasibility has been completed.
