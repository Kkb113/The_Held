# The Held: The First Step — implementation roadmap

**Roadmap revision 3.0 · 8 September 2026 · Draft for user review**

**Creative baseline:** [First Step master v3.0](blueprint/THE_HELD_First_Step_v3/THE_HELD_First_Step_Master_v3.md). **Active implementation phase: none. All FS phases are Not started.** This request authorizes document migration and roadmap rewriting, not gameplay implementation. PH00/PH01 remain historical technical evidence and potential reuse, not automatic acceptance of v3.

## 1. Authority and phase discipline

The blueprint defines the game. This file defines implementation order, review builds and acceptance gates. The [v3 production review](review/v3/Story_and_Production_Review.md) records the complete story reading, research and bounded contract ambiguities. The [package start page](blueprint/THE_HELD_First_Step_v3/START_HERE.md) leads to the original PDF, DOCX, workbook, registers and schemas. Imported source files remain unchanged for provenance.

The user's decisions retain **Unreal, Blender, Visual Studio, C++/Blueprints and Python automation**, with **final REAPER audio after gameplay completion**. These override the package's proposed Unity stack and overlapping schedule. The specific early-audio milestone exception is recorded below; the original audiovisual gate is never reported as passed by a temporary-audio build.

This roadmap replaces the former PH02-and-later queue. New development uses **FS00–FS36** so old phase IDs and evidence cannot silently acquire different meanings. Source **M00–M20** are milestone references, not another active queue. No fixed delivery date is promised; reforecast from measured creation, integration, testing and rework.

### When the actual story becomes playable

The campaign begins with **Ivo and Anja in their apartment**. FS01 builds the actual kitchen fragment, SQ-01-01. FS11 builds the actual first approximately fifteen minutes: kitchen, landing, separation, brace, shutter/tread and pursuit beginning. FS12 finishes the eighteen-minute Upper Terrace. Early Laundry, water and Ward entries are clearly labeled developer fixtures; they do not change campaign teaching or story order.

FS01 demonstrates domestic visual identity; FS04 provides the first integrated Laundry visual benchmark; FS07 proves the rough occupied Ward. FS14–FS15 are the pre-expansion gameplay/visual/capacity gates. FS23 is full campaign gameplay completion. Final REAPER production begins FS28; full audiovisual alpha is FS31.

### Approval and advancement

1. Record the user's approval of this revision before FS00 starts. Silence does not constitute approval.
2. Only one phase is active. FSnn requires FSnn-1 Accepted; FS00 requires roadmap approval. Reused work must pass the changed phase requirements.
3. At phase entry, read its complete sequence cards and resolve required systems, asset variants, animation tasks, audio events, facts, checkpoints and tests from the v3 registers. Use existing families; no features solely for technical interest.
4. Build a packaged experience. Small synthetic fixtures are allowed for early water, Ward and root risks because later campaign dependencies do not yet exist. Use separate test saves and developer entries. They cannot count as campaign completion.
5. Review every discipline below. Close blockers and high defects. A lower defect can be explicitly deferred with owner, impact, correction phase and regression case. Never defer accidental release, save loss or a required comprehension failure.
6. Record technical results and the user's experience review before advancing. An explicit next-phase instruction can authorize progression, but cannot make an unperformed check pass. Missing required evidence leaves the phase In review; any exception is named, justified and deadline-bound.
7. Record changes to canon, input semantics, save schema, geometry margins or puzzle predicates and update dependent fixtures. Resolve routine tuning inside the phase. Material creative ambiguity goes to review before dependent implementation.
8. Stop at each review boundary. Publishing, storefront actions and messages to other people require explicit user authorization; inclusion in the roadmap is not permission to publish.

## 2. Locked experience and implementation boundaries

### Creative invariants

Nine chapters, forty sequences, thirty-one puzzles, nineteen canonical durable facts, twelve unique survivor slots, one ending and a 225-minute active first-play target (working median band 210–240). Counts are scope estimates, not quotas for filler. All 131 supplied game tests remain Not run.

Ivo is thirteen, 1.52 m, ash-blue jacket and right-arm brace. Anja is his mother and maintenance worker; cuff and two taps preserve identity through domestic, transport and root presentations. Orren is freed independently and later voluntarily holds the ordinary gate. Custodians are people with visible institutional agency. The Porter is one worker and rail retrieval rig across gardens, cutting and water.

The understanding chain is direct restraint → external transfer → ordinary support → conscious captivity → reciprocal balance → moving safe air → irreversible root integration → tested discharge → occupied relocation → voluntary help. The calm outside sea does not remove the retained basin's danger. The twelve are six Exchange survivors, three Laundry attendants, two Burden House bearers and Orren. Laundry relief removes load; their communal exit opens later in C07.

The Ward is the recurring hostel with two uneven chimneys and pale curtain, powered by relocation machinery with four mechanical shoes. It has no organic legs, eyes, combat or roar. Ivo supplies balance and leaves the open cradle once supports carry it. He returns through the prepared culvert to the same root/Anja, takes the unloaded governor and deliberately releases after evacuation. Escape retries preserve her death and the survivors' safety.

No combat progression, crafting, collectibles, alternate endings, free city destruction, arbitrary telekinesis, moral meter, free-roaming vehicle or commanded survivor army. Swimming and the bell are required. The former stationary node-selection finale is superseded.

### Unreal translation

| Requirement | Implementation direction |
|---|---|
| Existing work | Reuse `Game/TheHeld`, BuildScripts, Git/LFS and useful motor behavior after FS00 audit. Legacy source revision: `1fd1beb`. PH00/PH01 maps remain developer fixtures; their saves are not v3 campaign progress. |
| Versions and MCP | Reverify recorded UE 5.8.2, Blender, VS build tools, dependencies and both required MCP connections before editor/DCC mutations. Record exact versions per build. Do not automatically install or upgrade an engine. |
| Coordinates | Source `(X travel,Y up,Z depth)` meters → UE `(100X,100Z,100Y)` centimeters. Validate rotation handedness with asymmetric markers. Serialize mechanism angles in radians and explicitly convert UE degree-valued editor APIs. Verify 152 cm Ivo and sockets through FBX round-trip. |
| Motor | Extend existing ACharacter/CharacterMovement if v3 fixtures pass. Add bounded custom states where needed. Preserve immediate input, buffered jump, clearance, occupied-hand restrictions and moving-support-relative placement. |
| Simulation | Initial 60 Hz coordinator: intent → transaction → mechanism → support/motor → swept collision/head-air → AI → facts → presentation → coherent snapshot. Interpolate rendering; pause danger/breath; bound catch-up safely. Avoid double-ticking movement or treating Chaos substeps as deterministic gameplay. |
| Ownership | One personal process; FreeDriver, Personal, Anchor, Station or MechanicalSupport. q, resumable velocity, owner and support commit together. No capacity overwrite, unowned transfer frame or accumulated impulse. |
| Data | Small USTRUCT records, components and data assets. C++ owns rules; Blueprints assemble/tune rooms and presentation. Immutable definitions separate from saves. One player/root/cohort authority; no generic framework or per-room copies of core scripts. |
| Input | Enhanced Input land/water/station/menu contexts. Keyboard/controller remapping, toggle grip/Hold, assisted timing/breath, reduced motion and captions. Canceled/Completed callbacks alone are not voluntary final-release intent. |
| Water | Bounded regions drive surface, head sample, float and bell; explicit pocket, hose, guide and tipping. Genuine swimming, no invisible walking floor or required full-fluid simulation. |
| Paired movement | Common travel/posture/Hold/Interact grammar on carrier, room and Ward. Authored support graph, clearance envelopes and automatic gait. Supported/clamped exit only. Resolve V3-03 braced-posture ambiguity at FS06/FS07. |
| Saves | Versioned SaveGame payload, coherent snapshots, integrity, prior generation and tested replacement/recovery. Settings separate. Load owners/dependencies before motion. Extend seed scalar schemas for Ward/bell. No automatic legacy save conversion. |
| Streaming | Persistent bootstrap and measured streamed sublevels; soft references/Asset Manager where useful. Explicit ownership pins and activation guards. Hostel proxies carry no gameplay authority; root return uses the original entity. |
| Animation/camera | Blender source rigs, Animation Blueprints and limited IK/Control Rig. Directed camera volumes, Sequencer presentation with facts outside tracks. First Step preserves gait input and pause/Hold. |
| Audio | Temporary original cues and stable state/events now; final REAPER later. Unreal audio routing/submixes; extra tooling only for measured needs. AI hears logical events regardless of player mix volume. |
| Visuals | Stylized broad forms, controlled matte surfaces, sparse practicals and depth. Vane, cable tension and posture signal Hold. No glowing fist/beam, photorealistic concrete noise or universal wet mirrors. Stock renderer; no required ray tracing. |

