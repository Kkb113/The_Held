> **Historical v1 evidence.** This review predates First Step v3. Its design and phase labels are superseded by the [current roadmap](../../implementation.md); no v3 test passes are inferred. See [history](../../history/README.md).

# PH01 — Responsive traversal in a coherent route

Status: **In review, not Accepted**. User explicitly authorized this phase after the PH00 playtest. No PH02 work is included. Original blueprint and campaign sequence definitions remain unchanged.

Review candidate: `0.1.0-PH01`, `C:/THE HELD/Builds/PH01/Windows/TheHeld.exe`. `build-manifest.json` identifies the source files and executable by SHA-256. The source-control parent is the previously backed-up PH00 baseline; this phase's changes are submitted for review separately.

## Design contract

The development route is a service passage, not an additional campaign chapter. It combines a reachable light handle, low pipe, broken floor, ledge, ladder, heavy trolley and bounded carrier. Ivo remains 13, approximately 1.52 m, in ash-blue clothing. The route introduces ordinary movement without revealing bearer anatomy, staging Anja's capture, or inventing a new story event. Its domestic repairs, cloth, porcelain and maintenance fittings establish the existing world's material language.

Blueprint sections reviewed for this phase: 1.2, 3–4, relevant Chapter 1–3 room cards, 8–10, and T01–T03/T44; implementation PH01 plus universal gate G. The previous full package and sequence reviews remain supporting evidence. Canonical defaults are starting values, not INSIDE measurements.

Movement uses Unreal centimetres: X travel, Z vertical, Y depth. A straight lane is the current authored lane segment; no free depth movement is offered. A project-owned accumulator calls the capsule-sweep CharacterMovement implementation at 60 Hz. This reuses Unreal collision and floor handling while controlling update cadence. It is not a claim that every stock engine subsystem becomes deterministic. Platform motion advances before the character in the same step. Catch-up is bounded at 15 steps; long stalls are not replayed without limit.

Initial values: 420 cm/s run, 160 cm/s minimum analog walk, 1400 cm/s² acceleration, 2000 cm/s² braking, 560 cm/s jump, 1800 cm/s² gravity, 100 ms coyote, 120 ms jump buffer, 25 cm steps, 42-degree slopes, 125 cm/s crouch, 85 cm/s heavy push, 150 cm/s ladder. Controls and presentation must be verified in packaged tests, not assumed from these constants.

## Visual reference translation

Primary reference: the user's Laundry bridge and Harbor cover images in `review/visual-references/prototypes/`.

| Reference element | PH01 translation |
|---|---|
| Dark foreground enclosing the view | Authored columns and low silhouettes outside the collision lane |
| Cool depth, small readable person | Perspective camera at 15 m; fixed exposure; layered windows and service structures |
| Hanging cloth and pipes | Original Blender folded-cloth source, pipe runs, supports and brackets |
| Warm useful surface | Restrained task lights and pale tactile handles |
| Human maintenance history | Tile repairs, timber threshold, trolley and ordinary service ladder |
| Wet surfaces | Local roughness changes rather than a universal rain filter |

These are original assets and a new development layout. The reference images are not textures or reusable game assets. PH01 remains proxy production; the final character, authored animation library and final environmental polish must not be claimed from procedural poses or a screenshot.

## Research and application

