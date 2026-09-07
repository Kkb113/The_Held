# The Held — implementation roadmap

Version 1.0 · 7 September 2026 · **PH00 implementation authorized by the user**

**Current phase: PH00 — In progress. All later phases are Not started. No phase is Accepted.** The user explicitly requested implementation of PH00 after reviewing this roadmap. See [PH00 evidence](<C:/THE HELD/phase-reviews/PH00/README.md>) for build results and outstanding acceptance checks. This does not authorize publishing the game.

## 1. Authority and scope

This file is the primary roadmap for **how we develop The Held**. The [master blueprint](<C:/THE HELD/THE_HELD_Master_Blueprint_v1.md>) remains authoritative for **what the game is**. The user's subsequent decisions select Unreal, Blender, Visual Studio and gameplay-first development, with final audio production in REAPER later. The [visual reference board](<C:/THE HELD/review/visual-references/README.md>) preserves the user's two prototype images as primary visual guidance; INSIDE is a production reference, not a source of reusable layouts, characters or game assets.

Upon user approval, this roadmap controls phase order and development gates. [DEVELOPMENT_DIRECTION.md](<C:/THE HELD/DEVELOPMENT_DIRECTION.md>) remains a decision history, not a competing task queue. Existing registers retain their stable content IDs and historical milestone definitions. They are not proof of completion. No canonical documents or registers are modified by creating this file.

Baseline: eight chapters, 48 sequences, 29 numbered challenges, one canonical ending, nominal 225 minutes. Do not add combat, crafting, swimming, collectibles, alternate endings, new monsters, new powers or a sandbox physics system. Ivo is 13; Anja and Orren retain their established identities. Human restraint, physical support, responsibility and ordinary voluntary help are the emotional spine.

No fixed calendar is promised here. Estimate each phase from measured effort, including revisions and integration. The blueprint's staffing and 96-week proposal are planning assumptions, not a commitment established by this roadmap. One person may cover several review roles, but engineering tests do not substitute for independent player understanding.

### Approval and change control

1. The user approves this roadmap before phase implementation starts. Approval must be recorded with version/date and the actual user decision; never infer it from elapsed time.
2. Only one phase is active. Start it only after its predecessor is Accepted. The first predecessor is roadmap approval.
3. Work within the active phase proceeds autonomously. Do not ask for permission for every ordinary reversible implementation step.
4. Submit the phase build and review evidence when ready. Record the user's acceptance of the experience and the technical gate result before advancing. An explicit user instruction to continue after reviewing the evidence may record that acceptance.
5. A failed criterion returns the phase to In progress. A blocked test remains blocked; it cannot be marked passed because hardware, testers or a connector is unavailable.
6. Future work stays in a deferred list. Early risk fixtures are allowed only where expressly assigned below. They are developer-only reproductions of canonical mechanics, not extra campaign rooms.
7. For a scope, story, mechanic or order change, describe the reason, affected phases/IDs, cost and retests; obtain the user's decision, then revise this file and affected specifications together. Routine tuning within approved rules is logged without a new roadmap approval.
8. A later regression reopens the affected gate. Stop dependent work until it is fixed and revalidated. Never preserve an Accepted label against contradictory evidence.

Status vocabulary: **Not started → In progress → In review → Accepted**; **Blocked** records a concrete dependency and **Reopened** records a regression. No automatic progression based on completion percentage.

## 2. Production contract

### Technology and responsibilities

| Concern | Planned implementation | Constraint |
|---|---|---|
| Runtime/editor | Unreal Engine; locally discovered 5.8.2 is the initial candidate | Phase 00 compiles/packages and locks the exact version, plugins and toolchain; no automatic upgrades |
| Gameplay | C++ for input/state/motion/ownership/save contracts; Blueprints and data assets for room composition and tuning | One authoritative state model; avoid duplicate rules in animation or Level Blueprints |
| Input | Enhanced Input actions and explicit gameplay/station/menu contexts | Preserve remapping, toggle-Hold, cancel semantics and fresh-command protection |
| Physics | Project-owned fixed-step process simulation, swept collision and controller integration; bounded secondary Chaos simulation | Enabling physics substeps alone does not implement the blueprint's ownership or reproducibility contract |
| Art/animation | Blender source assets; validated export/reimport; Unreal Animation Blueprints and bounded Control Rig/IK corrections | Controller responds immediately; animation cannot become the only completion signal |
| Camera/cinematics | Authored perspective framing volumes/splines; short Sequencer interactions | Semantic scenario state governs restore/skip; gameplay remains active when safe |
| Rendering | Profiled Unreal materials, lighting, fog, reflections, AA and Niagara | No mandatory Lumen, Nanite, ray tracing or custom renderer; choose the least costly path that meets the benchmark |
| Audio | Small replaceable Unreal event adapter and temporary cues first; REAPER production and Unreal integration after gameplay completion | Final sound creation is deferred, but gameplay timing, accessibility and sound-event contracts are not |
| Persistence/streaming | Versioned semantic snapshots, stable GUIDs, explicit chunk manifests and active-owner residency | Unreal object pointers, raw actor names and Sequencer playheads are not persistent identity |
| Testing/build | Unreal automation/functional tests, outcome-based replay fixtures, packaged Windows smoke tests and Unreal Insights | Human playtests judge comprehension and atmosphere; automated traces judge state and recovery |
| Source control | Git plus LFS for binary Unreal/DCC/audio assets; remote backup and restore rehearsal | Agree ownership/locking for binary maps/assets; do not commit generated caches or credentials |

Proposed project layout: `Game/TheHeld/` for the Unreal project, `SourceArt/` for Blender and texture sources, `AudioSource/` for later REAPER sessions, `BuildScripts/`, and `phase-reviews/PHxx/` for evidence. These are planned paths, not existing deliverables. Split runtime and editor-only code. Keep development maps and debug UI out of the shipping route.