See the [research sources and limits](review/v3/Story_and_Production_Review.md#research-refreshed-for-unreal-production). These support tool selection, not claims that unbuilt behavior is proven.

### Initial numerical fixtures

Blueprint starting values are editable after measured review: run 4.2 m/s, walk 1.6, crouch 1.2, heavy push 0.85, ladder 1.4; acceleration/braking 14/20 m/s²; jump 5.6 m/s, gravity 18 m/s²; coyote/buffer 0.10/0.12 s; routine gap 2.0 m with ≥0.3 m margin. Capsule height/radius 1.45/0.22 m; crouch height 0.88 m. Reconcile legacy crouch/ladder tuning deliberately.

Hold acquisition 3.2 m, sustain 6.0 m; vane at 5.0 m, click at 5.7 m, 0.4 s warning beyond 6.0 m. Target remains locked; only visible authored conduit extends eligible reach. Support tolerance starts at 0.02–0.04 m.

Surface/dive/one-arm swim speeds 2.1/1.9/1.55 m/s. Breath 24 s, warnings at 12/18/22 s elapsed, refill 8 reserve-seconds per second in valid air; assist doubles reserve. Head hysteresis 0.15 m/0.3 s. Normal clean swim legs 6–10 s; late committed leg <13 s. Pause never consumes reserve.

Camera initial vertical FoV 28–35°; normal span 14–22 m, intimate 9–13 m, exposed 28–40 m and Ward reveal about 42 m. Review actual A/B/C compositions and reduced-motion equivalents. Ward starts around 24 × 12.6 × 6 m, lowers to 9.8 m beneath a 10.6 m girder. Art and authoritative hulls must retain margins together.

## 3. Required evidence at every phase

Every phase inherits this checklist in addition to its specific criteria. Future tests are requirements, not reported results.

| Dimension | Evidence |
|---|---|
| Gameplay/understanding | Packaged entry-to-exit run without debug help; wrong order and action denial; keyboard/controller. Fresh uncoached observers at teaching/reveal gates with neutral interviews. |
| Story/puzzles | Sequence, puzzle and fact IDs; real before/after physical predicates. No omitted prerequisite, false civilian harm, early campaign spoiler or exposition replacing causality. |
| Physics | Affected routes at 30/60/120 fps; swept crush/reach, hand constraints, support/resume tolerance and restore. Cosmetic physics cannot decide solvability. |
| Animation | Normal-speed and contact-frame feet/hands/gaze/breath/denial review. Responsive motor; proxy limitations named. |
| Visuals/camera/VFX/atmosphere | Gameplay A/B/C frames in standard and reduced effects; grayscale/brightness/aspect checks. Continuous motion review for hero events; landing/contact visible during decisions. |
| Audio | Before FS28, temporary timing, restart, priority and visual/caption equivalents. Mark final sensory judgment Deferred to its audio phase; do not label missing final audio Pass. |
| Persistence/stability | Safe checkpoint/quit/restore at new transaction boundaries; no duplicate actors/facts, missing content or lost progress. Regress affected predecessors. |
| Performance | Build/hash, engine/config, hardware/driver/storage, resolution, quality, CPU/GPU frame time, p95/p99, memory and relevant cold/warm/hitch results. Average fps or a still is insufficient. |
| Production | Source/export/socket/collision/LOD/rights records, defects, actual effort, reproducible build/test commands and user review decision. |

Performance targets remain provisional until FS14–FS15 choose a measured floor: 1080p60, valid 30 fps mechanics, approximately <8 ms main/game thread, <5 ms render thread and <13 ms GPU, measured separately, not summed. Measure memory with OS/GPU headroom. The blueprint's 6 GB alarm does not certify an 8 GB machine. Test long sessions later.

Each review writes `phase-reviews/FSnn/README.md`: status, scope, build path/hash/revision, start/exit instructions, new/reused work, temporary elements, resolved IDs, exact tests/manual findings, every discipline Pass/Fail/Deferred-with-deadline, defects and user decision. The source registers remain the delivered baseline until a deliberate synchronized update; execution evidence lives in these reviews and this ledger.

## 4. Implementation phases

### FS00 — Reconcile the Unreal foundation with v3

- **What / why now:** preserve useful PH00/PH01 work and replace old assumptions. Entry is roadmap approval. Close V3-01/02/10 migration rules.
- **Gameplay / engineering:** audit bootstrap, fixed tick, motor, input, camera and build/test scripts against SYS-01/02/03/38/39. Lock new IDs/save namespace and developer entry labels. Reverify software/MCP and clean packaging.
- **Assets / animation:** reuse metric kit, proxy and original glyphs; inventory sources, contacts, handedness and missing skeletal clips. Draw nine-area elevation and hostel orientation sheet; no bulk art.
- **Visuals / VFX:** honest test-room presentation, v3 matte swatches and independently moving dust. Record older concepts' revised reference status.
- **Audio:** existing temporary foot/contact cues, mute/pause routing; no final production.
- **Physics / interactions:** centimeter/axis/rotation round-trip, gaps, collision matrix, support and stall recovery. No new campaign puzzle.
- **Playable / visual result:** reproducible foundation/traversal test entries with coherent scale and updated development labeling.
- **Tests / acceptance / exit:** prior technical regression plus TST-092/129 baseline; record actual external-device/machine availability. No v3 story passes inferred. Build provenance, conversions and reuse inventory accepted before FS01. Licensed reference play remains pending until actually performed.

### FS01 — Responsive traversal and the actual kitchen

- **What / why now:** requalify traversal and give the first new playable a real relationship. Build SQ-01-01/PZ-01; no claim that the landing is complete.
- **Gameplay / engineering:** SYS-02/03/04/05/14/15; responsive movement, grip/ledge/ladder, stable socket selection, required traversal remaps and denied actions; short kitchen event phases and safe restart.
- **Assets / animation:** rigged gameplay CHR-IVO/ANJA, ENV-TERRACE subset, CHAIR/CUP/TOOLS/ANJA-CUFF/WALL-FITTING. Locomotion/contact subset ANM-001–048, Ivo taps, Anja repair/wait/guide/taps. Commit at contact, not clip completion.
- **Visuals / VFX:** ash-blue domestic frame, one practical, matte plaster/wood, rain/washing outside and spoon vibration; chair/door and both people readable.
- **Audio:** temporary rain, cup, cloth, hand/taps and distant alarm, with stable event names.
- **Physics / puzzles:** constrained chair drag exposes door; free-hand cover repair; alarm/departure follows player progress. Anja waits, no kitchen death.
- **Playable / visual result:** control near second three, move chair, repair with Anja, see taps and reach an explicit development endpoint at the stair threshold. Separate traversal regression remains available.
- **Tests / acceptance / exit:** TST-001/002/093–096/106; find obstruction within 60 s uncoached, five-minute idle coherent, no duplicate events. Review hands, silhouette and mother relationship; close initial V3-11 clip flags before FS02.

### FS02 — One personal Hold and predictable release

- **What / why now:** establish the central rule before dependent challenges; use PZ-02/03 development fixtures without changing campaign introduction.
- **Gameplay / engineering:** SYS-06/07; intent tokens, eligibility/facing/visibility, target lock, range warnings, atomic ownership and hand restrictions; owner inspection and minimal state fixtures.
- **Assets / animation:** BRACE/WALL-FITTING/SHUTTER/ROTATOR/ANCHOR/simple support. Acquire/sustain/release, occupied-arm locomotion, heavy-grip denial and vane poses; valid arrest precedes reach blend.
- **Visuals / VFX:** still target versus moving dust/cloth, matte porcelain and cable tension; no glow.
- **Audio:** temporary acquire/deny/range/residual load, motor stop/resume and one event per transaction.
- **Physics / puzzles:** bounded slider/angular q/v, sweeps, legal driver resume, no hidden impulse; support and anchor capacity checks. Resolve units in V3-02.
- **Playable / visual result:** connected safe shutter/tread gym with wrong-angle retry and visible one-owner transfer demonstrations.
- **Tests / acceptance / exit:** TST-003–006/097/098 in prototype context; competing requests, repeat ID, adjacent release/transfer, range re-entry, pause/device cancellation and 30/60/120 fps. No owner gap, double Hold or target jump; player explains selected-only arrest before FS03.

### FS03 — Support-relief puzzle and moving contact

- **What / why now:** prove the alternative to endless Hold in a complete six-to-eight-minute target reasoning route.
- **Gameplay / engineering:** SYS-08/09/10; support alignment/ratchet/contact predicate, moving support delta, swept crush, solved-state reset and real exit condition.
- **Assets / animation:** JACK/STAIR-PAWL/BRIDGE/ANCHOR subset and rough conscious bearer; crank, occupied-hand denial, one-hand pawl and asynchronous relief poses.
- **Visuals / VFX:** load, support, bearer and exit share the reasoning frame; cable slack and brief settling dust.
- **Audio:** temporary ratchet/crank, seating and breath distinguish active restraint from physical support.
- **Physics / puzzles:** PZ-11/13 principles: take load, transfer, insert/lock support, release, verify and traverse. Armed catch differs from actual load-bearing support.
- **Playable / visual result:** safe observation, recoverable wrong order, support solve and later traversal failure preserving the solve.
- **Tests / acceptance / exit:** prototype TST-021/022/025/026 plus TST-078/099/100; support capture ordered before lethal adjudication, no stale velocity, lost prop or lucky bounce. Observer identifies why relief occurred. Sketch V3-06 reach geometry before FS04.

### FS04 — First integrated Laundry visual benchmark

- **What / why now:** early visual impact around proven gameplay. Build SQ-03-01/PZ-08 as developer entry, maintaining C03 campaign placement.
- **Gameplay / engineering:** transfer, far two-hand lever, receiving pin/return linkage; reusable SYS-16/18/36/37 contact, reaction, import and capture workflows.
- **Assets / animation:** ENV-LAUNDRY bay, BRIDGE/ANCHOR/LEVER/CART/SHEET, gameplay Ivo, hidden bearer and adult service-tool demonstration. Aligned feet/grip, transfer relaxation and continuing breath.
- **Visuals / VFX:** readable midground route, restrained foreground cloth, quiet tall depth and sparse amber practicals; all three support states reviewed in one composition, independent dust.
- **Audio:** temporary phase/strain, breath migrating to anchor and distinct pin seating; final mix deferred.
- **Physics / puzzles:** reversible wrong-angle anchoring, visible conduit/range and both-side recovery. Resolve V3-06 without unlimited wireless reach.
- **Playable / visual result:** five-to-eight-minute target arrival-to-exit bridge experience with original materials, lighting and physical consequence.
- **Tests / acceptance / exit:** TST-015/016/083 plus contact/import; 1,000 transfers without gaps; four of five fresh testers distinguish personal/anchor/support. Low-effects/grayscale frames preserve landing and contacts. No misleading gloss, glow or contact failure before FS05.

### FS05 — Saves, narrative phases and a continuous loop

- **What / why now:** prevent later scenes inventing independent progression systems; join existing fixture content into a ten-minute target route.
- **Gameplay / engineering:** SYS-10/11/12/13/31/35; canonical ledger, local phases, actor registry, prior-generation saves, restore order and owner-pinned second chunk. Close V3-04/05/10 alias/schema/dependency rules.
- **Assets / animation:** DATA-PUZZLES/CHECKPOINTS, UI-SAVE/ERROR/MAIN, shared threshold kit and existing bearer content; safe cancel/restart contacts and after-motion.
- **Visuals / VFX:** continuous camera/light transitions and restored presentation without interpolation jumps or replayed shards.
- **Audio:** SYS-17 router seed, restore-aware temporary loops/ambience; remove stale danger voices.
- **Physics / puzzles:** support solve persists after chase/fall; restore owner and geometry before ticking. The kitchen retains its separate actual-story entry.
- **Playable / visual result:** menu → integrated route → quit → continue → exit, including transfer and a human-source hint.
- **Tests / acceptance / exit:** TST-079/080/101–104/122/126; sandboxed corrupt/interrupted/full-disk tests, missing owner and duplicate event. Previous generation/settings preserved, no silent new game or unowned tick. Alias catalog and snapshot boundaries accepted before FS06.

### FS06 — Paired controls on carrier and domestic room

- **What / why now:** prove the new shared control grammar while art is inexpensive; PZ-15/PZ-22 in a labeled rehearsal.
- **Gameplay / engineering:** SYS-27, station binding, travel/posture, parking/receiving locks, free-hand entry and supported exit. Complete input/state table and close V3-03/09.
- **Assets / animation:** CARRIER/DOMESTIC-ROOM/PAIRED-STATION/SUPPORT-LOCK, bed/cupboard/cup and Ivo; ANM-065–071, hand/foot plate, lean/lower/raise/brace/exit and contained prop reactions.
- **Visuals / VFX:** body, assembly and receiving notch together; the second fixture reads as a lived-in room. Small cable/settle motion only.
- **Audio:** temporary hydraulics, contacts, strain and crockery show mechanical power and human correction.
- **Physics / puzzles:** bounded carrier guide and room tilt/travel, visible blockers, safe arrest, genuine lock before exit; serialize assembly and player together.
- **Playable / visual result:** park/exit the carrier, then move a domestic room with identical controls and no new tutorial.
- **Tests / acceptance / exit:** prototype TST-029/030/043/044/118; four of five fresh players park/exit in 90 s and reuse knowledge. No control inversion, balance timer or unsupported escape. Braced-posture rule demonstrated on both before FS07.

### FS07 — Rough occupied Ward and protected root risk proof

- **What / why now:** test flagship coherence and irreversible-input safety before bulk production; synthetic prerequisites remain explicitly fixture-only.
- **Gameplay / engineering:** SYS-28/29/30/32; support graph, automatic shoe order, room-local occupants and protected root phases. Extend common station controls.
- **Assets / animation:** rough WARD/chimneys/curtain/four shoes, pads/girder/porch/open cradle, twelve identifiable roster proxies and governor fixture. Lift/settle/narrow/crouch/kneel/lock with independent human catches.
- **Visuals / VFX:** progress-driven 8–12 s reveal, cup movement and restrained foundation dust; reduced-motion view retains people and support information.
- **Audio:** temporary structure/hydraulics plus small domestic reactions; taps and guarded handover cues in separate root fixture.
- **Physics / puzzles:** PZ-26–30 proof, stable contact snapshots, supported evacuation and cradle exit. Root requires prepared facts and fresh voluntary arm/release; pause/focus/device/remap disarm and preserve owner.
- **Playable / visual result:** twelve-to-fifteen-minute target carrier-to-Ward route with two maneuvers and return to Ivo; separate root interruption exercise.
- **Tests / acceptance / exit:** prototype TST-051–060/072–074/077/084/119–123; 30/60/120 fps, repeated restore and exact twelve slots. No accidental root release or replayed reveal. Four of five fresh viewers recognize occupied hostel and responsibility, not comic robot. Close V3-03/05/09 before FS08.

### FS08 — Custodian pursuit, cover and conscious restraint

- **What / why now:** integrate human threat and trustworthy concealment before Porter/water pressure.
- **Gameplay / engineering:** SYS-19/20/22, bounded routes, sight/hearing/last-known position, anticipation, swept capture, blocked return and harness/awareness separation.
- **Assets / animation:** CUST-A/B shared skeleton, HARNESS, GATE-CART/SHUTTER, thin wet sheet/thick blanket/torch. Patrol/reach/block/held body with independent eyes/breath and safe resumption.
- **Visuals / VFX:** silhouette teaching before search, perception tags match materials, route/retreat visible before danger; restrained torch/cloth motion.
- **Audio:** temporary directional footsteps, cloth/torch and conscious breath with captions; AI hearing independent of volume.
- **Physics / puzzles:** PZ-04/09/12 fixtures, prepare heavy cart before Holding worker, use one-hand brake then release for shutter. Covered contact is physically inaccessible.
- **Playable / visual result:** teaching → threat → quiet realization route, plus cart obstruction and setup-preserving retries.
- **Tests / acceptance / exit:** prototype TST-007/008/017/018/023/024/076/110/111/113; mute/low-light agreement, real capture sweep and ten retries. Player predicts detection and notices awareness. No invented immunity or teleport before FS09.

### FS09 — The Porter's bounded retrieval procedure

- **What / why now:** prove one consistent threat for three contexts before adding swimming pressure.
- **Gameplay / engineering:** SYS-21, rail/arm coordinates, load signals, committed target priority and obstruction. Dry retrieve-and-tip demonstration seeds FS10.
- **Assets / animation:** PORTER/rig/rail/hose, sack/salvage, grates/stone refuges/drive/dock cradle. Detect/orient/reach/secure/retract/unload/return, worker breath, basket tip and interrupted grab.
- **Visuals / VFX:** visible connected grate flex, reach shadow, stone refuge and dock rotation; cable/impact reaction supports causality.
- **Audio:** temporary ratchet, cradle fabric, hose and procedural cue, no creature scream.
- **Physics / puzzles:** PZ-07/17 fixture with shared moving exit driver; ≥1.2 s first warning, no off-rail movement, refuge penetration or target cancellation shortcut. Specify V3-08 capture/dock handoff.
- **Playable / visual result:** sack demonstration, first grate, salvage diversion and resumed platform escape; small development dock exercise.
- **Tests / acceptance / exit:** prototype TST-013/014/033/034/112, shared-driver retries, early/late release and obstruction. Player explains stone safety and why indefinite Hold cannot align exit. Then FS10.

### FS10 — Swimming, movable air and the tipping dock

- **What / why now:** close water fairness risk before expansion; ten-minute target route using the proven Porter.
- **Gameplay / engineering:** SYS-23/24/25, bounded regions, wade/swim/dive, head-air hysteresis, breath/assist, guided buoyancy and coherent bell/Porter snapshot.
- **Assets / animation:** DROWNED subset, WATER-VOLUME/AIR-BELL/AIR-POCKET/BELL-WINCH, hose/dock/rib/air landing and harmless chair/fish; ANM-072–090, one-arm swim and submerged reach.
- **Visuals / VFX:** clear low-effects air boundary and destination; restrained silt/bubbles, visible hose; tipping basket teaches danger first.
- **Audio:** temporary underwater/pocket blend, warnings/recovery/hose, captions and optional reserve display.
- **Physics / puzzles:** PZ-18–21 prototypes; initial leg <7 s, usual <10 s, late <13 s at default 24 s reserve. Tilt spills air; explicit guide/dock/hose transitions close V3-08. Water never freezes.
- **Playable / visual result:** safe swim → dock movable shelter → evade tipping retrieval → dry recovery, with chamber-drain fixture.
- **Tests / acceptance / exit:** TST-035–042/075/114–116 prototype scope; 100 boundary crossings, no refill exploit or simultaneous drown/air, moving-pocket restore, pause and assisted/muted routes. Novices identify air and dock danger before failure. Then FS11.

### FS11 — The actual first fifteen minutes

- **What / why now:** turn the kitchen fragment and proven systems into chronological onboarding. Integrate SQ-01-01–03 and the beginning of SQ-01-04; no montage or developer jump.
- **Gameplay / engineering:** opening phase controller, Anja wait/follow, protected landing, atomic transport/brace pickup, first-use guidance, new-game/continue and durable progression. Reuse SYS-06/11/12/31/33.
- **Assets / animation:** production-capable Ivo/Anja rigs, TERRACE/stairs, LANDING/TRANSPORT/BRACE, chair/cup/cuff and Custodians. Finish cover/taps, catch, wait, secure/transport, look-back, pickup and ordinary motion contacts.
- **Visuals / VFX:** intimate opening expands into stair depth; Ivo keeps foreground control during separation. Hand/cuff recognition and lower route stay readable; dust/rain continue through Hold.
- **Audio:** temporary domestic detail, taps, remote alarm, strain-before-slip, retreating wheels and modest brace click; timing follows actual event state.
- **Physics / puzzles:** PZ-01–03 plus pursuit entry. Rig takes ownership before Anja leaves; transport waits until Ivo crosses; brace cannot be lost. No timer forces departure while exploring kitchen.
- **Playable / visual result:** New Game starts with mother in the apartment and proceeds into the pursuit around the fifteen-minute target. The story's start is now continuously playable.
- **Tests / acceptance / exit:** TST-001–006/063/090/124; every transport/contact quit boundary, fast/slow/idling play, no brace loss or duplicated mother. Fresh players understand relationship, reason to follow and selected-only Hold. Cinematic response and control near second three reviewed before FS12.

### FS12 — Complete Upper Terrace

- **What / why now:** finish C01 before extending its geography; target eighteen active minutes from New Game.
- **Gameplay / engineering:** full SQ-01-04/PZ-04 pursuit, actual guard stairs/reach/blocked door, checkpoint preserving tread solve and streamed exterior threshold.
- **Assets / animation:** CUST-A, shutter/recess, SERVICE exit and GARDENS threshold, first consistent hostel proxy. Door catch, pursuit/reach/failure and running contacts.
- **Visuals / VFX:** guard visible before entering lane, door contact and destination framed; exit opens to wind/allotments and understated chimneys. Dust cannot hide next landing.
- **Audio:** temporary descending feet, closure strain and indoor-to-wind transition; no villain sting.
- **Physics / puzzles:** known arrest/cross/release grammar under fair pressure; real swept capture, no rubber-band. Preserve source 3.5 s visible approach starting point and tune with evidence.
- **Playable / visual result:** entire C01 and a stable garden entry, no editor transitions or missing opening actor.
- **Tests / acceptance / exit:** canonical TST-007/008 and all C01 regression; capture replay median <35 s, no duplicated guard, fast exit streaming and controller/keyboard. Whole chapter narrative and readability accepted before FS13. Final audio remains explicitly deferred.

### FS13 — Complete Tidal Gardens and forty-minute opening route

- **What / why now:** establish environmental variety and preserve urgency through the first new region. Integrate all SQ-02-01–04/PZ-05–07; capture the source's thirty-minute onboarding checkpoint inside the real route.
- **Gameplay / engineering:** garden diversion/float, connected wind panel, autonomous bird, canonical Porter and culvert observation; cross-chapter saves/streaming and landmark continuity.
- **Assets / animation:** GARDENS/CULVERT, WIND-SCREEN/SLUICE/DIVERSION/FLOAT, reed screen, sack, Porter/hose, groceries and residents; bird forage/flee, operator reactions, push/crouch/ladder.
- **Visuals / VFX:** exposed gray sky, raised beds, consistent chimneys, independent reeds and runoff; ordinary residents overhead after threat, not an immediate second ambush.
- **Audio:** temporary wind/reeds/bird, distinct inlet/overflow/outlet, rail warning then ordinary muffled footsteps and ventilation.
- **Physics / puzzles:** wrong diversion safely overflows, float constrained to stops, poor panel arrest has recovery shelf; same bounded Porter. Ambient behavior cannot block progress.
- **Playable / visual result:** New Game through full Gardens into Laundry entrance, target forty minutes; no artificial waits to stretch length.
- **Tests / acceptance / exit:** canonical TST-009–014/064 and prior C01. Thirty-minute fresh-run pacing review, no >90 s ladder search, predictable stone refuge, no audio-only clues. Root-to-hostel elevation and geography accepted before FS14.

### FS14 — Full Laundry gameplay and visual production gate

- **What / why now:** complete the real twenty-four-minute C03, using the early benchmark at full chapter scale. This is the first half of the explicit pre-expansion gate, not original audiovisual M13 completion.
- **Gameplay / engineering:** SQ-03-01–04/PZ-08–10, wet-mass scalar SYS-26, sheet concealment, repeat-safe reveal, save/streaming/quality tiers and caption infrastructure SYS-34.
- **Assets / animation:** finished representative Laundry kit/Ivo/bridge, drying frames, wet rack/rinse/lift/anchor, cloth variants, Custodian and bearer hand. Grip/ladder, restrained breath, squeeze, cover brush/finger and wet handling.
- **Visuals / VFX:** all A/B/C boards reach consistent gameplay quality, including cover contrast and subtle organic detail. Cloth visibility is authored; water/dust and wetness stay bounded and readable.
- **Audio:** complete temporary cue coverage, hidden-effort timing, changed wet mass and quiet finger moment; list every final REAPER dependency and estimate it. Final sound is not signed off here.
- **Physics / puzzles:** resolve V3-07 wet-rack catch/action ordering explicitly; no lift motion through active arrest. Saved saturation, owner, catches and derived mass agree. Three load-relief outcomes preserve later attendant identity.
- **Playable / visual result:** full New Game-to-Laundry-exit route, target 64 cumulative minutes; standalone chapter entry also provided for repeat reviews.
- **Tests / acceptance / exit:** canonical TST-015–020/065/076/083/117/125; quarter-saturation saves, 1,000 transfers, repeated failures preserve frames, four of five see organic detail. At least two fresh rounds, recorded floor hardware/cold-warm profile and real asset/rework times. No bulk expansion until FS15 also passes.

### FS15 — First Step quality benchmark and capacity decision

- **What / why now:** pair Laundry evidence with a three-to-six-minute occupied-Ward benchmark before committing to the remaining production volume. It adds no campaign minutes.
- **Gameplay / engineering:** refine FS07's shared station/gait, local-room presentation and progress-driven camera; still use labeled synthetic prerequisite setup, never claim the final campaign is built.
- **Assets / animation:** representative final Ward facade/shoes, one to two visible hero room bays, cohort appearances, pale curtain/cup and Ivo cradle; first support lift, reactions, arrest and settle at intended quality.
- **Visuals / VFX:** matched close-to-wide shots preserve recognizable hostel and individual people; stock shading, controlled dust and reduced-motion reveal. Image must work in motion on the floor fixture.
- **Audio:** carefully timed temporary large strain and small domestic cues; measure/estimate final recording, integration and mix needs without manufacturing final REAPER assets.
- **Physics / puzzles:** repeatable first step, narrow support or crouch subset, support snapshot/restore and containment; inherited holds and camera pause behavior unchanged.
- **Playable / visual result:** actual controlled reveal and maneuver with occupants, starting and ending on verified support. Review beside the full Laundry build.
- **Tests / acceptance / exit:** TST-070/077/084/087 prototype benchmark; unfamiliar carrier-trained players reuse controls and mention occupant responsibility; no comedy gait, hidden support or uncontrolled debris. Reforecast all remaining 164 families/211 animation tasks and audio work from measured throughput, review available capacity and risk owners. Accept both FS14/15 before FS16; original M13 stays incomplete until FS29 audio recheck.

### FS16 — Passenger Exchange and Orren's independent relief

- **What / why now:** expand only after the dual quality/capacity gate; turn the hidden cost into conscious public dependence.
- **Gameplay / engineering:** SQ-04-01–04/PZ-11–13; canonical crowd load driver, six queue IDs and Orren route state, exposed-harness/cart/shutter solution. SYS-30 replaces anonymous placeholders with stable cohort slots.
- **Assets / animation:** EXCHANGE/TRAM/TILT-DECK/JACK/GATE-CART/HARNESS/STAIR-PAWL, luggage, six queue variants and Orren coat/shoe. Independent eyes/breath, asynchronous relief, knee test and separate exit.
- **Visuals / VFX:** pale public upper level above darker constrained bodies, reversible inspection demonstration, recognizable hostel outside. Load movement and dust support the social composition.
- **Audio:** temporary public footfall, lower restraint rhythm, jack teeth, conscious breath and Orren's shoe; no celebratory rescue cue.
- **Physics / puzzles:** jack ratchet plus genuine deck contact relieve people; prepare cart before Holding worker; pawl supports staircase before Orren leaves. No mandatory civilian harm.
- **Playable / visual result:** continuous opening through C04, target 89 minutes; seven identified people begin independent safe routes.
- **Tests / acceptance / exit:** canonical TST-021–026/066/074, 20 support/roster reloads, no hand exploit or duplicate Orren. Players distinguish imposed motion from intention and remember Orren. Then FS17.

### FS17 — Counterweight Cut and canonical balance rehearsal

- **What / why now:** apply paired controls in their real story position and make deliberate release productive before water vulnerability.
- **Gameplay / engineering:** SQ-05-01–04/PZ-14–17; canonical carrier, receiving cradle and shared Porter/platform driver; persistent bounded impact and controlled slide transition.
- **Assets / animation:** CUT/gantries, dark counterweights, CARRIER/PAIRED-STATION, receiving cradle/walkway, salvage bundle and Porter. Carrier posture, heavy action, impact response and slide/recovery.
- **Visuals / VFX:** pale chalk/negative space, full sweep and safe pockets visible, hostel shoes glimpsed without full reveal; grit continues after arrest, never obscuring hazards.
- **Audio:** temporary open wind, cable, hydraulic effort, layered impact/settle and familiar rail procedure.
- **Physics / puzzles:** guided fall has 2.2 m working stroke, receiving pawl interlock and authored compression; walkway rises predictably. Carrier safe exit and broad moving-platform interval remain proven.
- **Playable / visual result:** complete C05 joined to a safe shallow shelf, target 116 cumulative minutes. No ongoing ambush at first swim.
- **Tests / acceptance / exit:** canonical TST-027–034, 2 cm impact repeatability, phase/owner restores, first-time carrier <90 s target, no lucky bounce or unsupported step. Then FS18.

### FS18 — Complete Drowned Street

- **What / why now:** apply FS10's proven water mechanics to the actual four-sequence chapter, preserving the movable-shelter lesson.
- **Gameplay / engineering:** SQ-06-01–04/PZ-18–21, linked water/bell/Porter/drain snapshots, wetness persistence and actual route streaming into Burden House.
- **Assets / animation:** full DROWNED kit/shopfronts, WATER/BELL/WINCH/POCKET/DOCK/PUMP, fish, floating chair, old harness and hose; final-direction swim/one-arm/air recovery and underwater retrieval contact.
- **Visuals / VFX:** recognizable old street, readable surface/pocket and dry exits, low-cost water/silt/bubbles, receding water reveals repainting/harness marks and route.
- **Audio:** temporary head-based filtering, pocket air/hose, familiar rail transmission, wet foley and pump-to-drips transition.
- **Physics / puzzles:** head sample matches rendering; gallery drain cannot invalidate active bell checkpoint. A single Hold suffices; tip, hose and guide authority explicit, no arbitrary currents.
- **Playable / visual result:** entire 27-minute target water chapter, continuous campaign to 143 minutes and dry service access.
- **Tests / acceptance / exit:** canonical TST-035–042/075, all stated leg margins, 100 boundary transitions, pause/device/assisted routes and safe restore at lower/moving/upper bell. Players explain moving shelter and unsafe dock before capture. Then FS19.

### FS19 — Burden House, Anja and all twelve survivors

- **What / why now:** resolve the personal mystery before preparing the finale; require real earlier relief facts, not synthesized presentation.
- **Gameplay / engineering:** SQ-07-01–04/PZ-22/23; reverse-side load displays, canonical room station, phased Anja recognition/refusal, local support and communal exit; complete roster reconciliation.
- **Assets / animation:** BURDEN/domestic backs, BODY-LINK, DOMESTIC-ROOM, ROOT/ANJA/cuff, receiving frame, intact bearers and Orren. Familiar compensations, failed gentle withdrawal, refusal, supporting load and separate recovery/exit.
- **Visuals / VFX:** match prior mechanisms' rhythms and load states; cuff first, root extent second, no graphic close-up. Intact harness/open service cradle contrast with incorporated collar; dry dust/contact motion.
- **Audio:** temporary recurring signatures with breath/cloth now visible; quiet refusal, reduced root strain after support. No dialogue explanation.
- **Physics / puzzles:** park station before exiting to push receiving frame, then lower onto actual ratcheted support. Freed Laundry load is not mistaken for an already opened cell; five remaining people join six queue survivors and Orren.
- **Playable / visual result:** campaign reaches C07 exit at 170-minute target; Ivo's changed goal and all twelve identities are established.
- **Tests / acceptance / exit:** TST-043–046/067/068/074; no root ownership loss, duplicate people or restored strain on relieved loads. Fresh viewers distinguish irreversible Anja from intact bearers and understand refusal; ambiguity blocks FS20.

### FS20 — Prove discharge and prepare the occupied refuge

- **What / why now:** physically earn final-release safety before allowing Ivo to enter the Ward.
- **Gameplay / engineering:** SQ-08-01–04/PZ-24–26; limited hydraulic proof, locked deflector/rack predicates, pad/culvert preparations, twelve occupied bays and one atomic cradle transfer.
- **Assets / animation:** SEAWALL/BASIN-GATES/DEFLECTOR/RACK/TEST-VALVE/PADS/PINS/PAIRED-STATION, established Ward proxy/real authority transition, residents/Orren. Test lever, seating, cradle inspection and balance entry.
- **Visuals / VFX:** low ordinary sea contrasted with retained water, visible good/bad test outlets, broken crossing and occupied windows; calm waves stay autonomous. Reveal only partial facade/shoes before C09.
- **Audio:** temporary ordinary wind/sea, proof flow and dry latch, room foley and quiet clamp transfer; reserve large response for first step.
- **Physics / puzzles:** reversible limited test cannot harm civilians; only valid flow commits DischargeProved. Pads stop rocking when locked, culvert physically opens and complete roster reaches real interior bays before entry.
- **Playable / visual result:** through C08 to supported open-cradle handover, target 195 cumulative minutes, continuous into C09 with no banner or new control scheme.
- **Tests / acceptance / exit:** canonical TST-047–052/069, invalid-order proof, all preparations reachable, one transaction across C08/C09 and no permanent collar on restore. Player can explain why moving/refuge/discharge are required. Then FS21.

### FS21 — The occupied Ward crosses, crouches and kneels

- **What / why now:** integrate the flagship using real campaign prerequisites and actual saved survivors.
- **Gameplay / engineering:** SQ-09-01–05/PZ-26–29, progress-led reveal, support graph, clearance, porch and independent evacuation; remove synthetic flags from campaign path.
- **Assets / animation:** full functional WARD/rooms/shoes/cradle/pads/girder/porch and twelve established identities. First lift, caught rail/cup, narrow support, crouch/rise, kneel, uneven exits and Ivo withdrawal.
- **Visuals / VFX:** human-scale approach to 42 m reveal, chimneys/curtain identify the same hostel. Visible occupants and receiving contacts remain legible; bounded dust and domestic prop reactions.
- **Audio:** temporary architectural strain mixed with individual shoes/cloth/crockery, subtract effort when supports engage; no heroic transformation music.
- **Physics / puzzles:** validated front/rear contact sequence, recoverable misalignment, 9.8 m lowered hull beneath 10.6 m girder and permanent abutments. Actual route completion of each survivor, not a timer, advances evacuation.
- **Playable / visual result:** real 20-minute target first part of C09, then Ivo exits the supported hostel into the prepared culvert; cumulative target 215 minutes.
- **Tests / acceptance / exit:** canonical TST-051–058/070/074/077/084; supported and mid-phase reloads, no new controls, hidden gait demands, duplicate civilians or automatic new step on neutral. All twelve visibly accounted for and Ward remains standing after exit. Then FS22.

### FS22 — The last hand, deliberate release and ordinary help

- **What / why now:** complete the actual ending only after real supports/discharge/evacuation facts exist.
- **Gameplay / engineering:** SQ-09-06–08/PZ-30/31; same root entity, isolation/handover, fresh arm/release, immutable post-release checkpoint, ordinary traversal, gate/help and completion/replay separation.
- **Assets / animation:** ROOT-GOVERNOR/ANJA/cuff, return culvert, ESCAPE-STAIR/ORDINARY-GATE/INLAND, original Orren and offered-hand survivor. Two taps/goodbye/opening fingers, nonlingering death, escape effort, voluntary gate and accepted hand.
- **Visuals / VFX:** return to intimate human scale; prepared discharge and stable hostel visible on escape; local settling never hides ordinary landings. Last steps remain playable before fade.
- **Audio:** temporary taps/cuff/breath, root strain disappearing, outlet/settle and unsynchronized ordinary footsteps; no surprise attack after relief.
- **Physics / puzzles:** Ivo owns only unloaded governor; all cancellation causes preserve owner and require fresh arm. Post-release gap/stair/crouch work without active network. Orren waits, never closes gate on Ivo.
- **Playable / visual result:** New Game can reach canonical final fade with no debug shortcut; the final approximately ten minutes complete the 225-minute design allocation.
- **Tests / acceptance / exit:** TST-059–062/071–073/085, every input/menu/focus/device/remap/quit boundary, exactly one release and no resurrection after escape failure. Ending survives immediate closure. Player explains both Anja's fate and prepared safety. Then FS23.

### FS23 — Full campaign gameplay-complete gate

- **What / why now:** establish that the whole game functions before broad final presentation/audio work. This is the operational gameplay-complete milestone.
- **Gameplay / engineering:** audit all forty cards, thirty-one puzzles, nineteen facts, twelve slots and every dependency; real start-to-end route, checkpoints, saves, settings and supported assisted paths. No missing actor, fake win button or synthetic campaign prerequisite.
- **Assets / animation:** complete functional collision/rig/socket coverage for every required family; readable gameplay stand-ins may remain only when they preserve meaning. All critical contacts/actions represented and inventoried for final replacement.
- **Visuals / VFX:** coherent nine-area geography, recurring hostel/root identity and every reveal visible; quality debt assigned by sequence, never used to excuse missing story.
- **Audio:** all temporary events and functional visual/caption equivalents integrated; complete final REAPER cue/recording backlog with sources and estimates.
- **Physics / puzzles:** all canonical intended/misuse routes, rare-order combinations, water/owner/support/finale invariants and state transitions tested as a connected game.
- **Playable / visual result:** clean New Game-to-ending build plus resume bank for each chapter, station, bell, Ward and root phase.
- **Tests / acceptance / exit:** full TST-001–131 applicability audit; execute gameplay/system portions and explicitly defer final-audio/distribution portions to named gates. TST-085/086 fresh causality/duration, full restore path and no blocking/high gameplay defects. Measure active/stall/retry time; never pad to 225. User reviews gameplay completion before FS24; this is not release readiness or full source M13 acceptance.

### FS24 — Final domestic, Gardens, Laundry and Exchange presentation

- **What / why now:** replace C01–C04 art/animation debt using accepted gameplay and measured Laundry production methods; retain the complete game for regression.
- **Gameplay / engineering:** bind final assets to existing facts/sockets, finish contact IK and per-shot quality profiles; no new mechanics or unexplained collision changes.
- **Assets / animation:** final Ivo, domestic/transport Anja, Orren, adult shared variants; TERRACE/GARDENS/LAUNDRY/EXCHANGE and shared kits. ANM locomotion/contact/Hold plus corresponding mother/Custodian/Porter/bearer/bird actions, with named contacts and reviewed loop flags.
- **Visuals / VFX:** each card's real A/B/C frames, restrained palette changes, readable porcelain/cuff/eyes; final cloth, rain, reeds and localized wetness. Eliminate legacy proxy look in these chapters.
- **Audio:** retain temporary original cues; confirm changed contact timing still drives correct event IDs. Capture useful reference timing for REAPER without treating it as final audio.
- **Physics / puzzles:** pivots, hulls, sockets, LODs and cover tags preserve accepted solutions; cosmetic detail cannot become a new blocker.
- **Playable / visual result:** first four chapters at intended final visual/animation quality inside the continuous campaign.
- **Tests / acceptance / exit:** all affected C01–C04 routes, recognition, input/contact and import/low-effects tests; compare before/after collision envelopes and profile. Source/export/license metadata complete, no important proxy remains here. Then FS25.

### FS25 — Final cutting, water, Burden House and seawall presentation

- **What / why now:** finish C05–C08 with distinct physical/emotional identities instead of repeating the Laundry kit.
- **Gameplay / engineering:** tune quality tiers, water/head agreement, station contacts and narrative pose binding while retaining authoritative states.
- **Assets / animation:** CUT/DROWNED/BURDEN/SEAWALL, carrier/room/bell/dock, final Anja-root identity and exposed bearers; swim/one-arm/bell, carrier/room, recognition/refusal and support contacts.
- **Visuals / VFX:** pale cutting scale, recognizable submerged shopfronts, intimate domestic backs and calm horizon. Bounded silt/air/water marks, cable response and believable root strain tied to load.
- **Audio:** temporary cues follow final animation and region transitions; preserve familiar mechanical signatures for later human-source recognition.
- **Physics / puzzles:** final bell shell must match safe-air geometry; no artistic scale change invalidates swim margin, hose, room receiving contact or discharge path.
- **Playable / visual result:** C05–C08 achieve intended visual and contact quality on the accepted campaign route.
- **Tests / acceptance / exit:** canonical water/bell/station/root-recognition/discharge regressions, reduced effects and breath assistance, contact-sheet review and recorded floor profiling. Players distinguish open harnesses and irreversible root. Then FS26.

### FS26 — Final Ward, inhabitants and ending performance

- **What / why now:** finish the most expensive visual/animation sequence using the early flagship benchmark as a measured guide.
- **Gameplay / engineering:** full Ward presentation rig, local-room containment and shared snapshots, progress-driven camera, sole root identity and final human contact alignment.
- **Assets / animation:** final facade, shoes, inhabited rooms, porch, inland route, Anja/Orren/hand details; ANM-189–205 Ward set plus independent survivor/recovery/evacuation and ending contacts. Source curves remain editable.
- **Visuals / VFX:** coherent human-to-building-to-human scale, recognizable landmarks, restrained grit/settle/discharge and ordinary last walk. No comic leg swing, organic creature or empty-vehicle interpretation.
- **Audio:** temporary big/small reaction balance retained; record final visual action phases and cue priorities for REAPER.
- **Physics / puzzles:** visible supports/clearance match the authoritative graph; contained dishes/furniture never decide survivor survival. Final meshes revalidate under-girder margin and cradle exit.
- **Playable / visual result:** entire final thirty-minute chapter at intended visual/animation quality with live controls and visible twelve-person continuity.
- **Tests / acceptance / exit:** TST-051–062/070–074/077/083/084 plus first-person controller observation, all reveal/root phase restores and maximum-view profiling. No remaining story-critical proxy, impossible contact or occupant ambiguity. Then FS27.

### FS27 — Complete settings, accessibility and content integrity

- **What / why now:** close cross-campaign usability and data debt before sound production, with gameplay and visual content represented.
- **Gameplay / engineering:** complete UI/slot recovery, all-action remaps, toggle paths, breath/timing assists, reduced motion, caption/localization infrastructure and supported-save policy. Review engine support without automatic upgrade.
- **Assets / animation:** final original/licensed glyphs and UI-BOOT/MAIN/PAUSE/SETTINGS/SAVE/ERROR/ROOT-CONFIRM/CREDITS. Assistance-safe interaction/contact variants; no mandatory simultaneous dexterity input.
- **Visuals / VFX:** readable UI scale/backing/safe areas, brightness calibration, 16:9/16:10 and authored ultrawide policy. Reduced effects preserve contacts, water and reveal information.
- **Audio:** temporary bus controls and reduced-dynamic-range route; final mixes remain scheduled. Caption wording uses stable cue IDs and no critical sound-only solution.
- **Physics / puzzles:** assistance changes permitted timing/reserve, never owner/support predicates or ending. No input-map change counts as release.
- **Playable / visual result:** full campaign usable through all supported settings and recovery paths with no gameplay debug UI required.
- **Tests / acceptance / exit:** TST-072/073/079/081–083/091/103/123–125, text expansion, physical hotplug, incompatible saves and full settings persistence. All 164 families/211 animation tasks receive explicit delivered/reused/deferred disposition; unneeded variants require scope review. Gameplay is ready for FS28 audio production.

### FS28 — REAPER production and final Laundry sound

- **What / why now:** begin final audio after gameplay completion. Establish the original recording/edit/export/mix pipeline in the full accepted Laundry chapter.
- **Gameplay / engineering:** finalize SYS-17/34 event metadata, buses, priorities, loop/one-shot restart policies and resident critical cues; audio cannot own puzzle success or death timing.
- **Assets / animation:** REAPER source sessions, dry recordings and edited 48 kHz/24-bit source where practical; FOL/VOC/BRACE/ANCHOR/RACK/WET-RACK/Laundry ambience and musical-layer subset. Shared breath phase aligns cosmetic animation without delaying motor.
- **Visuals / VFX:** retain final Laundry image; update only justified pose/cue alignment and captions, preserving silhouette/cover/physics.
- **Audio:** full material footfall, effort, ownership migration, support relief, wet mass, search and finger-reveal quietness. No copied INSIDE sounds or constant drone filling every gap.
- **Physics / puzzles:** confirm a muted output never changes AI hearing; motion-linked loops read q/load, water/wetness and committed events.
- **Playable / visual result:** full twenty-four-minute Laundry with final sound/music direction, recognizable clue rhythms and coherent retries.
- **Tests / acceptance / exit:** TST-082/108/125 plus Laundry regressions; headphones/stereo/mono/low volume/reduced dynamic range, loop seams, pause/restore/voice stealing and ten-minute idle. Target no clipping and ≥1 dB true-peak headroom, measured. Source/edit/event rights and metadata complete before FS29.

### FS29 — Final First Step sound and complete M13 audit

- **What / why now:** complete the second audiovisual benchmark and honestly close the source M13 requirement deferred by gameplay-first ordering.
- **Gameplay / engineering:** align Ward support/gait, room-local cues, camera reveal and audio restart phases; finalize representative voice/residency budget.
- **Assets / animation:** REAPER WARD/PAIRED/DOMESTIC/BREATH/FOOT material and restrained carry-layer sessions; recorded catches/brace/recover sync to final pose, with no additional control delay.
- **Visuals / VFX:** reuse the accepted three-to-six-minute flagship benchmark with final Ward art, reaction detail and reduced-motion framing.
- **Audio:** large structural strain leaves room for small dishes/hands/people; relief subtracts tension. No roar or triumphant vehicle theme.
- **Physics / puzzles:** sound follows actual shoe contact, arrest and support; a muted/failed device cannot advance the rig or drop passengers.
- **Playable / visual result:** final audiovisual Laundry plus final audiovisual First Step benchmark, both packaged and controllable.
- **Tests / acceptance / exit:** rerun the complete original M13 contract: two fresh-player rounds, all disciplines, floor-device tests, long retry soak and interruption matrix. Reconcile actual labor against FS15 estimates and reforecast remaining audio/polish. M13 may be marked accepted only with this combined evidence. Then FS30.

### FS30 — Final sound and music for the remaining campaign

- **What / why now:** apply the proven REAPER pipeline to every other region and the complete ending, preserving mechanical memory and emotional restraint.
- **Gameplay / engineering:** final event/cue coverage, phase clocks, mix transitions, spatial rooms, caption priorities and device recovery across all nine chapters.
- **Assets / animation:** complete all 52 cue families with reviewed variation needs; region ambience, remaining music layers, Anja/Orren/bearer breaths and final root/discharge/gate sounds. 399 initial variants are an estimate, not a duplication quota.
- **Visuals / VFX:** retain final images; synchronize visible breaths, footsteps, air boundaries and load reactions through shared state. No success flash added to compensate for weak sound design.
- **Audio:** intimate apartment/taps, open gardens, public/hidden exchange layers, large cutting, precious bell air, recognized body rhythms, ordinary sea, occupied Ward and unsynchronized ending steps. Keep silence contextual, not total device-like silence.
- **Physics / puzzles:** logical noise independent of mix; critical motion and breath work during mute/device change. Recreate safe cue phase after death, quit and streaming.
- **Playable / visual result:** complete campaign with final sound/music and no temporary cue remaining without explicit approved exception.
- **Tests / acceptance / exit:** whole sound/caption routes, ten-minute idle per region, mono/low-volume/headphones/speakers, repeated water/bell and root interruptions. Check no stacked one-shots or misleading danger after reset. Then FS31.

### FS31 — Complete audiovisual alpha

- **What / why now:** certify feature/content completeness only after final art, animation, sound and supported settings coexist.
- **Gameplay / engineering:** freeze new mechanics, resolve all content/register mismatches, finalize supported internal-to-release save transitions and engine-support decision.
- **Assets / animation:** all required families and essential 211-task coverage approved or explicitly consolidated; final character/room/hand contacts throughout, rights/source records complete.
- **Visuals / VFX:** full-game quality consistent with both benchmarks, every A/B/C board reviewed in normal/reduced settings, no critical placeholders.
- **Audio:** complete cue/mix/caption implementation, repeat-aware reveals and full final thirty-minute sound review.
- **Physics / puzzles:** full fact/owner/water/support/cohort/root chain preserved after final assets; all unsupported-order cases solvable or clearly rejected.
- **Playable / visual result:** feature/content-complete campaign suitable for broad external evaluation after review.
- **Tests / acceptance / exit:** entire TST suite applicable at alpha, plus source M15 criteria, two-hour memory/retry soak and supported save fixtures. No missing mandatory feature, sequence, actor, audio family or accessibility control. Known polish backlog bounded; user alpha review before FS32.

### FS32 — External beta and story comprehension

- **What / why now:** validate the whole experience without developer explanation, using fresh players rather than only familiar testers.
- **Gameplay / engineering:** repair demonstrated comprehension, navigation, timing and recovery defects; retain locked story and behavior. Recruit/distribute only through user-authorized arrangements.
- **Assets / animation:** targeted replacements for observed contact/readability issues, localization and disclosures; no speculative new content.
- **Visuals / VFX:** review missed finger/cuff/eye/hostel cues, floor-tier readability and camera comfort from real runs.
- **Audio:** full mix and caption testing with varied listening conditions/accessibility; check signature recognition and ending quietness.
- **Physics / puzzles:** assisted/non-assisted full routes, unusual orders, bell/catch margins and Ward correction warnings from novice behavior.
- **Playable / visual result:** stable representative beta; target 20–30 fresh full runs if capacity permits, actual sample and limits reported honestly.
- **Tests / acceptance / exit:** TST-081–088 and source M16; target ≥80% of observed sample explains conscious bearers, institutional choice, irreversible Anja and prepared release. Median active play target 210–240 min with stall/retry split; never repair duration through forced waits. No progression/save-loss or major readability issue before FS33.

### FS33 — Performance, contact and pacing polish

- **What / why now:** optimize measured weaknesses in the stable experience, not hypothetical hot paths.
- **Gameplay / engineering:** CPU/GPU/residency hotspots, streaming prefetch, pooling, shader readiness, load/retry latency and frame pacing; record quality tiers and supported hardware.
- **Assets / animation:** LOD/texture/shader/audio residency revisions and targeted contact fixes; silhouettes, cuff/fingers and support marks must survive reduction.
- **Visuals / VFX:** final atmosphere without excessive transparency/fog/reflections; low effects retain all clues; remove unnecessary camera shake and contact jitter.
- **Audio:** voice budgets, streaming and final transitions; critical breath/support cues never stolen by ambience.
- **Physics / puzzles:** optimizations cannot change driver steps, collision order or survivor safety. Regress affected paths at 30/60/120 fps after each material change.
- **Playable / visual result:** full game meeting agreed floor/target performance and cinematic consistency, with documented p95/p99/memory/loading results.
- **Tests / acceptance / exit:** TST-078/083/087/088/130, cold/warm opening/water/max-Ward, two-hour retries and full campaign. Measure target <3 s local retry where resident and retain specific chase/ending replay limits. Zero major performance or gameplay regression before FS34.

### FS34 — Release candidate and delivery rehearsal

- **What / why now:** test the exact intended distribution artifact rather than an editor or private development package.
- **Gameplay / engineering:** Shipping build, version/provenance, install/update/uninstall/offline startup, supported saves, error recovery, debug stripping and rollback artifact.
- **Assets / animation:** final packaged content, original store captures/key art, credits/licenses and support material; confirm final animation assets and state variants survive cooking.
- **Visuals / VFX:** truthful actual-game captures and calibrated default settings; no reference images, prototype screenshots or unlicensed content shipped as gameplay.
- **Audio:** cooked streaming/critical cues and device configuration match the approved mix; credits and attribution complete.
- **Physics / puzzles:** clean New Game-to-ending and bank of all save categories on actual distribution build; preserve root ledger across install/update/recovery.
- **Playable / visual result:** installable candidate hash and rollback candidate ready for user review. External upload/distribution only when explicitly authorized.
- **Tests / acceptance / exit:** TST-073/079/089/091/131 and source M18; clean offline machine, full disk/read-only/corrupt save, update/continue and ending. Zero ship-blocking defects, verified backup and assigned support owner before FS35.

### FS35 — Final production build and authorized release

- **What / why now:** approve the exact shipping artifact after delivery rehearsal; no new feature work.
- **Gameplay / engineering:** lock source/content/toolchain hash, archive build provenance, final smoke and rollback/hotfix process. Publish only after the user explicitly authorizes the concrete artifact and destination.
- **Assets / animation:** exact approved runtime assets, source archive, store materials and notices; final contact/character/room variants unchanged or regression-tested.
- **Visuals / VFX:** confirm shipping graphics/quality defaults match reviewed capture; no accidental debug overlays or different cooked materials.
- **Audio:** confirm final buses, files, captions and credits in the exact package.
- **Physics / puzzles:** smoke representative Hold/support, bell, Ward, protected release and post-release continue without development commands.
- **Playable / visual result:** signed-off final production package, fully playable offline; authorized distribution uses precisely the reviewed hash.
- **Tests / acceptance / exit:** source M19 and distribution smoke with provenance comparison. User artifact/release decision recorded, no waived blocker and rollback ready. If publication is not authorized, record package ready and publication pending; do not invent release completion. Then FS36 only as applicable.

### FS36 — Stabilization and maintenance

- **What / why now:** preserve a working shipped game through verified corrections. Reserve may repair earlier rejected gates before release, without bypassing their order.
- **Gameplay / engineering:** bounded defect fixes, supported save migration, hotfix branch and archived repros; no unrequested expansion or launch-time engine migration.
- **Assets / animation:** targeted corrected sources/exports/clips only; retain original editable hero/contact work.
- **Visuals / VFX:** verify repaired shots and quality tiers retain narrative readability; no silent art-style change.
- **Audio:** correct reproduced cue/device/loop issues and recheck neighboring transitions.
- **Physics / puzzles:** affected chapter plus ownership/save/root regression; fixes cannot reinterpret already committed ending facts.
- **Playable / visual result:** reproducible updated package preserving progress and canonical ending, with clear release notes.
- **Tests / acceptance / exit:** each patch has a repro case, appropriate tests, compatible-save evidence and separately authorized publication. Retrospective records remaining maintenance owners/capacity. No automatic recurring monitoring or new feature phase is created here.

## 5. Source milestones, sequencing exceptions and status

### Milestone reconciliation

| v3 source gate | Required roadmap evidence / treatment |
|---|---|
| M00 Foundation/reference | FS00; reuse historical proof only when compatible. Two-machine/license-reference tasks remain explicit if unavailable. |
| M01 Movement | FS01; occupied-hand integration FS02; later water/station contexts recheck. |
| M02 Hold | FS02–FS03; anchor and reach integrated FS04. |
| M03 First puzzle | FS03; canonical shutter/tread FS11. |
| M04 Loop/narrative state | FS05; actual opening FS11. |
| M05 Horror/tension | FS08; final sound recheck FS28–FS31. |
| M06 Enemies | FS08–FS10 prototypes; actual Gardens/Exchange/Cut/Water FS13/16/17/18. |
| M07 Integrated environment | FS04 visual proof and FS05 streaming; mature full Laundry FS14. Final audio deferred explicitly. |
| M08 Water/bell | FS10 risk gate; canonical chapter FS18. |
| M09 Reciprocal/Ward/root | FS06–FS07 risk gate, FS15 quality benchmark, actual progression FS17/19/21/22. |
| M10 First fifteen minutes | FS11; kitchen fragment intentionally earlier at FS01. |
| M11 Complete first chapter | FS12 gameplay/visual sign-off; final sound FS30/31. |
| M12 First thirty minutes | FS13 records the actual thirty-minute boundary and also completes Gardens; no stitched later-room montage. |
| M13 Full Laundry + flagship quality | FS14–FS15 are separate gameplay/visual/capacity gates before expansion. Original complete audiovisual M13 remains unpassed until FS28–FS29 and full re-audit. |
| M14 End-to-end playable | FS23 under the user's gameplay-first exception; real nine chapters/ending required. |
| M15 Alpha | FS31 after full final-audio/content integration and engine-support review. |
| M16 Beta | FS32. |
| M17 Optimization/polish | Continuous profiling, convergence FS33. |
| M18 Candidate | FS34. |
| M19 Production/launch | FS35; package approval and publication authority recorded separately. |
| M20 Stabilization | FS36; reserve may first repair a failed prelaunch gate. |

Approval of this roadmap approves these production-order changes, not claims that the original source milestones passed. FS01's real kitchen fragment is an intentional early reuse of canonical content; the complete opening still depends on tested Hold, saves and threat behavior. Rough Ward proof precedes water proof in this serial plan to address the source's highest-risk control feature early. No final world art is commissioned in bulk before both FS14 and FS15.

The source sprint SP-01–20 is a bounded task pool, not permission for simultaneous phases. Foundation/naming/units/reference/geography inform FS00; traversal/input/rig/swatches FS01; mechanism/ownership FS02; support FS03; paired/Ward FS06–FS07; water geometry and behavior FS09–FS10. Audio naming/events begin with the relevant fixture, final production FS28+. Carry reference availability and measured capacity honestly; package staffing/week estimates are not workspace commitments.

### Open contracts and deadlines

The complete issue descriptions, evidence and proposed resolutions are in the [review issue table](review/v3/Story_and_Production_Review.md#contract-issues-and-decisions-before-dependent-work). They are not assumed resolved merely because listed here.

| Issue | Required gate |
|---|---|
| V3-01 Engine translation | FS00 |
| V3-02 Position/rotation/unit conversion | FS00/FS02 |
| V3-03 Braced assembly versus posture correction | FS06, verified FS07 before dependent scenes |
| V3-04 Fact aliases versus local event phases | FS05, root FS07 |
| V3-05 Scalar schema versus composite snapshots | FS05 seed; FS06/FS07/FS10 typed extensions |
| V3-06 Bridge range/conduit/recovery | FS03–FS04; canonical FS14 |
| V3-07 Wet-rack arrest/catch ordering | FS14 before puzzle acceptance |
| V3-08 Bell capture/tilt/hose/air contract | FS09–FS10 |
| V3-09 Cradle transfer across chapter seam | FS06–FS07; canonical FS20–FS21 |
| V3-10 Inherited asset dependencies/cohort fields | FS00 rule; every phase entry |
| V3-11 Animation loop/contact flags | FS01 initial; final FS24–FS26 |
| V3-12 Source M13 audio ordering | Roadmap approval; FS15 and FS29 explicit gate review |

### Current ledger

- **Document migration/research:** performed on 8 September 2026; evidence in `review/v3/`. This is documentation work, not an accepted runtime phase.
- **Roadmap approval:** Pending user review of revision 3.0.
- **FS00–FS36:** Not started. No phase may inherit a pass from the imported source workbook's existence.
- **Historical PH00:** accepted for legacy progression on the basis recorded in its review; missing external evidence stays missing.
- **Historical PH01:** packaged traversal implementation and recorded checks at `1fd1beb`; user reported it working, but remaining formal evidence is not fabricated. Its map is not a v3 story chapter.
- **Next eligible action:** review this roadmap; after approval, authorize FS00. No implementation, new build, commit, push or publication is performed by rewriting this file.

## 6. Complete traceability

The tables below are planned assignments, not completion records. They cover every supplied sequence, puzzle, system, test and durable fact. Their underlying detail remains in the imported register row; execute its full steps/expected contract, not merely the title. Early prototype evidence must be repeated in its real campaign context. Cross-phase/global tests mature at FS23 and are rerun at FS31–FS35 as applicable.

For assets, animations and audio, every phase entry produces an exact resolved bill of work from sequence actors plus inherited dependencies (Ivo, owner/root, roster, camera, UI and shared kits). Record stable family/task/cue ID, variant, source/export, first use, presentation maturity and phase acceptance. Asset `uses` lists are not exhaustive. This avoids manufacturing 164 meshes or 211 clips just to match a count; consolidation requires documented retained coverage.

Final visual/animation passes: C01–C04 FS24; C05–C08 FS25; C09 FS26. Full final sound: C03 FS28, First Step benchmark FS29, remaining campaign FS30; integrated all FS31. Final distribution checks FS34–FS35 apply to the whole game.

### 6.1 All forty campaign sequences

| Sequence | Title | Campaign integration | Checkpoint |
|---|---|---|---|
| SQ-01-01 | A small thing that will not stay still | FS01 | CK-01-01 |
| SQ-01-02 | The landing that cannot be released | FS11 | CK-01-02 |
| SQ-01-03 | The shutter and the rotating tread | FS11 | CK-01-03 |
| SQ-01-04 | A door between two bodies | FS12 | CK-01-04 |
| SQ-02-01 | Wind has no owner | FS13 | CK-02-01 |
| SQ-02-02 | Give the water somewhere to go | FS13 | CK-02-02 |
| SQ-02-03 | The apparatus that catches falling things | FS13 | CK-02-03 |
| SQ-02-04 | The people above the drain | FS13 | CK-02-04 |
| SQ-03-01 | Leave the effort behind | FS14 | CK-03-01 |
| SQ-03-02 | The hanging corridor | FS14 | CK-03-02 |
| SQ-03-03 | The weight of wet cloth | FS14 | CK-03-03 |
| SQ-03-04 | A cover, not a machine | FS14 | CK-03-04 |
| SQ-04-01 | A waiting room beneath a waiting room | FS16 | CK-04-01 |
| SQ-04-02 | The queue that leans | FS16 | CK-04-02 |
| SQ-04-03 | The eyes that do not stop | FS16 | CK-04-03 |
| SQ-04-04 | Orren stands | FS16 | CK-04-04 |
| SQ-05-01 | The weight is visible | FS17 | CK-05-01 |
| SQ-05-02 | Borrowed balance | FS17 | CK-05-02 |
| SQ-05-03 | Make a fall useful | FS17 | CK-05-03 |
| SQ-05-04 | Beneath the rescue rail | FS17 | CK-05-04 |
| SQ-06-01 | The street below the street | FS18 | CK-06-01 |
| SQ-06-02 | A room for one breath | FS18 | CK-06-02 |
| SQ-06-03 | A rescue that would drown him | FS18 | CK-06-03 |
| SQ-06-04 | Water leaves a record | FS18 | CK-06-04 |
| SQ-07-01 | You have heard this before | FS19 | CK-07-01 |
| SQ-07-02 | A room that follows your shoulders | FS19 | CK-07-02 |
| SQ-07-03 | Mother is not behind the machine | FS19 | CK-07-03 |
| SQ-07-04 | A rescue that changes the room | FS19 | CK-07-04 |
| SQ-08-01 | The storm has already passed | FS20 | CK-08-01 |
| SQ-08-02 | Prove a safe way down | FS20 | CK-08-02 |
| SQ-08-03 | The refuge cannot remain here | FS20 | CK-08-03 |
| SQ-08-04 | An open place to stand | FS20 | CK-08-04 |
| SQ-09-01 | Taking the balance | FS21 | CK-09-01 |
| SQ-09-02 | The First Step | FS21 | CK-09-02 |
| SQ-09-03 | Carry the rooms across | FS21 | CK-09-03 |
| SQ-09-04 | A building crouches | FS21 | CK-09-04 |
| SQ-09-05 | The house kneels | FS21 | CK-09-05 |
| SQ-09-06 | The last hand | FS22 | CK-09-06 |
| SQ-09-07 | Let the emergency finish | FS22 | CK-09-07 |
| SQ-09-08 | Long enough to pass | FS22 | CK-09-08 |

SQ-01-04 begins in FS11; FS12 completes it. PZ-26 crosses the C08/C09 seam and must be tested as one state transition. All early fixture entries remain outside New Game ordering.

### 6.2 All thirty-one puzzles

| Puzzle | Name | First proof | Canonical gate |
|---|---|---|---|
| PZ-01 | Kitchen chair and cover | FS01 | FS01 |
| PZ-02 | First shutter | FS02 | FS11 |
| PZ-03 | Rotating tread | FS02 | FS11 |
| PZ-04 | Pursuit door | FS08 | FS12 |
| PZ-05 | Wind panel | FS13 | FS13 |
| PZ-06 | Garden diversion | FS13 | FS13 |
| PZ-07 | First Porter | FS09 | FS13 |
| PZ-08 | Laundry bridge transfer | FS04 | FS14 |
| PZ-09 | Hanging corridor | FS08 | FS14 |
| PZ-10 | Wet blanket counterweight | FS14 | FS14 |
| PZ-11 | Queue deck jack | FS03 | FS16 |
| PZ-12 | Conscious guard/cart/shutter | FS08 | FS16 |
| PZ-13 | Orren's stair pawl | FS03 | FS16 |
| PZ-14 | Exposed counterweight sweep | FS17 | FS17 |
| PZ-15 | Balance carrier | FS06 | FS17 |
| PZ-16 | Useful falling mass | FS17 | FS17 |
| PZ-17 | Porter diversion and moving exit | FS09 | FS17 |
| PZ-18 | First swim | FS10 | FS18 |
| PZ-19 | Moving air shelter | FS10 | FS18 |
| PZ-20 | Obsolete rescue dock | FS10 | FS18 |
| PZ-21 | Chamber drain | FS10 | FS18 |
| PZ-22 | Reciprocal domestic room | FS06 | FS19 |
| PZ-23 | Support instead of root transfer | FS19 | FS19 |
| PZ-24 | Discharge proof | FS20 | FS20 |
| PZ-25 | Ward receiving pads | FS20 | FS20 |
| PZ-26 | Open cradle and balance | FS07 | FS20/FS21 |
| PZ-27 | Narrow support | FS07 | FS21 |
| PZ-28 | Crouch under girder | FS07 | FS21 |
| PZ-29 | Kneel and support | FS07 | FS21 |
| PZ-30 | Final handover | FS07 | FS22 |
| PZ-31 | Deliberate root release | FS07 | FS22 |

### 6.3 All forty system contracts

| System | Name | First proof | Mature requirement |
|---|---|---|---|
| SYS-01 | Bootstrap and service lifetime | FS00 | FS23 gameplay; FS31 integration |
| SYS-02 | Input and accessibility routing | FS01 | FS23 gameplay; FS31 integration |
| SYS-03 | Lane capsule motor | FS01 | FS23 gameplay; FS31 integration |
| SYS-04 | Ledge and ladder interaction | FS01 | FS23 gameplay; FS31 integration |
| SYS-05 | Contextual interaction resolver | FS01 | FS23 gameplay; FS31 integration |
| SYS-06 | Hold ownership transactions | FS02 | FS23 gameplay; FS31 integration |
| SYS-07 | Mechanism drivers | FS02 | FS23 gameplay; FS31 integration |
| SYS-08 | Supports and load graph | FS03 | FS23 gameplay; FS31 integration |
| SYS-09 | Moving support and crush | FS03 | FS23 gameplay; FS31 integration |
| SYS-10 | Puzzle facts and sequence exits | FS03 | FS23 gameplay; FS31 integration |
| SYS-11 | Checkpoint snapshot service | FS05 | FS23 gameplay; FS31 integration |
| SYS-12 | Save integrity and migration | FS05 | FS23 gameplay; FS31 integration |
| SYS-13 | Local streaming and residency | FS05 | FS23 gameplay; FS31 integration |
| SYS-14 | Camera volumes and leads | FS01 | FS23 gameplay; FS31 integration |
| SYS-15 | Animation presentation state | FS01 | FS23 gameplay; FS31 integration |
| SYS-16 | Foot/hand contact IK | FS04 | FS23 gameplay; FS31 integration |
| SYS-17 | Audio router and mixes | FS05 | FS28–FS30 final audio; FS31 integration |
| SYS-18 | VFX reaction bundles | FS04 | FS23 gameplay; FS31 integration |
| SYS-19 | Custodian perception and pursuit | FS08 | FS23 gameplay; FS31 integration |
| SYS-20 | Harness restraint and awareness | FS08 | FS23 gameplay; FS31 integration |
| SYS-21 | Porter rail rescue AI | FS09 | FS23 gameplay; FS31 integration |
| SYS-22 | Sheet concealment | FS08 | FS23 gameplay; FS31 integration |
| SYS-23 | Water volume graph | FS10 | FS23 gameplay; FS31 integration |
| SYS-24 | Swimming and breath | FS10 | FS23 gameplay; FS31 integration |
| SYS-25 | Bell air pocket and winch | FS10 | FS23 gameplay; FS31 integration |
| SYS-26 | Wet-cloth mass | FS14 | FS23 gameplay; FS31 integration |
| SYS-27 | Reciprocal balance station | FS06 | FS23 gameplay; FS31 integration |
| SYS-28 | Ward support/gait planner | FS07 | FS23 gameplay; FS31 integration |
| SYS-29 | Ward local-room presentation | FS07 | FS23 gameplay; FS31 integration |
| SYS-30 | Survivor roster and safe routes | FS07 | FS16/FS19 identities; FS21 full evacuation; FS23 |
| SYS-31 | Narrative event phases | FS01 | FS23 gameplay; FS31 integration |
| SYS-32 | Final root release guard | FS07 | FS22 actual root; FS27/FS31/FS34 regression |
| SYS-33 | UI and settings | FS11 | FS23 gameplay; FS31 integration |
| SYS-34 | Localization and captions | FS14 | FS23 gameplay; FS31 integration |
| SYS-35 | Sequence/ownership debug tools | FS05 | FS23 gameplay; FS31 integration |
| SYS-36 | Camera/storyboard capture tool | FS04 | FS23 gameplay; FS31 integration |
| SYS-37 | Asset import validation | FS04 | FS23 gameplay; FS31 integration |
| SYS-38 | Build and regression automation | FS00 | FS23 gameplay; FS31 integration |
| SYS-39 | Performance capture and route replay | FS00 | FS23 gameplay; FS31 integration |
| SYS-40 | Release packaging and recovery | FS34 | FS34 candidate; FS35 exact distribution |

### 6.4 All 131 supplied tests

Run the complete source row. Prototype entries cover only the available fixture; the canonical/mature gate is mandatory even if the early fixture passed. Tests after FS23 include final-audio or actual distribution portions, not permission to omit their earlier gameplay invariants. All statuses currently remain **Not run**.

| Test | Title | First relevant proof | Canonical / mature gate |
|---|---|---|---|
| TST-001 | Kitchen chair and cover — intended route | FS01 | FS01; affected regressions FS31–FS35 |
| TST-002 | Kitchen chair and cover — misuse and interruption | FS01 | FS01; affected regressions FS31–FS35 |
| TST-003 | First shutter — intended route | FS02 | FS11; affected regressions FS31–FS35 |
| TST-004 | First shutter — misuse and interruption | FS02 | FS11; affected regressions FS31–FS35 |
| TST-005 | Rotating tread — intended route | FS02 | FS11; affected regressions FS31–FS35 |
| TST-006 | Rotating tread — misuse and interruption | FS02 | FS11; affected regressions FS31–FS35 |
| TST-007 | Pursuit door — intended route | FS08 | FS12; affected regressions FS31–FS35 |
| TST-008 | Pursuit door — misuse and interruption | FS08 | FS12; affected regressions FS31–FS35 |
| TST-009 | Wind panel — intended route | FS13 | FS13; affected regressions FS31–FS35 |
| TST-010 | Wind panel — misuse and interruption | FS13 | FS13; affected regressions FS31–FS35 |
| TST-011 | Garden diversion — intended route | FS13 | FS13; affected regressions FS31–FS35 |
| TST-012 | Garden diversion — misuse and interruption | FS13 | FS13; affected regressions FS31–FS35 |
| TST-013 | First Porter — intended route | FS09 | FS13; affected regressions FS31–FS35 |
| TST-014 | First Porter — misuse and interruption | FS09 | FS13; affected regressions FS31–FS35 |
| TST-015 | Laundry bridge transfer — intended route | FS04 | FS14; affected regressions FS31–FS35 |
| TST-016 | Laundry bridge transfer — misuse and interruption | FS04 | FS14; affected regressions FS31–FS35 |
| TST-017 | Hanging corridor — intended route | FS08 | FS14; affected regressions FS31–FS35 |
| TST-018 | Hanging corridor — misuse and interruption | FS08 | FS14; affected regressions FS31–FS35 |
| TST-019 | Wet blanket counterweight — intended route | FS14 | FS14; affected regressions FS31–FS35 |
| TST-020 | Wet blanket counterweight — misuse and interruption | FS14 | FS14; affected regressions FS31–FS35 |
| TST-021 | Queue deck jack — intended route | FS03 | FS16; affected regressions FS31–FS35 |
| TST-022 | Queue deck jack — misuse and interruption | FS03 | FS16; affected regressions FS31–FS35 |
| TST-023 | Conscious guard/cart/shutter — intended route | FS08 | FS16; affected regressions FS31–FS35 |
| TST-024 | Conscious guard/cart/shutter — misuse and interruption | FS08 | FS16; affected regressions FS31–FS35 |
| TST-025 | Orren's stair pawl — intended route | FS03 | FS16; affected regressions FS31–FS35 |
| TST-026 | Orren's stair pawl — misuse and interruption | FS03 | FS16; affected regressions FS31–FS35 |
| TST-027 | Exposed counterweight sweep — intended route | FS17 | FS17; affected regressions FS31–FS35 |
| TST-028 | Exposed counterweight sweep — misuse and interruption | FS17 | FS17; affected regressions FS31–FS35 |
| TST-029 | Balance carrier — intended route | FS06 | FS17; affected regressions FS31–FS35 |
| TST-030 | Balance carrier — misuse and interruption | FS06 | FS17; affected regressions FS31–FS35 |
| TST-031 | Useful falling mass — intended route | FS17 | FS17; affected regressions FS31–FS35 |
| TST-032 | Useful falling mass — misuse and interruption | FS17 | FS17; affected regressions FS31–FS35 |
| TST-033 | Porter diversion and moving exit — intended route | FS09 | FS17; affected regressions FS31–FS35 |
| TST-034 | Porter diversion and moving exit — misuse and interruption | FS09 | FS17; affected regressions FS31–FS35 |
| TST-035 | First swim — intended route | FS10 | FS18; affected regressions FS31–FS35 |
| TST-036 | First swim — misuse and interruption | FS10 | FS18; affected regressions FS31–FS35 |
| TST-037 | Moving air shelter — intended route | FS10 | FS18; affected regressions FS31–FS35 |
| TST-038 | Moving air shelter — misuse and interruption | FS10 | FS18; affected regressions FS31–FS35 |
| TST-039 | Obsolete rescue dock — intended route | FS10 | FS18; affected regressions FS31–FS35 |
| TST-040 | Obsolete rescue dock — misuse and interruption | FS10 | FS18; affected regressions FS31–FS35 |
| TST-041 | Chamber drain — intended route | FS10 | FS18; affected regressions FS31–FS35 |
| TST-042 | Chamber drain — misuse and interruption | FS10 | FS18; affected regressions FS31–FS35 |
| TST-043 | Reciprocal domestic room — intended route | FS06 | FS19; affected regressions FS31–FS35 |
| TST-044 | Reciprocal domestic room — misuse and interruption | FS06 | FS19; affected regressions FS31–FS35 |
| TST-045 | Support instead of root transfer — intended route | FS19 | FS19; affected regressions FS31–FS35 |
| TST-046 | Support instead of root transfer — misuse and interruption | FS19 | FS19; affected regressions FS31–FS35 |
| TST-047 | Discharge proof — intended route | FS20 | FS20; affected regressions FS31–FS35 |
| TST-048 | Discharge proof — misuse and interruption | FS20 | FS20; affected regressions FS31–FS35 |
| TST-049 | Ward receiving pads — intended route | FS20 | FS20; affected regressions FS31–FS35 |
| TST-050 | Ward receiving pads — misuse and interruption | FS20 | FS20; affected regressions FS31–FS35 |
| TST-051 | Open cradle and balance — intended route | FS07 | FS21; affected regressions FS31–FS35 |
| TST-052 | Open cradle and balance — misuse and interruption | FS07 | FS21; affected regressions FS31–FS35 |
| TST-053 | Narrow support — intended route | FS07 | FS21; affected regressions FS31–FS35 |
| TST-054 | Narrow support — misuse and interruption | FS07 | FS21; affected regressions FS31–FS35 |
| TST-055 | Crouch under girder — intended route | FS07 | FS21; affected regressions FS31–FS35 |
| TST-056 | Crouch under girder — misuse and interruption | FS07 | FS21; affected regressions FS31–FS35 |
| TST-057 | Kneel and support — intended route | FS07 | FS21; affected regressions FS31–FS35 |
| TST-058 | Kneel and support — misuse and interruption | FS07 | FS21; affected regressions FS31–FS35 |
| TST-059 | Final handover — intended route | FS07 | FS22; affected regressions FS31–FS35 |
| TST-060 | Final handover — misuse and interruption | FS07 | FS22; affected regressions FS31–FS35 |
| TST-061 | Deliberate root release — intended route | FS07 | FS22; affected regressions FS31–FS35 |
| TST-062 | Deliberate root release — misuse and interruption | FS07 | FS22; affected regressions FS31–FS35 |
| TST-063 | The landing that cannot be released — narrative continuity | FS11 | FS11; affected regressions FS31–FS35 |
| TST-064 | The people above the drain — narrative continuity | FS13 | FS13; affected regressions FS31–FS35 |
| TST-065 | A cover, not a machine — narrative continuity | FS14 | FS14; affected regressions FS31–FS35 |
| TST-066 | A waiting room beneath a waiting room — narrative continuity | FS16 | FS16; affected regressions FS31–FS35 |
| TST-067 | You have heard this before — narrative continuity | FS19 | FS19; affected regressions FS31–FS35 |
| TST-068 | Mother is not behind the machine — narrative continuity | FS19 | FS19; affected regressions FS31–FS35 |
| TST-069 | The storm has already passed — narrative continuity | FS20 | FS20; affected regressions FS31–FS35 |
| TST-070 | The First Step — narrative continuity | FS07 | FS21; affected regressions FS31–FS35 |
| TST-071 | Long enough to pass — narrative continuity | FS22 | FS22; affected regressions FS31–FS35 |
| TST-072 | Final release cancellation | FS07 | FS22; affected regressions FS31–FS35 |
| TST-073 | Root postrelease persistence | FS07 | FS22; affected regressions FS31–FS35 |
| TST-074 | Cohort uniqueness | FS07 | FS21; affected regressions FS31–FS35 |
| TST-075 | Water/bell restore | FS10 | FS18; affected regressions FS31–FS35 |
| TST-076 | Thin versus thick cloth | FS08 | FS14; affected regressions FS31–FS35 |
| TST-077 | Ward support recovery | FS07 | FS21; affected regressions FS31–FS35 |
| TST-078 | Moving-platform controller | FS03 | FS21; affected regressions FS31–FS35 |
| TST-079 | Save interrupted writes | FS05 | FS27; affected regressions FS31–FS35 |
| TST-080 | Streaming owner pinning | FS05 | FS21; affected regressions FS31–FS35 |
| TST-081 | Input accessibility complete route | FS10 | FS27; affected regressions FS31–FS35 |
| TST-082 | No-audio critical route | FS10 | FS31; affected regressions FS31–FS35 |
| TST-083 | Low-effects readability | FS04 | FS26; affected regressions FS31–FS35 |
| TST-084 | First Step emotional transfer | FS07 | FS21; affected regressions FS31–FS35 |
| TST-085 | Story causality | FS22 | FS32; affected regressions FS31–FS35 |
| TST-086 | Duration without filler | FS23 | FS32; affected regressions FS31–FS35 |
| TST-087 | Performance cold/warm | FS15 | FS33; affected regressions FS31–FS35 |
| TST-088 | Long-session memory | FS23 | FS33; affected regressions FS31–FS35 |
| TST-089 | Clean distribution run | FS34 | FS35; affected regressions FS31–FS35 |
| TST-090 | Opening control and mother | FS01 | FS11; affected regressions FS31–FS35 |
| TST-091 | No source-art leakage | FS27 | FS34; affected regressions FS31–FS35 |
| TST-092 | Bootstrap and service lifetime — system acceptance | FS00 | FS23; affected regressions FS31–FS35 |
| TST-093 | Input and accessibility routing — system acceptance | FS01 | FS23; affected regressions FS31–FS35 |
| TST-094 | Lane capsule motor — system acceptance | FS01 | FS23; affected regressions FS31–FS35 |
| TST-095 | Ledge and ladder interaction — system acceptance | FS01 | FS23; affected regressions FS31–FS35 |
| TST-096 | Contextual interaction resolver — system acceptance | FS01 | FS23; affected regressions FS31–FS35 |
| TST-097 | Hold ownership transactions — system acceptance | FS02 | FS23; affected regressions FS31–FS35 |
| TST-098 | Mechanism drivers — system acceptance | FS02 | FS23; affected regressions FS31–FS35 |
| TST-099 | Supports and load graph — system acceptance | FS03 | FS23; affected regressions FS31–FS35 |
| TST-100 | Moving support and crush — system acceptance | FS03 | FS23; affected regressions FS31–FS35 |
| TST-101 | Puzzle facts and sequence exits — system acceptance | FS03 | FS23; affected regressions FS31–FS35 |
| TST-102 | Checkpoint snapshot service — system acceptance | FS05 | FS23; affected regressions FS31–FS35 |
| TST-103 | Save integrity and migration — system acceptance | FS05 | FS23; affected regressions FS31–FS35 |
| TST-104 | Local streaming and residency — system acceptance | FS05 | FS23; affected regressions FS31–FS35 |
| TST-105 | Camera volumes and leads — system acceptance | FS01 | FS23; affected regressions FS31–FS35 |
| TST-106 | Animation presentation state — system acceptance | FS01 | FS23; affected regressions FS31–FS35 |
| TST-107 | Foot/hand contact IK — system acceptance | FS04 | FS23; affected regressions FS31–FS35 |
| TST-108 | Audio router and mixes — system acceptance | FS05 | FS31; affected regressions FS31–FS35 |
| TST-109 | VFX reaction bundles — system acceptance | FS04 | FS23; affected regressions FS31–FS35 |
| TST-110 | Custodian perception and pursuit — system acceptance | FS08 | FS23; affected regressions FS31–FS35 |
| TST-111 | Harness restraint and awareness — system acceptance | FS08 | FS23; affected regressions FS31–FS35 |
| TST-112 | Porter rail rescue AI — system acceptance | FS09 | FS23; affected regressions FS31–FS35 |
| TST-113 | Sheet concealment — system acceptance | FS08 | FS23; affected regressions FS31–FS35 |
| TST-114 | Water volume graph — system acceptance | FS10 | FS23; affected regressions FS31–FS35 |
| TST-115 | Swimming and breath — system acceptance | FS10 | FS23; affected regressions FS31–FS35 |
| TST-116 | Bell air pocket and winch — system acceptance | FS10 | FS23; affected regressions FS31–FS35 |
| TST-117 | Wet-cloth mass — system acceptance | FS14 | FS23; affected regressions FS31–FS35 |
| TST-118 | Reciprocal balance station — system acceptance | FS06 | FS23; affected regressions FS31–FS35 |
| TST-119 | Ward support/gait planner — system acceptance | FS07 | FS23; affected regressions FS31–FS35 |
| TST-120 | Ward local-room presentation — system acceptance | FS07 | FS23; affected regressions FS31–FS35 |
| TST-121 | Survivor roster and safe routes — system acceptance | FS07 | FS23; affected regressions FS31–FS35 |
| TST-122 | Narrative event phases — system acceptance | FS01 | FS23; affected regressions FS31–FS35 |
| TST-123 | Final root release guard — system acceptance | FS07 | FS23; affected regressions FS31–FS35 |
| TST-124 | UI and settings — system acceptance | FS11 | FS23; affected regressions FS31–FS35 |
| TST-125 | Localization and captions — system acceptance | FS14 | FS31; affected regressions FS31–FS35 |
| TST-126 | Sequence/ownership debug tools — system acceptance | FS05 | FS23; affected regressions FS31–FS35 |
| TST-127 | Camera/storyboard capture tool — system acceptance | FS04 | FS23; affected regressions FS31–FS35 |
| TST-128 | Asset import validation — system acceptance | FS04 | FS23; affected regressions FS31–FS35 |
| TST-129 | Build and regression automation — system acceptance | FS00 | FS23; affected regressions FS31–FS35 |
| TST-130 | Performance capture and route replay — system acceptance | FS00 | FS23; affected regressions FS31–FS35 |
| TST-131 | Release packaging and recovery — system acceptance | FS34 | FS34; affected regressions FS31–FS35 |

### 6.5 All nineteen canonical durable facts

Local presentation and encounter flags are separately cataloged in FS05. Descriptive aliases are not extra durable facts. No synthetic fixture fact may migrate into campaign saves.

| Fact | Source sequence | Real campaign commit gate | Required prerequisites |
|---|---|---|---|
| BraceOwned | SQ-01-02 | FS11 | None |
| TransferLearned | SQ-03-01 | FS14 | BraceOwned |
| LaundryLoadsRelieved | SQ-03-03 | FS14 | TransferLearned |
| QueueReleased | SQ-04-02 | FS16 | TransferLearned |
| OrrenReleased | SQ-04-04 | FS16 | TransferLearned |
| BalanceLearned | SQ-05-02 | FS17 | TransferLearned |
| BellRouteCleared | SQ-06-03 | FS18 | BraceOwned |
| AnjaRecognized | SQ-07-03 | FS19 | BalanceLearned |
| CohortRoutesOpen | SQ-07-04 | FS19 | LaundryLoadsRelieved, QueueReleased, OrrenReleased |
| RootLoadReduced | SQ-07-04 | FS19 | AnjaRecognized |
| DischargeProved | SQ-08-02 | FS20 | RootLoadReduced |
| WardPadsPrepared | SQ-08-03 | FS20 | DischargeProved |
| WardOccupied | SQ-08-04 | FS20 | CohortRoutesOpen |
| FirstStepSeen | SQ-09-02 | FS21 | BalanceLearned, WardPadsPrepared, WardOccupied |
| WardSupported | SQ-09-05 | FS21 | FirstStepSeen, WardPadsPrepared |
| CohortEvacuated | SQ-09-05 | FS21 | WardSupported, WardOccupied |
| RootHandoverComplete | SQ-09-06 | FS22 | DischargeProved, CohortEvacuated, WardSupported |
| RootReleased | SQ-09-07 | FS22 | RootHandoverComplete |
| EndingComplete | SQ-09-08 | FS22 | RootReleased |

### 6.6 Per-sequence production completion

Every integrated sequence inherits the blueprint card’s blockout, solution, A/B/C boards, actors, threat, narrative, audio, save and exit requirements. At FS23 reconcile the complete sequence/asset dependency list; at FS24–FS27 reconcile every animation/source/variant; at FS30 reconcile all 52 audio families. Every record receives actual evidence or an explicit approved consolidation that preserves its function. A count match alone is not an acceptance test.

The twelve COH-01–COH-12 identities follow the source cohort register: COH-01–06 released at FS16, COH-07–09 unloaded at FS14 but confinement ends at FS19, COH-10–11 released at FS19, COH-12/Orren released at FS16. All occupy the Ward by FS20 and evacuate through verified visible routes in FS21. RootReleased cannot commit until the real CohortEvacuated fact exists.