- [Playdead: The Lighting of INSIDE](https://blog.playdead.com/articles/the_lighting_of_inside/lighting_of_inside.html): deliberate image hierarchy and selective lighting motivate local fills and readable contact areas. Its custom decal renderer is not copied.
- [Official corridor reference](https://blog.playdead.com/articles/the_lighting_of_inside/screen_corridor.jpg) and [cargo-hall reference](https://blog.playdead.com/articles/the_lighting_of_inside/cargohallpuzzle_wlights.jpg): source-hosted study images; © Playdead. Compare depth and light placement, not exact layouts.
- [Epic: CharacterMovement](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/UCharacterMovementComponent): reuse swept floor, step, slope and moving-base behavior inside the project's update cadence.
- [Epic: Crouch](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/UCharacterMovementComponent/Crouch): capsule fit checks are required; blocked uncrouch must preserve the smaller shape.
- [Epic: SafeMoveUpdatedComponent](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/UMovementComponent/SafeMoveUpdatedComponent): swept movement and penetration handling support the motor; visual pose does not own collision.

## Build and validation

`BuildScripts/Build-PH01.ps1` compiles editor and game, cooks, stages and archives to `Builds/PH01`. `-CreateAssets` imports the original cloth and generates small seeded temporary audio cues. REAPER production remains deferred. No new plugin dependency is introduced.

`-HeldTraversalTest` runs rendered integration fixtures inside the actual route and writes `Saved/PH01-test.json`. Teleports establish test setups. These fixtures do not prove a continuous human playthrough or physical device swap. Record results and limitations after validation; do not mark the phase Accepted automatically.

`BuildScripts/Test-PH01.ps1 -FPS 60 -Width 1920 -Height 1080` launches the package, requires fresh JSON and screenshot evidence, validates pixel dimensions, and fails on any failed fixture. Repeat at 30/60/120 caps. A requested cap is not proof the GPU sustained that rate; consult frame times. CPU values are Unreal's game-thread timing; they do not represent the sum of all CPU threads. GPU values use the engine's GPU-frame timing query. These short fixture samples are not a ten-minute resident performance certification.

`-HeldRouteTest` exercises the connected forward route with automated action handlers and no fixture teleports. Retry can still return to a safe point following a missed crossing. Its expert timing is not a first-time-player duration measurement. Physical device testing and a non-leading human route review remain separate.

## Controls

- A/D or arrows: move; analog left stick: walk/run.
- Space / controller A: jump, or climb from a caught ledge.
- S/down or stick down: crouch; let go from a ledge.
- E / controller X: grip a nearby handle or take the ladder. Hold while moving a prop, unless toggle-grip assistance is enabled.
- W/S or up/down on a ladder: ascend/descend. Interact releases the ladder.
- Escape / Menu: pause. Up/down selects menu entries; Enter/A confirms. Left/right adjusts temporary sound volume.
- Pause menu: retry from the most recent safe landing, toggle grip, mute, remap five keyboard traversal actions, restore keys, or quit.

Pause clears pending traversal input and grip. It does not silently keep pushing a prop when resumed. The current keyboard remapper reserves navigation aliases and the future Hold/candidate keys. Controller bindings are currently fixed; full controller rebinding is not claimed. Hold is introduced in PH02, so Q/right trigger do not yet activate it.

## Production boundary and review questions

The character is a 17-part articulated procedural proxy with original Blender garment geometry. Its velocity-driven pose families cover idle, walk/run, crouch, airborne/landing, ledge, ladder and grip. It is not the final skinned character or an authored animation-clip library. Foot contact on level surfaces and hand targets are approximations that require motion review, especially on the ramp. Temporary cues are original seeded synthesis, not final REAPER audio.

The route uses scenery instances and a small set of authoritative collision actors. Only authored objects participate in grip or platform behavior. No new enemy, story beat, Hold system, campaign save format or final audio pipeline is introduced.

For the user review: can you identify the next ordinary action without being told the solution, traverse both directions, retry a failed crossing, and operate each action comfortably? Check whether hands/feet and platform edges remain legible while moving. Record whether the service passage evokes the supplied material/lighting direction, while distinguishing this proxy quality from the later final visual target. The 3–5-minute first-play target remains a measured-review question.

## Validation record and acceptance boundary

The final connected forward route passed in **47.70 seconds with automated expert inputs**. The bot grips the trolley until it is clear of the overhead beam, climbs, traverses the carrier and reaches the exit. This is useful progression evidence, not a human comprehension test. The rail stop now prevents trolley/platform overlap; climbing checks the capsule's vertical and horizontal clearance before beginning. Pulling retains the body's facing toward the handle.

The integration suite contains 27 checks: acceleration, jump height, landing, blocked and clear uncrouch, ledge catch/climb, ladder ascent/descent, light grip, heavy push, carrier ride/departure bounds, retry, buffered landing jump, coyote jump, reverse stairs, slope ascent/descent, paused process clock, Enhanced Input dispatch/release, toggle grip, keyboard remapping, synthetic device-glyph switching, blocked climb clearance and reverse grip contact. Read the exact final results in `validation-summary.json` and individual `test-*.json` files.

These checks cover important portions of T01–T03 and the PH01 input subset of T44. They are not exhaustive boundary testing, a physical controller test, or a proof of every simultaneous-input combination. CPU/GPU samples are short-run fixture measurements; a full resident-route profile with worst-frame investigation remains outstanding. The user should review continuous motion, contact quality, sound audibility and first-time comprehension before phase acceptance. A recorded uninterrupted human motion capture and final-quality character animation are not supplied by these still-frame tests.

No phase acceptance is implied by a passing Boolean test suite. PH02 remains gated. If the user finds a progression, control, contact or readability defect, reopen the affected check and fix it in PH01.

Final validation: all 27 checks passed at 720p/30, 1080p/60, 720p/120 and native 1280×800/60. The connected forward route and the PH00 route/contact regression also passed. A final presentation-only correction lowered the crouched proxy to match its capsule; the complete 27-check suite was rerun at 720p/60 afterward, and `crouch-clearance.png` was visually inspected. The other matrix results precede that pose-only correction; movement, interaction and collision logic did not change in it. `ph00-regression.json` preserves the cumulative foundation result.

The latest 1080p fixture run measured game-thread p95 around 1.7 ms and GPU p95 around 6.6 ms on the previously recorded Intel Arc development machine. Consult the JSON for exact values and sampling limits. Source and executable hashes are refreshed for the final review candidate. Physical controller comfort, continuous human motion review, contact polish, full controller rebinding, a final authored animation library, first-time pacing and broader performance verification remain explicit review/production limits; they are not silently marked complete.
