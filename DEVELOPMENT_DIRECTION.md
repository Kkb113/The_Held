# Development direction — First Step v3

Recorded 8 September 2026. This file summarizes settled workspace choices; [implementation.md](implementation.md) is the sole phase-order authority, and the [v3 master](blueprint/THE_HELD_First_Step_v3/THE_HELD_First_Step_Master_v3.md) defines the game.

## Tools and production order

- **Unreal Engine:** gameplay, physics, camera, lighting, animation integration, saves, packaging and profiling. Verify the existing engine version and required MCP connections before editor mutations; do not upgrade automatically.
- **Blender:** original models, rigs, authored animation and asset exports, validated in Unreal at the actual gameplay camera.
- **Visual Studio, C++ and Blueprints:** C++ for authoritative rules; Blueprints for scene assembly and bounded tuning. Python supports repeatable import, audits and build automation.
- **REAPER:** final sound and music production after the gameplay-complete gate. Early phases still use temporary original cues and stable audio events to make interactions and danger understandable.

The source archive proposes Unity and an overlapping staffed production schedule. Those are source recommendations, not authorization to replace the user's toolchain or strict phase-by-phase approach. The root roadmap explicitly translates them to Unreal and records the delayed final-audio milestone exception.

## Creative scope

Preserve the new nine-chapter story, actual apartment opening, Anja, Orren, the Porter, one personal Hold, ordinary support and reciprocal balance, swimming and movable air, twelve survivors, the occupied Ward, deliberate final release and ordinary offered help. INSIDE informs production craft; it does not replace this story or its mechanics.

Retain the prototypes' composition, scale, restraint and human infrastructure. Follow v3's broad matte forms and physical indicators; the old images' glowing hand and wet gloss do not become required effects.

## Advancement

The rewritten roadmap is **Draft for user review**. FS00–FS36 are all Not started. Approve the roadmap before implementation begins; thereafter implement one phase, package it, test it and review it before advancing. Refer to each phase's explicit deliverable and exit gate. No acceptance is inferred from a planning validator or historical build.

PH00/PH01 remain available as prior technical work. Audit reuse at FS00; do not silently migrate their maps or saves into the new campaign. The [history note](history/README.md) identifies the superseded baseline. The [production review](review/v3/Story_and_Production_Review.md) records twelve issues to settle before their dependent work, including paired Hold/posture semantics and protected final-release intent.