Epic references for implementation validation: [Enhanced Input](https://dev.epicgames.com/documentation/unreal-engine/enhanced-input-in-unreal-engine), [automation framework](https://dev.epicgames.com/documentation/en-us/unreal-engine/automation-test-framework-in-unreal-engine), [C++ toolchain setup](https://dev.epicgames.com/documentation/en-us/unreal-engine/setting-up-visual-studio-development-environment-for-cplusplus-projects-in-unreal-engine), and [audio systems](https://dev.epicgames.com/documentation/unreal-engine/audio-in-unreal-engine-5). Verify APIs against the locked local release when implementing; this roadmap is not a claim of tested plugin compatibility.

### Gameplay invariants — apply in every affected phase

- Hold arrests an addressed **process**, not time or an entire actor hierarchy. It does not rewind, heal or repair. Capture process coordinate/phase and permitted velocity; release resumes without accumulated force or elapsed-time backlog.
- One personal Hold. Acquisition uses the blueprint's exposed compatible contact, facing/visibility and 3.2 m reach; retention uses its 6 m connection envelope and explicit conduit rules. Initial warnings: vane at 5 m, click at 5.7 m, 0.4 s break warning. Convert meters to Unreal centimeters once, centrally. Ordinary occlusion after acquisition is not automatically a broken conduit.
- Anchor transfer is atomic and capacity-checked. Releasing the button after transfer does not release the anchor. An unused anchor is still connected to a bearer.
- Moving/crouching/jumping and eligible one-handed catches can coexist with Hold. Heavy pushing and two-handed ladders cannot. Reject the incompatible action without silently dropping the load.
- Physical support is not synonymous with restraint. Contact/lock validity, safe physical settlement, bearer detachment and durable Resolved state must be explicit. No decorative prop becomes a valid support by accident.
- Stations retain a defined assembly and branch latches. Directional selection, Hold-to-latch and Interact-to-unlatch must remain consistent. Specify every paired mechanical lever separately; never invent a new input or overloaded action by accident.
- Keep Anja's root ownership separate from Ivo's temporary evacuation aggregate and withdrawal restraint. Only the final deliberate root handover transfers that root to Ivo.
- Final release requires an intentional gameplay command after valid preparation and acquisition. Focus loss, pause, device disconnection, restore, range/path loss and repeated callbacks cannot commit the ending.
- Tier A motion determines puzzle outcomes; Tier B contact/secondary animation adds weight; Tier C debris/cloth adds atmosphere. Cosmetic physics cannot change solvability. Do not claim bitwise cross-machine determinism.
- Narrative strain changes posture, fingers and breath, not arbitrary stamina, movement latency or a hidden morality score. Preserve the single ending and Anja's irreversible loss.

### Presentation maturity and early impact

| Gate | What the player can see and do |
|---|---|
| PH00–PH02 | Recognizable proportions, layered composition and immediate control; first working Hold with local motion contrast |
| **PH03 — first playable visual impact** | A real Laundry transfer bridge, readable hand contact, original porcelain/brass identity, lighting, wetness and independent cloth/drips, viewed while playing |
| PH07–PH11 | Threat, human cost and opening motivation integrated with the established visual treatment |
| **PH12 — repeatable visual/gameplay benchmark** | All six Laundry sequences at production visual direction and representative animation, with temporary audio; measured reusable asset pipeline |
| PH19 | Whole campaign gameplay-complete, with chapter-specific visual targets already present |
| PH23 | Whole campaign visual/contact/camera pass and gameplay lock; temporary audio remains explicitly temporary |
| PH24–PH26 | Final audio benchmark, full audio integration, then whole-game audiovisual alpha acceptance |
| PH27–PH29 | External validation, optimization and exact release candidate |

The prototype images guide framing, scale, atmosphere and tactile fittings. Preserve Ivo's canonical ash-blue clothing rather than adopting the prototype's reddish top as a redesign. A warm fitting accent must still read as physical porcelain, not neon magic. Wetness is localized; the daylight ending and domestic chapters must not inherit a universal wet industrial filter.

Before PH24, every phase uses a small set of original/simple or properly licensed temporary sounds and visible equivalents. They demonstrate synchronization, tension/silence intent and cue coverage. Do not produce final REAPER sessions, buy a large sound library or pretend temporary audio proves final emotional impact. Final mix, sonic identity and audio-driven pacing are judged again later.

### Universal exit gate G — required by every phase

Every phase below inherits G **in addition to its own criteria**. “Reuse” means integrate and retest earlier work, not omit that discipline.

| Review area | Required evidence |
|---|---|
| Build/run | Identified packaged Windows build, source revision, launch route and reproducible setup; no editor-only action needed to play the deliverable |
| Gameplay/input | Intended actions, refusal, cancel, rapid repeats, both keyboard and controller; no critical control defect |
| Puzzle/physics | Intended solution and valid alternatives, misuse/reversal, support boundaries, recovery and meaningful 30/60/120 rendered-fps checks where motion is involved |
| Visual/camera | Same-camera target comparison plus uninterrupted motion capture; hands, feet, hazards and causes readable at 720p and supported aspect ratios |
| Animation | Contact, interruption, transitions, strain and paired actions applicable to the phase; no animation-caused input delay or false puzzle state |
| Story/understanding | Exact room-card alignment and a non-leading comprehension question; speculation about mystery allowed, confusion about required action diagnosed |
| Audio/atmosphere | Required cue events, silence intent, restart synchronization and visual equivalents; temporary/final status explicit; no accidental volume-spike dependence |
| Stability/save | Launch/retry/pause/device loss/quit/restore for new interactions; no reproducible crash, softlock, duplicate owner or corrupt save |
| Performance | Packaged CPU/GPU p95/p99, worst frames and memory for the new route; compare to accepted baseline and explain regressions |
| Production | Source/provenance, stable IDs, export recipe, dependency/variant coverage, known defects, actual effort and next-phase prerequisites |

Severity: **Critical** = crash/data loss/progression failure/ownership corruption or unintended ending. **High** = unreliable taught solution, hidden lethal cause, essential story misunderstanding, severe readability/accessibility failure or missed agreed performance gate. No Critical or High defect may pass. Lower defects need owner, impact, bounded correction phase and proof they do not invalidate the current review. Aesthetic and emotional review cannot be replaced by a numerical average.

For PH01 onward, retain a short cumulative movement/Hold/checkpoint smoke route. Rerun affected prior tests after a shared-system change. From PH19 onward, use the full 29-puzzle regression suite. Compare outcomes and tolerances rather than decorative transforms. Test counts below are formative minimums/targets, not statistical certification; repeated confusion requires iteration even when a percentage passes.

Performance starting targets from blueprint §10.12: 1080p/60, CPU p95 ≤12 ms, GPU p95 ≤13 ms, no unexplained >33 ms frame in a ten-minute resident slice run; log streaming separately. Initial working set ≤4 GB, VRAM ≤4.5 GB, installation ≤12 GB. PH00 records exact test hardware; PH03 assesses rendering feasibility; PH12 locks measured budgets or records an explicit user-approved rebaseline. CPU/GPU timings overlap and are not added. Do not silently lower quality, raise minimum hardware or defer all performance work to PH28.

Support quality tiers, reduced flashes/shake, captions, remapping, toggle-Hold and timing assistance without changing puzzle ownership, hiding essential clues or removing final agency. Native 16:9/16:10 and verified ultrawide reveal limits follow the blueprint. Keep danger replay loss near the proposed 20–45 seconds unless review justifies an exception.

## 3. Ordered phases

Each phase depends on acceptance of **all preceding phases**. Its exit section names additional conditions before the next phase. All map labels below are planned developer entry points unless stated as campaign content. Durations describe intended review routes, not deadlines or enforced player waiting.

### PH00 — Reproducible Unreal foundation

- **Implement / why now:** establish a small packaged room that proves the chosen toolchain before gameplay or asset investment. Translate configuration/build assumptions from Unity without changing design.
- **Gameplay systems:** basic controllable Ivo-scale proxy, pause, quit and restart; no claim of final movement.
- **Engineering:** C++ project, runtime/editor separation, Enhanced Input bootstrap, logging/build ID, Git/LFS conventions, clean build script, stable-ID convention and basic content validator. Verify Unreal/Blender connections or document a working local CLI route; missing MCP is not proof that the editor works.
- **Assets:** floor, step, scale grid, 1.52 m proxy, neutral and charcoal materials; one Blender export/reimport round trip. Confirm Visual Studio compiler/SDK, not merely installed languages.
- **Animation:** simple idle/walk proxy sufficient to see orientation and contact height.
- **Visuals / VFX:** dark foreground, readable lane and soft backdrop with restrained practical light; no costly FX required.
- **Audio:** one temporary input/contact cue, master volume and a mute check.
- **Physics:** collision scale, gravity, safe floor and bounded test platform; document fixed-step integration plan.
- **Puzzles / interactions:** walk, touch a marker and restart; an infrastructure check, not added campaign content.
- **Playable result:** packaged room launches from a clean user profile and accepts keyboard/controller.
- **Visual demonstration:** Ivo scale and gameplay camera agree with blueprint proportions in an actual executable.
- **Tests:** compile/cook/package, cold launch, input swap, reimport, missing-reference detection, 720p/1080p and frame capture. Record exact CPU/GPU/RAM/OS/driver fixture. Complete the bounded licensed INSIDE reference study assigned by M00 and record observations separately from imitation.
- **Acceptance / exit:** G; a second clean workspace rebuild succeeds from documented steps, ideally by another person; no editor dependency. Lock engine/plugins/toolchain and name review responsibilities. Compiler or packaging failures block PH01.

### PH01 — Responsive traversal in a coherent route

- **Implement / why now:** turn the foundation into a 3–5 minute service passage containing the ordinary movement vocabulary; later puzzles must rely on trusted movement.
- **Gameplay systems:** acceleration/stop, jump buffer, crouch, ledge catch, ladder, light grip and constrained heavy push.
- **Engineering:** lane motor, collision sweeps, input remapping/toggle configuration, interaction socket selection and camera look-ahead. Measure controller integration with the process clock rather than assuming stock movement meets every requirement.
- **Assets:** proxy Ivo rig; stairs, ledges, low tunnel, ladder, trolley, grip handles and moving platform, using reusable kit dimensions.
- **Animation:** idle/walk/run starts/stops, jump/land, crouch, catch, climb, push; early hand/foot alignment and cancellation coverage.
- **Visuals / VFX:** compose the route with foreground framing and one lit contact area; sparse dust only.
- **Audio:** temporary footsteps, landing, grip and movement loops with event hooks.
- **Physics:** capsule/step/slope/head clearance, platform carrier velocity once, constrained trolley mass and collision; no random launches.
- **Puzzles / interactions:** ordinary traversal and a movable obstruction; no new puzzle concept.
- **Playable result:** complete the connected route, reverse direction, retry and use each movement action without a console.
- **Visual demonstration:** body weight and camera stability during actual input, including close contact and small gaps.
- **Tests:** T01–T03, T44; approach boundaries both ways, buffered landing jump, moving-platform edges, device swap and blocked uncrouch.
- **Acceptance / exit:** G; every traversal action works at 30/60/120 fps with recorded tolerances; no High contact/input fault. Baseline movement clips and camera become the regression route for PH02.

### PH02 — First Hold and trustworthy resumed motion

- **Implement / why now:** integrate P01 shutter and P02 drum fixtures into the service route. Teach stopping and resumption before adding external owners.
- **Gameplay systems:** SYS-HOLD, SYS-MOTION, target selection, range feedback and one-handed compatibility.
- **Engineering:** process coordinate/velocity, slider/rotator profiles, owner identity, reason-coded refusal, process inspector, safe reset and input interruption guard.
- **Assets:** brace, physical porcelain port, shutter, tilted drum, tray, receiving platforms and explicit safe refuge.
- **Animation:** acquire/brace/release, target glance, refusal, held walking/crouching and one-handed catch.
- **Visuals / VFX:** local warm practical on ceramic, readable moving edges; dust and drips continue outside the stopped process.
- **Audio:** temporary motor loop, stop/resume transition, strain and range warning with visual equivalents.
- **Physics:** 60 Hz authored process updates initially; frozen q/permitted velocity, sweep-before-motion and explicit crush/stall policy. No force backlog or global time dilation.
- **Puzzles / interactions:** stop a rising shutter, cross, release; arrest the drum within a generous usable angle and jump to safety.
- **Playable result:** both first-Hold puzzles with failure and immediate recovery, connected to PH01 movement.
- **Visual demonstration:** moving world around a locally arrested load; stable feet on the drum.
- **Tests:** T04–T06, T09–T10, T12; 0/25/50/100% travel, holds of 1/10/60 seconds, 1,000 cycles per implemented process type, rapid commands and all warning thresholds.
- **Acceptance / exit:** G; no lost process/owner, hidden exact-angle solution or silent hand-conflict release. At least 4/5 fresh formative players explain resumption versus repair. Keep findings and failed hypotheses before PH03.

### PH03 — First playable visual impact: Laundry bridge

- **Implement / why now:** stage the canonical P04 transfer bay as a 3–5 minute playable benchmark using H01's framing principles. This is the first deliberate visual-impact gate, not a promotional movie.
- **Gameplay systems:** SYS-TRANSFER, SYS-HANDOFF, SYS-HOLD-OWNER; transfer, free hands and ladder access.
- **Engineering:** atomic transfer transaction, occupied-anchor refusal, state-driven vane/material/animation hooks; Blender import presets and initial quality settings.
- **Assets:** hero bridge, cables/pivots, porcelain/brass anchor, tile/drain subset, baskets, curtains, Ivo first-direction model/rig. Exact geometry follows C02-S02 rather than tracing the prototype.
- **Animation:** hand reaches/settles, load handover, weight shift, refusal, free-hand ladder; do not delay logical response for ornament.
- **Visuals / VFX:** H01-style dark foreground, cool depth, restrained warm fitting, localized wet reflections, small steam/drip/cloth effects; light the full travel and far landing.
- **Audio:** temporary motor/strain/transfer/catch and restrained room tone; audible state differs after external ownership without final REAPER production.
- **Physics:** held bridge as bounded assembly; anchor retains its load after button release; separate cloth and incidental debris.
- **Puzzles / interactions:** arrest bridge level, hand off, cross and climb; incompatible ladder request refuses safely before transfer.
- **Playable result:** enter, solve, retry and exit a convincing Laundry space in the packaged build.
- **Visual demonstration:** record an uninterrupted player-controlled pass beside target frames; inspect reflections and thin structures during motion, not just stills.
- **Tests:** T07–T08, T10, T29–T30, T34; 1,000 handovers, occupied destination, interrupted alignment, grayscale/720p, fog/AA/quality changes and measured CPU/GPU cost.
- **Acceptance / exit:** G; user reviews and accepts the first visual target in motion; at least 4/5 fresh players distinguish anchor retention from personal Hold. One owner always survives failure. Reuse pipeline and scalable render path documented before PH04.

### PH04 — Physical support and human relief

- **Implement / why now:** add P07 support and a developer P10 Orren fixture to the existing route. Prove the distinction between transferring effort and removing its necessity before multiplying puzzles.
- **Gameplay systems:** SYS-SUPPORT, support sockets, takeback/release, physical ratchet and NAR-ORREN-FREED prototype.
- **Engineering:** specify contact validity versus support readiness, settlement, detachment and Resolved commit. Resolve collision/support ordering so a valid seated support constrains motion before lethal adjudication; document this clarification against the blueprint's tick order.
- **Assets:** roller, receiving notch, service prop, staircase hinge, broad ratchet tooth/pawl, Orren proxy with recognizable shoe and exit clearance.
- **Animation:** one-handed lever, takeover, fingers uncurling, bearer stands/moves aside; interrupted states retain valid contacts.
- **Visuals / VFX:** show force path and support contact; subtle settlement dust follows contact, not before it; vane slackens after relief.
- **Audio:** temporary ratchet click, settlement, strain reduction and breath; quiet relief rather than a victory sting.
- **Physics:** broad tolerances, constrained lowering, physical pawl/notch, safe catch for unsupported attempts; cosmetic debris never substitutes for support.
- **Puzzles / interactions:** P07's transfer→prop→takeback→release and P10's descend→recapture→ratchet→release.
- **Playable result:** two complete reversible support puzzles connected to the traversal/transfer route; Orren fixture stays outside campaign order.
- **Visual demonstration:** supported mechanism stays still while the relieved person visibly changes state.
- **Tests:** T12–T13, T47; tolerance boundaries, wrong prop, early/late lever, reverse action order and repeated entry. Five fresh formative sessions.
- **Acceptance / exit:** G; ≥4/5 explain why physical support frees a bearer; no false support or permanent obstruction. Signed support/commit state table is required before PH05.

### PH05 — Persistent consequences and reliable recovery

- **Implement / why now:** make the assembled movement/Hold/transfer/relief route a durable mini-game. Repetition must preserve learning instead of losing state.
- **Gameplay systems:** SYS-SAVE, SYS-CHECKPOINT, SYS-EVENTS, retry, continue and separate replay session.
- **Engineering:** versioned semantic snapshot, immutable capture, asynchronous temporary write/checksum/replace/backup; stable-ID registration and ordered restore; idempotent scenario events; initial sequence launcher and solved presets.
- **Assets:** reuse PH01–PH04; minimal readable start/continue/settings interface and checkpoint data.
- **Animation:** reconstruct defined safe substates for push, brace, ratchet and Orren recovery; no new cinematic.
- **Visuals / VFX:** restored vane/support/body state matches the actual owner; clear temporary effects on reload.
- **Audio:** resynchronize temporary loops from process state; no doubled voice or motor after retry.
- **Physics:** restore coordinates, permitted velocity, support locks and carrier state before enabling the player; discard irrelevant debris state.
- **Puzzles / interactions:** replay the integrated 10–12 minute route, quit mid-interaction, resume and revisit relieved mechanisms.
- **Playable result:** start, complete, die, continue and replay without debug commands.
- **Visual demonstration:** continuous and restored runs depict the same physical consequences.
- **Tests:** T23–T24, T26, T31, T44; terminate during each durable-write stage, damaged primary, restart during transfer and unsafe checkpoint rejection.
- **Acceptance / exit:** G; all authored checkpoints restore and permit continued progress; last valid save survives interrupted writes. Known schema/backup behavior and cumulative smoke tests are required before PH06.

### PH06 — Station and final-release risk proof

- **Implement / why now:** extend the same project with bounded developer fixtures for P20, evacuation dependencies and P28 interruption. This explicit exception tests high-risk late controls early; it does not add finale content to the onboarding route.
- **Gameplay systems:** SYS-NETWORK-CONTROL, SYS-NODE-SELECT, SYS-AGGREGATE-HOLD, SYS-WITHDRAWAL-HANDOFF, SYS-ROOT-RELEASE.
- **Engineering:** complete a branch-action table: selected node, process direction, latch/unlatch, physical lever, hand needs, input priority, safe state and disconnect condition. Use the canonical three-node station; label any two-node diagnostic as a subset, not campaign design. Separate root/evacuation/withdrawal ownership ledgers.
- **Assets:** reusable lift, drain, counterweight, three-node station, paired lever, refuge/route proxies and distinct root terminal proxy.
- **Animation:** stationary connect/select/lever/disconnect, early strain posture and portable withdrawal contact.
- **Visuals / VFX:** world-space branch continuity, visible node/physical state and ordinary drips; no strategy-map UI or new magic beams.
- **Audio:** temporary branch rhythm, latch/unlatch and safety refusal; selection cue is replaceable.
- **Physics:** one engineered aggregate with defined retained branches; deterministic physical stops and root interlocks, no unlimited personal Holds.
- **Puzzles / interactions:** station lift/stop/drain/counterweight rehearsal; safe two-group route mock; final acquire/postpone/release only after preparation.
- **Playable result:** developer-accessible 5–8 minute risk route plus unchanged earlier playable route.
- **Visual demonstration:** same Hold language scales to a stationary body and distant machinery.
- **Tests:** T11, T15–T16, T22, T26, T33, T41; enumerate focus, pause, range/path break, unload, death, restart, remap, toggle, unplug, held input on restore and duplicate-event causes. Exercise every defined invalid/valid interlock combination.
- **Acceptance / exit:** G; branch actions are unambiguous, other latches persist on selection change, final release commits once only on fresh intended command. Resolve the review's station/support/root specification issues in an approved clarification before PH07; no silent rewrite of core controls.

### PH07 — Custodian, cover and psychological unease

- **Implement / why now:** add C02-S04's P06 wet-sheet interaction and the safe human-cost motif to the Laundry route; prove fear using readable rules.
- **Gameplay systems:** AI-CUSTODIAN, AI-COVER-VOLUME, hearing/exposure, lamp mechanical-shutter Hold and tension presentation.
- **Engineering:** perception/awareness state machine, emitted-location hearing events, opaque/translucent cover contracts, capture telegraph and debug overlay; checkpoint-aware AI restore.
- **Assets:** covered Custodian rig, blanket rack, wet sheet, lamp shutter, safe opaque refuge, porcelain/hand and frosted-glass worker study.
- **Animation:** patrol, investigate, search, capture windup/recovery, cloth passage, distant bracing and subtle inhale/finger movement.
- **Visuals / VFX:** adapt H02's depth/threat-light relationship to the canonical Laundry layout; wet-sheet translucency, restrained cone and cloth motion never disguise actual cover.
- **Audio:** temporary steps, mechanical lamp motion, breath and sparse room tone; tension may build before visibility, with equivalent visual/caption cues.
- **Physics:** blanket rack uses constrained heavy movement; Hold stops the lamp shutter process, not light itself; incidental cloth cannot alter cover unpredictably.
- **Puzzles / interactions:** preposition opaque cover, wait, arrest shutter, cross and release from refuge; motif hints at human cost without revealing Anja.
- **Playable result:** bridge/transfer, stealth and quiet aftermath in one coherent route.
- **Visual demonstration:** readable crouched silhouette, exposure, distance and subtle human movement inside the system.
- **Tests:** T17–T18, T20, T32, T34, T47; five full patrol cycles, all cover edges, no-audio/low-volume, dim display and restored awareness.
- **Acceptance / exit:** G; taught route succeeds repeatedly, capture causes are identifiable, five fresh participants can distinguish cover types. Most report an intended human unease without a loud surprise; document observations before PH08.

### PH08 — Exposed harness, Porter and survivor foundations

- **Implement / why now:** prove P12–P14 and evacuation movement before relying on them in chapter production; share the existing motor/ownership/checkpoint systems.
- **Gameplay systems:** SYS-HARNESS-HOLD, AI-BLOCKED-PATH, Porter assembly motion, AI-EVAC-SAFETY and survivor identity/refuges.
- **Engineering:** covered/exposed port adapters, retained awareness, capture suppression during Hold, bounded Porter path, route safety/occupancy and saved survivor phases.
- **Assets:** exposed Custodian variant, trolley/brake, shutter, luggage frame, Porter body/hose/basket proxy, two survivor groups and refuge markers.
- **Animation:** eyes/breath independent of held body, reach/resume telegraph, trolley obstruction handling, Porter capture/recovery, individual survivor walking/waiting/help gestures.
- **Visuals / VFX:** face remains legible in a held pose; hoses describe a human rescue rig, not a new monster; limited dust and swaying secondary parts.
- **Audio:** temporary harness strain, rail motor, capture warning and survivor footsteps; no final creature sound production.
- **Physics:** gravity trolley on bounded rail, one-handed brake, basket/platform state synchronized with held assembly; safe refuge gating.
- **Puzzles / interactions:** P12 pass restrained harness; P13 preposition trolley before Hold and release brake; P14 arrest basket then cross; two-group evacuation fixture.
- **Playable result:** connected developer encounter route reached through the sequence launcher; existing Laundry route remains intact.
- **Visual demonstration:** conscious restraint and physical scale produce horror without arbitrary immunity.
- **Tests:** T14, T17–T22; all AI states through save/Hold/release, six Porter phase samples, early trolley release, reverse path and 20 evacuation runs.
- **Acceptance / exit:** G; no impossible two-handed solution, capture-hitbox mismatch, hidden knowledge, basket launch or survivor deadlock. Contact/rig feasibility is proven before PH09.

### PH09 — Actual campaign opening, roughly 15 minutes

- **Implement / why now:** assemble C01-S01–S05 to replace test-route context with Ivo's real motivation and onboarding.
- **Gameplay systems:** opening scenario, Anja follow/wait, brace pickup persistence, first-use guidance, P01/P02 and traversal.
- **Engineering:** SYS-CINEMATICS, short alignment/skip/restore rules, safe transport trigger, chapter entry manifest and narrative-fact ledger.
- **Assets:** domestic kit subset, Anja recognizable cuff, Ivo ash-blue identity, chair/cup, landing, bypass transport, dropped brace, drum and subfloor passage.
- **Animation:** stand, chair move, two taps, Anja repair/brace/point, Custodian transfer, pickup, follow and tracking reactions.
- **Visuals / VFX:** ash-blue domestic dusk and weak practicals, cup rattle and dust around stopped landing; protect mother-transfer sightline.
- **Audio:** temporary home sounds, alarm, taps, transport and mechanism cues; identify motivation visually as well.
- **Physics:** controlled landing fold with protected player recess, accessible brace in every state; established shutter/drum rules.
- **Puzzles / interactions:** safe chair lesson, cross Anja's held landing, acquire brace, solve P01/P02 and follow transport shadows.
- **Playable result:** campaign New Game through a safe subfloor checkpoint, no forced 15-minute cutoff.
- **Visual demonstration:** a lived-in home becomes an emergency; cinematic staging occurs around active player control.
- **Tests:** T01–T06, T23, T29, T42; obstruct/flee/linger during transport, quit around pickup/gesture, optional glyph timing and five fresh opening sessions.
- **Acceptance / exit:** G; ≥4/5 move within 15 seconds, understand the immediate objective and do not interpret Anja's capture as a preventable skill failure. Opening events cannot crush/trap Ivo or lose the brace. Ready for pursuit integration.

### PH10 — Complete Chapter 1 and its first pursuit

- **Implement / why now:** finish C01-S06/P03 and join the opening to the Laundry entrance. Verify the taught verb under pressure.
- **Gameplay systems:** pursuit orchestration, covered Custodian, shutter/crouch escape, chapter completion and replay.
- **Engineering:** threat trigger bounds, authored blocked/reopening behavior, chapter save isolation and first real streaming seam.
- **Assets:** courtyard/service exit subset, familiar shutter, low side door, chase-ready Custodian and Laundry entry preview.
- **Animation:** sprint/brace/crouch blends, worker shutter collision and slower reopening, Ivo recovery.
- **Visuals / VFX:** threat light and next-choice framing, minimal rain/dust; chapter transition preserves value hierarchy.
- **Audio:** temporary approach/footsteps/shutter impact and aftermath; no required audio-only warning.
- **Physics:** known shutter collision policy, no worker clipping or shared doorway softlock; platform/input behavior unchanged.
- **Puzzles / interactions:** P03 applies familiar Hold and crouch; no chase-only ability.
- **Playable result:** full nominal 20-minute C01, New Game to Laundry entrance.
- **Visual demonstration:** tension rises through pursuit and releases through a coherent environmental transition.
- **Tests:** T20, T23, T27–T29, T33, T44; three uninterrupted runs, every C01 checkpoint, correct taught sequence at supported frame rates and timing assist.
- **Acceptance / exit:** G; Chapter 1 completes without debug intervention; repeat failure avoids long narrative replay; no seam blocker or untaught action. All C01 dependencies/presets reviewed before PH11.

### PH11 — Opening through the first Laundry allocation puzzle

- **Implement / why now:** integrate C02-S01–S03 after C01, including P05's two-rack route. Confirm that early useful control expands into responsibility without repeated explanations.
- **Gameplay systems:** separate circuits, anchored lower rack plus personal upper rack, heavy basket move and external ownership persistence.
- **Engineering:** shared asset references, explicit cross-chunk owner residency, canonical entry/solved snapshots and cumulative pacing telemetry.
- **Assets:** laundry basket/drain, tied sleeves, frosted-glass worker, two racks and separate local anchor; reuse PH03 bridge.
- **Animation:** push basket, handover, held one-handed catch/jump, distant worker contact and strain response.
- **Visuals / VFX:** green-gray tile, pale fabric, shallow steam; both rack paths and connection endpoints read through full travel.
- **Audio:** temporary machine/breath motif, anchor retention and local rack motion distinguish circuits without exposition.
- **Physics:** stable phase/tolerance alternatives and collision-safe crossing; earlier bridge remains on its independent circuit.
- **Puzzles / interactions:** P04 transfer followed by P05 allocation; no invisible operation order for valid arrangements.
- **Playable result:** continuous first approximately 32 minutes through C02-S03, not a timer-limited demo.
- **Visual demonstration:** motifs and materials carry from home to Laundry while each puzzle has a clear silhouette.
- **Tests:** T07–T12, T23, T27–T31, T46–T47; every reachable rack phase, backtracking, interrupted transfers and five fresh extended sessions.
- **Acceptance / exit:** G; no circuit confusion in state or presentation, seam stalls or repeated gate filler. Fresh players distinguish the two owner types and retain the forward objective. Ready to complete Laundry.

### PH12 — Complete Laundry visual/gameplay production gate

- **Implement / why now:** finish C02-S04–S06 and consolidate all six sequences into the reusable production benchmark before expanding the campaign.
- **Gameplay systems:** full movement/transfer/allocation/stealth/support/revelation loop; integrated input, save, accessibility and settings.
- **Engineering:** asset/ID/import validators, production rig integration, chunk boundary ownership, quality tiers and repeatable packaging. Measure actual per-room effort and revise capacity forecasts.
- **Assets:** complete Laundry kit subset needed by these rooms, Ivo rig/materials, covered Custodian, all hero mechanisms, sleeve/porcelain/fingernail and start/continue/settings UI.
- **Animation:** complete critical slice contact and locomotion transitions, handover, lever, restrained finger response, refusal and retry; no critical placeholder pose.
- **Visuals / VFX:** PH03 treatment consistently across rooms; reveal fingernail at gameplay scale, fog/reflections/thin conduits remain stable in motion; streamed exit into houses.
- **Audio:** complete temporary event coverage with a deliberate exploration→tension→relief contour; explicitly not the final mix or original M11 audio sign-off.
- **Physics:** all current mechanism types, generous support tolerance, safe alternative rack solutions, faithful wet-sheet cover and restore.
- **Puzzles / interactions:** P04–P07 plus sleeve release/fingernail discovery; the human-cost reveal follows player action.
- **Playable result:** nominal 25-minute contiguous Chapter 2, plus the accepted C01 connection. Separate familiarization is not counted as campaign content.
- **Visual demonstration:** in-motion visual benchmark for the whole production, supported by consistent assets and measured render cost.
- **Tests:** all applicable T01–T34, T46–T47; ≥12 fresh slice sessions across inputs/experience, every checkpoint, lower-quality pass, 10-minute resident profiling and seam stress. At least 4/5 in the targeted reveal check identify a human finger.
- **Acceptance / exit:** G; user accepts gameplay/art/animation direction; budgets met or explicitly rebaselined with evidence; known production capacity and bounded defects. **Only this separate gameplay/visual gate permits PH13. Original M11 remains incomplete until PH24's final audio acceptance.**

### PH13 — Chapter 3: homes, conduits and Orren

- **Implement / why now:** build C03-S01–S06 using the validated kit/process pipeline; replace the early P10 fixture with its canonical context.
- **Gameplay systems:** SYS-CONDUIT-GRAPH, SYS-GRAVITY-PROCESS, support relief, NAR-ORREN-FREED and connected hatches.
- **Engineering:** explicit graph addressing/visited protection, stable remote endpoint IDs, reversible puzzle milestones and callback state for Orren.
- **Assets:** domestic rear cavities, bath/flap, cabinet/rail, floor seat, staircase/pawl, paired hatches, repaired wallpaper/height marks, Orren and transport glimpse.
- **Animation:** crawl/flap, conduit rotate, cabinet push, one-handed ratchet, Orren fingers/stand/clear, Ivo observation and ladder descent.
- **Visuals / VFX:** faded wallpaper and narrow amber light slices; early completed target for Orren's relief amid simpler surrounding art; small settling plates/dust.
- **Audio:** temporary domestic creak, connection/ratchet, relief breath and familiar transport/taps.
- **Physics:** controlled balance/settlement, support tolerance, visible conduit path and safe middle refuge.
- **Puzzles / interactions:** P08 remote connection, P09 floor/cabinet balance, P10 explicit relief, P11 reversible coupled path.
- **Playable result:** C01–C03 connected, nominal 75 minutes; all six new room cards playable.
- **Visual demonstration:** domestic life and concealed human support distinguish The Held from generic industry.
- **Tests:** T09, T12–T13, T23, T27, T29, T42–T43, T47; graph breaks, loop traversal, cabinet settling saves, refuge permutations and timed transport visibility. Five fresh chapter sessions.
- **Acceptance / exit:** G; ≥4/5 explain support replacing effort; Orren never blocks the stairs; no inaccessible hatch state. Both continuous and chapter-preset exits carry correct relief facts into PH14.

### PH14 — Chapter 4: conscious restraint and the Porter

- **Implement / why now:** place the accepted exposed-harness/Porter mechanics into C04-S01–S06, revealing that restrained workers remain aware.
- **Gameplay systems:** P12–P15, harness Hold, AI blocked path, Porter assembly and two-support tram settlement.
- **Engineering:** encounter orchestration, one-shoe checkpoint states, synchronized human/rig presentation and camera-through-wall transition.
- **Assets:** civic hall/glazing/trusses, booth/service arm, luggage, trolley, Porter, tram/winch/shoes and reverse-side cabinet/bearer. Establish one production-direction Porter view early in this phase.
- **Animation:** safe port demonstration, continuing eyes/breath, capture/recovery, trolley block, basket traversal, winch/shoe and cabinet reveal.
- **Visuals / VFX:** large charcoal hall, cool glazing and task lights; restrained hose secondary motion and settlement dust.
- **Audio:** temporary rail/rig/capture/eye-breath contrast, tram settlement and quieter cabinet aftermath.
- **Physics:** preposition trolley before Hold; basket stops with assembly; either tram shoe order works, with bounded one-shoe states.
- **Puzzles / interactions:** safe demonstration→P12 person restraint→P13 two dangers→P14 Porter→P15 supported tram passage.
- **Playable result:** C01–C04 connected, nominal 105 minutes, including seamless public-side to bearer-side reveal.
- **Visual demonstration:** human rescue equipment creates the threatening silhouette; no extra creature or combat solution.
- **Tests:** T14, T17–T21, T23, T29–T30, T35, T43; five fresh chapter sessions, all encounter restarts, tram shoe orders and harness awareness on release.
- **Acceptance / exit:** G; ≥4/5 targeted participants explain what stopped and what continued; all taught escapes reproducible; no harness immunity or basket drift. State-correct tram/support output required for PH15.

### PH15 — Chapter 5: burden, dependency and Anja

- **Implement / why now:** build C05-S01–S06, letting earlier actions explain the burden gallery and the difference between relief and irreversible integration.
- **Gameplay systems:** P16–P19, SYS-SUPPORT-CONDITION, dependency relief, narrative facts and protected failed-takeover demonstration.
- **Engineering:** state-driven callback variants, paired dependencies, jack/collar predicates and Anja's shared identity/breath phase across integrated proxies.
- **Assets:** maintenance backs of familiar mechanisms, recovering Orren, slab/support trolley/jack, intact bearer, Anja cuff/hand installation, unused cradle and bypass walkway.
- **Animation:** vent flap, trolley/jack/collar, bearer steps clear, Anja two taps/refusal, Ivo hand contact/recoil and safe bypass traversal.
- **Visuals / VFX:** close cavities, ceramic and skin contact, stressed building material; one finished-direction Anja reveal without an alien-body redesign. Settling and leak guide cause/effect.
- **Audio:** temporary human/machine rhythm correspondences, relief subtraction, taps and pressure direction; no final score.
- **Physics:** support trolley cannot block sole return; too-low jack settles to reversible safety stop; release handle demonstration catches before injury.
- **Puzzles / interactions:** clear rail P16, jack/collar/double relief P17, Anja local takeover P18, avoid permanent cradle via P19 bypass.
- **Playable result:** C01–C05 connected, nominal 140 minutes, with the new forward objective to prepare release.
- **Visual demonstration:** earlier relieved bearers appear slack/recovering, never falsely strained; Anja's physical distribution remains intelligible.
- **Tests:** T13, T23, T35–T36, T42–T43, T48; direct presets versus continuous states, all jack tolerance/reverse orders and five fresh narrative sessions.
- **Acceptance / exit:** G; ≥4/5 understand why ordinary support can free an intact bearer but cannot restore Anja. No implied secret rescue timer/good ending, no accidental cradle attachment. Approved callback variant ledger required for PH16.

### PH16 — Chapter 6: the unfinished flood and preparation

- **Implement / why now:** build C06-S01–S06, escalating the same process/support language to the hydraulic scale and rehearsed station controls.
- **Gameplay systems:** P20–P23, network station, assembly support, discharge/deflector/bypass facts and temporary strain.
- **Engineering:** implement the PH06 branch-action table in canonical geometry; authored water state/flow routes, route manifest and prerequisite validator.
- **Assets:** hydraulic galleries, two distinct water levels, tide markers, lift/drain/counterweight station, barrier/rack/crank, receiving blocks, deflector panel and bypass apparatus.
- **Animation:** station connect/select/lever, crank/winch, body bracing, approaching cuff apparatus and safe withdrawal.
- **Visuals / VFX:** first in-motion flood vista at production direction early in the phase; ordinary lower sea versus arrested surge, separate test streams, bounded mist and controlled collapse debris.
- **Audio:** temporary large-water/pressure/strain, latch/lock and small test-flow cues; visual test-flow equivalent mandatory.
- **Physics:** authored water volume/collision/hazards separate; deflector success uses blocks/sockets, never procedural destruction or fluid simulation.
- **Puzzles / interactions:** three-node P20, discharge rack/crank P21, receiving blocks/deflector P22, bypass under pressure P23; inland path establishes geography.
- **Playable result:** C01–C06 connected, nominal 175 minutes, with all evacuation/release preparations saved.
- **Visual demonstration:** both water levels readable in one composition; body/environment motion conveys strain without camera sickness.
- **Tests:** T11–T12, T23, T29, T34, T36, T41, T43; block offset permutations, all station latches, interrupted connect/withdraw, aspect ratios and five fresh chapter sessions.
- **Acceptance / exit:** G; ≥4/5 distinguish ordinary sea from trapped water and explain the release route. Station cannot trigger final release. All mandatory preparation flags and recoverable failure states pass before PH17.

### PH17 — Chapter 7: temporary bearer and evacuation

- **Implement / why now:** build C07-S01–S06 around the proven station/refuge system, making the climax an extension of earlier responsibility.
- **Gameplay systems:** aggregate Hold, P24–P26, evacuation groups A/B, safety, selected branches and withdrawal handoff.
- **Engineering:** named survivor ledger, per-crossing snapshots, world-space camera/node routing, safety interlocks and explicit root/aggregate/withdrawal ownership audit.
- **Assets:** central station, familiar tram/canopy/stair/shutters, refuges, established cohort, Orren helping another person, catwalk and quiet root approach.
- **Animation:** stationary full-body brace, individual walking/hesitation/help, connection/withdrawal, fingers remaining curled and ordinary crawl/hatch/stair.
- **Visuals / VFX:** familiar locations seen through their connections; restrained strain/settlement with no abstract command map or new biome.
- **Audio:** temporary branch rhythms, crowd footfalls and gradual strain subtraction; quiet approach with optional observation time.
- **Physics:** single curated aggregate, real supports and occupancy sensors; shut routes only after the last survivor clears. Timeout requests safe repath at refuge, not visible teleport.
- **Puzzles / interactions:** inspect dependency, settle tram and maintain shutter P24, support canopy/stair and crossing P25, withdraw via local restraint P26.
- **Playable result:** C01–C07 connected, nominal 205 minutes; Ivo can return to ordinary traversal while Anja still owns the root.
- **Visual demonstration:** people choose to move themselves, Ivo's body remains physically involved and the environment grows quieter as dependencies resolve.
- **Tests:** T11, T15, T22–T23, T26–T29, T30, T41–T43; save at each survivor boundary, rapid selection, wrong order, 20 full evacuation cycles and five fresh chapter sessions.
- **Acceptance / exit:** G; ≥4/5 identify the first physical obstruction without commentary; no lost/duplicated survivor, deadlock or root-owner contradiction. Audit the quiet approach's real attention time rather than enforcing a four-minute wait. Safe final-chapter entry required.

### PH18 — Chapter 8: deliberate release and ordinary help

- **Implement / why now:** finish C08-S01–S06 using established controls and saved preparation; deliver the canonical ending before cosmetic completion.
- **Gameplay systems:** P27–P29, NAR-ROOT-RELEASED, dead network, final handover, completion and replay/credits.
- **Engineering:** fresh-command release latch, exact-once semantic ending event, interruption-safe paired gesture, post-loss checkpoint and atomic completion save.
- **Assets:** visible drain-test linkage, Anja/Ivo hand/cuff, prepared root/discharge, dry escape route, lightweight balanced gate, Orren and survivor open hand.
- **Animation:** eight-second approximate two-tap interaction, takeover/postponement/release, quiet irreversible loss, familiar escape, Orren voluntary gate lift and Ivo uncurl/accept/final steps.
- **Visuals / VFX:** readable test stream, authored safe discharge/settlement, transition from bare stone to pale overcast daylight; no spectacle that obscures the human moment.
- **Audio:** temporary taps/breath/release/water, silence after loss and unsynchronized ending steps; mark final emotional mix unvalidated until PH25–PH27.
- **Physics:** safe authored flood trajectory, known gaps/slope/beam, gate occupancy protects both people; network remains powerless.
- **Puzzles / interactions:** verify prepared path P27, deliberate root handover/release P28, ordinary movement escape P29, voluntary gate assistance and playable epilogue.
- **Playable result:** New Game to ending/credits without debug skips, nominal 225 minutes; final steps remain player-controlled after the short hand alignment.
- **Visual demonstration:** responsibility, loss and relief conclude through ordinary movement and another person's hand.
- **Tests:** T16, T23–T26, T33, T37, T41–T45, T48; all root interlocks and release causes, quit during fade, credits skip, replay isolation and repeated escape failure.
- **Acceptance / exit:** G; no accidental ending, alternate-root owner or repeated Anja death after escape retry; all prerequisites derive from mandatory play. Five fresh ending reviews connect preparation to release and recognize Anja's loss. Full campaign is ready for PH19 audit, not yet declared complete.

### PH19 — Full campaign gameplay-complete gate

- **Implement / why now:** close gameplay gaps across all 48 sequences and all 29 challenges before final content/audio work. This is the explicit gameplay-first completion gate.
- **Gameplay systems:** all verbs, enemies, station, survivors, narrative interactions, checkpoints, replay and ending; corrections only, no new features.
- **Engineering:** full sequence/dependency matrix, canonical solution traces, checkpoint sweep, save-schema fixtures, softlock diagnostics and local duration ledger.
- **Assets:** all gameplay-critical geometry/props/cast present; remaining visual proxies individually listed, never concealing unproven reach or collision.
- **Animation:** every required interaction has playable contact/timing, including refusals, interruptions and final gestures; cosmetic refinements may remain.
- **Visuals / VFX:** one accepted moving target per chapter and no placeholder that prevents understanding of water, support, cover, anatomy or story.
- **Audio:** full temporary coverage and event/state documentation; auditory polish explicitly deferred.
- **Physics:** regression across every process/assembly/support/AI/puzzle state; validate frame-rate outcomes and lower-quality independence.
- **Puzzles / interactions:** all P01–P29 from canonical entry, intermediate, failure and solved states; allow legitimate alternatives.
- **Playable result:** complete uninterrupted campaign, separate replay sessions and valid durable saves throughout.
- **Visual demonstration:** continuous emotional/visual progression rather than a set of disconnected demos.
- **Tests:** T01–T30, T33–T38, T41–T44, T46–T48 as applicable to temporary presentation; three full internal runs, every checkpoint, 29 solution traces and eight fresh full-run sessions as a formative target. Missing testers block the human gate rather than being fabricated.
- **Acceptance / exit:** G; no missing sequence, debug skip, Critical/High defect or unproven late rule; all required comprehension tests and recovery paths pass. Duration findings distinguish active play, retries, pauses and idle attention; target 210–240-minute median without filler. User accepts gameplay completion. Record geometry/mechanic lock and bounded remaining presentation work before PH20.

### PH20 — Domestic and Laundry visual production pass

- **Implement / why now:** bring C01–C03 to PH12's visual standard after gameplay geometry is understood; preserve the early benchmark while extending its pipeline.
- **Gameplay systems:** existing opening, Laundry and domestic puzzles; only evidence-driven fixes.
- **Engineering:** asset variant/use matrix, source/export validation, LOD/collision separation, material budget checks and reimport regression.
- **Assets:** final required domestic/Laundry modules and props; production Ivo, Anja opening and Orren materials; repairs, cloth, cup, wallpaper and porcelain variants.
- **Animation:** refine starts/stops, chair/brace/ladder/ratchet contacts, tapping and Orren relief in these chapters.
- **Visuals / VFX:** chapter-specific dusk, steam and amber slices; texture detail at hands/feet/story; fix reflection/fog/AA artifacts during movement.
- **Audio:** preserve temporary cue timing/coverage; no REAPER production yet.
- **Physics:** identical authored collision and support tolerances after art replacement; changes reopen affected puzzle tests.
- **Puzzles / interactions:** replay P01–P11 and associated story actions using final-direction assets.
- **Playable result:** complete campaign still works; first three chapters visibly production-representative.
- **Visual demonstration:** matched before/after sequences and user prototype alignment in real gameplay, including low settings.
- **Tests:** T01–T13, T23, T27–T30, T34, T42–T43, T46; all changed colliders, contact sockets, supported ratios and material budgets.
- **Acceptance / exit:** G; no critical visual proxy in C01–C03, no art-induced puzzle change, documented source/provenance and repeatable import. User accepts consistency with PH12 before PH21.

### PH21 — Civic and burden-room visual production pass

- **Implement / why now:** finish C04–C05 characters and mechanisms without losing the conscious-restraint and irreversible-integration distinctions.
- **Gameplay systems:** existing P12–P19, AI, dependency relief and narrative callback states.
- **Engineering:** shared rigs/material variants, Anja phase linkage, saved-state presentation adapters and streaming cost controls.
- **Assets:** final hall/glazing/luggage, Custodians, Porter body/hose/basket, tram, cabinets, jack/slab, bearer variants and Anja installation.
- **Animation:** capture/recovery/harness eyes/breath, Porter weight, bearer detachment, Anja refusal and cuff/tap continuity.
- **Visuals / VFX:** targeted face/hand lighting, restrained human tissue/stressed material, minimal secondary hoses/dust; no glossy alien redesign.
- **Audio:** temporary rig/human rhythms retained; update event attachment positions with revised rigs.
- **Physics:** exact assembly/capture/basket alignment after model/rig changes; final art cannot introduce collision or support instability.
- **Puzzles / interactions:** P12–P19 plus state-correct recognition gallery in full campaign context.
- **Playable result:** complete campaign with C04–C05 at the established moving visual benchmark.
- **Visual demonstration:** threat and personhood coexist; relieved variants and integrated Anja read accurately.
- **Tests:** T14, T17–T23, T29–T30, T35–T36, T42–T43, T46, T48; actor scale, contact bounds, callback variants and targeted fresh comprehension rechecks.
- **Acceptance / exit:** G; no critical proxy or rig mismatch; neither visual fidelity nor stylization undermines human identity or essential comprehension. Approved C04–C05 captures and budgets precede PH22.

### PH22 — Hydraulic, climax and ending visual production pass

- **Implement / why now:** finish C06–C08 at equal quality to the opening; monumental effects must not weaken the prepared-release logic.
- **Gameplay systems:** existing P20–P29, evacuation, withdrawal, root and epilogue.
- **Engineering:** final chunk manifests, warmed effect/shader assets, water presentation states and quality-preserving scalability.
- **Assets:** final hydraulic ribs/channels, water surfaces, block/deflector/station, survivor variants, root structures, balanced gate and embankment.
- **Animation:** all strain layers, group helping/waiting, body withdrawal, final hands and voluntary gate timing with contact refinement.
- **Visuals / VFX:** distinct ordinary/arrested water, bounded flow/debris, clear survivor shelters, gradual daylight and independent final motion.
- **Audio:** maintain complete temporary sound-event coverage and staging markers for later REAPER sessions.
- **Physics:** unchanged authored flow/hazard routes and supported assemblies; low-quality effects cannot alter interlocks or hide route safety.
- **Puzzles / interactions:** P20–P29 and all final gestures at production visual scale.
- **Playable result:** all chapters have production-direction art/VFX and readable gameplay; campaign remains start-to-finish.
- **Visual demonstration:** flood scale and intimate final hands both survive ordinary viewing distance and lower settings.
- **Tests:** T11–T12, T15–T16, T22–T30, T33–T34, T36–T43, T46; water-level framing, final command permutations, extreme camera/FX load and checkpoint transitions.
- **Acceptance / exit:** G; no critical late-game visual placeholder or safe-route ambiguity; performance stays within accepted allocations. Full visual asset inventory and final-state variants reconciled before PH23.

### PH23 — Whole-game animation, camera and player-facing completion

- **Implement / why now:** consolidate the actual player experience and lock timing before sound production, preventing REAPER work against unstable scene cuts/contacts.
- **Gameplay systems:** final approved gameplay corrections, assist modes, menus, replay, credits and user-facing error recovery.
- **Engineering:** complete animation interruption matrix, cinematic restore/skip contracts, input context/glyph validation, text/caption localization pipeline and settings/save migration.
- **Assets:** final required menus/glyphs/signage/caption styles and remaining contact/face variants; scope supported languages explicitly rather than inventing a list.
- **Animation:** all required starts/stops/blends, hands/feet, four strain stages, paired alignment, death/retry, posture recovery and epilogue gestures; clip count is not acceptance.
- **Visuals / VFX:** continuous camera/pacing pass, no foreground obstruction, exposure pumping or cut pops; reduced shake/flashes retain information.
- **Audio:** temporary mix remains; export a cue sheet with event IDs, spatial emitters, intended emotion, silence, state parameters and screenshot/time references for every sequence.
- **Physics:** retest contact-driven boundaries; animation/VFX never become the authority for puzzle completion.
- **Puzzles / interactions:** all campaign interactions on default, remapped/toggle and timing-assist configurations.
- **Playable result:** stable gameplay and visual/cinematic experience ready for final audio production.
- **Visual demonstration:** consistent weight, active cinematic framing, short local alignment and readable UI through all eight chapters.
- **Tests:** T23–T30, T33–T38, T41–T48; target ≥95% ordinary movement or active station control time, inspect 10–15-second alignment exceptions, font overflow, input swaps and chapter replay isolation.
- **Acceptance / exit:** G; PH19 gameplay gate revalidated after final art/animation, no critical proxy or unexplained input lock, approved timing/event sheet and feature freeze. User accepts readiness for REAPER; gameplay changes after this point require impact-based audio retesting.

### PH24 — REAPER production and final Laundry audio benchmark

- **Implement / why now:** begin final sound work only after the gameplay lock. Use the existing complete Laundry slice to establish the repeatable sonic quality bar.
- **Gameplay systems:** unchanged C02 loop; final event/state-driven feedback and accessibility cues.
- **Engineering:** REAPER source/export recipe, audio asset naming/provenance, Unreal event adapter/MetaSounds or equivalent, bus hierarchy, concurrency, attenuation, occlusion and state resynchronization.
- **Assets:** original/licensed Laundry room tones, cloth/water, steps, hands, porcelain/metal, machine/breath/strain families and restrained musical textures where justified.
- **Animation:** synchronize footsteps, inhale/exhale, contact and handover without making animation notifies the sole gameplay trigger.
- **Visuals / VFX:** preserve the accepted visual target; coordinate existing mechanical/light responses only where grounded in the world.
- **Audio:** finished Laundry SFX/ambience, dynamic tension and silence, mix and captions; stereo/mono/reduced-dynamic-range verification. Human breath is designed carefully, not spread as a generic loop over every machine.
- **Physics:** audio observes authoritative phase, velocity, owner/support and impact intensity; pause/resume/retry remain coherent.
- **Puzzles / interactions:** all P04–P07 and the fingernail revelation with final audio.
- **Playable result:** final audiovisual 25-minute Laundry slice and full campaign with other chapters still marked temporary in audio.
- **Visual demonstration:** the already accepted scene gains audible material/weight without louder visual clutter or gameplay changes.
- **Tests:** T23, T26, T28, T31–T34, T47; ≥12 fresh slice sessions, headphones/speakers/mono/low volume, no-audio equivalents, voice limits, device change and profiling.
- **Acceptance / exit:** G; user and discipline reviewers accept final sonic identity, puzzle readability and reveal; no loop duplication, clipping, missing cue or performance regression. Revalidate every original M11 requirement against this exact build before marking M11 complete. Export/session pipeline ready for PH25.

### PH25 — Final audio across the campaign

- **Implement / why now:** extend the approved sonic language to C01 and C03–C08, keeping each chapter's emotional and physical character.
- **Gameplay systems:** existing movement, AI, process, station, survivor and narrative events with complete final responses.
- **Engineering:** full cue-to-sequence coverage, streaming/preload rules, voice budgets, saved mix state, caption timing and deterministic trigger deduplication.
- **Assets:** REAPER sessions and exports for domestic/civic/hydraulic spaces, cast/rig breathing, surfaces, alarm, taps, water, withdrawal and ending footsteps; music stems only where designed.
- **Animation:** final alignment of breaths, steps, contact, capture, two taps and paired gestures with variant control.
- **Visuals / VFX:** synchronize existing justified lamps, particles and impacts; preserve silence and quiet visual aftermath.
- **Audio:** original restrained score/texture, distance, occlusion, dynamic-range modes, material detail and purposeful silence; no imitation of recognizable INSIDE motifs or processing signatures.
- **Physics:** q/velocity-driven motor/strain layers, supported-state subtraction, matched impact/settlement and prepared discharge sequence.
- **Puzzles / interactions:** every puzzle, refuge/capture and narrative interaction receives final cues and accessible equivalents.
- **Playable result:** first full campaign with final intended audio coverage from home to independent epilogue footfalls.
- **Visual demonstration:** sound directs attention within existing compositions and makes ordinary support/relief perceptible.
- **Tests:** T18, T23, T26–T28, T31–T32, T35–T38, T42–T43, T48; event coverage scan, all checkpoints, repeated deaths, mono/low volume and full-run tension notes.
- **Acceptance / exit:** G; no mandatory cue remains temporary/missing, no monotonous loops or volume-spike dependency; source rights and exports reconciled. User accepts full sonic pass; new pacing defects are fixed before PH26.

### PH26 — Full audiovisual alpha

- **Implement / why now:** integrate and judge the whole game as one experience after final audio changes the perception of timing, threat and story.
- **Gameplay systems:** feature/content-complete campaign; targeted corrections only.
- **Engineering:** consolidated asset/state validators, prior-schema save migration, release-like packaging and long-session diagnostics.
- **Assets:** all essential art/animation/audio/UI integrated; no placeholder preventing judgment of the intended experience.
- **Animation:** resolve whole-game contact, transition and emotional timing defects uncovered by full runs.
- **Visuals / VFX:** match every chapter to its accepted benchmark without flattening color/scale progression.
- **Audio:** full mix in context, scene transitions, silence and range modes; revise where final audio exposes pacing weaknesses.
- **Physics:** full process/ownership/support and collision regression after integrated content revisions.
- **Puzzles / interactions:** all 29 challenges, consequences, required narrative beats and canonical ending.
- **Playable result:** complete alpha with frozen feature/narrative structure, suitable for fresh full-game testing.
- **Visual demonstration:** coherent competence→unease→complicity→responsibility→loss/relief journey in continuous play.
- **Tests:** T01–T48 applicable to alpha, ≥8 new full-run testers, every checkpoint, no-audio/assist routes and long-session memory. Release-only install/update checks may remain scheduled but cannot be reported passed.
- **Acceptance / exit:** G; no missing essential content or Critical/High defect; remaining polish is bounded, assigned and estimated. User accepts alpha and content-freeze boundary before PH27. Satisfies original M13 only with all its evidence.

### PH27 — Beta, accessibility and external experience validation

- **Implement / why now:** validate the completed game across unfamiliar players/configurations before final optimization and release locking.
- **Gameplay systems:** frozen content; fix demonstrated confusion, accessibility and compatibility problems.
- **Engineering:** shipping settings, localization integration for the agreed languages, save/settings migration, controller handling and consent-aware diagnostics policy.
- **Assets:** final captions/glyphs/localized signage, credits and compatibility corrections; no new chapter or mechanic.
- **Animation:** corrections for assist modes, repeat failures, contact and paired gestures on alternate input paths.
- **Visuals / VFX:** validate dim displays, 720p, supported ratios, reduced flashes/shake, low settings and critical hand/water/cover readability.
- **Audio:** headphones/speakers/mono, low volume/reduced range, captions and optional cue equivalents preserve required information without explaining the mystery.
- **Physics:** same rules/outcomes across settings, frame rates, device changes and long play sessions.
- **Puzzles / interactions:** complete fresh campaign runs, ending agency and tutorial-use ethical framing; no leading explanation by moderators.
- **Playable result:** stable representative beta on the declared support matrix.
- **Visual demonstration:** early benchmark quality extends to all rooms and accessible configurations.
- **Tests:** all applicable tests, especially T25–T38, T42, T47–T48; approximately 24 fresh full-run participants as a formative target and 20-session checkpoint stress. Record skill/input/horror-tolerance profiles and attrition.
- **Acceptance / exit:** G; zero known Critical/High blockers; median duration target 210–240 minutes supported without filler, essential causality/ending understood, all promised accessibility/language features verified. User accepts beta before PH28; unavailable test coverage is an explicit blocker.

### PH28 — Performance and final production polish

- **Implement / why now:** close measured frame-time, memory, loading and repeated-play defects on locked content; optimization has been continuous, this is the final convergence gate.
- **Gameplay systems:** unchanged rules; narrowly scoped corrections with affected-puzzle regression.
- **Engineering:** Unreal Insights captures, activation/streaming scheduling, shader warmup, voice budgets, asset stripping and reproducible cook/package.
- **Assets:** justified LOD/material/texture/animation revisions, pooled effects and sound variations; retained clue/hand fidelity.
- **Animation:** remove remaining contact pops, sliding and transition discontinuities without adding input latency.
- **Visuals / VFX:** optimize overdraw, shadows/fog/reflections and water while retaining accepted reference shots and motion clarity.
- **Audio:** eliminate repetition, restart artifacts and mixing/voice spikes; protect danger cues under load.
- **Physics:** confirm optimized tick/LOD/culling never changes authoritative process behavior or removes active owner endpoints.
- **Puzzles / interactions:** worst-case station, flood, pursuit, support and checkpoint scenes plus full regression.
- **Playable result:** near-final campaign meeting the accepted target hardware/quality budgets in a packaged build.
- **Visual demonstration:** side-by-side proof that performance work preserves the original visual and narrative intent.
- **Tests:** T01–T02, T23–T34, T39, T43–T46; CPU/GPU p95/p99/worst, cold cache/boot, disk contention, fastest route, repeated deaths, long-session memory and resize/alt-tab.
- **Acceptance / exit:** G; accepted frame/memory/install budgets met, no unexplained resident spikes, streaming stress resolved and all Critical/High regressions closed. Record exact support matrix and freeze candidate inputs before PH29.

### PH29 — Release candidate and final production build

- **Implement / why now:** produce and verify the exact distributable game, not a different editor/demo executable.
- **Gameplay systems:** frozen shipped campaign, settings, completion, replay and offline start.
- **Engineering:** immutable candidate hash, build provenance, packaging integrity, clean install/update/rollback, crash/support procedure and source/build archive.
- **Assets:** final cooked content, source rights/notices/credits, accurate controls/accessibility description and marketing capture from accepted content; delivery channel requirements recorded.
- **Animation:** no new content; verify shipping cook includes every required animation and restored cinematic state.
- **Visuals / VFX:** verify packaged shaders/effects, quality defaults and all late-game assets on clean hardware.
- **Audio:** verify every exported asset/reference, first boot, offline playback, streaming and credits mix; no mismatched revisions.
- **Physics:** exact candidate full puzzle/owner/support/input-interruption regression, including final release and continued saved games.
- **Puzzles / interactions:** New Game to credits, all checkpoint entries, chapter replay, completion and reset-progress confirmation.
- **Playable result:** immutable final production build with reproducible installation and recoverable saves.
- **Visual demonstration:** final gameplay captures correspond to the candidate and accurately represent supported quality.
- **Tests:** T16, T23–T28, T33, T39–T46; clean-machine install, offline start, full campaign, interrupted saves, update/rollback from supported fixtures and final ending. If no prior public release exists, use a labeled staged predecessor fixture.
- **Acceptance / exit:** G; zero Critical/High release blockers; exact hash and all discipline/user sign-offs recorded, sources and rollback archived. Any fix creates a new candidate and relevant retests. **Publishing/distribution is a separate explicit user action/authorization; roadmap acceptance alone is not publication approval.**

### PH30 — Stabilization of the accepted release

- **Implement / why now:** maintain the verified game after release or use this reserve to resolve candidate issues first; no promised expansion content.
- **Gameplay systems:** only affected existing behavior; preserve story and save compatibility.
- **Engineering:** reproducible report intake, narrow patch branches, supported-version matrix, rollback and migration rehearsal.
- **Assets:** replacement files only for reproduced faults, patch notes and support guidance.
- **Animation:** correct a verified contact/capture/gesture fault only when present; otherwise reuse unchanged assets.
- **Visuals / VFX:** targeted compatibility/performance corrections; otherwise no new effects.
- **Audio:** fix verified missing/repeating/misrouted cues; otherwise keep accepted mix.
- **Physics:** minimal reproduction for reported process/collision faults and regression against all affected dependencies.
- **Puzzles / interactions:** reproduce the reported failure, confirm intended solution/recovery and rerun ending/save-critical routes.
- **Playable result:** tested patch candidate or unchanged supported release with an evidence-based triage record; do not invent a patch when none is needed.
- **Visual demonstration:** before/after fault capture and preserved benchmark quality.
- **Tests:** T23–T26, T39–T46 plus defect-specific tests on matching configurations; stage update/rollback before distribution.
- **Acceptance / exit:** G; reproduced incidents resolved or documented with an accepted mitigation, saves intact and exact supported hash archived. User separately approves patch publication; future ports/new content require a separate scope decision.

## 4. Evidence and phase handoff

Each phase review goes in the planned `phase-reviews/PHxx/` location. Build binaries may live in an artifact store; record their immutable location/hash rather than checking large builds into source control.

Required review packet:

1. `review.md`: phase/version, source revision, exact build hash, launch instructions, scope/IDs, actual versus planned deliverable and known limitations.
2. Build/cook log and test results, with pass/fail/blocked status and reproduction steps. Keep automated results separate from human observations.
3. Target and actual screenshots at the same camera, an uninterrupted gameplay capture, performance traces and minimum-quality capture. Capture gameplay locally; do not generate synthetic video as acceptance evidence.
4. Every new checkpoint entry/exit, intended solution trace, failure/recovery map, owner/support state and story-fact deltas.
5. Required assets/variants, source/provenance/export paths, animation transitions and audio cue coverage. Asset-family counts are planning units, not finished-file counts.
6. Playtest profile/count, non-leading questions, actual observations, confusion/failure/time ledger and resulting decisions. Never label developer familiarity as fresh-player evidence.
7. G review with Gameplay, Visuals, Story, Puzzles, Physics, Animation, Audio, Atmosphere, Performance, Stability, Understanding and Production each marked Pass/Fail/Blocked, reviewer/date and supporting evidence.
8. Defects and next-phase prerequisite checklist; estimated remaining work using measured capacity; explicit user acceptance reference.

Suggested review record:

```text
Phase: PHxx / roadmap version:
Status: In review
Build location / hash / source revision:
Playable entry and expected exit:
Blueprint sequence / puzzle / system / test IDs:
New work / reused work / temporary elements:
Automated results / manual results / player findings:
G discipline decisions and evidence:
Performance fixture / resolution / quality / p95 / p99 / memory:
Critical defects: 0 required
High defects: 0 required
Lower defects / owner / planned correction / impact:
Predecessor regressions: none unresolved
User review decision / date / message reference:
Exit: Accepted only when all required evidence and acceptance exist
Next phase: PHxx+1, not started until this exit is recorded
```

Maintain a current phase ledger in this file once approved. Evidence folders and issue trackers support it; they do not override the phase order. Start with all phases Not started and approval pending. The coverage tables below are planned assignments, not completion claims.

## 5. Traceability

The following tables connect this roadmap to all canonical sequences, system packages and tests. Stable IDs must survive content renames. Counts and names come from the supplied JSON registers. Their `uses` lists are not assumed exhaustive: build the actual dependency/variant graph from every sequence's asset references before assigning bulk production work. Each phase's required asset/animation/VFX/audio lists are the initial work-package brief; at phase entry resolve them to existing family IDs, required variants and source paths. The phase review records that resolved list. Do not create 200 packages or 162 clips merely to satisfy planning counts.

### 5.1 All 48 campaign sequences

Early fixtures reuse canonical mechanics but do not change when the player encounters them. The integration phase below is when the actual campaign sequence becomes required; visual refinement never substitutes for playable integration.

| Sequence | Canonical title | Campaign integration | Final presentation pass |
|---|---|---|---|
| C01-S01 | A hand on the table | PH09 | PH20; PH23; PH25; full-game gates PH26–PH29 |
| C01-S02 | The landing does not fall | PH09 | PH20; PH23; PH25; full-game gates PH26–PH29 |
| C01-S03 | The useful shutter | PH09 | PH20; PH23; PH25; full-game gates PH26–PH29 |
| C01-S04 | The tilted drum | PH09 | PH20; PH23; PH25; full-game gates PH26–PH29 |
| C01-S05 | Below the wheels | PH09 | PH20; PH23; PH25; full-game gates PH26–PH29 |
| C01-S06 | The worker behind you | PH10 | PH20; PH23; PH25; full-game gates PH26–PH29 |
| C02-S01 | Sleeves with no hands | PH11 | PH20; PH23; PH24; full-game gates PH26–PH29 |
| C02-S02 | Someone else holds it | PH11 | PH20; PH23; PH24; full-game gates PH26–PH29 |
| C02-S03 | The hanging corridor | PH11 | PH20; PH23; PH24; full-game gates PH26–PH29 |
| C02-S04 | The wet sheet | PH12 | PH20; PH23; PH24; full-game gates PH26–PH29 |
| C02-S05 | The room behind the room | PH12 | PH20; PH23; PH24; full-game gates PH26–PH29 |
| C02-S06 | Under the porcelain | PH12 | PH20; PH23; PH24; full-game gates PH26–PH29 |
| C03-S01 | At the back of a kitchen | PH13 | PH20; PH23; PH25; full-game gates PH26–PH29 |
| C03-S02 | Reach through a wall | PH13 | PH20; PH23; PH25; full-game gates PH26–PH29 |
| C03-S03 | The tilted dining room | PH13 | PH20; PH23; PH25; full-game gates PH26–PH29 |
| C03-S04 | The staircase and Orren | PH13 | PH20; PH23; PH25; full-game gates PH26–PH29 |
| C03-S05 | The outside of the bedroom | PH13 | PH20; PH23; PH25; full-game gates PH26–PH29 |
| C03-S06 | A line that leads down | PH13 | PH20; PH23; PH25; full-game gates PH26–PH29 |
| C04-S01 | The waiting passengers | PH14 | PH21; PH23; PH25; full-game gates PH26–PH29 |
| C04-S02 | His eyes are still moving | PH14 | PH21; PH23; PH25; full-game gates PH26–PH29 |
| C04-S03 | One hand, two dangers | PH14 | PH21; PH23; PH25; full-game gates PH26–PH29 |
| C04-S04 | The Braced Porter | PH14 | PH21; PH23; PH25; full-game gates PH26–PH29 |
| C04-S05 | The tram that never arrived | PH14 | PH21; PH23; PH25; full-game gates PH26–PH29 |
| C04-S06 | The other side of the fittings | PH14 | PH21; PH23; PH25; full-game gates PH26–PH29 |
| C05-S01 | The people carrying the town | PH15 | PH21; PH23; PH25; full-game gates PH26–PH29 |
| C05-S02 | Make room for a support | PH15 | PH21; PH23; PH25; full-game gates PH26–PH29 |
| C05-S03 | A room without a bearer | PH15 | PH21; PH23; PH25; full-game gates PH26–PH29 |
| C05-S04 | Mother, in more than one place | PH15 | PH21; PH23; PH25; full-game gates PH26–PH29 |
| C05-S05 | The place prepared for you | PH15 | PH21; PH23; PH25; full-game gates PH26–PH29 |
| C05-S06 | Follow the pressure | PH15 | PH21; PH23; PH25; full-game gates PH26–PH29 |
| C06-S01 | The sea is below us | PH16 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C06-S02 | A smaller junction | PH16 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C06-S03 | Give the water a route | PH16 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C06-S04 | The fallen section becomes a wall | PH16 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C06-S05 | The building breathes with you | PH16 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C06-S06 | An inland path | PH16 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C07-S01 | The last bearer | PH17 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C07-S02 | See who must cross | PH17 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C07-S03 | A bridge for people who choose to move | PH17 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C07-S04 | The shelter becomes ordinary | PH17 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C07-S05 | Withdraw your hands | PH17 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C07-S06 | No one is pulling you onward | PH17 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C08-S01 | Check the path you made | PH18 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C08-S02 | Two taps | PH18 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C08-S03 | Let it move | PH18 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C08-S04 | The last moving corridor | PH18 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C08-S05 | A person holds the gate | PH18 | PH22; PH23; PH25; full-game gates PH26–PH29 |
| C08-S06 | Open hand | PH18 | PH22; PH23; PH25; full-game gates PH26–PH29 |

### 5.2 All 40 system packages

First proof is a bounded integration target, not final-system completion. Every package must also pass the campaign gameplay gate PH19 and applicable final gates PH23–PH29.

| System ID | Register name | First required proof |
|---|---|---|
| AI-BLOCKED-PATH | Blocked Path | PH08 |
| AI-COVER-VOLUME | Cover Volume | PH07 |
| AI-CUSTODIAN | Custodian | PH07 |
| AI-EVAC-SAFETY | Evac Safety | PH06; actor proof PH08 |
| NAR-ORREN-FREED | Orren Freed | PH04; canonical PH13 |
| NAR-ROOT-RELEASED | Root Released | PH06; canonical PH18 |
| SYS-AGGREGATE-HOLD | Aggregate Hold | PH06 |
| SYS-ASSEMBLY-SUPPORT | Assembly Support | PH06; hydraulic assembly PH16 |
| SYS-CONDUIT-GRAPH | Conduit Graph | PH06; remote conduit PH13 |
| SYS-DEAD-NETWORK | Dead Network | PH18 |
| SYS-EVAC-GROUP-A | Evac Group A | PH08; canonical PH17 |
| SYS-EVAC-GROUP-B | Evac Group B | PH08; canonical PH17 |
| SYS-GRAVITY-PROCESS | Gravity Process | PH04; cabinet balance PH13 |
| SYS-HANDOFF | Handoff | PH03; opening PH09 |
| SYS-HARNESS-HOLD | Harness Hold | PH08 |
| SYS-HOLD | Hold | PH02 |
| SYS-HOLD-OWNER | Hold Owner | PH02; external owner PH03 |
| SYS-NETWORK-CONTROL | Network Control | PH06 |
| SYS-NODE-SELECT | Node Select | PH06 |
| SYS-ROOT-RELEASE | Root Release | PH06 |
| SYS-SUPPORT | Support | PH04 |
| SYS-SUPPORT-CONDITION | Support Condition | PH04; dependency relief PH15 |
| SYS-TRANSFER | Transfer | PH03 |
| SYS-WITHDRAWAL-HANDOFF | Withdrawal Handoff | PH06; canonical PH17 |
| SYS-CONTROLLER | Plane-constrained player controller | PH01 |
| SYS-INPUT | Remapping, toggle actions and interruption guard | PH00; full traversal PH01 |
| SYS-MOTION | Fixed-step q-based mechanism framework | PH02 |
| SYS-SAVE | Atomic semantic save and migrations | PH05 |
| SYS-CHECKPOINT | Checkpoint validation and restore coordinator | PH05 |
| SYS-STREAMING | Chunk manifest, ownership pins and seam prefetch | PH10; owner seam PH11 |
| SYS-CAMERA | Camera volumes, look-ahead and node selection | PH01; benchmark PH03 |
| SYS-ANIMATION | Animation state, IK/contact and strain layers | PH01; benchmark PH03 |
| SYS-AUDIO | Audio event adapter, phase clock and mix state | PH02 temporary; final PH24 |
| SYS-EVENTS | Idempotent typed world events and trigger ledger | PH05 |
| SYS-CINEMATICS | Short in-engine sequences with restore/skip policy | PH09 |
| SYS-VALIDATOR | GUID, missing reference and puzzle interlock checks | PH00; expanded PH05/PH12 |
| SYS-REPLAY-TEST | Canonical puzzle traces and regression fixtures | PH02; support PH04 |
| SYS-TELEMETRY | Local development telemetry and profiling | PH00; pacing PH11 |
| SYS-BUILD-CI | Reproducible builds, package lock and smoke suite | PH00 |
| SYS-QUALITY | Quality settings preserve visibility and game rules | PH03; gate PH12 |

### 5.3 All 48 blueprint tests

Run the full setup/action/expected contract in registers/tests.json. These targets distinguish early proofs from final acceptance. A later canonical context cannot be tested solely through an earlier fixture; notably T35 requires Chapter 4, T36 Chapter 6 and T37 the ending. All results currently remain Not run.

| Test | Area | First relevant execution | Required mature recheck |
|---|---|---|---|
| T01 | Movement | PH01 | PH26–PH29 as applicable; affected changes thereafter |
| T02 | Movement | PH01 | PH26–PH29 as applicable; affected changes thereafter |
| T03 | Movement | PH01 | PH26–PH29 as applicable; affected changes thereafter |
| T04 | Movement | PH02 | PH26–PH29 as applicable; affected changes thereafter |
| T05 | Hold | PH02 | PH26–PH29 as applicable; affected changes thereafter |
| T06 | Hold | PH02 | PH26–PH29 as applicable; affected changes thereafter |
| T07 | Hold | PH03 | PH26–PH29 as applicable; affected changes thereafter |
| T08 | Hold | PH03 | PH26–PH29 as applicable; affected changes thereafter |
| T09 | Hold | PH02 | PH26–PH29 as applicable; affected changes thereafter |
| T10 | Hold | PH02 | PH26–PH29 as applicable; affected changes thereafter |
| T11 | Hold | PH06 | PH26–PH29 as applicable; affected changes thereafter |
| T12 | Physics | PH02 | PH26–PH29 as applicable; affected changes thereafter |
| T13 | Puzzle P10 | PH04 | PH26–PH29 as applicable; affected changes thereafter |
| T14 | Puzzle P13 | PH08 | PH26–PH29 as applicable; affected changes thereafter |
| T15 | Puzzle P24 | PH06 fixture; PH17 canonical | PH26–PH29 as applicable; affected changes thereafter |
| T16 | Puzzle P28 | PH06 fixture; PH18 canonical | PH26–PH29 as applicable; affected changes thereafter |
| T17 | AI | PH07 | PH26–PH29 as applicable; affected changes thereafter |
| T18 | AI | PH07 | PH26–PH29 as applicable; affected changes thereafter |
| T19 | AI | PH08 | PH26–PH29 as applicable; affected changes thereafter |
| T20 | AI | PH07 | PH26–PH29 as applicable; affected changes thereafter |
| T21 | Porter | PH08 | PH26–PH29 as applicable; affected changes thereafter |
| T22 | Survivors | PH08 fixture; PH17 canonical | PH26–PH29 as applicable; affected changes thereafter |
| T23 | Save | PH05 | PH26–PH29 as applicable; affected changes thereafter |
| T24 | Save | PH05 | PH26–PH29 as applicable; affected changes thereafter |
| T25 | Save | PH23 | PH26–PH29 as applicable; affected changes thereafter |
| T26 | Suspend | PH05 | PH26–PH29 as applicable; affected changes thereafter |
| T27 | Streaming | PH10/PH11 | PH26–PH29 as applicable; affected changes thereafter |
| T28 | Streaming | PH12 | PH26–PH29 as applicable; affected changes thereafter |
| T29 | Camera | PH01/PH03 | PH26–PH29 as applicable; affected changes thereafter |
| T30 | Animation | PH03 | PH26–PH29 as applicable; affected changes thereafter |
| T31 | Audio | PH05 temporary | PH24–PH26 |
| T32 | Audio | PH07 temporary | PH24–PH27 |
| T33 | Accessibility | PH06 | PH26–PH29 as applicable; affected changes thereafter |
| T34 | Accessibility | PH03 | PH26–PH29 as applicable; affected changes thereafter |
| T35 | Narrative | PH14 | PH26–PH29 as applicable; affected changes thereafter |
| T36 | Narrative | PH16 | PH26–PH29 as applicable; affected changes thereafter |
| T37 | Narrative | PH18 | PH26–PH29 as applicable; affected changes thereafter |
| T38 | Duration | PH19 | PH27 |
| T39 | Performance | PH03/PH12 baseline | PH28–PH29 |
| T40 | Build | PH00 smoke; PH29 full | PH29 |
| T41 | Finale | PH06 fixture; PH18 canonical | PH26–PH29 as applicable; affected changes thereafter |
| T42 | Continuity | PH09 partial; PH18 complete | PH26–PH29 as applicable; affected changes thereafter |
| T43 | Regression | PH02 incremental; PH19 all puzzles | PH26–PH29 as applicable; affected changes thereafter |
| T44 | Input | PH01 | PH26–PH29 as applicable; affected changes thereafter |
| T45 | Release | PH29 | PH29; patches PH30 |
| T46 | Integrity | PH00 incremental; PH12 expanded | PH26–PH29 as applicable; affected changes thereafter |
| T47 | Pacing | PH04 | PH26–PH29 as applicable; affected changes thereafter |
| T48 | Ethical framing | PH15 partial; PH18 complete | PH26–PH29 as applicable; affected changes thereafter |

### 5.4 Original milestone reconciliation

This roadmap serializes the blueprint's overlapping work and explicitly changes the audio/production ordering to honor the user's gameplay-first decision. Approval of this document approves that sequencing change, not a declaration that the original gates have passed. Original week numbers no longer control execution.

| Blueprint gate | Roadmap evidence / treatment |
|---|---|
| M00 Setup/reference | PH00 |
| M01 Movement | PH01–PH02 |
| M02 Hold/station | PH02–PH06; extend cycle tests to each newly introduced process type |
| M03 First puzzles | PH02/PH04 with PH05 persistent recovery |
| M04 Core loop | PH03–PH05; continued integrated routes |
| M05 Horror/tension | PH07 and PH12 provisional experience; final sound validation PH24 |
| M06 Enemies/Porter/survivors | PH07–PH08; actual chapters PH14/PH17 |
| M07 First environment | PH03 early target; streaming integration PH10–PH12 |
| M08 Opening 15 minutes | PH09 |
| M09 Complete Chapter 1 | PH10 |
| M10 First 30–32 minutes | PH11 |
| M11 Final-quality Laundry | PH12 is a separate gameplay/visual/capacity gate; original full audiovisual M11 can pass only at PH24 after rechecking its entire contract |
| M12 Full playable | PH19; explicitly allowed after PH12's separate gate rather than waiting for original M11 audio completion |
| M13 Feature/content alpha | PH26, after final art/animation and audio integration |
| M14 Beta | PH27 |
| M15 Optimization/polish | Continuous profiling plus PH28 convergence |
| M16 Release candidate | PH29 |
| M17 Stabilization | PH30; reserve may first repair prelaunch blockers |

The old first-sprint tasks are a source of bounded work, not authorization for parallel phases. SP01–SP03 inform PH00/PH01; SP04/SP06/SP15 inform movement/contact; SP05/SP08/SP10/SP16 inform PH02–PH04; SP09 becomes temporary cues only; SP12/SP19 inform PH06; SP14 informs PH05; SP13's narrative/dependency audit is expanded chapter by chapter; SP07/SP18 inform PH03/PH07. SP11/SP17/SP20's testing/review discipline applies at every relevant gate. No sprint status is advanced without the matching evidence.

### 5.5 Specification issues assigned before dependent production

| Issue from production review | Required resolution | Deadline |
|---|---|---|
| Station branch motion versus latch and physical lever actions | Complete action/priority table using existing input vocabulary; test three canonical nodes | PH06 exit |
| Two-node sprint mock versus three-node campaign station | Label subset fixture; canonical fixture and C06 station remain three-node | PH06 exit |
| Physical contact versus support/Resolved commit | Explicit ordering and state diagram; validate safe contact before lethal motion adjudication | PH04 exit |
| Ordinary automatic release versus final agency | Enumerate every cause; only explicit valid player release commits root event | PH06 proof; PH18 canonical recheck |
| Root versus evacuation aggregate versus withdrawal restraint | Stable owner ledger across all relevant checkpoints | PH06 proof; PH17–PH18 canonical recheck |
| Earlier relief versus burden-gallery presentation | Saved-state relaxed/recovering variants from real prior outcomes | PH15 exit |
| Anja's irreversible integration | Non-leading tests distinguish her from intact relieved bearers | PH15/PH16, then full ending PH18/PH27 |
| Long observation-duration assumptions | Measure player attention, action, retries and idle time separately; never add compulsory waits to reach 225 minutes | Each chapter; whole campaign PH19/PH27 |
| Asset-family uses and quantity assumptions | Build actual per-sequence/variant dependencies; measure integration throughput | PH12 before expansion; reconcile PH23 |
| Historical M11 audio versus gameplay-first production | Separate PH12 gameplay/visual gate and PH24 final audiovisual gate; never conflate statuses | Approval of this roadmap and both gate reviews |

## 6. Approval and current state

- Roadmap approval: **v1.0 authorized for PH00 on 7 September 2026**, through the user's explicit instruction: “Let's implement PH00 — Reproducible Unreal Foundation.”
- Active phase: **PH00 — In progress**.
- Last accepted phase: **None**.
- Completed implementation work under this roadmap: PH00 foundation source and assets; validation is recorded in the phase review, not assumed from file existence.
- Next eligible work: complete PH00 evidence and user review. **PH01 remains gated.**
- Current technical evidence: [PH00 review and logs](<C:/THE HELD/phase-reviews/PH00/README.md>), including live MCP verification, compiler builds and Blender reimport validation. Outstanding checks remain explicit.

Keep the blueprint's intent fixed while reviewing phase scope, evidence requirements, early visual impact and the deliberate separation of temporary audio from final REAPER production. Only an accepted PH00 permits PH01.
