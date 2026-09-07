# THE HELD
## THE FIRST STEP
### Master Production Blueprint · v3.0

**Baseline: 8 September 2026**  
**Ivo, 13 · 225 minutes · nine continuous chapters**  
**Game design · narrative · sequence boards · technical design · art · audio · production · QA**

> A boy learns to stop a falling thing. Then he discovers who has been holding it.

Build specification and production baseline. Prototype, playtest and performance gates remain to be executed.


# How to use this package

Start with sections 01–04 for authority, story and the interaction contract. Level designers then use sections 05–14: every sequence has a blockout, exact interaction, three camera beats, state, threat, audio, checkpoint and acceptance criteria. Engineers use sections 15, 18, 19 and 24. Art, animation and audio use sections 16, 17 and 20. Producers and QA use sections 21–23 and the linked registers.

**Build first:** the controller/ownership/support gym, then the carrier-to-Ward control proof and water/bell proof. Do not begin bulk art until M13 passes. The full roadmap is a staffing-dependent scenario, not a date commitment.


| Baseline register | Count / meaning |
| --- | --- |
| Campaign | 9 chapters; 40 sequence cards; 225 active-play target minutes |
| Puzzles | 31 numbered concepts; all have dependencies and success predicates |
| Asset families | 164 work packages; kits/variants are included within packages |
| Engineering | 40 system contracts |
| Animation | 211 initial clip/pose tasks; reuse reviewed after prototyping |
| Audio | 52 cue families; 399 initial variations/stems allocated |
| Production | 21 milestone gates; 18 risks; 20 first-sprint tasks |
| Testing | 131 unexecuted test records; package validator is separate |
| Narrative continuity | 19 durable facts; twelve unique survivor slots |


# 01 | Production contract and scope

## The shipping proposition

**THE HELD: The First Step** is an original, single-player, side-on 2.5D psychological-horror puzzle-platformer. Ivo, a 13-year-old boy, follows his mother into a coastal town whose damaged architecture is sustained by conscious human bearers. A useful restraint device reveals that the town has appropriated the instinct to catch a fall. In the climax, Ivo uses the same connection in reverse: an occupied relief hostel becomes an extension of his balance, and the building takes its first step.

The final action is not defeating a monster. Ivo makes the refuge mechanically safe, allows its inhabitants to leave, and releases the root restraint that has kept his mother suffering. Another survivor then holds an ordinary door open for him, voluntarily and briefly.

**Product baseline:** 225 minutes / 3 hours 45 minutes of first-playthrough active experience; nine chapters; one canonical ending; Windows PC first; controller and keyboard; offline play; 60 fps target at 1080p on the benchmark floor established at the vertical slice. A 30 fps cap must remain mechanically valid. The camera is directed, not player-rotated. All important geometry is 3D; locomotion is constrained to authored planes and connecting lanes.

## Duration and version authority

The brief contains a five-to-five-and-a-half-hour phrase and a final approximately “3.45 hours” phrase. This document follows the approved First Step concept and the final timing requirement: **3 hours 45 minutes, not 3.45 decimal hours and not a five-hour campaign**. Menus, pauses and credits do not count. The target median in fresh-player testing is 225 minutes, with a working acceptable median range of 210–240 minutes. Individual runs can be shorter or longer. Do not slow walking, lengthen waits or add redundant puzzles to meet a stopwatch.

This v3 master supersedes the earlier eight-chapter blueprint and stationary network-selection finale. Swimming, the air bell, paired balance stations, the nine-area route and the Walking Ward are now baseline features. Old room, asset, save and milestone IDs must not be merged blindly. This package uses a new namespace: SQ-CC-NN for sequence cards, PZ-NN for puzzles, CK-CC-NN for checkpoints and SYS-NN for systems. Display names can change; stable IDs cannot be recycled.

**Creative decisions are locked. Tuning is provisional.** Dimensions, speeds, breath timings, counts, budgets and milestone weeks below are explicit initial implementation values, not measurements of INSIDE and not results of an unbuilt game. A director may revise a value after testing, with its dependent fixtures and tests updated together. A document can authorize preproduction; only working builds can validate feel, fun, clarity, exact duration and performance.

## What is included and excluded

Included: vulnerable locomotion, one personal Hold, burden transfer, supports and latches, body-linked mechanisms, two grounded threat families, constrained swimming and buoyancy, an authored relocation machine, contextual animation, continuous streaming, persistent checkpoints, accessibility, localization-ready UI, a production register and release gates.

Excluded: combat progression, weapons, crafting, randomized loot, open-world backtracking, collectible-dependent endings, sanity meters, corruption points, unrestricted telekinesis, free-form city destruction, procedural levels, multiplayer, voiced exposition, photorealistic assets, mandatory ray tracing, a new rendering engine, and simultaneous mobile/console launch. Ports can be approved after the PC feature and performance envelope is understood.

A young protagonist does not imply a child audience. The game contains captivity, drowning danger, implied bodily integration, bereavement and institutional abuse. Failure animation must not linger on a child's injury. Ratings, content disclosures, rights and regional release requirements need qualified production review; no rating is promised here.

## Owners and authority

The game director owns the emotional and mechanical argument. The lead designer owns route clarity, puzzle causality and encounter fairness. The technical lead owns authoritative state and platform behavior. Art and audio leads own the sensory benchmark. The producer owns dependencies, staffing and gate decisions. QA provides reproducible evidence, not a substitute for design ownership.

Each sequence has one accountable designer and one assigned engineer. Art, animation, sound and QA sign off against the same card. A feature is not complete because its script compiles or its mesh looks finished in isolation. It is complete when its player-visible behavior, save state, accessibility, performance and failure recovery pass in a packaged build.

The master is the design contract; JSON/CSV registers are the structured mirror; the workbook is the tracking surface. After a tracker edit changes scope, update the master and structured source deliberately. There is no automatic two-way synchronization between Word, Excel and engine data. The included validator checks this delivered baseline, not future arbitrary edits.

# 02 | Reference research and translation

## What was checked

Research for this revision inspected Playdead's official gameplay stills, its before/after lighting example, model-design article, published animation presentation, character-audio slides including their state and breathing diagrams, performance/streaming presentation and Huddle/audio session descriptions. The official trailer endpoint was attempted but unavailable; a local motion-sample fetch also failed. This is not a claim to have run INSIDE, watched its complete campaign in this session, measured its controller or accessed proprietary code. [R01–R08]

The art target is the restrained game-rendered language in the user's references: broad masses, controlled surfaces, readable silhouettes, depth and directed light. Previously generated photorealistic-looking concept frames are **not** approved material benchmarks for this production. References are for analysis, not assets to ship.

## Evidence becomes a build requirement

| Observed reference principle | THE HELD production decision | Validation fixture |
|---|---|---|
| Playdead describes subtracting model detail until essential forms remain, preserving composition rather than adding high-contrast clutter. [R02] | Default props use simple silhouettes and restrained materials. Add detail only where scale, interaction or story requires it. | An untextured Laundry blockout must already communicate cart, route, bridge and threat. |
| Lighting was individually art-directed around the known side-on camera. [R01] | Each camera volume has a lighting/readability review. Use stock rendering with authored fill and selective effects rather than recreating Playdead's renderer. | Review the same shot in color, grayscale, low brightness and reduced-effects modes. |
| The animation presentation prioritizes immediate response while combining clips, contextual layers and anticipatory contact. [R03] | The gameplay motor owns travel. Animation and contact correction express weight without delaying valid input. | A jump, turn and rejected pull remain responsive while feet and hands reach their intended contacts. |
| The Huddle was produced through collaboration between animation, physics and specialized presentation. [R04] | Walking Ward movement uses an authored support graph and articulated rig; incidental physics adds consequence, not route authority. | The same support transition succeeds across frame rates and reloads while interior props respond believably. |
| Character audio uses a shared state, contextual footsteps, wetness and breathing feedback. [R05] | One Ivo presentation snapshot feeds animation, foley and breath. | A wet landing cannot play dry foley; pausing cannot desynchronize the breath pose. |
| The audio session connects sound, suspense and respawn continuity. [R06] | Mechanical phase, cues and ambience have explicit restart policies. | Retrying a chase does not resume a misleading cue from the failed state. |
| Playdead's performance material includes automated input playback and active streaming. [R07] | Record scripted test routes and profile packaged builds early. | Cold and warm runs through scene boundaries produce comparable mechanical states. |
| Small effects such as moving highlights and linked light changes support environmental events. [R08] | Each hero interaction has a restrained response bundle: tension, contact, nearby movement and sound. | Activation changes the target and its connected context, not a detached particle effect. |

These are translations, not instructions to reproduce an INSIDE room, dog chase, mind-control apparatus, submerged pursuer, Huddle silhouette or ending composition. The fictional explanation of INSIDE's ending is not settled here. THE HELD must answer its own causal questions without depending on a particular interpretation of another game.

## Hands-on reference capture task

In milestone M00, a designer, animator and engineer should capture a licensed local reference session. Review a running start/stop, reversal, ordinary jump, ledge contact, push, failed interaction, dog pursuit, human-control sequence, water transition, one destruction event, Huddle movement and final camera composition. Record controller action, visible response, information available before danger and restart cost. Separate observations from hypotheses.

Produce a short internal comparison against THE HELD's controller gym. Do not copy source animation, meshes, sound, staging or puzzle solutions. Do not turn approximate reference timings into immutable design laws. The outcome is a shared review vocabulary: contact, anticipation, authority, readable threat, consequence and recovery.

## Engine research boundary

The proposed baseline is Unity 6.3 LTS with C#, URP, Input System, Cinemachine, Timeline and local Addressables. Official documentation confirms the relevant workflows; package versions must be resolved together in M00 and committed to the lockfile, rather than assuming independently documented versions form a tested combination. [R09–R14]

At the research date, Unity lists 6.3 LTS support through December 2027. The proposed schedule can extend beyond that date. Reserve an engine-support review and a rehearsed upgrade branch before alpha. A current LTS recommendation is not a promise of support throughout the full project. [R09]

# 03 | Vision, narrative and character bible

## The dramatic thesis

**The game is about mistaking restraint for care.** Hold begins as an empowering shortcut. Its use exposes a person sustaining that shortcut. Its inverse lets Ivo carry a structure, but that power is frightening because people depend on his balance. Relief arrives when physical preparation removes the need for anyone to keep holding.

Five experience pillars govern production: readable physical causality; a vulnerable body with trustworthy controls; a continuous geography that changes the kind of play; conscious people rather than anonymous resources; and release earned through engineering. A scene that is impressive but does not support at least two pillars should be cut or redesigned.

The emotional progression is urgency, curiosity, unease, responsibility, dangerous competence, bodily vulnerability, grief, resolve, and imperfect relief. Intensity oscillates inside that progression. Darkness, enemy count and loudness do not need to rise continuously.

## Complete canonical history

The harbor town was damaged by a surge before Ivo was born. Emergency crews used balance-and-restraint apparatus to buy time for evacuation. Motors, hydraulic accumulators and counterweights supplied force. Living attendants supplied continuous correction through a fictional body-linked interface that appropriated the human impulse to brace against imbalance.

The temporary solution worked in some districts. Other repairs were postponed. Moving residents, abandoning valuable buildings and admitting that the emergency remained unfinished became institutionally unacceptable. The Relief Office replaced maintenance with substitutions: a tired bearer became another bearer, an exposed connection became a covered fitting, and temporary accommodation became permanent housing.

The apparatus does not decide policy and is not secretly omniscient. It responds to load and contact. Human institutions choose who must remain connected. Some Custodians are constrained workers; others knowingly enforce the arrangement. Their different actions remain visible. Bureaucracy is not presented as an excuse that absolves every participant.

The original sea surge has receded. A retained basin, damaged gates and unstable buildings remain dangerous. Rain and runoff replenish parts of the basin. The town cannot simply disconnect everyone at once; it needs supports, a safe discharge route and a moved refuge. The entire endgame makes those changes, rather than revealing that the danger was imaginary.

## Complete playable story

Ivo helps Anja repair a domestic safety fitting. She reassures him with two taps. An evacuation alarm draws them into a stairwell. A landing begins to fail; Anja Holds it so Ivo can cross. Custodians transfer her connection to a transport apparatus and take her below. Ivo initially believes she is being moved somewhere she can be relieved. He follows with a dropped portable brace.

The brace arrests a shutter and a rotating tread. In exposed gardens, Ivo learns that water needs a route and encounters the Braced Porter, an emergency retrieval rig whose procedure can become predatory. In the laundry he transfers a burden to a hidden anchor, solves hanging-space and wet-mass problems, and discovers a fingernail beneath porcelain.

At the passenger exchange, constrained people compensate for changes in a loaded deck while their eyes remain independent. Ivo realizes that the system has commandeered bodies without removing awareness. He learns to replace restraint with physical support and frees Orren. An exposed-harness Custodian remains conscious while immobilized.

Beneath the exchange, the chalk cutting exposes the enormous scale of the suspended loads. Ivo uses a paired balance cradle to guide a small maintenance carrier, learning that the connection can work in both directions. He deliberately allows a counterweight to fall into a receiving cradle and escapes the Porter again.

The original street lies underwater. Ivo learns to swim, travels with a guided maintenance bell that provides an air pocket, and survives the Porter attempting to return that shelter to a dock that is no longer safe. Draining a small room exposes the history of its repeated use. He enters the reverse side of the bearer network.

Familiar machine rhythms are now visibly connected to people. A linked domestic room moves with Ivo's balance. He finds Anja irreversibly incorporated into the root installation. She recognizes him and refuses the replacement position the system offers. He cannot restore her by releasing a harness: the physical conversion has already happened, and Hold cannot heal or reverse time.

Ivo changes his goal. He lowers a load onto an ordinary support, easing Anja's strain. At the seawall he sees the low, calm sea beyond the retained basin. He prepares a discharge channel, tests limited flow, and readies receiving pads for the occupied relief hostel. A familiar landmark with two uneven chimneys and a pale curtain must move out of danger before the root can be released.

Ivo enters its open maintenance cradle. His attempted step lifts a foundation shoe. The camera reveals that the whole occupied hostel is moving. Using the same controls learned on the carrier and domestic room, he carries it across an authored relocation route, adjusts its posture under a girder and lowers it onto permanent abutments. The survivors leave independently. The machine locks bear its weight; Ivo withdraws before permanent integration.

He returns through the short established service passage to Anja. With the refuge safe and the discharge prepared, the remaining root control is a governor, not the entire pressure of the basin. He takes it through the portable brace. Anja gives two taps and opens her hand. The player deliberately releases. Water follows the prepared channel; the root relaxes; Anja dies. Ivo escapes local settling structure.

At a dead exit fitting he reaches automatically for control. Orren instead holds the ordinary gate open for him. Ivo accepts another survivor's offered hand on the inland path. Their steps are not synchronized. The screen darkens after the player has walked the last few meters.

## Questions the game must answer

| Question | Canonical answer | Required evidence |
|---|---|---|
| Why does the town behave this way? | Continuous bodily correction sustains damaged machinery and structures. | Repeated mechanical posture and bearer posture match. |
| Who controls people? | The Relief Office assigns them; the apparatus enforces corrections. | An intentional capture procedure, visible connections and contrasting Custodian behavior. |
| Why is Ivo different? | He is unassigned, carries a portable service brace, knows ordinary repairs and chooses relief. He is not genetically chosen. | An adult uses equivalent equipment; no blood-test or prophecy reveal. |
| What is Hold really doing? | Connecting a person to an interrupted process, not stopping time. | Free dust and breath; external burden; reciprocal balance. |
| Can Anja be saved bodily? | No. Her root conversion is irreversible within established abilities. | Removable peripheral harnesses contrast with her incorporated root anatomy. |
| Why not release everything immediately? | Real retained water and unsupported structures would endanger the visible survivor group. | Unsafe limited test, then corrected discharge and supported refuge. |
| Did Ivo save the entire town? | No claim is made. He saves the established surviving cohort along his route. | The camera identifies the group and shows their escape; unseen districts remain outside the promise. |

The origin of the technology and the fate of distant districts may remain uncertain. The meaning of Ivo's final action must not.

## Character specifications

**Ivo / CHR-IVO.** Thirteen; initial scale 1.52 m; slight, ordinary proportions; uneven short dark hair. Ash-blue short work jacket, pale collar, charcoal cropped trousers and worn lace-up shoes. No red-shirt copy, luminous eyes or detailed photorealistic face. Brace on right forearm; left hand handles the two-tap gesture. His silhouette must read at approximately 100–170 screen pixels in normal shots. Curious gaze, anticipatory reach and hesitant touch communicate thought. Four additive strain levels affect shoulders, fingers and breath, never input timing.

**Anja / CHR-ANJA.** Maintenance worker and mother. Practical hair, rolled sleeves, double-stitched left cuff. She understands surface fittings and believes attendants are rotated; she has not knowingly selected permanent victims. Three forms share identity: domestic, transport harness and root presentation. The root is a purpose-built sculpt and rig, not a procedural mutilation system. Recognition depends on cuff and gesture, not graphic close-up injury or explanatory dialogue.

**Orren / CHR-ORREN.** Older repair worker with one missing coat button and a bent shoe. Freed at the exchange; glimpsed recovering near the hostel; helps another person during evacuation; holds the final gate. His continuity uses a few authored route segments, not a full-campaign escort. Never becomes an inventory companion.

**Custodians / CHR-CUST-A and B.** Human maintenance enforcers in padded emergency harnesses and waterproof workwear. One shielded and one exposed-contact variant share a skeleton. Worn faces and purposeful gestures, not copied blank masks. Threat is capture and forced placement. Covered contacts are physically inaccessible, not magically immune. At least one worker shows hesitation; another deliberately secures a captive, maintaining institutional accountability.

**Braced Porter / CHR-PORTER.** A human worker and a rail-mounted retrieval rig form one recognizable threat. Counterweights, hoses, cradle and mechanical reach create scale. Anatomy stays human. A breathing hose explains the flooded encounter. Same behavioral grammar in gardens, cutting and water; presentation and route constraints change. It does not teleport between rails.

**Bearers and survivors / CHR-BEARER-01 to 04.** Four base bodies/clothing sets with pose and prop variations. Twelve named production slots form the visible evacuation cohort; no dialogue names are required. Orren is one of those twelve. Other slots are recognized through an apron, repaired sleeve, headscarf, walking stick or folded blanket. Bodies may compensate together; attention remains individual. Add background resident cards where needed, never imply a mathematically complete city rescue.

**The root / CHR-ROOT.** Anja's sustaining apparatus, connective surfaces, tension bands and recognizably human hand. It has no separate monster will or combat behavior. It changes with load, not random emotional lighting.

**The Walking Ward / RIG-WARD.** A three-story relief hostel, two uneven chimneys, pale curtain, porch and relocation undercarriage. Its apparent body comes from foundations, hydraulic shoes and rooms adopting Ivo's posture. No eyes, organic legs, absorbed flesh, roar or combat attacks. Inhabitants remain people inside a moving place, not cells merged into a creature.

**Natural life / FAUNA-WADER and FISH.** One small wading-bird rig and a cheap fish-school presentation provide autonomous life. They react to actual motion and disturbance, not the brace merely being activated. They are not collectible companions or new threat families.

# 04 | Player, Hold and physical interaction contract

## The continuous loop

Read the composition; identify a route and interrupted process; test a reachable contact; manipulate or Hold; observe the consequence; assign or remove the burden; traverse; discover what that action meant. Short actions last seconds; a reasoning unit typically spans 1–3 minutes; a substantial puzzle can occupy 4–8 minutes including traversal and observation.

There is no modal inventory, journal screen or task list in default play. Contextual prompts appear for first-use actions and on prolonged inability to identify an available interaction. Optional reminders can be enabled. A prompt is attached to a valid action, not used to conceal unclear art.

## Input maps

| Action | Controller | Keyboard | Contract |
|---|---|---|---|
| Move | Left stick | A/D; W/S in water/station | Analog walk-to-run; constrained lane travel. |
| Jump / surface intent | South face | Space | Buffered jump on land; strong upward intent in water; not a new jump ability at stations. |
| Interact / grip | West face | E | Push, pull, operate, transfer or station lock; available action chosen deterministically. |
| Hold | Right trigger | Q or right mouse | Arrest current selected process; optional toggle mode. |
| Crouch / lower | Stick down | S | Land crouch; swim down; station posture lower. |
| Cycle candidate | Right shoulder | Tab | Only cycles valid nearby acquisition targets while no personal Hold is active. |
| Pause | Menu | Escape | Stops gameplay clocks, breath depletion and dangerous scripted progression. |

Station map: horizontal input requests travel; vertical input adjusts posture within the authored envelope; Hold arrests active articulation; Interact engages a nearby verified mechanical lock or exits when supported. No foot-order minigame. Menus and gameplay have separate action maps so closing a menu cannot also release a restraint.

All actions are remappable. Offer toggle Hold/grip, extended timing windows, breath assistance, interaction-contrast assistance, reduced camera motion, sound captions and independent dialogue/foley/music/ambience levels. The final release has a protected accessible equivalent described in section 19.

## Initial motor metrics

World units are meters. X is principal travel, Y vertical, Z depth. Lane splines may curve gently in depth; crossing lanes requires explicit connectors. No free camera rotation or unmarked Z wandering.

| Parameter | Initial value | Review rule |
|---|---:|---|
| Mesh / standing capsule height | 1.52 / 1.45 m | Validate hand, ledge and ceiling contacts with final proportions. |
| Capsule radius / crouch height | 0.22 / 0.88 m | Keep narrow passages visibly wider than the capsule. |
| Walk / run / crouch speed | 1.6 / 4.2 / 1.2 m/s | Analog control; no stamina economy. |
| Push / ladder speed | 0.85 / 1.4 m/s | Heavy items and ladders require free hands. |
| Ground acceleration / braking | 14 / 20 m/s² | Response begins immediately; animation supplies apparent effort. |
| Jump launch / gravity | 5.6 / 18 m/s² | Approximate ballistic rise 0.87 m and same-height travel 2.61 m before margins. |
| Routine gap / routine ledge grab | 2.0 / 1.15 m | Larger challenges require explicit context, moving support or catch animation. |
| Coyote / input buffer | 0.10 / 0.12 s | Evaluate against render-rate tests; never attributed to INSIDE. |
| Step / routine traversable slope | 0.25 m / 42° | Tag slides and lethal inclines separately. |
| Surface swim / dive speed | 2.1 / 1.9 m/s | Holding while swimming uses a one-arm variant at 1.55 m/s. |
| Shallow-water travel | Up to 2.4 m/s | Depth blend; avoid a discontinuous speed snap. |

The jump values imply t_air = 2v/g and h = v²/(2g); they are proposed calculations, not captured reference behavior. Do not build every gap at the numerical maximum. Preserve at least 0.3 m tolerance on ordinary jumps.

Motor states: Grounded, Crouched, Airborne, LedgeHang, Mantle, Ladder, PushPull, Wade, SurfaceSwim, Dive, Station, ScriptedContact and Failed. Each state declares whether movement, Hold and Interact are allowed. A fall becomes lethal only through a tagged landing/failure contract, not visual distance alone; ordinary high falls need clear staging. No unpredictable ragdoll decides whether a puzzle can continue.

## Hands, contacts and denied actions

A personal Hold occupies the brace arm. Ivo can move, crouch, jump, grab a one-handed edge and operate a one-hand latch while sustaining it. He cannot use a two-handed heavy grip, ordinary ladder or two-hand crank. When denied, he tests the object with his available hand and the obstructing part visibly resists. Never silently ignore the input.

Interaction selection uses eligibility first, then facing, reach, authored priority and stable ID as tie-break. Never choose solely by distance through a wall. Preview one candidate through gaze, reach and optional glyph. Lock the target during an active grip. Heavy props carry authored grip sockets and push rails; doors have known open arcs and blocked states. A player cannot drag critical props irretrievably into water or another scene.

## Hold invariants

H01: one personal process at a time. H02: only compatible connected contacts can be acquired. H03: time, awareness and unrelated motion continue. H04: Hold postpones; it does not repair. H05: transfers change ownership atomically. H06: mechanical supports can permanently remove a burden. H07: stationary paired interfaces expose reciprocal balance. H08: no hidden corruption or random malfunction. H09: menu/device events are not narrative release intent.

Acquisition starts within 3.2 m of an exposed contact, in the facing half-plane with clear acquisition visibility. A personal connection can be sustained within 6.0 m. A ceramic vane bends at 5.0 m and clicks at 5.7 m; crossing 6.0 m starts a 0.4-second warning before release. Re-entering cancels the warning. An established cable route can extend reach only where the level shows continuous conduit and the author explicitly enables that route. Do not invent wireless range to save a broken puzzle.

A personal target never changes while held. Failed acquisition produces a restrained click and gesture, not a success glow. An externally anchored burden persists after Ivo leaves range. An anchor accepts one defined burden; unavailable sockets visibly remain closed. An occupied anchor must not silently overwrite its existing bearer.

## Motion ownership and release

Important machinery is represented by authored coordinates q, velocity v, allowed range and driver. A slider may have q in meters; a hinge in degrees; a linked assembly can have a bounded route coordinate plus posture. On Hold, capture q and the configured resumable velocity. While held, do not integrate forces into an ever-growing hidden impulse. On release, resume the legal driver from the captured state with its specified acceleration and collision checks.

External changes still matter. A support inserted beneath a slab can intercept its released path; a drained counterweight changes the driver's next motion. A support-confirmed state may zero velocity and mark the process mechanically supported. This is not a time rewind. An impact already taken and damage already sustained remain.

Owners are FreeDriver, Personal, Anchor, Station or MechanicalSupport. Ownership is a transaction: validate destination and capacity, freeze authoritative progression, switch both references, publish one committed event, then update presentation. A transfer animation may blend over 0.2–0.35 seconds, but there is no frame in which neither owner sustains the load.

## Paired balance: same idea, opposite direction

The paired interface has two palm plates and a floor plate; it is visibly unlike a normal wall anchor. Enter only with free hands and no unresolved personal burden. The station owns a predeclared composite process, not an arbitrary set of world objects. Its motors and accumulators supply movement; Ivo supplies balancing corrections.

Horizontal input requests a forward or backward safe step along an authored path. Vertical input lowers or raises posture. Neutral completes only the current permitted settling action toward a nearby stable support; it cannot launch a new hazardous step. Hold immediately arrests the active phase, including an intermediate pose. Interact seats a verified physical lock. Exit is available only when the assembly is on a mechanical support or station parking clamp. Its visible release handle remains blocked otherwise.

The quarry carrier, domestic room and Walking Ward share this contract. Their scale and consequence change, not the number of buttons. Gait ordering is automatic; the player's problems are where to move, when to brace, what posture fits and whether a receiving support has actually engaged.

## Water and breath

Water is not stopped by Hold. The player restrains sluices, winches and guided floating machinery. Use bounded water volumes with authored levels, flow vectors and air-pocket overrides. Surface and underwater movement are genuine controllable states, not a cutscene or an invisible walking floor.

Initial breath capacity is 24 seconds at default settings. Known-route underwater legs should take 6–10 seconds; the late committed leg should remain under 13 seconds on a clean run. Recover at 8 seconds of reserve per second with the head in valid air. Wetness remains after leaving water. Warning behavior changes at 12, 18 and 22 seconds elapsed; the optional breath display conveys equivalent information without relying on hearing. Assistance doubles reserve without changing the story.

Submergence uses a head sample with 0.15 m spatial and 0.3-second temporal hysteresis. An air pocket requires the head to be inside its safe volume, not merely touching its outside collider. Save/resume in an air bell restores the bell, hose, guide, pocket and breath together. No checkpoint may spawn a novice in an immediately lethal dive.

## Failure, retries and persistent progress

Capture, crushing, a clearly lethal fall or breath exhaustion produce a short outcome and a rapid local reset. Target under three seconds to control when the relevant chunks are resident. Do not dwell on injury. Reset the current reasoning unit; keep an already completed support installation if the next chase failed.

There are no health potions, lives, penalty currency or moral scores. The player may experiment with a physically safe puzzle indefinitely. The game does not scold them for mandatory early transfers made before they understand the cost. Later scenes provide a genuine chance to remove burdens.

Important revelations are stateful. Reloading after a solve does not repeat Anja's entire recognition scene; restarting before it restores all contacts consistently. The finale's emotional actions are protected from focus loss, controller disconnect and menu input.

# 05 | Campaign topology, timing and storyboard use

## One place, nine kinds of play

Upper housing overlooks reclaimed allotments. Their drainage and supply lines lead into the communal laundry. Linen dispatch adjoins the passenger exchange. Transit counterweights descend into a chalk cutting. Beneath later construction lies the flooded original street. Its drained service access reaches the reverse side of domestic bearer infrastructure. Root conduits lead to the seawall, retained basin and relocation foundations of the relief hostel. After the hostel moves inland, an opened service culvert returns Ivo to the same root entity for the final handover.

The playable route is mostly left-to-right, with short local reversals, vertical connections and authored depth changes. A reversal needs a visible objective and different return state. No full-chapter backtracking. Optional alcoves rejoin within roughly 20–45 seconds and deepen already understandable information. There are no hidden essential endings or mandatory journal documents.

The hostel appears repeatedly through consistent geography: terrace overlook, garden chimneys, laundry vent, transit window, quarry underside, drowned-street opening and bearer-service aperture. Use one landmark reference rig and shared orientation sheet. A distant proxy is visual-only; it cannot own a second copy of the real Ward process. The pale curtain and two chimneys remain on the same facade throughout.

## Time is a design allocation, not a timer

The sequence cards allocate all 225 minutes. Their small actions are not meant to be stretched into long waits. Timings include initial orientation, exploration of adjacent spaces, physical experiments, retries and transitions. The first clean expert run will be shorter. Reject any quiet route that becomes empty walking for its allocated minutes.

Working campaign mix: 105 minutes puzzle reasoning and manipulation, 43 minutes traversal/exploration, 35 minutes threat/survival including ordinary retries, 30 minutes interactive narrative and environmental recognition, and 12 minutes transitions/recovery. These are proposed production allocations, not measured results; each live sequence should be tagged by actual activity during testing. Do not double-count a chase with a puzzle as both full durations.

A useful pacing review asks what changes every 2–5 minutes: the space, a physical relationship, player knowledge, a threat rule or the emotional interpretation of a familiar action. It does not require an entirely new mechanic every five minutes. No more than two adjacent reasoning units should ask the same question with different dressing.

The critical understanding chain is: direct Hold → external transfer → ordinary support → conscious restraint → reciprocal balance → moving safe air → irreversible root → tested discharge → occupied architecture → voluntary help. The route should remain comprehensible without remembering every intermediate object.

## Exact opening event direction

The opening is interactive. The following timings are event-relative targets, not instructions to move the player automatically.

| Event | Earliest presentation | Player authority | Completion condition |
|---|---|---|---|
| Kitchen resolves from darkness | 0–3 seconds | Input may be buffered during fade; locomotion available at approximately second 3. | Scene, input and camera initialized. |
| Spoon and Anja introduced | First 15 seconds | Player may move immediately; no required look lock. | Both fit in opening composition. |
| Chair investigation | Player approaches door | Grip/drag fully controlled; Anja continues a quiet repair loop. | Door clearance achieved. |
| Shared cover repair | Player chooses contact | Short contact alignment; ordinary movement resumes after latch seat. | Hands meet and cover is repaired. |
| Two taps | Immediately after contact | A brief hand action, never a lengthy movie scene. | Gesture is visible or its optional caption delivered. |
| Alarm and departure | On subsequent hall approach | Anja waits at the stair threshold. | Ivo enters following range. |
| Landing slip | Both reach load strip | Authored safe recovery then normal crossing. | Ivo is on far safe platform. |
| Custodian transfer | After successful crossing | Ivo can move within the far platform and observe. | Rig owns the load before Anja leaves plate. |
| Brace collection | Player interacts on reachable floor | Pickup contact only; no skill-tree screen. | Brace equipped and service opening available. |

Never advance a separation simply because the player spent a fixed number of seconds in the kitchen. The game must accommodate curiosity, accessibility settings and a player who pauses during the first scene.

## Sequence-card contract

Every following card contains an initial blockout, required actor families, starting state, three shot beats, an actual solution, threat/recovery behavior, a story consequence, audio direction, persistence and a test. Coordinates are local to the scene and are initial values. Blockout dimensions are length × height × depth; side-on travel is on z=0 unless specified. Designers can resize after testing while preserving dependencies and gameplay margins.

Shot A establishes the space; B contains the decisive interaction; C shows its consequence or transition. These are storyboard instructions for the level designer, camera designer and animator. They are not finished concept paintings or an animatic. A production storyboard pass must turn them into grayscale frames using the real blockout camera before final art is approved.

Each card's checkpoint ID identifies its principal safe entry. Additional mid-card safe snapshots use suffixes -A, -B and so forth in engine authoring. The save contract explains what must persist. A checkpoint is not permission to serialize inconsistent partial transactions.

The cards are detailed enough for greybox construction, but their acceptance tests remain unexecuted game tests. The included package validation checks names, links, totals and data shape; it does not claim that an engine build has passed them.

| Chapter | Campaign clock | Minutes | New relationship |
| --- | --- | --- | --- |
| C01 · The Upper Terrace | 0:00–0:18 | 18 | Direct Hold, trust in movement, first readable pursuit. |
| C02 · The Tidal Gardens | 0:18–0:40 | 22 | Flow diversion, environmental autonomy, load-sensing Porter. |
| C03 · The Laundryworks | 0:40–1:04 | 24 | Transfer, cloth visibility, wet mass and the porcelain reveal. |
| C04 · The Passenger Exchange | 1:04–1:29 | 25 | Compensating crowd, conscious restraint, independent relief. |
| C05 · The Counterweight Cut | 1:29–1:56 | 27 | Paired interface, controlled impact, repeated threat with new geometry. |
| C06 · The Drowned Street | 1:56–2:23 | 27 | Swim, air pocket, buoyancy, obsolete rescue route. |
| C07 · The Burden House | 2:23–2:50 | 27 | Recognized machine rhythms, room-scale balance, irreversible root conversion. |
| C08 · The Unfinished Sea | 2:50–3:15 | 25 | System-scale causality, tested discharge, receiving pads, open cradle. |
| C09 · The First Step | 3:15–3:45 | 30 | Occupied building control, kneeling evacuation, root release and voluntary help. |


# 06 | C01 — The Upper Terrace

**Target:** 18 minutes · campaign minutes 0–18. **Player question:** Where are they taking Mother?

**Visual identity:** Intimate ash-blue domestic rooms; damp stair concrete; one warm practical light.

**New experience:** Direct Hold, trust in movement, first readable pursuit. **Landmark continuity:** Hostel visible across the district at exit.

**Exit transition:** Service door opens onto wind and allotment roofs.


| Sequence / play focus | Target | Puzzle IDs |
| --- | --- | --- |
| SQ-01-01 · A small thing that will not stay still | 4 min | PZ-01 |
| SQ-01-02 · The landing that cannot be released | 5 min | Narrative / traversal |
| SQ-01-03 · The shutter and the rotating tread | 5 min | PZ-02, PZ-03 |
| SQ-01-04 · A door between two bodies | 4 min | PZ-04 |


**Chapter review:** confirm the new physical relationship is taught before threat, the landmark stays geographically consistent, and the exit preserves established facts. Review every A/B/C composition at gameplay distance before final art. The following pages are one-sequence build cards; their whitespace is available for team annotations.


## SQ-01-01 | A small thing that will not stay still

**Campaign 0:00–0:04 · 4 min · PZ-01 · CK-01-01**


**Blockout.** Kitchen 10 × 3.6 × 5 m, playable lane z=0. Chair at x=2.8, door x=4.0, fitting x=6.0 at hand height 1.05. A cup sits in the near background, not on the collision route.


**Initial state.** No brace. Door obstructed by a light chair constrained to a 1.2 m drag rail. Anja waits at the fitting. Spoon vibration is cosmetic and runs on an independent ambient phase.


**Storyboard A / B / C.** A / Opening side-on frame; Ivo on left third, Anja center-right, moving washing outside a dark window. Directional control is live at approximately second 3. B / Camera follows only after he moves; chair and blocked door share the frame. C / A small push-in at the fitting reveals the two-tap contact while keeping Ivo controllable after the hand animation.


**Player action and solution.** Move to the chair; hold Interact and drag left until the door clearance strip is exposed. Release grip, pass the door and approach the low cover Anja is holding. Interact steadies the cover for a brief contextual hand contact; Anja replaces its latch. The response commits when the hands meet, not after a long uninterruptible flourish. Two taps occur on contact; waiting elsewhere does not advance the evacuation. Afterward the alarm can begin when Ivo turns toward the hall. No pixel-sized pick-up item or cabinet search.


**Threat, failure and recovery.** Nonlethal. The chair cannot tip into a softlock or be pushed through the exit. Anja has wait, look and repair loops rather than repeating a greeting. Repeated interaction plays a small acknowledgement, not another full scene.


**Narrative consequence.** Makes repair and temporary voluntary help familiar. The spoon, cuff and two taps are recurring identifiers, not clues that require a journal.


**Audio direction.** Close cloth, cup tick and restrained domestic rain. No score swell. Anja has nonverbal exertion only. The alarm initially belongs to another part of the building.


**Checkpoint / save contract.** Entry canonical checkpoint; on cover completion save DoorClear, CoverLatched and TwoTapsSeen together. Respawn is beside the cleared doorway, never with the chair intersecting Ivo.


**Exit / transition.** Anja opens the stair door once Ivo approaches. Atmosphere blends to stair acoustics; no fade or chapter title.


**Acceptance test.** Fresh tester finds the door obstruction without a prompt in 60 seconds; alternate keyboard/controller inputs do not double-fire the cover event. Idling five minutes leaves a coherent scene.


**Required asset families:** CHR-IVO, CHR-ANJA, ENV-TERRACE, PRP-CHAIR, PRP-CUP, GME-WALL-FITTING.


## SQ-01-02 | The landing that cannot be released

**Campaign 0:04–0:09 · 5 min · Narrative / traversal · CK-01-02**


**Blockout.** Stair shaft 18 × 9 × 6 m. Safe near platform x=0–5, hinged landing x=5–10, far ledge x=10–14. Transport doorway in background z=3, reached by a visible rail path.


**Initial state.** Landing appears intact until both characters reach the marked load strip. Anja owns the emergency connection after its initial 0.35 m drop. Transfer rig is present above but not yet in view.


**Storyboard A / B / C.** A / Ivo and Anja descend together; a slight vertical reframe exposes space below the landing before it moves. B / Anja catches Ivo’s wrist and the plate in one continuous action; no cut to a separate movie angle. C / After Ivo crosses, the camera stays on his side while Custodians take Anja into depth. Her cuff and two taps on the railing remain visible.


**Player action and solution.** Follow Anja, recover from the authored slip and cross the arrested landing using ordinary movement. The landing is broad; this is not a precision jump during a relationship beat. At the far side a half-open service barrier keeps Ivo from following the transport directly, but its accessible lower route remains visible. Custodians connect the rig before removing Anja from the plate, preserving ownership. A service brace falls to a reachable floor stop. Interact picks it up; the wrist-fit animation is brief and leads into a safe test reach.


**Threat, failure and recovery.** The first landing slip cannot randomly kill Ivo. After the separation, the barrier is a physical obstruction rather than an invisible wall. Mother waits if Ivo has not crossed; transport cannot depart with him stranded on the unsafe side.


**Narrative consequence.** Ivo believes he is following a rescue procedure. A Custodian deliberately secures the harness rather than repairing the damage. We do not explain the root yet.


**Audio direction.** Metal strain starts before displacement. Anja’s breath continues during Hold. Wheel clicks move away in depth; no villain sting. Brace pickup has a modest ceramic click, not a power-up sound.


**Checkpoint / save contract.** Commit AnjaTaken and BraceOwned only after the rig is clear and the brace attached. A quit during transfer resumes the coherent pre-transfer or post-transfer checkpoint; never half a transaction.


**Exit / transition.** Ivo enters a lower service opening beneath the transport route. The next shutter can be seen cycling from safety.


**Acceptance test.** Player can neither retrieve Anja through geometry nor lose the brace. Interrupt every transfer frame with pause/restart in testing; ownership and narrative phase remain valid.


**Required asset families:** CHR-IVO, CHR-ANJA, CHR-CUST-A, RIG-TRANSPORT, GME-LANDING, GME-BRACE, ENV-TERRACE.


## SQ-01-03 | The shutter and the rotating tread

**Campaign 0:09–0:14 · 5 min · PZ-02, PZ-03 · CK-01-03**


**Blockout.** Service corridor 30 × 6 × 5 m. Shutter at x=8, contact x=6.8 y=1.1. Beyond it, a 2.0 m radius maintenance tread rotates beside a 1.8 m gap at x=20. Targets never overlap acquisition cones.


**Initial state.** Shutter cycles on an 8 s period, including 2.5 s fully open. Tread rotates slowly through four readable step orientations. Both have local motors and exposed contacts; neither is anchored externally.


**Storyboard A / B / C.** A / Fixed reasoning frame includes the shutter, contact and safe recess. B / On arrest, dust falls through the unmoving shutter silhouette. C / Past the shutter, the camera reveals the full tread and destination before allowing the gap to become a hazard.


**Player action and solution.** Observe at least part of the shutter cycle from the recess. Acquire while it is above Ivo’s clearance, cross within the sustain radius and release. On the tread, arrest when its flat platform faces upward and aligns with the far ledge. Jump onto it and across a routine gap. The second use changes the problem from timing an opening to selecting an orientation. A small wrist after-motion follows release without changing locomotion. If the player arrests too low or at a poor angle, they can release and retry safely.


**Threat, failure and recovery.** Crush zones are attached to moving edges and only active while the sweep threatens Ivo. Tread falls reset locally. No first-use lethal event before the player can see a full cycle. Target selection does not switch midway through Hold.


**Narrative consequence.** The tool genuinely works. The body’s residual posture hints that the connection is not merely a battery. Unrelated dust establishes the no-time-freeze rule.


**Audio direction.** Motor sound loses its motion component while held; a residual load tone remains. Foot contacts match metal and stone. The wrist after-motion has a tiny jacket and brace creak.


**Checkpoint / save contract.** Checkpoint after the shutter and before the tread preserves BraceOwned and the solved shutter clearance. Tread phase resets to the same readable start; shutter is not re-solved after a later fall.


**Exit / transition.** A high opening silhouettes a Custodian approaching the service stair. The corridor continues directly into the pursuit.


**Acceptance test.** Ten attempts at 30/60/120 fps preserve clearance. Wrong-angle arrests are recoverable. A tester can explain that only the selected mechanism stops.


**Required asset families:** CHR-IVO, GME-BRACE, GME-SHUTTER, GME-ROTATOR, ENV-SERVICE, FX-DUST.


## SQ-01-04 | A door between two bodies

**Campaign 0:14–0:18 · 4 min · PZ-04 · CK-01-04**


**Blockout.** Pursuit corridor 42 × 7 × 6 m. Guard entry stair visible at x=8, Ivo starts x=13. Exit shutter x=30 with contact x=28; release recess x=33; exterior threshold x=39.


**Initial state.** Custodian begins on an upper stair and needs 3.5 s of visible approach before entering the player lane. Door follows the same motion family learned immediately before.


**Storyboard A / B / C.** A / Wide enough to show the descending guard and the route ahead. B / Camera leads right before Ivo reaches the door, keeping the contact out of silhouette tangency. C / The guard catches the released door briefly behind Ivo; wind opens the image beyond the exit.


**Player action and solution.** Run to the contact, arrest the door above head height, pass through and release from the far recess. Release lets the door close between Ivo and the worker. The worker’s catch is an authored reaction that delays closure visually but does not reverse the successful solution. Move through the outer service opening. The player does not need to wait for the guard to nearly touch them. A too-early Hold can be released while behind a short safe obstruction, providing a second chance.


**Threat, failure and recovery.** Capture requires a real approach and swept contact, not a camera trigger. Guard speed is tuned below Ivo’s full run with a head start; no hidden teleport or late rubber-band. A failure resets to the pursuit start, not the preceding tread.


**Narrative consequence.** Ivo learns that the Custodian is a physical person with strength and limitations. The route is escape from a procedure, not combat victory.


**Audio direction.** Footsteps descend from above into the same acoustic space. Door strain masks the guard only after he is blocked. Exterior wind replaces corridor resonance over the threshold.


**Checkpoint / save contract.** Entry pursuit snapshot has guard at top of stair and door at known phase. DoorBlocked is saved only after Ivo is in the exterior-safe zone. Repeated restart does not duplicate a second guard.


**Exit / transition.** Camera widens onto allotments and the hostel’s two uneven chimneys. No title card; player still holds directional control.


**Acceptance test.** First-time players see both route and pursuer before danger. Median replay cost after a capture remains under 35 s. Fast players cannot outrun asset streaming.


**Required asset families:** CHR-IVO, CHR-CUST-A, GME-SHUTTER, ENV-SERVICE, ENV-GARDENS.


# 07 | C02 — The Tidal Gardens

**Target:** 22 minutes · campaign minutes 18–40. **Player question:** Why does safety equipment hunt a child?

**Visual identity:** Horizontal reed screens, salt earth, wind and open gray sky.

**New experience:** Flow diversion, environmental autonomy, load-sensing Porter. **Landmark continuity:** Two uneven hostel chimneys beyond vegetable beds.

**Exit transition:** Runoff culvert rises into laundry ventilation.


| Sequence / play focus | Target | Puzzle IDs |
| --- | --- | --- |
| SQ-02-01 · Wind has no owner | 5 min | PZ-05 |
| SQ-02-02 · Give the water somewhere to go | 6 min | PZ-06 |
| SQ-02-03 · The apparatus that catches falling things | 6 min | PZ-07 |
| SQ-02-04 · The people above the drain | 5 min | Narrative / traversal |


**Chapter review:** confirm the new physical relationship is taught before threat, the landmark stays geographically consistent, and the exit preserves established facts. Review every A/B/C composition at gameplay distance before final art. The following pages are one-sequence build cards; their whitespace is available for team annotations.


## SQ-02-01 | Wind has no owner

**Campaign 0:18–0:23 · 5 min · PZ-05 · CK-02-01**


**Blockout.** Exposed allotment strip 65 × 9 × 14 m. Three raised beds, one 1.8 m drainage gap and a hinged windscreen at x=31. Background hostel at z=65; bird on a disconnected channel shelf.


**Initial state.** Wind screens not attached to apparatus move freely. One civic hinged panel is connected to a restraint socket and swings through a safe traverse pose. Bird has idle, forage and flee states.


**Storyboard A / B / C.** A / Horizontal long view with open sky; Ivo small but not lost in reeds. B / The panel’s sweep and opposite bank share a stable frame. C / A bird reacts only when the panel actually moves, while fog reveals the hostel chimneys behind it.


**Player action and solution.** Follow the raised path, crouch beneath a low screen and reach the connected panel. Arrest it near horizontal, step onto its broad face and cross the gap. Release after reaching stone. A noncritical loose screen keeps swaying while the held one stays still. The path then loops around a low bed to give a view back at the panel and bird. This is a short traversal idea, not another multi-stage shutter puzzle; the time includes breathing room and exploration of a visible side alcove.


**Threat, failure and recovery.** The first poor arrest drops the panel toward a shallow recoverable ledge rather than an instant death. Critical ground edges are not hidden by foreground reeds. Bird behavior does not introduce a stealth penalty.


**Narrative consequence.** Natural life exists outside the system. The machine does not suspend all reality. The recurring hostel is introduced as an ordinary place, not highlighted as a future creature.


**Audio direction.** Wind in three texture layers, reed knocks, distant metal settling and one bird call. No music cue on the landmark. Cold air changes Ivo’s breath effort modestly.


**Checkpoint / save contract.** Save at stable stone before and after the panel. Bird state may be reconstructed from an ambient seed; panel phase and personal ownership must be exact.


**Exit / transition.** Water running through a raised bed leads the player toward the sluice without an objective arrow.


**Acceptance test.** A grayscale review keeps the panel distinct from decorative screens. Muting audio does not obscure the moving hazard. Hold never affects the bird or wind cloth.


**Required asset families:** CHR-IVO, ENV-GARDENS, GME-WINDSCREEN, FAUNA-WADER, FX-WIND, PRP-REED-SCREEN.


## SQ-02-02 | Give the water somewhere to go

**Campaign 0:23–0:29 · 6 min · PZ-06 · CK-02-02**


**Blockout.** Garden channel 34 × 6 × 12 m. Upper sluice x=7, diversion handle x=12 on high ledge, guided float x=18–24, destination lip x=27. Side channel clearly descends away from the float basin.


**Initial state.** Holding the main sluice closed raises upstream water and drives the float against an overhead stop, too high to use. Side drain starts closed. The float is rail-guided and cannot drift into a softlock.


**Storyboard A / B / C.** A / Show incoming water and the float before the player acts. B / A higher side handle and its channel remain visible during the failed simple solution. C / Successful diversion reveals a lower pale water mark as the float settles to the crossing height.


**Player action and solution.** Arrest the main sluice briefly to observe that preserving stillness makes the float less useful. Release, climb the safe side ledge and open the diversion. Water now leaves the basin through the side channel; the float lowers to its guided lower stop. Arrest the sluice in its open-clear state only if needed to pass the narrow service throat, then cross on the stable float. The side handle latches mechanically, so no second personal Hold is required. The system is a small volume-transfer graph with bounded level change, not unrestricted fluid simulation.


**Threat, failure and recovery.** A wrong order raises water toward a visibly marked overflow, then stabilizes; it does not unexpectedly flood the entire chapter. Ivo can return to the ledge. Falls land in a shallow recovery pool.


**Narrative consequence.** The first explicit lesson that resolving a process differs from stopping it. Old high flood marks remain above current water; no exposition explains them.


**Audio direction.** Inlet, overflow and diverted trickle have distinct locations. Water-level changes are slow enough to read. The moving float creaks against its guide before reaching a stop.


**Checkpoint / save contract.** Persist DiversionOpen and basin target state at the exit checkpoint. Mid-puzzle death restores a coherent level/float combination. Do not save a float transform independently of its water driver.


**Exit / transition.** A supply sack travels overhead toward a loading grate and draws the eye to the next apparatus.


**Acceptance test.** The player can infer the bad consequence of the initial Hold from the same shot. Solving by releasing early remains legal. Water volumes and float never overlap Ivo into a wall.


**Required asset families:** CHR-IVO, ENV-GARDENS, GME-SLUICE, GME-FLOAT, GME-DIVERSION, FX-WATER-FLOW.


## SQ-02-03 | The apparatus that catches falling things

**Campaign 0:29–0:35 · 6 min · PZ-07 · CK-02-03**


**Blockout.** Loading terrace 40 × 10 × 12 m. Porter rail overhead y=6, connected floor grate x=13–23, disconnected stone refuges x=9 and 27. Capture reach 3.2 m beneath current carriage; exit underpass x=32.


**Initial state.** A sack is ready to fall into a safe demonstration zone. Porter carriage begins parked above it. Detection grates have a visible cable path to the rail. Stone refuges are disconnected.


**Storyboard A / B / C.** A / Frame the falling sack and the rig’s catch while Ivo is safe. B / Let the padded cradle open slowly, revealing the worker as the apparatus returns. C / On Ivo’s first grate step, the carriage turns; the next refuge is already on screen.


**Player action and solution.** Watch or move through the nonblocking sack demonstration. Step onto the connected grate; its flex produces a load signal and the Porter searches the reachable zone. Retreat to stone if necessary. Reach the exposed drive contact, arrest the active carriage long enough to cross the first span, then release from a refuge. Cross the final span during its return stroke and crouch into the underpass. Hold targets the carriage drive, not the worker’s thoughts. The player can read reach through the physical rig and its guide shadow.


**Threat, failure and recovery.** Detection precedes capture by a visible orient-and-reach sequence of at least 1.2 s. The first grate is recoverable by stepping back. No offscreen instant capture. Restart preserves the observed sack demonstration fact and restores the rig parked.


**Narrative consequence.** A rescue process becomes dangerous when it treats Ivo as an unsupported load. Its padded equipment is more unsettling than a predatory animal replacement.


**Audio direction.** Rail wheel, tension ratchet, worker breath and cradle fabric. A bell-like confirmation belongs to the retrieval procedure, not a jump-scare sting. Load transmission has a matching grate flex.


**Checkpoint / save contract.** Checkpoint before the grate; SackDemoSeen persists. Porter drive phase, route position and capture state reset together. The sack is excluded from repeat collision once the demo completes.


**Exit / transition.** Ivo drops into a drainage corridor too low for the rig. Its rail visibly continues toward the industrial district, explaining later reappearance.


**Acceptance test.** A novice can state why stone is safer than grating. Holding indefinitely does not let the target switch. The rig cannot reach through the stone refuge or leave its rail.


**Required asset families:** CHR-IVO, CHR-PORTER, RIG-PORTER, GME-PORTER-DRIVE, PRP-SACK, ENV-GARDENS, FX-CABLE.


## SQ-02-04 | The people above the drain

**Campaign 0:35–0:40 · 5 min · Narrative / traversal · CK-02-04**


**Blockout.** Culvert 70 × 4 × 9 m with two low crouch sections and one shallow vertical climb. Ceiling grilles reveal occupied public ground at z=3; laundry intake visible ahead.


**Initial state.** No active enemy in the player lane. Residents have bounded ambient routes. One support pulse is triggered by Ivo crossing a clear view volume, then becomes an ambient low-frequency behavior.


**Storyboard A / B / C.** A / Low camera follows Ivo beneath feet and grocery bags. B / A brief stationary frame aligns a flexing support with residents steadying themselves above; their attention never turns down. C / Gradual upward camera move follows a service ladder toward hanging fabric and warmer vapor.


**Player action and solution.** Crouch under a root cable, pull a light grate cover aside and climb the short ladder. This section provides recovery and observation, not a disguised five-minute corridor: include a small optional dry shelf that exposes the same support from its reverse side and rejoins in seconds. Required traversal is compact; timing assumes cautious looking and the first impression of occupied life. All critical hands are free; no retained personal Hold is necessary.


**Threat, failure and recovery.** No surprise attack after the chase. A dripped-on pipe may sound human but has a visible source when approached. Avoid making every silence a setup for a jump scare.


**Narrative consequence.** Residents have adapted to the town’s instability. Their normality makes the hidden cost plausible. A supply route links gardens and laundry into one place.


**Audio direction.** Muffled ordinary feet overhead, bags brushing railings, drain water and growing ventilation tone. The Porter’s ratchet disappears before the first quiet pause.


**Checkpoint / save contract.** Store chapter progress at the dry ladder base and laundry threshold. Ambient residents reconstruct from safe poses. Their schedules cannot block the route or advance unseen narrative facts.


**Exit / transition.** Ivo emerges behind linen baskets. A laundry worker demonstrates a surface fitting in the distance as the player approaches the first transfer puzzle.


**Acceptance test.** No tester should spend more than 90 s looking for the ladder after reaching its room. Optional observation does not hide mandatory story comprehension. No chapter-loading hitch at the vent transition.


**Required asset families:** CHR-IVO, ENV-CULVERT, CHR-RESIDENTS, PRP-GROCERY, FX-DRIPS, ENV-LAUNDRY.


# 08 | C03 — The Laundryworks

**Target:** 24 minutes · campaign minutes 40–64. **Player question:** Who keeps an anchored burden still?

**Visual identity:** Hanging fabric layers, matte concrete, quiet amber task lighting.

**New experience:** Transfer, cloth visibility, wet mass and the porcelain reveal. **Landmark continuity:** Hostel curtain glimpsed through a high exterior vent.

**Exit transition:** Linen dispatch tunnel enters the passenger exchange.


| Sequence / play focus | Target | Puzzle IDs |
| --- | --- | --- |
| SQ-03-01 · Leave the effort behind | 6 min | PZ-08 |
| SQ-03-02 · The hanging corridor | 6 min | PZ-09 |
| SQ-03-03 · The weight of wet cloth | 6 min | PZ-10 |
| SQ-03-04 · A cover, not a machine | 6 min | Narrative / traversal |


**Chapter review:** confirm the new physical relationship is taught before threat, the landmark stays geographically consistent, and the exit preserves established facts. Review every A/B/C composition at gameplay distance before final art. The following pages are one-sequence build cards; their whitespace is available for team annotations.


## SQ-03-01 | Leave the effort behind

**Campaign 0:40–0:46 · 6 min · PZ-08 · CK-03-01**


**Blockout.** Laundry bridge room 32 × 12 × 18 m. Near platform x=0–9, tilting bridge x=9–17, far platform x=17–27. Anchor x=7.2; release lever on far platform. Conduit runs visibly from anchor to bridge.


**Initial state.** Bridge hangs too steeply to traverse. Holding it level prevents Ivo from operating the two-handed far lever after crossing. Nearby anchor is available; its hidden bearer is not visible.


**Storyboard A / B / C.** A / Entire bridge and far destination shown through sheets; an adult worker in depth uses a portable-equivalent contact, disproving chosen-child implications. B / Close enough for the anchor vane, with no full cinematic cut. C / Hold remains on the bridge after Ivo walks away; the camera does not immediately reveal its source.


**Player action and solution.** Operate the one-hand bridge release, let it settle toward level and arrest it. At the near anchor, Interact transfers ownership. The brace hand relaxes while the anchor vane closes. Cross the supported bridge with both hands now free, turn the far two-hand lever to seat a receiving pin, then disengage the anchor through a visible return linkage. The bridge remains level on metal. Crossing without transfer is possible, but the far lever rejects a one-hand attempt with an informative animation. The player can return without losing the bridge.


**Threat, failure and recovery.** Wrong-angle anchoring is reversible from either side using the return linkage. The bridge cannot permanently seal the player below it. Initial bridge movement has no enemy pressure.


**Narrative consequence.** Transfer feels like relief before the concealed bearer’s breath unsettles it. The first major slice puzzle contains both assignment and removal of burden.


**Audio direction.** Local brace effort migrates to a wall breath when ownership transfers. A solid pin seating sound differs from an active strain hum. No magic beam.


**Checkpoint / save contract.** Capture bridge q, owner and pin state together. Exit checkpoint requires pin seated and no personal Hold. Hidden bearer strain matches ownership after reload.


**Exit / transition.** The bridge opens onto the overlapping hanging frames, carrying the player directly into spatial manipulation and stealth.


**Acceptance test.** At least four of five fresh testers distinguish personal Hold, anchor and mechanical support after play. Zero ownership gaps across 1,000 automated transfer attempts.


**Required asset families:** CHR-IVO, ENV-LAUNDRY, GME-BRIDGE, GME-ANCHOR, GME-LEVER, PRP-LAUNDRY-CART, CHR-BEARER-01.


## SQ-03-02 | The hanging corridor

**Campaign 0:46–0:52 · 6 min · PZ-09 · CK-03-02**


**Blockout.** Drying hall 44 × 14 × 20 m. Two parallel gameplay-safe paths at y=0 and y=2.4, linked by one ladder. Three sliding frames on independent 6 m rails; wet-sheet and thick-blanket cover zones explicitly placed.


**Initial state.** Frame A blocks the low route; frame B provides the climb but slides back unless anchored. Frame C controls a sightline. Custodian enters only after Ivo has seen his own silhouette through a wet sheet.


**Storyboard A / B / C.** A / Stable wide shot shows the low obstruction and upper return route. B / Ivo’s silhouette appears through a lit wet sheet with no enemy present. C / A searchlight later passes the same screen; the thick blanket stays opaque, showing the difference visually.


**Player action and solution.** Push frame A to its stop, freeing the lower passage. Arrest and anchor frame B at ladder alignment, climb, and release frame C’s latch to hang a thick blanket across the search angle. Cross the upper ledge while the light moves behind the opaque layer. Descend to the far side and latch frame B mechanically through a low pull cord, removing its anchor burden. The spatial route and concealment arrangement form one puzzle; do not require rhythmic button tapping or an invisible stealth meter.


**Threat, failure and recovery.** The Custodian detects exposure through tagged thin material but not thick cover, matching the rendered silhouettes. A wrong arrangement provides retreat before capture. Restart at the search approach preserves the solved frame positioning, not an entire re-push sequence.


**Narrative consequence.** Ordinary domestic material becomes spatial language. The hidden burden remains present through wall strain; the player can relieve it rather than leave it active forever.


**Audio direction.** Wet cloth slaps softly; thick blankets absorb high frequencies. Search footsteps remain directional. Audio hints support, but do not substitute for, visible light and cover.


**Checkpoint / save contract.** Save frame positions, latch states, cover tags, guard entry phase and B owner. Never rely on cloth simulation to recreate occlusion after reload.


**Exit / transition.** A rinse outlet ahead pours onto a small counterweight basket, previewing the next material-state puzzle.


**Acceptance test.** Occlusion tags agree with the image at all supported effects settings. Player never loses the critical landing behind a foreground sheet. Three consecutive failed attempts do not replay a solved manipulation.


**Required asset families:** CHR-IVO, ENV-LAUNDRY, GME-DRYING-FRAME, GME-ANCHOR, CHR-CUST-A, PRP-SHEET, PRP-BLANKET.


## SQ-03-03 | The weight of wet cloth

**Campaign 0:52–0:58 · 6 min · PZ-10 · CK-03-03**


**Blockout.** Rinse-lift chamber 30 × 11 × 14 m. Dry rack x=8, lift x=17, overhead rinse spout x=9, lower drain handle x=23. Lift has top, crossing and service stops with visible notches.


**Initial state.** Dry rack mass is below the lift’s counterbalance threshold. Wetness scalar begins at 0. The inlet can be directed onto the rack; lower drain access requires the mid-height crossing.


**Storyboard A / B / C.** A / Frame both weights of the system with their cable crossing visible. B / Water darkens blankets and the rack visibly settles. C / The changed lift height exposes the lower drain passage instead of merely opening a generic door.


**Player action and solution.** Rotate the rinse spout toward the rack using a one-hand handle. Water increases its authored mass from dry to saturated over 8 seconds; the counterbalanced lift descends. Arrest at the marked crossing notch and transfer to the nearby anchor. Cross the lift to reach the drain, then close the inlet and open the rack drain. Reduced mass pulls the lift upward, but a mechanical service catch now intercepts it and opens the lower crawl route. Release the anchor only after the catch is seated. One scalar controls visual wetness, weight and drip rate.


**Threat, failure and recovery.** Overflow is safe and bounded. The rack is guided; cloth simulation cannot change its physical mass or catch in the lift. An incorrect stop can be released and retried from either bank. A support indicator prevents an ambiguous release.


**Narrative consequence.** The player enjoys predicting a material behavior. The darker implication appears only through the transferred strain, not a separate cutscene.


**Audio direction.** Dry cloth, saturation trickle, heavier cable creak and a dwindling drain. The bearer’s breath follows strain but is mixed below the puzzle’s functional cues.


**Checkpoint / save contract.** Store wetness scalar, inlet/drain states, lift q, anchor owner and service catch. Checkpoint after the catch; wetness resumes from authored state, not wall-clock elapsed time.


**Exit / transition.** The crawl route places Ivo close to a damaged porcelain fitting while the solved machinery remains audible behind him.


**Acceptance test.** Player can identify why wetness matters without a numeric weight label. No double-Hold solution is required. Saving at every quarter of saturation reconstructs matching height and audio.


**Required asset families:** CHR-IVO, ENV-LAUNDRY, GME-WET-RACK, GME-LIFT, GME-RINSE, GME-ANCHOR, FX-WATER-FLOW.


## SQ-03-04 | A cover, not a machine

**Campaign 0:58–1:04 · 6 min · Narrative / traversal · CK-03-04**


**Blockout.** Narrow maintenance return 58 × 5 × 7 m, one body-width squeeze at x=24. Damaged fitting at x=26 y=1.05; linen dispatch exit x=51. Optional alcove shows old replaced covers.


**Initial state.** A cover is already chipped. The story hand has independent finger and breath motion; it is not a dismembered pick-up or enemy. Only one reveal can commit.


**Storyboard A / B / C.** A / Ivo squeezes sideways through a believable maintenance gap. B / His sleeve brushes the chipped fitting; a small shard falls with the camera at gameplay distance. C / As he turns toward the dispatch passage, a fingernail flexes beneath the cover. The framing gives enough contrast without a zoom into gore.


**Player action and solution.** Use ordinary movement and the contextual squeeze; the player retains forward/back intent during approach and can pause after the contact. A short one-hand lift of a loose cover permits a clearer optional view but is not required for comprehension. Continue through a linen chute with a controllable ladder descent. The section includes a safe observation loop and a small service door lift, not a six-minute uninteractive reveal. The first transfer sound returns from the now-revealed wall.


**Threat, failure and recovery.** No attack or chase follows the finger. Do not train the player to distrust every quiet inspection. Shard collision is cosmetic; it cannot obstruct the narrow exit. The squeeze has a safe cancel point before entry.


**Narrative consequence.** Porcelain is a housing for a connection to a person. This is the first undeniable physical hint, not the full reverse-side explanation.


**Audio direction.** One dry ceramic tick, a joint movement in the familiar drum rhythm, distant linen wheels. Remove the low musical layer briefly without muting the room.


**Checkpoint / save contract.** FingernailSeen persists after the interaction threshold. Re-entering plays idle hand motion, not another shard break. Save player on either side of the squeeze, never embedded halfway.


**Exit / transition.** A dispatch hatch opens into ordered transit architecture. Cool daylight replaces the close laundry task light.


**Acceptance test.** At least four of five first-time viewers notice an organic detail, without needing to identify whose hand. Low-vision contrast mode preserves its meaning. The scene remains unsettling without a sting.


**Required asset families:** CHR-IVO, ENV-SERVICE, GME-WALL-FITTING, CHR-BEARER-HAND, PRP-PORCELAIN-SHARD, FX-DUST.


# 09 | C04 — The Passenger Exchange

**Target:** 25 minutes · campaign minutes 64–89. **Player question:** Can a person be controlled and still be aware?

**Visual identity:** Ordered public geometry; pale concourse over dark occupied waiting rails.

**New experience:** Compensating crowd, conscious restraint, independent relief. **Landmark continuity:** Hostel facade appears beyond a tram terminal window.

**Exit transition:** Maintenance stair descends behind transit counterweights.


| Sequence / play focus | Target | Puzzle IDs |
| --- | --- | --- |
| SQ-04-01 · A waiting room beneath a waiting room | 6 min | Narrative / traversal |
| SQ-04-02 · The queue that leans | 7 min | PZ-11 |
| SQ-04-03 · The eyes that do not stop | 7 min | PZ-12 |
| SQ-04-04 · Orren stands | 5 min | PZ-13 |


**Chapter review:** confirm the new physical relationship is taught before threat, the landmark stays geographically consistent, and the exit preserves established facts. Review every A/B/C composition at gameplay distance before final art. The following pages are one-sequence build cards; their whitespace is available for team annotations.


## SQ-04-01 | A waiting room beneath a waiting room

**Campaign 1:04–1:10 · 6 min · Narrative / traversal · CK-04-01**


**Blockout.** Exchange hall 64 × 18 × 24 m. Upper public passage at y=7, restrained queue rail y=1 in background z=4, player maintenance lane y=0. Suspended tram at x=33.


**Initial state.** Public residents use independent short routes. Restrained queue is driven by the deck load parameter, with separate look and breath tracks. No automatic marching loop.


**Storyboard A / B / C.** A / Bright ordered upper concourse contrasts with the lower lane. B / A tram weight shifts; bodies below lean while a face remains turned toward Ivo. C / A brief window view recalls the hostel and its curtain beyond the platform.


**Player action and solution.** Climb through an inspection opening, move a light luggage frame and traverse beneath the tram. A local inspection lever shifts a small test load enough to demonstrate compensation without requiring a full puzzle. Ivo can reverse the lever and watch the same people respond. This optional experiment makes the cause-and-effect readable. The exit path passes toward the main loaded deck, so the observation is spatially connected to the next challenge.


**Threat, failure and recovery.** No guard attack during the first crowd demonstration. Decorative residents cannot wander into the player lane. The tram cannot crush Ivo outside its marked moving zone.


**Narrative consequence.** Public life is literally supported by a constrained group. Different eyes, fingers and breaths establish awareness before Ivo restrains a worker himself.


**Audio direction.** Upper footsteps and luggage are softened by distance; lower restraint clicks answer the load. Voices remain indistinct, not a hidden exposition conversation.


**Checkpoint / save contract.** Record CrowdCompensationSeen when the test completes or Ivo reaches the next inspection opening with the demonstration visible. Crowd individual IDs remain stable into evacuation.


**Exit / transition.** The loaded deck blocks the low route; a service jack below it is already visible through a maintenance window.


**Acceptance test.** Viewers distinguish coordinated body response from coordinated intention. Looking away does not make the mandatory causal event happen permanently offscreen.


**Required asset families:** CHR-IVO, ENV-EXCHANGE, CHR-RESIDENTS, CHR-BEARER-01, CHR-BEARER-02, GME-TRAM, PRP-LUGGAGE.


## SQ-04-02 | The queue that leans

**Campaign 1:10–1:17 · 7 min · PZ-11 · CK-04-02**


**Blockout.** Loaded deck puzzle 36 × 9 × 15 m. Pivot x=18; deck spans x=10–26; jack storage x=5, jack rail ends x=16. Anchor x=9; crank accessible from under-deck refuge at x=14.


**Initial state.** Deck tilted enough to block passage and force the waiting rail to compensate. Jack is too far left to receive it. Personal Hold keeps the deck safe but occupies a hand needed to move the jack.


**Storyboard A / B / C.** A / The deck and waiting bodies share a composition, while the jack is in a readable lower pocket. B / A successful anchor transfer shifts the strain to the plate behind the queue. C / When the jack takes weight, torsos relax at slightly different rates; one person continues gripping a rail after it is no longer needed.


**Player action and solution.** Raise the deck with its low service lever and arrest at the clearance notch. Transfer to the available anchor. Move the jack along its constrained rail beneath the deck, then turn its two-hand crank until its top contacts the receiving plate. Interact seats its ratchet. Release the anchor; the deck descends a small visible amount onto the jack and stays there. The queue is relieved because the deck correction is no longer demanded, not because Ivo sends a mental command. Crawl through the newly safe underside and unlatch the far service gate.


**Threat, failure and recovery.** Jack travel is rail-bounded and cannot be lost. Releasing too early lowers the deck toward a visible refuge shelf, allowing recovery; it does not randomly kill the waiting people. A wrong solution shows continuing strain.


**Narrative consequence.** Introduces a concrete alternative to control: remove the imposed correction. The queue members are later part of the twelve-person cohort.


**Audio direction.** Jack teeth seat with a distinct dry cadence. The deck’s load tone disappears only when physical contact is verified. Separate breaths recover out of sync.


**Checkpoint / save contract.** Persist JackPosition, JackRatchet, DeckSupported and assigned survivor slots atomically. Guard encounter afterward starts from this completed solve.


**Exit / transition.** A service shutter opens toward a worker’s inspection post. Ivo has both hands free and sees an exposed harness contact.


**Acceptance test.** The player can explain why the group relaxed. No mandatory solution harms a civilian. A 20-run checkpoint loop retains jack support and unique survivor IDs.


**Required asset families:** CHR-IVO, ENV-EXCHANGE, GME-TILT-DECK, GME-JACK, GME-ANCHOR, CHR-BEARER-01, CHR-BEARER-02.


## SQ-04-03 | The eyes that do not stop

**Campaign 1:17–1:24 · 7 min · PZ-12 · CK-04-03**


**Blockout.** Inspection corridor 34 × 7 × 10 m. Worker patrol x=14–21, gate-cart rail x=7–17 with 3° slope, brake x=11, exit shutter x=25. Safe preparation pocket x=4–10.


**Initial state.** Cart begins outside its barrier track. Worker contact exposed during inspection. The shutter and worker compete for one personal Hold. A two-handed cart move is impossible while holding the worker.


**Storyboard A / B / C.** A / Show cart rail, slope and exit before the worker closes distance. B / When the harness is arrested, the body freezes but the eyes visibly track Ivo. C / Cart reaches its stop between the worker and Ivo; camera leads to the shutter rather than lingering on a helpless person.


**Player action and solution.** From the safe pocket, push the gate-cart onto the sloped receiving rail and engage its brake. Approach the worker’s exposed contact, arrest his harness during the reach, then use the one-hand brake lever. Gravity rolls the cart to its hard stop and it becomes a barrier. Release the worker, acquire the shutter, cross and release again. The shutter target cannot accidentally replace the held worker. If the cart was not prepared, retreat is possible and the worker returns to inspection after losing sight. A brief early demonstrative restraint may be released without resolving the entire puzzle.


**Threat, failure and recovery.** Worker catch requires proximity. Arrested eyes and breath are cosmetic awareness, not extra attack mechanics. Cart barrier collision matches the visible frame. No solution requires Ivo to push heavy equipment with an occupied hand.


**Narrative consequence.** This confirms that consciousness continues in every hidden bearer. The tool remains useful after the revelation, creating genuine tension rather than becoming an ability the player should never use.


**Audio direction.** Harness catches with fabric and metal, not a magical freeze. A shallow conscious breath remains audible. The worker resumes his interrupted reach on release before re-evaluating the obstruction.


**Checkpoint / save contract.** Checkpoint after cart preparation; cart stop and worker state reset consistently. Exit checkpoint records ConsciousRestraintSeen and the worker safely behind the barrier.


**Exit / transition.** Maintenance stair leads beneath the last tram support, where Orren’s body matches a hanging linkage.


**Acceptance test.** Repeated play cannot skip cart preparation through hand exploits. Test restraint/release at every reach phase. The player identifies awareness without a close-up face cinematic.


**Required asset families:** CHR-IVO, CHR-CUST-B, GME-HARNESS, GME-GATE-CART, GME-SHUTTER, ENV-EXCHANGE.


## SQ-04-04 | Orren stands

**Campaign 1:24–1:29 · 5 min · PZ-13 · CK-04-04**


**Blockout.** Under-platform support bay 28 × 8 × 10 m. Hanging stair section x=11–18, pawl x=15 y=1.0, Orren alcove x=19 at z=2. Exit ladder x=23.


**Initial state.** Orren’s harness sustains the stair angle. A rusted receiving pawl is obstructed by a light maintenance plate. No immediate pursuit.


**Storyboard A / B / C.** A / Camera shows the stair geometry before Orren’s whole body. B / As Ivo takes the load, Orren’s fingers move independently. C / After support is seated, the frame allows time for the bent shoe to find the floor and the hand to open.


**Player action and solution.** Move the loose plate aside, take the stair’s restraint through its service contact and lower it toward the receiving notch. Hold at alignment, engage the one-hand pawl, then release. The stair rests on metal and Orren’s harness unlocks. He removes himself; Ivo does not drag him like a prop. Climb the now-supported stair and open a simple service hatch. Orren tests his balance, then takes a separate marked resident route toward the hostel. He does not follow Ivo into the cutting.


**Threat, failure and recovery.** No timed rescue pressure. A misaligned pawl gives tactile resistance and can be tried again. Orren is protected from the stair’s puzzle collision; unsafe releases remain intercepted by the old harness until support is correct.


**Narrative consequence.** A named production identity makes relief tangible. The missing button and bent shoe prepare recognition in the final gate scene.


**Audio direction.** A final harness creak, ordinary shoe scuff and a breath that no longer matches the stair. Resist adding celebratory music.


**Checkpoint / save contract.** OrrenFreed commits only when support and route exit are available. Save Orren’s segment index, not a free-wandering transform. Reload cannot duplicate him in both the bay and hostel.


**Exit / transition.** Ivo descends behind massive transit counterweights. Chalk dust and open light replace concourse order.


**Acceptance test.** Testers remember Orren by appearance without dialogue. His relief never depends on an optional collectible. The supported stair remains stable in later route snapshots.


**Required asset families:** CHR-IVO, CHR-ORREN, GME-STAIR-PAWL, GME-ANCHOR, ENV-EXCHANGE, PRP-ORREN-PROPS.


# 10 | C05 — The Counterweight Cut

**Target:** 27 minutes · campaign minutes 89–116. **Player question:** What happens when the structure follows my balance?

**Visual identity:** Pale chalk, large negative space, dark suspended masses.

**New experience:** Paired interface, controlled impact, repeated threat with new geometry. **Landmark continuity:** Hostel relocation shoes glimpsed from below without revealing the whole.

**Exit transition:** Chalk slide leads to the submerged original street.


| Sequence / play focus | Target | Puzzle IDs |
| --- | --- | --- |
| SQ-05-01 · The weight is visible | 6 min | PZ-14 |
| SQ-05-02 · Borrowed balance | 7 min | PZ-15 |
| SQ-05-03 · Make a fall useful | 8 min | PZ-16 |
| SQ-05-04 · Beneath the rescue rail | 6 min | PZ-17 |


**Chapter review:** confirm the new physical relationship is taught before threat, the landmark stays geographically consistent, and the exit preserves established facts. Review every A/B/C composition at gameplay distance before final art. The following pages are one-sequence build cards; their whitespace is available for team annotations.


## SQ-05-01 | The weight is visible

**Campaign 1:29–1:35 · 6 min · PZ-14 · CK-05-01**


**Blockout.** Chalk cutting 90 × 28 × 28 m. Three suspended masses create a visible sweep corridor; refuges at x=20, 42 and 64. Playable platforms remain 2.0 m or wider.


**Initial state.** A maintenance cycle slowly translates one mass across the route. It has a connected exposed drive and clear safe pockets. Far relocation shoes are background silhouettes, not interactive targets.


**Storyboard A / B / C.** A / Wide pale shot before entering hazard range. B / Falling grit marks the moving weight’s sweep while a dark refuge reads against chalk. C / After crossing, a downward reframe exposes the small paired carrier beneath the path.


**Player action and solution.** Walk the approach, climb a short ladder and observe the maintenance cycle. Arrest the sweep drive to cross the first exposed section, release from a stone pocket, and cross the second during its natural return. The change from darkness to exposure supplies variety. One optional overlook shows the hostel’s undercarriage as ordinary maintenance structure without revealing locomotion. Do not stretch the route through repeated identical weights; one authored sweep with two uses is enough.


**Threat, failure and recovery.** The full sweep corridor is visible before commitment. Chalk effects never obscure a lethal edge. A falling minor stone is cosmetic unless explicitly tagged and staged as a hazard.


**Narrative consequence.** Buildings are suspended over a landscape of stored maintenance decisions. Ivo’s scale against mass matters more than an increased enemy count.


**Audio direction.** Wind carries distant metal groans; stone sheds grit after the main motion stops. Bright space receives a thinner mix than the enclosed chapters.


**Checkpoint / save contract.** Checkpoint at each stable refuge; driver phase starts in a readable position. Cosmetic debris is reseeded outside Ivo’s contact path, not replayed as damage.


**Exit / transition.** A small articulated carrier blocks the continuation. Its open paired interface is clearly within reach.


**Acceptance test.** Users can identify safe pockets in grayscale. Maximum camera distance still leaves Ivo readable. No hidden mass collider extends beyond its visual sweep envelope.


**Required asset families:** CHR-IVO, ENV-CUT, GME-COUNTERWEIGHT, GME-SWEEP-DRIVE, FX-CHALK, PRP-GANTRY.


## SQ-05-02 | Borrowed balance

**Campaign 1:35–1:42 · 7 min · PZ-15 · CK-05-02**


**Blockout.** Carrier fixture 28 × 12 × 12 m. Articulated carrier 5.5 m long, 2.5 m tall, guided travel 6 m and posture range ±12°. Entry cradle x=7; receiving ledge x=18 at y=2.2.


**Initial state.** Carrier parked on visible clamps. Interface has two palm plates and a foot plate. All personal burdens must be relieved before entry. Mechanical lock at far ledge begins open.


**Storyboard A / B / C.** A / Side view puts Ivo’s body and first support shoe in one composition. B / On a directional lean, the shoe moves with his posture. C / Camera follows the carrier enough to keep the receiving notch visible, but does not make it feel like a new free-roaming vehicle.


**Player action and solution.** Enter the cradle with Interact. Move horizontally to request a controlled shift; use down to lower the near end beneath a low brace, then up to meet the receiving ledge. Hold arrests the assembly at alignment. Interact seats the receiving lock; release Hold to verify that the carrier stays supported. Exit through the mechanically released cradle latch. Neutral only settles the current safe phase; Hold is the precise brake. A poor alignment visibly blocks the lock and can be corrected without a fall. This exact control contract returns in the domestic room and Ward.


**Threat, failure and recovery.** Teaching fixture is nonlethal. No hidden balancing stamina or stick-wobble minigame. The player cannot exit while the carrier lacks a support and materialize beside it.


**Narrative consequence.** The connection has two directions. Ivo is not merely stopping a machine; the machine can follow his balance. The full architectural implication remains concealed.


**Audio direction.** Foot plate contact, modest hydraulic response and Ivo’s breath guide the perceived body link. Motor force is audible, avoiding an implication that his muscles power the carrier.


**Checkpoint / save contract.** Save parked or locked support states. Mid-station suspend stores q, posture, phase, owner and Ivo’s station binding. Pausing cannot issue an exit or release.


**Exit / transition.** The carrier reaches a maintenance ledge overlooking a blocked counterweight and its receiving cradle.


**Acceptance test.** Four of five fresh testers operate and exit within 90 seconds after first entry. Later Ward test uses the same inputs with no new control explanation. No input inversion during camera tracking.


**Required asset families:** CHR-IVO, ENV-CUT, GME-PAIRED-STATION, RIG-CARRIER, GME-SUPPORT-LOCK, FX-CABLE.


## SQ-05-03 | Make a fall useful

**Campaign 1:42–1:50 · 8 min · PZ-16 · CK-05-03**


**Blockout.** Counterweight bay 42 × 24 × 16 m. Hanging block x=18 at y=10; receiving cradle on rail x=9–18 at y=3; linked walkway x=25–34. Service arrest plate x=14.


**Initial state.** Block is restrained above the route. Cradle starts laterally displaced. Walkway is too low. A visible cable links cradle displacement to walkway lift. Fall is bounded to a 2.2 m working stroke, not a catastrophic ten-meter free drop.


**Storyboard A / B / C.** A / Show weight, displaced cradle and inaccessible walkway in one vertical composition. B / Low camera tracks the cradle being moved under the drop marker. C / On release, camera remains wide enough to register impact, lifted walkway and a distant worker steadying himself.


**Player action and solution.** Take the existing block restraint at its service plate and transfer to a local maintenance anchor, freeing the crane-side interlock. Move the receiving cradle along its rail until its guide marks align beneath the block. Engage its side pawl. Release the anchor; the block falls through its bounded working stroke into the cradle and the counterbalanced walkway rises. Arrest the walkway if needed at its crossing notch, seat its one-hand stop and traverse. The irreversible block drop can occur only after the receiving pawl is genuinely engaged; a wrong release is intercepted by the old safety catch and shows the missing support.


**Threat, failure and recovery.** Do not use uncontrolled rigidbody bounce for the puzzle-bearing mass. An authored impact event switches to the seated state after a short compression travel. Cosmetic chips may scatter but cannot knock the player off the safe platform.


**Narrative consequence.** Ivo deliberately lets something move and makes the outcome useful. This is the intellectual bridge between temporary Hold and the final controlled discharge.


**Audio direction.** Impact onset, structure response and long settling tail are separate. A worker’s hand contacting a distant rail is nearly lost inside the larger sound; close repeat play reveals it.


**Checkpoint / save contract.** After the block seats, save CradleAligned, CradleLocked, BlockSeated and WalkwayRaised as one completion. Later deaths cannot demand dropping the block again.


**Exit / transition.** The raised walkway enters the Porter rail system. A salvage bundle hangs above the next exposed grate.


**Acceptance test.** The result is repeatable within 2 cm at all render rates. A player can predict which platform will rise before committing. No solution depends on a fortunate bounce.


**Required asset families:** CHR-IVO, ENV-CUT, GME-COUNTERWEIGHT, GME-RECEIVING-CRADLE, GME-LIFT-WALKWAY, GME-ANCHOR, FX-IMPACT.


## SQ-05-04 | Beneath the rescue rail

**Campaign 1:50–1:56 · 6 min · PZ-17 · CK-05-04**


**Blockout.** Rail pursuit 68 × 18 × 16 m. Salvage bundle x=20; connected grates x=12–31; refuge x=34; moving exit platform x=45–52; slide entry x=58.


**Initial state.** The Porter enters along the rail last seen continuing from gardens. It uses the same detection/reach rules. Salvage bundle is above its reachable capture corridor. Exit platform shares the drive phase for the last segment.


**Storyboard A / B / C.** A / Familiar ratchet arrives before the apparatus enters the foreground. B / Both bundle and grate show their connection; safe stone lies beyond. C / Camera leads to the exit platform before the final release and jump, then follows Ivo down a controlled slide.


**Player action and solution.** Release the salvage bundle from the side lever; the Porter commits to securing it. Cross the first grate during the retrieval and arrest the drive from the stone refuge. The exit platform is now stopped short of its destination because it shares that drive. Release, allow it to advance and jump onto it within a broad 2.5-second usable interval. Ride to the slide, then let ordinary movement carry Ivo into the lower route. Holding forever buys thought time but does not produce the missing alignment. This is a recombination of known rules, not a new immunity or speed boost.


**Threat, failure and recovery.** No unseen catch during the jump. Failure restores the refuge and bundle retrieval stage, preserving the completed counterweight puzzle. Slide direction is controllable within a safe lane; cinematic dust cannot cover the next landing.


**Narrative consequence.** The apparatus repeats its rescue procedure; Ivo now redirects that procedure rather than treating it as a monster with a health bar. Releasing becomes active problem-solving.


**Audio direction.** Rail rhythm, bundle fabric, motor restart and gritty slide. Underwater muffling starts only when the head actually submerges at the end, not before contact.


**Checkpoint / save contract.** Checkpoint at refuge before final drive release. Store Porter route phase and exit-platform shared driver together. Successful slide arrival commits CuttingComplete.


**Exit / transition.** The slide ends on a shallow shelf overlooking the drowned original street. Ivo can recover and inspect water without a continuing chase.


**Acceptance test.** A correct full-speed run has generous clearance. Controller and keyboard timing both pass. The shared drive state cannot desynchronize on restart or a long pause.


**Required asset families:** CHR-IVO, CHR-PORTER, RIG-PORTER, GME-SALVAGE-RELEASE, GME-EXIT-PLATFORM, ENV-CUT, FX-CHALK.


# 11 | C06 — The Drowned Street

**Target:** 27 minutes · campaign minutes 116–143. **Player question:** Can I move a place to breathe rather than conquer the water?

**Visual identity:** Green-gray water, submerged ordinary shopfronts, bands of weak daylight.

**New experience:** Swim, air pocket, buoyancy, obsolete rescue route. **Landmark continuity:** Hostel curtain seen above a gap in later construction.

**Exit transition:** A drained service room exposes bearer access.


| Sequence / play focus | Target | Puzzle IDs |
| --- | --- | --- |
| SQ-06-01 · The street below the street | 6 min | PZ-18 |
| SQ-06-02 · A room for one breath | 8 min | PZ-19 |
| SQ-06-03 · A rescue that would drown him | 7 min | PZ-20 |
| SQ-06-04 · Water leaves a record | 6 min | PZ-21 |


**Chapter review:** confirm the new physical relationship is taught before threat, the landmark stays geographically consistent, and the exit preserves established facts. Review every A/B/C composition at gameplay distance before final art. The following pages are one-sequence build cards; their whitespace is available for team annotations.


## SQ-06-01 | The street below the street

**Campaign 1:56–2:02 · 6 min · PZ-18 · CK-06-01**


**Blockout.** Submerged street approach 58 × 13 × 22 m. Wading shelf x=0–15 at water depth 0.3–0.9 m; first swim gap 8 m; safe landing x=24; shallow dive tunnel length 9 m with visible air on both sides.


**Initial state.** No pursuing enemy. Water volume is active; head sample and buoyancy presentation agree. A guided floating chair bumps a restraint cable but is not a required platform.


**Storyboard A / B / C.** A / Camera opens onto recognizably ordinary submerged shopfronts, keeping the surface line visible. B / Ivo’s transition from feet-on-ground to swimming is shown in profile. C / A view through an opening reveals the hostel curtain above the later construction.


**Player action and solution.** Wade from the slide shelf, swim the short surface gap and climb to the dry landing. Use downward intent to pass the low submerged lintel, then surface into a clearly visible pocket. The leg takes under 7 seconds on a clean run and provides ample reserve. A nearby rung lets the player reverse and repeat the transition safely. Ordinary movement, water sound and head position teach the new state without a modal tutorial. The floating chair and fish move independently of the brace.


**Threat, failure and recovery.** First breath warning can be experienced safely beside a surface escape. No ambush during the swimming lesson. Surface collisions and camera bounds must not trap the player under a decorative ceiling.


**Narrative consequence.** The town built over its unfinished disaster. Water is a physical medium with its own behavior, not an excuse for a new magic ability.


**Audio direction.** Waterline crossing blends filters and head-local bubbles. Wet clothes persist on the dry landing. Underwater sounds have less high-frequency detail but never eliminate an essential direction cue.


**Checkpoint / save contract.** Checkpoints only on the dry landing and full-air pocket during onboarding. Record breath, wetness and water-region ID; restoring a safe checkpoint resets reserve to full.


**Exit / transition.** A maintenance bell hangs ahead from a guide and an intact air hose. The view shows its open underside and pale pocket before the player commits.


**Acceptance test.** Test 100 waterline crossings with no state chatter, surface jitter or infinite breath from boundary flicker. Novices identify both air exits before diving.


**Required asset families:** CHR-IVO, ENV-DROWNED, GME-WATER-VOLUME, PRP-FLOAT-CHAIR, FAUNA-FISH, FX-SILT.


## SQ-06-02 | A room for one breath

**Campaign 2:02–2:10 · 8 min · PZ-19 · CK-06-02**


**Blockout.** Bell chamber 36 × 16 × 20 m. Bell 2.4 m diameter, 3.2 m high on a vertical guide with 3.6 m stroke. Lower entry y=-3; upper passage y=0.5. Bell pocket begins 1.1 m above the open rim; hose visibly feeds it.


**Initial state.** Bell moored below a blocked passage. It is buoyant but winch-constrained. Lower release contact is reachable from a safe ledge and the interior lever can be operated one-handed. Pocket volume is attached to the bell, with bounded local water height.


**Storyboard A / B / C.** A / Show guide, bell rim and upper destination together before the dive. B / Camera follows head entry into the pocket; sound returns to close breath with water visible around the boundary. C / On rise, the upper passage enters the same frame, making the bell a moving shelter rather than a vehicle cutaway.


**Player action and solution.** Release the lower mooring and Hold the guide brake while swimming beneath the rim. Enter the air pocket and recover. Operate the interior lever to disengage the lower guide stop; release Hold so buoyancy lifts the bell. Arrest near the upper access notch, engage its physical docking catch and swim the short upper connection to the next landing. Each open-water leg remains under 10 seconds. A wrong height can be corrected while sheltered. The guided bell cannot rotate freely, depart its hose range or become an uncontrolled boat.


**Threat, failure and recovery.** The pocket requires head-inside validation; touching the bell exterior gives no air. Ivo’s one-arm swim variant is used while sustaining Hold. No timed mechanism continues to drain the safe pocket during observation.


**Narrative consequence.** Ivo does not acquire immunity to drowning. He learns to move a place where he can breathe, foreshadowing moving a place where others can live.


**Audio direction.** Close air-pocket breath, hose pulse, hollow bell resonance and external water pressure. Rising changes resonance subtly. The musical bed stays sparse so the small refuge feels precious.


**Checkpoint / save contract.** Mid-puzzle suspend stores bell q, mooring, dock catch, pocket local plane, hose state and breath. Resume inside the pocket requires its chunk resident before Ivo activates. Dock checkpoint is a safe full-air state.


**Exit / transition.** Beyond the upper landing, the Porter rail descends into the old flooded retrieval dock. Its silhouette and breathing hose are visible before engagement.


**Acceptance test.** A head can never be both drowning and receiving air in one authoritative tick. Pausing on a rising bell freezes guide, pocket and breath together. All safe catches can be undone from inside.


**Required asset families:** CHR-IVO, ENV-DROWNED, GME-AIR-BELL, GME-BELL-WINCH, GME-AIR-POCKET, GME-WATER-VOLUME, FX-BUBBLES.


## SQ-06-03 | A rescue that would drown him

**Campaign 2:10–2:17 · 7 min · PZ-20 · CK-06-03**


**Blockout.** Flooded retrieval dock 40 × 15 × 18 m. Porter rail descends toward a submerged unloading cradle at y=-5. A hinged empty retrieval basket demonstrates tipping there. Bell guide has a 2.6 m upward escape stroke.


**Initial state.** Porter uses the same detect/reach/secure/retract states. Its submerged dock mechanically tips retrieved containers for unloading; tipping the air bell would spill its pocket. The danger is the visible dock geometry, not simply being underwater.


**Storyboard A / B / C.** A / A discarded empty basket is drawn into the dock and tipped, showing the procedure before Ivo is targeted. B / The Porter approaches the bell through silt while its hose traces back to the rail. C / Camera shows the upward escape notch and a short exposed swim toward a fixed air landing.


**Player action and solution.** From the safe bell pocket, release the guide brake rather than freezing the apparatus. Buoyancy carries the bell above the Porter’s capture sweep. Arrest at the upper notch and engage a one-hand safety catch. Leave the shelter through an open-water leg under 13 seconds, swim behind a structural rib and pull the fixed retrieval-gate latch from the air landing. The Porter completes its reach against the now-blocking gate. Holding the bell low indefinitely is safe only while out of capture range; the telegraphed approach prompts movement. The player never needs to Hold the Porter and the bell simultaneously.


**Threat, failure and recovery.** Capture has a recoverable reach warning and one interrupted-grab opportunity before failure. If the bell is retrieved, show loss of shelter briefly and reset; do not require watching a long drowning scene. Checkpoint at the fully supplied pocket, with Porter out of reach.


**Narrative consequence.** The procedure still functions, but its definition of a safe destination has become lethal. The rig is not a new aquatic supernatural species.


**Audio direction.** Muffled rail vibration through the bell, worker breathing through a hose, basket tip and escaping bubbles. Do not use a sudden creature scream to announce a familiar apparatus.


**Checkpoint / save contract.** Porter route branch, retrieval target, bell guide state and gate state are one encounter snapshot. On success the dock is isolated and the Porter cannot follow into dry rooms.


**Exit / transition.** A drain control in the fixed air landing lowers the adjacent service room, revealing a route behind domestic walls.


**Acceptance test.** Players recognize why the dock is unsafe before capture. The escape works with sound muted and breath assistance. No AI shortcut crosses a structural rib.


**Required asset families:** CHR-IVO, CHR-PORTER, RIG-PORTER, GME-AIR-BELL, GME-BELL-WINCH, GME-DOCK-CRADLE, ENV-DROWNED.


## SQ-06-04 | Water leaves a record

**Campaign 2:17–2:23 · 6 min · PZ-21 · CK-06-04**


**Blockout.** Drain chamber 32 × 8 × 12 m. Water level falls from y=2.3 to y=0.2. Valve x=6 on dry shelf; pump latch x=14 under an initial 1.4 m dive; exit stair x=25.


**Initial state.** Main drain valve alone opens a bypass but the pump governor is latched off. A short dive exposes a linked service contact. Safe return shelf remains close.


**Storyboard A / B / C.** A / Frame waterline against repainting bands and a closed service stair. B / As water falls, former hand heights and harness outlines appear, with no camera cut to a note. C / The last drips reveal a dry passage into the same structures whose machines Ivo has used.


**Player action and solution.** Open the bypass from the air shelf. Dive to the nearby governor contact, arrest its closing lever long enough to move the one-hand pump latch, then return to air. The pump lowers the adjacent bounded volume and exposes the stair. No two-hand underwater crank is required. A player who releases early simply lets the governor return and can retry. Once the pump’s mechanical run latch engages, no person must sustain it. Optional inspection of discarded covers adds history without blocking the route.


**Threat, failure and recovery.** Keep the short dive within 8 seconds and show the contact from the shelf. Drain flow cannot pull Ivo into an invisible current death. The pump cannot empty a region that the active bell checkpoint still depends on.


**Narrative consequence.** Emergency hardware was repainted and reused rather than replaced. The scale of repeated confinement becomes visible in ordinary maintenance marks.


**Audio direction.** Water recedes from full room resonance to individual drips. Old harness straps move as the level drops. The root’s low tension rhythm enters gradually.


**Checkpoint / save contract.** Persist PumpLatched, RoomDrained and safe stair availability together. Reload on the stair uses the drained volume; no visual water plane can disagree with swim logic.


**Exit / transition.** A body-width passage behind apartment walls opens toward the reverse side of the bearer system.


**Acceptance test.** The player sees a continuous material history, not collectible exposition. A save made during the drain restores the correct transition phase or its safe completed state without trapping Ivo.


**Required asset families:** CHR-IVO, ENV-DROWNED, GME-DRAIN-PUMP, GME-WATER-VOLUME, PRP-OLD-HARNESS, FX-WATER-MARK.


# 12 | C07 — The Burden House

**Target:** 27 minutes · campaign minutes 143–170. **Player question:** Can I relieve Mother without becoming her replacement?

**Visual identity:** Close domestic backs, dry dust, body-sized cavities, pressure and contact.

**New experience:** Recognized machine rhythms, room-scale balance, irreversible root conversion. **Landmark continuity:** Survivors enter the hostel through a high opening.

**Exit transition:** Root-load conduit follows a passage into the seawall.


| Sequence / play focus | Target | Puzzle IDs |
| --- | --- | --- |
| SQ-07-01 · You have heard this before | 6 min | Narrative / traversal |
| SQ-07-02 · A room that follows your shoulders | 6 min | PZ-22 |
| SQ-07-03 · Mother is not behind the machine | 8 min | Narrative / traversal |
| SQ-07-04 · A rescue that changes the room | 7 min | PZ-23 |


**Chapter review:** confirm the new physical relationship is taught before threat, the landmark stays geographically consistent, and the exit preserves established facts. Review every A/B/C composition at gameplay distance before final art. The following pages are one-sequence build cards; their whitespace is available for team annotations.


## SQ-07-01 | You have heard this before

**Campaign 2:23–2:29 · 6 min · Narrative / traversal · CK-07-01**


**Blockout.** Bearer service spine 60 × 7 × 12 m. Three inspection apertures at x=14, 29 and 44 correspond to laundry drum, waiting deck and a smaller service burden. Playable lane remains unobstructed.


**Initial state.** Visible linkages repeat recognizable movement signatures from earlier puzzles. Formerly unloaded laundry attendants are still behind locked maintenance access; their load is gone but confinement remains.


**Storyboard A / B / C.** A / Begin with a familiar rhythm before its source is visible. B / At the first aperture the matching limb posture is revealed, while Ivo stays in profile. C / A farther window frames Ivo’s own strained hand beside a bearer’s hand without creating a mirror-image supernatural double.


**Player action and solution.** Move through the service spine, open two ordinary inspection latches and climb a short maintenance step. Each aperture reveals the back of an encountered machine family. A one-hand test handle produces a small reversible movement in a safe demonstration linkage, making the relationship inspectable. No new puzzle currency or lore document is required. A locked communal service exit is visible beyond the attendants; Ivo will open it after relieving the overhead domestic support later in this chapter.


**Threat, failure and recovery.** No surprise chase in this recognition sequence. Aperture grates stop Ivo entering bearer collision volumes. Noncritical ambient motion never turns into an unannounced instant kill.


**Narrative consequence.** The town has used people as continuous corrections. Earlier relief removed loads but did not automatically open every cell; this prevents a false claim that all affected people were already free.


**Audio direction.** Reuse exact rhythmic signatures, not necessarily the same literal audio clip. Machine motion is now accompanied by joint fabric and breath. Let recognition occur before adding new sound.


**Checkpoint / save contract.** Recognition flags are set at view-confirmed thresholds. Existing solved-puzzle facts drive the displayed load states. Sequence cannot show a bearer straining under a process already mechanically relieved.


**Exit / transition.** The next room contains a paired balance interface connected to recognizable domestic architecture.


**Acceptance test.** Fresh players connect at least one shown person to an earlier mechanism. Completed loads remain visibly relieved. Narrative cannot contradict the player’s saved interventions.


**Required asset families:** CHR-IVO, ENV-BURDEN, CHR-BEARER-01, CHR-BEARER-02, CHR-BEARER-03, GME-BODY-LINK, FX-CONTACT.


## SQ-07-02 | A room that follows your shoulders

**Campaign 2:29–2:35 · 6 min · PZ-22 · CK-07-02**


**Blockout.** Linked domestic chamber 30 × 11 × 14 m. Movable room module 6 × 3.6 × 5 m on a 10° tilt frame; bed and cupboard constrained inside. Cradle on fixed service side, receiving support x=19.


**Initial state.** Room leans across a blocked exit. It is unoccupied but visibly lived-in. Its paired interface shares the carrier’s geometry and input grammar. A mechanical receiving stop is just outside alignment.


**Storyboard A / B / C.** A / Enter at close human scale: bed, cup and an old curtain. B / Ivo leans in the cradle; the room’s lamp and floor change angle with him. C / Camera opens enough to show the receiving stop, making the domestic space readable as an assembly.


**Player action and solution.** Enter the paired cradle, lower the room’s near edge to clear the service beam, move its guided base a short distance, then raise toward the receiving support. Hold at the marked notch and engage the lock. Release to confirm the support carries it; exit and traverse through the newly aligned doorway. Two independent bounded coordinates, guide travel and tilt, are sufficient. Furniture has constrained incidental reactions but cannot jam the exit or change the solution. This second rehearsal adds emotional recognition, not new buttons.


**Threat, failure and recovery.** Wrong posture blocks travel with a visible structural contact. The station safely settles instead of throwing Ivo. The lock cannot confirm without genuine alignment and support contact.


**Narrative consequence.** Architecture has been an external skeleton. The room is intimate enough that a sliding cup makes the bodily connection disturbing before the Ward enlarges it.


**Audio direction.** Crockery against wood, lamp chain, foot plate and familiar hydraulic response. Ivo’s breath aligns with strain through shared state, not by delaying control.


**Checkpoint / save contract.** Store room guide q, tilt, support and station binding. If restoring a locked state, furniture settles to curated poses outside traversal. One-off cupboard slide does not retrigger as a collision hazard.


**Exit / transition.** A partially open root access shutter reveals Anja’s distinctive cuff before the larger installation.


**Acceptance test.** Players transfer carrier knowledge without tutorial. The scene reads as a domestic room, not a second industrial vehicle. Prop response is visible but never mechanically random.


**Required asset families:** CHR-IVO, ENV-BURDEN, RIG-DOMESTIC-ROOM, GME-PAIRED-STATION, GME-SUPPORT-LOCK, PRP-BED, PRP-CUPBOARD.


## SQ-07-03 | Mother is not behind the machine

**Campaign 2:35–2:43 · 8 min · Narrative / traversal · CK-07-03**


**Blockout.** Root reveal chamber 26 × 12 × 15 m. Anja hand and cuff at x=12 y=1.1; incorporated root body set behind x=15 z=3; sealed replacement collar x=18; open service path x=22.


**Initial state.** Anja sustains the root. Root collar is visibly sealed and physically incorporated, unlike open peripheral harnesses. An adjacent replacement position is prepared but not secretly compulsory.


**Storyboard A / B / C.** A / Familiar cuff and two taps identify her before the apparatus is understood. B / Slow side reframe exposes the connection’s irreversible physical extent while Ivo can approach or step back. C / When he looks toward the replacement position, she presses his free hand away from it.


**Player action and solution.** Approach and Interact for the hand contact. Ivo can take a small service load, easing one restraint and permitting a gentle attempted withdrawal of her arm. The deeper incorporated connection remains; the apparatus visibly resists without a new arbitrary force field. Release returns the small load to its original owner through an explicit handover, not a drop. Inspect the nearby replacement cradle and the blocked service route. A short ordinary valve action opens the way onward. The eight-minute budget includes approach, player observation and the surrounding intimate space, not an eight-minute cutscene.


**Threat, failure and recovery.** No time limit, no secret rescue branch and no ability to attack Anja. Interaction retries play abbreviated responses. The first major physical contact has a safe cancel before commitment and a short noninterruptible contact window.


**Narrative consequence.** Hold cannot undo damage. The system offers substitution; Anja refuses it for Ivo. Her death later must follow this established condition, not arrive as an unexplained punishment.


**Audio direction.** Prior machine rhythms thin to one difficult breath and fabric contact. No dialogue explains the apparatus. Silence leaves local room detail, never a complete audio vacuum.


**Checkpoint / save contract.** RootRecognitionSeen, HandContactSeen and ReplacementRefused commit at separate coherent beats. Anja remains root owner. A suspend during the contact resumes at its nearest authored safe contact state.


**Exit / transition.** Ivo follows a load conduit to an ordinary receiving frame blocking the service exit for other intact bearers.


**Acceptance test.** Testers distinguish removable harnesses from the root. They understand her refusal without captions. Repeated interaction cannot accidentally transfer the root permanently to Ivo.


**Required asset families:** CHR-IVO, CHR-ANJA, CHR-ROOT, RIG-ROOT, GME-ROOT-SERVICE, PRP-ANJA-CUFF, ENV-BURDEN.


## SQ-07-04 | A rescue that changes the room

**Campaign 2:43–2:50 · 7 min · PZ-23 · CK-07-04**


**Blockout.** Domestic load bay 40 × 12 × 16 m. Overhead slab x=12–25, receiving frame x=7–18 on rail, service exit at x=28. Paired room interface remains accessible from the fixed side.


**Initial state.** Load obstructs an old mechanical receiving frame and keeps the communal service exit pinched. Three previously unloaded laundry attendants and two local intact bearers wait beyond it. Six queue survivors and Orren are already on separate routes to the hostel.


**Storyboard A / B / C.** A / The unsafe load and a useful ordinary frame occupy the same shot. B / From the paired interface, the player sees the overhead obstruction lift enough for the frame to slide. C / When the frame takes weight, Anja’s distant hand relaxes through a small connecting aperture and the service exit opens.


**Player action and solution.** Guide the linked room slightly upward and Hold it in clearance. Engage the station parking clamp so Ivo can exit with the load supported. Push the receiving frame under its marked seat, set its ratchet, re-enter and lower the room onto it. Release the station restraint and verify the frame remains loaded. Exit and open the freed communal door. The five waiting intact bearers leave along an authored route toward the hostel. This sequence distinguishes temporary station support, ordinary support and human release without adding a new verb.


**Threat, failure and recovery.** No exit from an unsupported station. The receiving frame cannot be moved while loaded. Wrong alignment blocks lowering into a safe contact state. Civilian movement starts only when the door and route are valid.


**Narrative consequence.** Ivo can reduce suffering even though he cannot reverse Anja’s conversion. The visible cohort is now twelve: six queue survivors, three laundry attendants, two local bearers and Orren.


**Audio direction.** Frame engagement removes a layer of root strain. Different shoes and uneven breathing replace a synchronized correction rhythm. Orren is glimpsed helping, not summoned by command.


**Checkpoint / save contract.** Persist frame support, five release flags and the twelve-member cohort roster. Civilian exit segments are idempotent. The root hand’s reduced-strain presentation reads the same load fact.


**Exit / transition.** A seawall maintenance route opens beside the support. The camera briefly shows survivors entering the familiar hostel above.


**Acceptance test.** All twelve survivor identities are accounted for without an escort grind. No one can be duplicated or stranded by streaming. The player understands that a change in architecture enabled the rescue.


**Required asset families:** CHR-IVO, ENV-BURDEN, RIG-DOMESTIC-ROOM, GME-RECEIVING-FRAME, GME-SUPPORT-LOCK, CHR-BEARER-03, CHR-BEARER-04, CHR-ORREN.


# 13 | C08 — The Unfinished Sea

**Target:** 25 minutes · campaign minutes 170–195. **Player question:** What must change before it is safe to let go?

**Visual identity:** Cool retained basin contrasted with low ordinary sea; broad horizon.

**New experience:** System-scale causality, tested discharge, receiving pads, open cradle. **Landmark continuity:** Hostel and route now shown as a mechanical problem, not yet a full body.

**Exit transition:** Ivo enters the hostel service cradle without a loading break.


| Sequence / play focus | Target | Puzzle IDs |
| --- | --- | --- |
| SQ-08-01 · The storm has already passed | 6 min | Narrative / traversal |
| SQ-08-02 · Prove a safe way down | 7 min | PZ-24 |
| SQ-08-03 · The refuge cannot remain here | 7 min | PZ-25 |
| SQ-08-04 · An open place to stand | 5 min | PZ-26 |


**Chapter review:** confirm the new physical relationship is taught before threat, the landmark stays geographically consistent, and the exit preserves established facts. Review every A/B/C composition at gameplay distance before final art. The following pages are one-sequence build cards; their whitespace is available for team annotations.


## SQ-08-01 | The storm has already passed

**Campaign 2:50–2:56 · 6 min · Narrative / traversal · CK-08-01**


**Blockout.** Seawall gallery 72 × 17 × 28 m. Retained basin behind damaged gatework on left/background; low sea visible through openings to the right. Main play lane remains dry and physically connected.


**Initial state.** Water moves within the retained basin; gates and structural restraints are what remain arrested. Current sea is visibly below the old high-water damage. Rain and runoff explain continuing retained volume.


**Storyboard A / B / C.** A / Tight passage preserves the old industrial expectation. B / Ivo walks into a broad opening and the camera reveals the calm low sea without a dramatic cut. C / A reverse-side view puts the retained basin and its damage in relation to that ordinary horizon.


**Player action and solution.** Traverse the inspection gallery, lift a light grating and open an ordinary viewing shutter. A short hand-operated gate test moves a small indicator float, establishing that the outside sea is not another frozen surface. Optional inspection of old repair outlines supports the same conclusion. Continue along the physical discharge conduit. The important information is spatial and hydraulic; no document is required to explain that the original storm is gone.


**Threat, failure and recovery.** No threat interrupts the first horizon view. Exposed edge safety is clearly railed. Background waves cannot trigger player swim states. Avoid an invisible lethal boundary where the player expects to look outward.


**Narrative consequence.** The danger remains real, but its historical justification has changed. The institution preserved an emergency instead of completing repairs and evacuation.


**Audio direction.** Ordinary sea, distant bird and open air replace constant mechanical pressure. Let the anticlimactic normality be unsettling. No orchestral revelation cue.


**Checkpoint / save contract.** Store SeaRevealed after the viewing threshold. Preserve basin gate restraints and root ownership. The sea’s cosmetic phase is independent of saved hydraulic quantities.


**Exit / transition.** The discharge route is visible descending away from occupied ground. A displaced deflector and blockage explain why it is not already usable.


**Acceptance test.** Players do not describe the water as time-frozen. They understand why simply switching off the root would still be unsafe. Low effects mode retains the level distinction.


**Required asset families:** CHR-IVO, ENV-SEAWALL, GME-BASIN-GATES, FX-SEA, FX-RAIN, PRP-FLOOD-MARK.


## SQ-08-02 | Prove a safe way down

**Campaign 2:56–3:03 · 7 min · PZ-24 · CK-08-02**


**Blockout.** Discharge works 48 × 18 × 20 m. Deflector hinge x=13, receiving stops x=17, debris rack x=27, test valve x=6 on dry gallery. Observation window sees outlet beyond x=39.


**Initial state.** Deflector displaced; receiving stops accessible. Rack obstructs the intended channel. Test flow is physically limited to a small bypass, so a wrong setup is observable without killing people.


**Storyboard A / B / C.** A / Show the intended downhill path and the bad spill path near the refuge. B / Camera holds a stable wide composition while the deflector seats. C / At the test window, water visibly follows the corrected outlet away from the occupied hostel.


**Player action and solution.** Take the deflector restraint, lower it to its receiving stops and seat the one-hand pin. Push the debris rack along a service rail to clear the channel. Return by an upper dry path to the test valve and open the limited bypass. If the rack or deflector is wrong, water strikes a visible safe catch basin and the indicator stays below the pass notch. Close the valve, correct the physical setup and test again. Correct flow trips a mechanical proof latch. Full discharge remains impossible until the refuge is moved; the test is a demonstration, not an arbitrary switch puzzle.


**Threat, failure and recovery.** Test water never reaches civilians or traps Ivo on the return path. The valve can always be closed from the safe gallery. Decorative debris does not secretly block the certified channel.


**Narrative consequence.** The player earns confidence in release by observing its physical route. This is the final answer to the garden lesson about giving water somewhere to go.


**Audio direction.** Start with trickle and deflector contact, then outlet rush. The proof latch is a dry sound amid water. Music does not falsely signal success before flow reaches the correct outlet.


**Checkpoint / save contract.** DischargeProved commits only when deflector pin, rack clearance and test outlet agree. Save hydraulic test phase or safe closed state; never a certified fact with an obstructed channel.


**Exit / transition.** A walkway leads beneath the hostel to the relocation foundations and the failed static crossing.


**Acceptance test.** Players predict the safe outlet before the test. An unsafe configuration is reversible and clearly different. Regression changes to basin geometry must invalidate and retest the proof latch.


**Required asset families:** CHR-IVO, ENV-SEAWALL, GME-DEFLECTOR, GME-DEBRIS-RACK, GME-TEST-VALVE, GME-WATER-VOLUME, FX-WATER-FLOW.


## SQ-08-03 | The refuge cannot remain here

**Campaign 3:03–3:10 · 7 min · PZ-25 · CK-08-03**


**Blockout.** Hostel foundation yard 66 × 18 × 24 m. Three receiving pads on an authored maintenance spine, temporary supports between them; root-return culvert below far abutment; hostel visible only in partial facades.


**Initial state.** The fixed pedestrian crossing is visibly broken. Relocation shoes exist beneath the hostel. Receiving pads have two displaced locking blocks and one trapped old restraint. All survivors are inside or entering the hostel.


**Storyboard A / B / C.** A / Frame the broken fixed crossing and inhabited windows together. B / Low traversal shows a relocation shoe shaped like the small carrier’s support, but no full-body reveal. C / A high window shows Orren helping a queue survivor while the pale curtain moves outside.


**Player action and solution.** Traverse the dry maintenance spine, move the two light receiving blocks to their rail stops and engage their locks. Take a trapped old restraint, release its unloaded pin, and let the local support settle onto a prepared stop. Open the return culvert’s far grille from the accessible service side; it will be reachable from the hostel after arrival. The player inspects a route for a structure, not a set of collectible keys. Each prepared pad visibly changes from rocking to seated. The pads will later make the Ward’s footing legible.


**Threat, failure and recovery.** Do not allow entry into an occupied relocation machine before receiving supports are prepared. This is enforced by physical service interlocks and an unavailable open-cradle release, not an unexplained objective wall. No civilians are endangered during preparation.


**Narrative consequence.** The refuge’s original relocation hardware was held in incomplete preparation. The player is finishing an abandoned engineering action rather than granting a random power to a building.


**Audio direction.** Exterior wind, occupied-room foley above and low shoe hydraulics. The scene is quieter than a chase; concentration and anticipation carry tension.


**Checkpoint / save contract.** Save each pad lock and CulvertOpened. All preparations must remain visible in the finale. CohortReady validates twelve distinct slots, not twelve spawned clones.


**Exit / transition.** The safe maintenance spine leads into the hostel’s open service cradle. The large route remains partly hidden by the building.


**Acceptance test.** A tester can point to the receiving route and explain why the building must move. The culvert’s geography makes the later return to Anja plausible. All required preparation is reachable before commitment.


**Required asset families:** CHR-IVO, ENV-SEAWALL, RIG-WARD, GME-RECEIVING-PAD, GME-RELOCATION-PIN, GME-SUPPORT-LOCK, CHR-SURVIVORS.


## SQ-08-04 | An open place to stand

**Campaign 3:10–3:15 · 5 min · PZ-26 · CK-08-04**


**Blockout.** Hostel service cradle 20 × 8 × 12 m. Open hand-and-foot interface x=8, parking clamps visible under floor, release handle within left-hand reach. Window frames the first receiving pad.


**Initial state.** Cradle is an open maintenance interface, not Anja’s sealed root collar. Parking clamps sustain the building. All route-preparation facts true before enter prompt becomes eligible.


**Storyboard A / B / C.** A / Human-scale composition echoes the quarry carrier. B / Ivo checks the release handle; it moves freely while parking clamps are loaded. C / The camera stays inside the service room as he steps onto the foot plate, concealing full scale.


**Player action and solution.** Inspect the release handle and local support diagram embodied by actual mechanical linkages. Engage the station with Interact. First, use Hold and Interact together through the established transfer gesture to take the balance from parking clamps; release the clamp lever only after the station owns the assembly. This is a one-time station-enter transaction, not a sustained two-button dexterity test; toggle mode performs the same contextual sequence. Small local posture changes establish control. The next chapter begins without a cut, but the player may pause or quit safely here.


**Threat, failure and recovery.** No surprise permanent conversion. The open release hardware and the blocked-under-load rule are clearly visible. A failed preparation check offers a specific blocked handle response and a route back.


**Narrative consequence.** Ivo knowingly takes temporary responsibility. He is neither tricked into a secret skill nor destined by blood to operate the station.


**Audio direction.** Foot plate, palm contact, clamp transfer and a small breath. Keep the building’s larger creak in reserve for the First Step. Interior crockery remains quiet.


**Checkpoint / save contract.** Checkpoint immediately before ownership transfer and a supported station state afterward. Save station binding, parking clamps, route proof, pads and cohort together.


**Exit / transition.** The same room continues into SQ-09-01. No chapter banner, control tutorial modal or menu replaces the moment.


**Acceptance test.** Input remapping and toggle settings can complete the transfer. Quit/resume cannot close a permanent collar. The player knows how to release the station once mechanically supported.


**Required asset families:** CHR-IVO, RIG-WARD, GME-PAIRED-STATION, GME-SUPPORT-LOCK, ENV-WARD-INTERIOR, PRP-PALE-CURTAIN.


# 14 | C09 — The First Step

**Target:** 30 minutes · campaign minutes 195–225. **Player question:** Can I carry these people until nobody has to hold them?

**Visual identity:** Recognizable rooms become articulated architecture, then return to human scale.

**New experience:** Occupied building control, kneeling evacuation, root release and voluntary help. **Landmark continuity:** The familiar two chimneys and curtain identify the Walking Ward.

**Exit transition:** Ordinary footsteps, accepted hand, darkness, then credits.


| Sequence / play focus | Target | Puzzle IDs |
| --- | --- | --- |
| SQ-09-01 · Taking the balance | 3 min | PZ-26 |
| SQ-09-02 · The First Step | 3 min | Narrative / traversal |
| SQ-09-03 · Carry the rooms across | 5 min | PZ-27 |
| SQ-09-04 · A building crouches | 5 min | PZ-28 |
| SQ-09-05 · The house kneels | 4 min | PZ-29 |
| SQ-09-06 · The last hand | 4 min | PZ-30 |
| SQ-09-07 · Let the emergency finish | 3 min | PZ-31 |
| SQ-09-08 · Long enough to pass | 3 min | Narrative / traversal |


**Chapter review:** confirm the new physical relationship is taught before threat, the landmark stays geographically consistent, and the exit preserves established facts. Review every A/B/C composition at gameplay distance before final art. The following pages are one-sequence build cards; their whitespace is available for team annotations.


## SQ-09-01 | Taking the balance

**Campaign 3:15–3:18 · 3 min · PZ-26 · CK-09-01**


**Blockout.** Same cradle and hostel asset as chapter eight. Initial Ward route q=0, posture neutral, all four shoes supported. Only the near shoe and interior cross-brace visible.


**Initial state.** Station owns the relocation assembly; parking clamp opens only after the accepted transfer. Survivors are in assigned interior bays with secured ordinary grips.


**Storyboard A / B / C.** A / Tight side view links Ivo’s foot to the near support shoe. B / A small directional request shifts an interior brace; residents steady themselves at the edge of frame. C / Camera remains human-scale until forward intent passes the first step threshold.


**Player action and solution.** Test a small left/right lean and use Hold to arrest the local response. Lower and raise within a safe 0.2 m range if desired. Forward input begins a normal assisted step; no new control instructions are required. Neutral settles within the initial supported envelope. The player is free to observe for longer than the planned time. The major reveal waits for actual movement intent rather than a clock.


**Threat, failure and recovery.** The rehearsal zone is nonlethal and cannot strand the building. No prolonged controller lock. Survivors react cosmetically but never fall because the player explores the input range.


**Narrative consequence.** The player recognizes the paired interface yet still perceives it as a large maintenance assembly. The discovery belongs to their attempted movement.


**Audio direction.** Close breath and foot contact; a larger low-frequency structural response enters only as the shoe begins lifting. Do not cue a heroic transformation melody.


**Checkpoint / save contract.** Station checkpoint preserves binding and active support graph. Restoring before the reveal does not mark it as seen. Menu cancellation cannot issue forward intent.


**Exit / transition.** The first deliberate forward step crosses the camera-reveal threshold and continues directly into SQ-09-02.


**Acceptance test.** Players who learned the carrier require no new buttons. Idling is safe. A fast input sequence cannot skip the shoe lift and reveal setup.


**Required asset families:** CHR-IVO, RIG-WARD, GME-PAIRED-STATION, ENV-WARD-INTERIOR, CHR-SURVIVORS.


## SQ-09-02 | The First Step

**Campaign 3:18–3:21 · 3 min · Narrative / traversal · CK-09-02**


**Blockout.** Ward dimensions start at 24 m facade length, 12.6 m height and 6 m depth. Four articulated relocation shoes with 2.4 m bounded stroke. Reveal camera spans approximately 42 m; no organic appendages.


**Initial state.** One assisted step has been requested. Ivo remains in the open cradle. The twelve-person cohort occupies stable interior cells. Scene geometry, rather than a mesh swap, is already the eventual moving building.


**Storyboard A / B / C.** A / Foundation shoe lifts below the familiar room. B / Camera pulls back over approximately 8–12 seconds while movement remains responsive; a cup slides, somebody catches a rail, and the porch changes angle. C / Two uneven chimneys and pale curtain identify the hostel as the whole structure takes the step.


**Player action and solution.** Continue forward or Hold to stop the step mid-phase. The camera reveal is tied to committed gait progress and a safe minimum reveal window, not to confiscating input. A player who pauses or arrests the machine sees a coherent arrested pose; the camera may finish a short readable reframe but not simulate a step they did not request. After the first shoe seats, forward input advances to the narrow-support staging point. The route is guided, but the posture and braking are under player control.


**Threat, failure and recovery.** No lethal decision during the reveal. The first receiving support is deliberately generous. Failure after this sequence must not replay the full pullback unless the user restarts from before its checkpoint.


**Narrative consequence.** Architecture has become Ivo’s external body. The immediate emotional question is not how much he can destroy, but whether the people inside will remain safe.


**Audio direction.** Enormous strain followed by a small domestic break. Individual hands, shoes and dishes make scale personal. No roar, bombastic theme or generalized flesh sound.


**Checkpoint / save contract.** FirstStepSeen commits after the first supported landing and completed readable reveal. Cosmetic cup break becomes a persistent interior state; it cannot repeatedly crash on every reload.


**Exit / transition.** The camera now follows the full building toward the prepared support spine. Interior occupants remain selectively visible through service openings.


**Acceptance test.** Fresh viewers identify the building before an external label. At least four of five express concern for occupants rather than treating it as an empty vehicle. Any comedy-walking response triggers art/gait revision.


**Required asset families:** CHR-IVO, RIG-WARD, ENV-WARD-INTERIOR, CHR-SURVIVORS, PRP-CUP, PRP-CUPBOARD, PRP-PALE-CURTAIN, FX-WARD-DUST.


## SQ-09-03 | Carry the rooms across

**Campaign 3:21–3:26 · 5 min · PZ-27 · CK-09-03**


**Blockout.** Narrow support segment: 16 m authored maintenance spine with 2.4 m step stations; pad heights differ by up to 0.6 m. Front pair reaches a 4 m pier before rear pair leaves the old bank. No foot traverses an impossible unsupported gap.


**Initial state.** Building upright; front support alignment is high relative to rear. A visible plumb indicator and shoe contact marks show the mismatch. Pads match preparations from PZ-25.


**Storyboard A / B / C.** A / Keep front shoe, narrow pier and at least one occupied room in the frame. B / On excessive pitch, a resident catches a bedpost and the plumb indicator approaches its limit. C / When posture lowers and the shoe seats, the same resident relaxes before the next step.


**Player action and solution.** Advance until the front pair meets the narrow pier. Hold before committing the rear pair. Lower posture to bring the effective balance and receiving marks into the permitted envelope. Interact seats the front support lock; release Hold and request the next assisted step. Rear shoes advance in authored order. The player is choosing support, posture and commitment, not individually placing four feet. Attempting forward while misaligned produces a visible blocked-drive state and creak; a deliberate continued overdrive can trigger a short protected failure only after a broad warning.


**Threat, failure and recovery.** Default misalignment is recoverable. A severe committed failure resets to the last stable support without graphic civilian deaths. Holding offers unlimited thinking time; the puzzle still needs correct posture and support engagement.


**Narrative consequence.** Ivo’s new scale increases obligation, not aggression. The earlier receiving-cradle logic now supports inhabited space.


**Audio direction.** Footing contact, wood under strain, one whispered nonverbal gasp and uneven clothing movement. Successful support removes tension layers rather than adding a victory chord.


**Checkpoint / save contract.** Commit stable support snapshots only at verified shoe contacts. Save route q, gait phase, posture, support mask, locks and each survivor bay binding. Interior props reset outside traversal hazards.


**Exit / transition.** The building reaches a wide supported stance before the hanging tram girder. This is a safe observation and checkpoint area.


**Acceptance test.** Outcome is repeatable at 30/60/120 fps. A novice can recover from initial misalignment. The player never needs to solve by memorizing invisible foot order.


**Required asset families:** RIG-WARD, GME-RECEIVING-PAD, GME-SUPPORT-LOCK, CHR-SURVIVORS, ENV-SEAWALL, FX-WARD-DUST.


## SQ-09-04 | A building crouches

**Campaign 3:26–3:31 · 5 min · PZ-28 · CK-09-04**


**Blockout.** Girder segment 14 m. Girder underside clearance 10.6 m; Ward upright height 12.6 m, lowered posture 9.8 m. Safe supported stance before and after. Clearance evaluated against simplified authoritative hulls.


**Initial state.** Girder visibly blocks the upper floor. It cannot be destroyed safely. A sheltered low posture is available through previously learned vertical input.


**Storyboard A / B / C.** A / Frame obstruction and building roofline with unambiguous overlap. B / Lowering makes the hostel adopt the same compressed posture Ivo used under earlier obstacles; people brace independently inside. C / The pale curtain brushes close to the girder while the authoritative collision hull still has margin.


**Player action and solution.** Hold on the supported approach, lower the structure and wait for its posture stop. Release Hold and advance under the girder; the assisted gait remains inside the safe lowered envelope. After the roof clears the far contact plane, brace, raise and engage the far receiving support. Pushing upright into the girder causes visible resistance and a blocked drive rather than silently shattering the inhabited floor. The player must recognize the shared posture language, not discover a new “duck building” button.


**Threat, failure and recovery.** Roof contact is recoverable while both support pairs are safe. Decorative curtain/loose trim may brush without an invisible lethal collision. A committed unsafe lift under the girder gives a clear warning and local reset, not a long falling-house movie.


**Narrative consequence.** A place of shelter behaves like a vulnerable body. Power remains constrained by care for occupants and recognizable architecture.


**Audio direction.** Compressed joints, cloth, dishes prevented from sliding by a resident’s hand. The most intense sound can be a small object almost falling, not an explosion.


**Checkpoint / save contract.** Safe checkpoint before lowering and after far support. Store posture and clearance phase. Restoring a lowered state cannot spawn an upright collider through the girder.


**Exit / transition.** Inland receiving abutments and an exit porch come into view. Occupants can see stable ground but still cannot safely disembark.


**Acceptance test.** The girder problem is understood visually from the approach. Camera motion reduction does not crop the roof. Collision and art margins remain valid after mesh revisions.


**Required asset families:** RIG-WARD, GME-GIRDER, GME-SUPPORT-LOCK, ENV-SEAWALL, CHR-SURVIVORS, FX-CABLE.


## SQ-09-05 | The house kneels

**Campaign 3:31–3:35 · 4 min · PZ-29 · CK-09-05**


**Blockout.** Inland abutment 30 × 15 × 22 m. Ward arrival sockets align with four shoes; porch ramp reaches ground only below 0.8 m threshold. Exit route clear to screen right. Return culvert under near abutment was opened in C08.


**Initial state.** Ward is stable but elevated. Permanent locks open. All twelve survivor slots remain in their known interior bays. Ivo still owns the station process.


**Storyboard A / B / C.** A / Show the inaccessible drop from porch to ground. B / As the house lowers, porch becomes a ramp and each floor changes from strained movement to stillness. C / Occupants leave at different times; Orren helps another person, not in response to a player command.


**Player action and solution.** Lower the Ward onto the prepared abutments. Hold when receiving marks align, engage permanent locks with Interact and release to verify they carry the structure. The porch ramp unfolds through a visible linkage. Survivors then choose their authored safe routes out; Ivo is not required to click individuals. The player maintains the stable posture until the final visible crossing. With weight on mechanical supports, the cradle release becomes available. Exit as Ivo, not as a detached camera.


**Threat, failure and recovery.** Evacuation begins only after stable support and route checks. Small prop obstructions are disabled or cleared before NPC traversal. A stuck NPC watchdog moves them to a nearby valid continuation out of sight, never kills them or increments the count invisibly.


**Narrative consequence.** The building can now stand without a person. Independent departure reverses the exchange’s enforced compensation.


**Audio direction.** Uneven footsteps gradually replace linked strain. Orren’s bent shoe has a recognizable scrape. The low tone disappears only after the last active support is relieved.


**Checkpoint / save contract.** Persist WardSupported, twelve unique SurvivorSafe flags, CradleReleased and root-return access. The final gate needs Orren in the correct route segment, not a newly spawned duplicate.


**Exit / transition.** Ivo descends into the short pre-established root-return culvert beneath the landing. The hostel stays supported in the background.


**Acceptance test.** All twelve are visibly accounted for across framing, not necessarily simultaneously. Full-state reload preserves an empty safe hostel and Ivo outside the station. No remaining personal burden is silently discarded.


**Required asset families:** RIG-WARD, GME-RECEIVING-PAD, GME-PORCH, CHR-SURVIVORS, CHR-ORREN, ENV-INLAND.


## SQ-09-06 | The last hand

**Campaign 3:35–3:39 · 4 min · PZ-30 · CK-09-06**


**Blockout.** Root return 44 m culvert plus 12 m contact chamber. Same root entity as C07, approached from its seaward service side. Governor fitting within 1.0 m of Anja’s hand; escape stair visible behind Ivo.


**Initial state.** DischargeProved, WardSupported and CohortEvacuated all true. Anja remains root owner. The remaining process is an unloaded sequencing governor, not the entire weight of water.


**Storyboard A / B / C.** A / Ordinary boy scale and close footfall return after the large exterior. B / At the hand, camera echoes the opening contact distance; two taps are readable without facial close-up. C / Anja opens her fingers while Ivo takes the governor; leave a quiet composition for deliberate release.


**Player action and solution.** Traverse the established culvert, operate the visible service isolation handle and Interact with Anja’s hand. The final handover validates prepared supports and transfers the governor to Ivo atomically. Hold sustains it while he chooses the moment to let go. There is no countdown. The scene enters an armed final-release state only after a fresh intentional gameplay press, separated from any pause/device event. Toggle mode uses a clearly indicated second intentional action after arming. No secret morality score or alternate rescue ending.


**Threat, failure and recovery.** This contact is nonlethal. Unplugging a controller, losing focus, quitting or opening a menu cannot count as release. Rejected readiness checks report an explicit development assertion; shipping progression should make them impossible.


**Narrative consequence.** Anja cannot be restored, but her suffering need not be inherited. The same gesture means reassurance, recognition and permission to stop.


**Audio direction.** Two close taps, cuff fabric and a tired breath. No lyrical song or voice explains the ending. Let the player wait in a believable room.


**Checkpoint / save contract.** RootReady, PlayerHasGovernor and FinalReleaseArmed are separate states. Suspend preserves the root safely; resume requires new deliberate intent. RootReleased is an idempotent irreversible event.


**Exit / transition.** On confirmed release, the discharge sequence begins along the prepared channel and the root relaxes.


**Acceptance test.** Test every menu/input/disconnect edge around handover. Exactly one release event can fire. Players understand why they are letting go and why this does not destroy the refuge.


**Required asset families:** CHR-IVO, CHR-ANJA, CHR-ROOT, RIG-ROOT, GME-ROOT-GOVERNOR, ENV-BURDEN, PRP-ANJA-CUFF.


## SQ-09-07 | Let the emergency finish

**Campaign 3:39–3:42 · 3 min · PZ-31 · CK-09-07**


**Blockout.** Root escape 60 × 14 × 15 m. Prepared outlet visible through two windows; three familiar traversal obstacles: short gap, lowering stair, duck-under beam. All are within ordinary motor metrics.


**Initial state.** RootReleased true. Water begins its authored channel transfer. The root no longer sustains the local fittings. Escape route’s independent mechanical supports are already present.


**Storyboard A / B / C.** A / Anja’s fingers relax, then the camera follows Ivo rather than lingering on death. B / Two openings show water following the tested path and the supported hostel staying still. C / Local structure settles behind him as the camera leads to each known landing.


**Player action and solution.** Release triggers gates in a verified sequence. Move toward the escape stair, jump a routine 1.6 m gap, wait or step onto the lowering stair at its mechanical stop, and crouch under the beam. The brace has no active network on these fittings; a failed attempt gives a dead-contact response, not an arbitrary power-removal cutscene. Ordinary movement suffices. The sequence is urgent but short enough not to replace the goodbye with a prolonged action finale.


**Threat, failure and recovery.** No unfamiliar hazard language. A failure restores a post-release local checkpoint, never forces another goodbye or reverses Anja’s death. Structural collapse uses authored states; cinematic debris cannot create random blockers.


**Narrative consequence.** Release is safe because the player changed the world. The supported hostel is visual proof that care did not require permanent restraint.


**Audio direction.** Water movement, structural settling and Ivo’s effort. Root strain falls away instead of climaxing into a monster cry. Keep loudness within the established mix headroom.


**Checkpoint / save contract.** Use a post-release immutable story ledger plus local escape snapshots. On reload, root remains released and survivors remain safe. Gate/hydraulic phases reconstruct as a coherent authored state.


**Exit / transition.** Ivo reaches a dead exit fitting and an ordinary gate. Orren is already on the safe side through his independent route.


**Acceptance test.** The escape is solvable on first sight. A retry costs under 30 seconds and does not replay the emotional contact. The water effect agrees with the proved channel.


**Required asset families:** CHR-IVO, CHR-ROOT, GME-BASIN-GATES, GME-ESCAPE-STAIR, ENV-SEAWALL, FX-DISCHARGE, FX-SETTLE.


## SQ-09-08 | Long enough to pass

**Campaign 3:42–3:45 · 3 min · Narrative / traversal · CK-09-08**


**Blockout.** Exit gate 12 × 5 × 8 m, then inland path 52 × 10 × 24 m. Gate contact at x=4; Orren on opposite side; final offered-hand marker on broad level ground before the horizon.


**Initial state.** Powered fitting is dead. Orren’s final route segment is available; survivors are moving independently inland. No threat remains and no final secret puzzle is hidden.


**Storyboard A / B / C.** A / Ivo reaches for the familiar fitting and gets no response. B / Orren pushes the gate by hand and holds it while Ivo crosses. C / Wide human-scale path; Ivo’s curled hand gradually opens to another survivor’s offered hand. Last steps remain playable before fade.


**Player action and solution.** Approach the gate and attempt the natural contact or continue into Orren’s view. He opens it through an ordinary hinged interaction and waits until Ivo passes. Walk inland. At the offered hand, Interact accepts; continuing directional input also completes a gentle authored reach once Ivo is aligned, avoiding a confusing final prompt hunt. The fade begins only after a short shared walk. A player who stops can remain safely in the scene. Credits begin after the emotional image has settled.


**Threat, failure and recovery.** No surprise attack, jump scare, alternate-ending collectible or cruel final death. Orren does not close the gate on Ivo. End-of-game menu input cannot skip the hand accidentally.


**Narrative consequence.** Voluntary help is temporary and human. The last relationship is not synchronized control. The outcome is grief with relief, not a perfect rescue of history.


**Audio direction.** Orren’s shoe scrape, ordinary gate hinge, wind and footsteps with independent timing. No triumphant anthem; a thin tonal resolution may begin only after darkness.


**Checkpoint / save contract.** CampaignComplete records after final walk, with chapter replay states separate from continue save. Reload before completion returns to the safe inland path; after completion menu offers credits/replay without overwriting the ending ledger.


**Exit / transition.** Darkness, then credits and a restrained return to menu. No sequel hook contradicts the emotional resolution.


**Acceptance test.** The ending still communicates when sound is muted. Every survivor offered-hand variant aligns at Ivo’s height. Credits and completion state survive immediate application closure.


**Required asset families:** CHR-IVO, CHR-ORREN, CHR-SURVIVORS, GME-ORDINARY-GATE, ENV-INLAND, FX-SEA.


# 15 | Puzzle framework, physical systems and threats

## A small vocabulary with different reasoning structures

The 31 numbered puzzles include onboarding interactions and the final escape, not 31 equally large logic chambers. Their detailed solutions live in the sequence cards and puzzle register. The principal reasoning languages are clearance timing, orientation, flow diversion, ownership transfer, spatial arrangement, material-state mass, support substitution, competing demands on one Hold, counterbalance, reciprocal posture, buoyancy/air access, safe path certification and inhabited relocation.

Do not add a new mechanic merely to decorate a new room. A new actor must either express an established rule in a meaningfully different topology or earn its cost through a later payoff. Wet blankets teach a state-dependent load; the air bell makes safe space movable; the domestic room makes architecture bodily; the Ward combines those implications at inhabited scale.

## Puzzle actor contract

Every puzzle-bearing actor has a stable entity ID, scene owner, authored starting state, reachable controls, legal state transitions, input requirements, motion coordinate, contact geometry, support conditions, effect bundle, save adapter and test fixture. Critical IDs cannot depend on scene hierarchy names. Duplicating a prefab instance creates a new world ID; duplicating a prefab definition does not alter IDs in existing scenes.

A PuzzleDefinition names the required actors, completion predicate, reversible states, irreversible transactions and canonical recovery checkpoints. It does not contain an opaque script that teleports objects into a solved pose. Sequence-specific orchestration may exist, but it must call the same tested actor interfaces as ordinary play.

Example PZ-11 completion: jack on its receiving rail stop AND jack ratchet seated AND deck physically contacting the jack AND deck owner is MechanicalSupport AND exit route clear. The crowd relief event follows this predicate. It does not fire merely because the player pressed the crank once.

Example PZ-24 completion: deflector pin engaged AND debris rack clear AND test flow observed at safe outlet AND full-release gate still isolated. Changing any dependency before the proof latch mechanically locks invalidates the provisional success. The full story fact commits only after the latch seats.

## Motion families and default tunings

| Family | Authoritative representation | Starting tuning | Recovery |
|---|---|---|---|
| Shutter | One vertical coordinate, motor phase, crush sweep | 8 s cycle; 2.5 s clear plateau; 0.15 m safety margin | Return to readable pre-cycle state. |
| Rotating tread | Hinge angle and angular driver | Slow full cycle; 4 useful orientations; generous landing face | Resume captured phase, not a fresh random phase. |
| Sliding frame | Rail coordinate and latch state | 6 m rail; bounded 0.85 m/s manual push | Hard stops prevent loss. |
| Guided counterweight | Coordinate plus opposing load expression | Limited working stroke; clamped acceleration | Safety catch before irreversible drop. |
| Wet rack | Saturation scalar, drain/inlet state, derived mass | 8 s dry-to-saturated; deterministic drain curve | Recreate one scalar, not cloth vertices. |
| Water region | Volume or normalized level, bounded ports | Level change visible over several seconds | Safe shelf remains available. |
| Air bell | Guided q, dock latch, local pocket, hose | 3.6 m stroke; 2.4 m diameter; fixed authored pocket band | Supported pocket checkpoint. |
| Support/jack | Rail position, extension, ratchet, contact | Contact tolerance 0.02–0.04 m; lock only in range | Explicit blocked response. |
| Harness | Body pose driver with independent awareness layer | Captures main restraint pose, leaves eyes/breath | Resumes interrupted motion before AI replan. |
| Paired assembly | Route q, posture, support mask, station binding | Small carrier first; common controls at all scales | Parking/receiving support required for exit. |

These are authored gameplay models. Incidental physics can enhance clothing, loose debris and small props, but cannot decide whether an essential platform arrives or a survivor survives. Do not promise bitwise physics determinism across machines. Test repeatability of authoritative results with tolerances.

## Load model and physical support

The fictional apparatus captures bodily correction; it does not create unlimited mechanical energy. Show ordinary motors, accumulators and counterweights where movement requires them. Use one normalized load parameter per process to drive strain, pose, sound and contact deformation. Its visual scale is art-directed and does not claim biological realism.

For a simple counterbalance, authored force can follow F = (mA − mB)g − damping × v, integrated at a fixed tick and clamped to the actor's legal stroke. For wet cloth, m = mDry + saturation × waterCapacity. For guided buoyancy, upward drive depends on an authored displaced-volume curve and remains bounded by the guide. Avoid using equations to create unpredictable emergent puzzle solutions; calibration fixtures should confirm the same functional outcome.

Support replacement is explicit. A receiving frame must have a compatible surface, valid alignment and a seated latch before it can own a load. Contact without a latch can temporarily oppose motion but does not claim permanent relief. Once mechanically supported, the load indicator slackens and a personal/anchor release cannot launch the object using stale velocity.

Destruction has stages: intact, warning, break committed, settling, stable debris. Major collision geometry swaps at authored boundaries. Minor shards use pooled physics and are excluded from puzzle routing. Breaks reveal supports or routes; they do not create randomized platform geometry.

## Custodian AI

Use a bounded state machine: Patrol, Inspect, Suspicious, Investigate, ConfirmedPursuit, Reach, Capture, Restrained, Blocked and Return. Patrols are authored lane graphs with visible stairs and depth connectors. A worker never moves between background and foreground without a route.

Initial sight envelope: up to 10 m in a 75° forward cone on ordinary lit ground; shorter inside designated darkness; peripheral suspicion before full confirmation. Query a small set of target points, including head and torso. Cover tags define opaque, silhouette-revealing and open surfaces. The render setup must agree with those tags; fog alone is not reliable cover unless explicitly authored.

Initial detection buildup: roughly 0.6–1.0 s after clear exposure; loud contact can provoke investigation without revealing the player's exact location. Footstep hearing radius is authored by surface and movement, not read from the speaker volume. Accessibility audio changes cannot alter AI hearing. Last-known-position pursuit uses actual observed data, not omniscience.

Initial pursuit speed 4.0 m/s versus Ivo's 4.2 m/s, with acceleration and route-specific head starts. Threat comes from geometry and commitment, not unavoidable faster running. Capture requires reach range, legal facing and a swept contact window. No capture during a protected narrative contact or through solid barriers.

A held harness pauses the main body driver, not cognition. Eyes and breath continue. On release, complete the remaining legal reach motion briefly, then resume sensing. Shielded workers cannot be acquired until the cover is physically displaced or another route is used. Do not add arbitrary “Hold immunity” to preserve a chase.

## Braced Porter AI

The Porter is one worker-rig assembly on a continuous rail network. State machine: Parked, LoadDetected, Orient, Reach, Secure, Retract, Unload, Return, DriveHeld and Obstructed. Each encounter defines legal rail segments, capture zones, accessible drive contact and temporary targets. The gardens, cutting and flooded dock are variations of this grammar, not three separately coded monsters.

Load detection originates at marked connected grates or retrieval objects. The signal must have a visible cable/grate explanation. Orient displays the target direction before reach. Capture reach begins around 3.2 m and a first-use warning lasts at least 1.2 s. Rail travel and arm extension are authored motion coordinates. Overlapping geometry, even during a fast step, must be swept rather than checked at a single sampled pose.

Priority is existing secured load, then the strongest valid local unsupported load, then idle return. The player can divert it with a falling bundle because the retrieval procedure commits to that load. A new target cannot instantly cancel the old capture animation. The flooded dock changes the consequence of unloading; it does not change the worker's supernatural nature or give it free swimming.

The Porter cannot leave its rail, see through every wall, track the brace globally or teleport to keep pace. Its rail and breathing supply are part of level dressing and story. A successful escape visibly isolates the route or places Ivo outside its reach.

## Crowds and survivors

Constrained groups use authored compensation curves tied to actual deck/load parameters, with per-person offsets and independent eyes, head attention, fingers and breathing. Do not use a single identical animation on every person. The movement must read as an imposed mechanical response rather than willing choreography.

The twelve-person survivor roster is finite. Six originate in the exchange queue, three are laundry attendants relieved of load but freed from their communal exit in C07, two are local Burden House bearers, and Orren is the twelfth. All are mandatory route outcomes. Background residents are not silently counted as saved.

Survivor movement uses waypoint segments with capacity reservations and safe-stop poses. Each survivor has one persistent slot ID and at most one active actor instance. Start evacuation only when the porch, support and route are valid. No free navmesh crowd is required inside the moving Ward. Interior positions are local to its rigid room modules and transition to world coordinates at verified exits.

A stuck-NPC watchdog requests a replan to a known local continuation; if that fails, stop the sequence safely and log it in development. A shipping fallback can reposition out of sight to the next validated route point, but it must not invisibly increment the safe count while the visible person remains trapped. All such recoveries require QA evidence.

## Horror without unreliable controls

Horror changes through implication: a useful arrest, a distant breath, a living finger, aware eyes, a familiar room following Ivo, Anja's irreversible connection, and occupied architecture taking his balance. A new scare must not invent a rule the player could not have anticipated.

No fake crash, fabricated save corruption, random input reversal or seizure-like flashing is part of the design. The screen does not lie about an available route merely to punish confidence. Sound and animation may suggest uncertainty while the physical rules remain reliable.

Use anticipation, obscured but inferable sources, delayed consequences and small human reactions. A captured child failure is brief and nonlingering. Civilians are not repeatedly killed as a tutorial. Relief scenes are allowed to remain relief scenes.

## Complete puzzle dependency index

Each concept is specified in its sequence card. The dependency below means a learned rule, not an inventory key. PZ-26 deliberately spans entering the cradle and taking control across the chapter boundary.


| Puzzle | Reasoning / prerequisites | Success predicate |
| --- | --- | --- |
| PZ-01 · Kitchen chair and cover | Teach physical interaction / None | Cover accessible and interaction completed with free hands |
| PZ-02 · First shutter | Teach arrest timing / PZ-01 | Ivo crosses readable clearance without changing selected target |
| PZ-03 · Rotating tread | Choose useful orientation / PZ-02 | Stable arrested surface permits the demonstrated gap |
| PZ-04 · Pursuit door | Release as separation / PZ-03 | Ivo reaches safe recess and door separates the visible guard |
| PZ-05 · Wind panel | Select connected motion / PZ-03 | Traverse panel while unconnected wind remains active |
| PZ-06 · Garden diversion | Resolve flow instead of stop / PZ-05 | Latched side channel lowers float onto traversable stop |
| PZ-07 · First Porter | Read bounded capture space / PZ-04 | Cross connected grate through known drive arrest and stone refuges |
| PZ-08 · Laundry bridge transfer | External ownership / PZ-06 | Anchor sustains bridge and support permits leaving without losing load |
| PZ-09 · Hanging corridor | Spatial access and concealment / PZ-08 | Rack arrangement opens exit and thick cover blocks demonstrated sight |
| PZ-10 · Wet blanket counterweight | Change material state / PZ-06, PZ-08 | Saturated rack positions lift; drain and latch make next passage safe |
| PZ-11 · Queue deck jack | Relieve involuntary compensation / PZ-08 | Mechanical jack supports deck and queue-body constraint relaxes |
| PZ-12 · Conscious guard/cart/shutter | Allocate one Hold and plan release / PZ-04, PZ-11 | Prepositioned cart blocks guard after release; shutter can be Held to exit |
| PZ-13 · Orren's stair pawl | Remove a human dependency / PZ-11 | Ratchet bears staircase and OrrenReleased commits |
| PZ-14 · Exposed counterweight sweep | Read mass trajectory / PZ-03 | Traverse known safe pockets and bounded sweep clearance |
| PZ-15 · Balance carrier | Teach reciprocal posture / PZ-08, PZ-14 | Carrier reaches parked contact and station exit becomes safe |
| PZ-16 · Useful falling mass | Reconfigure energy path / PZ-15 | Receiving cradle catches released block and raises walkway |
| PZ-17 · Porter diversion and moving exit | Commit to release under pursuit / PZ-07, PZ-16 | Salvage redirects capture and resumed drive aligns exit platform |
| PZ-18 · First swim | Learn breath and recovery / PZ-06 | Ivo reaches dry landing with visible recovery opportunity |
| PZ-19 · Moving air shelter | Position safety instead of immunity / PZ-08, PZ-18 | Guided bell and pocket reach upper safe access with hose valid |
| PZ-20 · Obsolete rescue dock | Exploit consistent rescue rule / PZ-07, PZ-19 | Bell avoids tip capture and Ivo secures upper guide from far side |
| PZ-21 · Chamber drain | Reveal through state change / PZ-06, PZ-19 | Water lowered safely and maintenance record/route exposed |
| PZ-22 · Reciprocal domestic room | Reinterpret familiar control / PZ-15 | Room inclines clear of obstruction and parks on support |
| PZ-23 · Support instead of root transfer | Apply relief to Anja's load / PZ-13, PZ-22 | Receiving frame holds room; local root strain reduced and cohort route opens |
| PZ-24 · Discharge proof | Predict large flow safely / PZ-06, PZ-16, PZ-21 | Deflector latched, blockage clear, limited test reaches safe outlet |
| PZ-25 · Ward receiving pads | Prepare future support graph / PZ-23, PZ-24 | Pads/culvert deployed and obsolete pins released without losing occupied refuge |
| PZ-26 · Open cradle and balance | Unify previously learned controls / PZ-15, PZ-22, PZ-25 | Station occupied; valid balance handover; current safe support maintained |
| PZ-27 · Narrow support | Carry occupants through load transition / PZ-26 | Ward center/support envelope permits next route edge without pitching rooms |
| PZ-28 · Crouch under girder | Change architecture's posture / PZ-27 | Lowered clearance envelope passes girder and restores receiving-pad alignment |
| PZ-29 · Kneel and support | End dependence before evacuation / PZ-28 | Porch aligns; twelve survivors exit; locks carry building and cradle releases Ivo |
| PZ-30 · Final handover | Take only unloaded governor / PZ-24, PZ-29 | Mother-to-Ivo ownership transfer after verified safe prerequisites |
| PZ-31 · Deliberate root release | Finish the prepared emergency / PZ-30 | Voluntary armed release commits root fact and safe discharge; postrelease retry is coherent |


# 16 | Art, camera, animation and cinematic direction

## Visual target: a game-rendered world, not a photograph

The target is a restrained stylized 3D image: broad geometric forms, readable planes, carefully selected edge curvature, matte surfaces, limited texture contrast and depth controlled by light and atmosphere. Do not interpret “simple” as crude geometry everywhere. Ivo's hands and a moving hinge need enough shape for their function; a distant wall does not need photogrammetric cracks.

Playdead's model article describes reducing objects toward essential forms; its lighting article explains controlling detail around camera distance and gameplay focus. Those principles inform the target, but the material and rendering implementation below is a new proposal. [R01, R02]

The prior generated frames with glossy puddles, dense concrete noise and large magical glows must not be used as final-quality sign-off. In THE HELD, a Hold connection is mainly communicated by a ceramic vane, cable tension, arrest of motion, bodily response and sound. No constant energy beam, glowing fist, outline aura or frozen spray of particles.

## Palette and value hierarchy

| Role | Starting sRGB reference | Use |
|---|---|---|
| Deep silhouette | #171E21 | Foreground occluders and deep cavities; do not crush all gameplay edges into it. |
| Main structure | #35454B | Concrete, dark workwear and metal planes. |
| Atmospheric middle | #677B80 | Haze and distant facade separation. |
| Chalk / porcelain | #B9C0B8 | Pale cutting, worn fitting edges and selected contact surfaces. |
| Ivo jacket | #586B78 | Slight chromatic separation without a bright heroic marker. |
| Warm practical | #B49B68 | Sparse lamps and inhabited windows, not every interaction. |
| Sea / daylight | #849B9D | Outside horizon and water depth separation. |

These are starting art swatches, not final shader values. Lighting changes perceived color. Review representative shots in grayscale and on an SDR display at several brightness settings. Gameplay readability cannot depend solely on blue-versus-green discrimination. Avoid a single global teal-and-orange grade that erases environmental differences.

Normal composition has a dark foreground frame, legible midground action and lighter or quieter distant depth. A lit background can silhouette Ivo, but his hand/contact and next landing need local separation. Foreground pipes and sheets may frame the route; they may not hide a mandatory landing during its decision window.

## Environment direction and kit boundaries

| Chapter | Architecture and materials | Dominant motion | Light and weather | Hero read |
|---|---|---|---|---|
| Upper Terrace | Narrow municipal tenements; simple wood furniture, plaster and stair steel | Spoon, laundry outside, local structural shift | Weak domestic practicals; rain outside | Mother's cuff, hand contact, failing landing |
| Tidal Gardens | Reclaimed beds, reed screens, retaining walls, service grates | Wind, runoff, bird, retrieval carriage | Exposed gray sky; less enclosed contrast | Connected panel versus autonomous surroundings |
| Laundryworks | Large concrete bays, hanging frames, rinse lifts, sparse pipe runs | Cloth, guided racks, water and searchlight | Soft high windows; sparse amber task lamps | Anchor, weight relationship, cover material |
| Passenger Exchange | Ordered concourse, tram steel, waiting rails, luggage | Independent public routes above imposed compensation | Broad pale side light; quiet upper level | Two social levels and conscious eyes |
| Counterweight Cut | Chalk excavation, gantries, huge dark masses | Grit, cables, bounded falls, carrier shoes | Pale daylight; wind; strongest negative space | Scale and receiving supports |
| Drowned Street | Ordinary shopfronts under later construction | Silt, fish, floating chair, bell rise | Green-gray depth; surface shafts; no glossy chrome | Air boundary and short safe route |
| Burden House | Domestic backs, wall cavities, root service frames | Fingers, breathing, shifting room | Intimate isolated lamps; drier dust | Familiar rhythm given a human source |
| Unfinished Sea | Gate galleries, basin walls, discharge channel, relocation pads | Ordinary sea, test flow, settling supports | Wide cool horizon; reduced industrial pressure | Real sea lower than retained danger |
| First Step | Familiar hostel, open service side, four relocation shoes, inland abutments | Gait, rooms, inhabitants, porch, final water | Large readable silhouette then ordinary daylight | Inhabited architecture and eventual stillness |

Kit interfaces use 0.5 m placement grid and 1/2/4 m standard structural modules, with hero exceptions recorded. Floors, steps and rails must respect the controller metrics before art subdivision. Decorative slope and collision slope are reviewed together. A texture trim sheet may be shared across chapters; repeating the exact hero composition is not acceptable.

## Materials, models and effects

Use a small shader family: opaque stylized surface, translucent cloth, water surface/underwater, emissive practical, decal/contact and atmosphere. Default materials use flat color or low-contrast masks; normal maps are optional and restrained. No high-frequency concrete noise pasted across every surface. Metal highlights are broad and scarce enough to communicate shape. Wetness changes value and localized reflectance; the whole floor does not become a mirror.

Author contact edges and wear around handles, rungs, grip surfaces and receiving pads. These marks explain use. Porcelain is smooth but not luminous; cracked covers are hero variants, not random procedural damage. A human finger beneath a fitting should have enough tonal distinction to be noticed at game distance without becoming photorealistic anatomical horror.

Hero contact characters initially budget 15–25k triangles including clothing; background people 3–8k; important props 0.5–5k; ordinary modular pieces lower where silhouette permits. These are review ceilings, not optimization proofs. Large mesh count, overdraw, skinning and material changes matter alongside triangles. LOD transitions must not change a crucial silhouette, hand gesture or visible support state.

Most cloth uses authored bones or simple deformation with collision-independent cover volumes. Only selected hero cloth needs simulation. Water uses authored surfaces and volume state; falling water follows splines or meshes with limited particles. Dust continues moving during Hold. Warm light does not flare dramatically whenever a button is pressed. The Ward reveal needs falling grit and small domestic reactions, not an explosion of effects.

## Camera system and shot metrics

Use perspective with an initially low-distortion lens, approximately 28–35° vertical field of view, and authored distance rather than a single global orthographic size. Shot review may choose another lens where required. Normal frames show around 14–22 m of playable width; intimate shots 9–13 m; exposed cutting shots 28–40 m; First Step reveal around 42 m. These spans are art-tuning targets, not hard clipping boundaries.

Track along a camera rail offset from the movement lane. Maintain approximately 30–40% of screen width ahead of travel during threat approach, but do not snap direction on a single input tap. Initial horizontal response 0.2–0.35 s; vertical framing uses a dead band during small jumps and explicit targets during large climbs. Camera position and Ivo position are different systems: camera delay cannot delay movement.

A priority stack resolves conflicting volumes: protected contact/reveal, active puzzle framing, threat lead, normal traversal, ambient look. Blends use known entry/exit conditions. The player cannot drag the camera beyond useful puzzle boundaries or look into unfinished room backs. Ultrawide initially uses pillarboxed authored framing rather than exposing unfair offscreen information; a wider policy requires per-shot review.

Reduced-motion mode removes shake, minimizes roll and lengthens nonessential blends. It must preserve the First Step's scale reveal and every mechanical clue. Shake is optional, additive and never the only cue of impact. No camera rotation makes station left/right controls invert.

## Animation direction and authority

Ivo's travel comes from the motor. Locomotion loops are in-place; root motion is limited to explicitly constrained contact actions whose displacement is checked by the motor. Blend from live intent, speed, ground normal and semantic state, not a giant animation graph that also decides puzzle truth.

Foot planting uses anticipated contact and stable surfaces. Hands align to authored sockets for push, latch, ladder, porcelain contact and the two-tap gesture. A one-hand Hold changes available actions and pose; it does not magically free both hands for a heavy push. Additive strain, gaze, breathing, wet discomfort and cautious posture provide expression without replacing every locomotion clip.

A denied interaction needs an authored response: a one-handed test, taut cable, immovable latch or visible obstruction. Normal contact actions accept input immediately, then commit at a short authoritative action time aligned with the hand event. A skipped animation frame cannot skip the game-state transaction. Hold itself arrests the target immediately on valid acquisition; its hand reach blends afterward.

Animation categories in the register cover locomotion, contacts, Hold, station, water, failure, narrative, Custodians, Porter, bearer poses, survivor actions and Ward presentation. A listed clip is a required task, not necessarily a unique long recording. Mirroring is allowed where handedness, brace, cuff and collision remain correct. Reusable loops should avoid distinctive repeated ticks that become conspicuous.

## Cinematic implementation rules

Most story presentation is live gameplay with directed camera and animation. Timeline or equivalent sequencing may coordinate noninteractive layers, but irreversible game facts must be committed by authoritative events outside an animation track. Skipping, loading or disabling a cosmetic track cannot alter whether a support is installed or a person is saved. [R13]

Protected contact windows should generally remain under two seconds; longer authored movement must preserve directional intent where feasible. The First Step pullback takes approximately 8–12 seconds, but does not steal the gait input. The final goodbye permits unlimited waiting. A player who Holds the Ward mid-step sees a stopped mechanism with independent cloth and breath, not a movie continuing behind disabled controls.

For each hero scene, create a grayscale three-frame board from the real blockout camera, then a timed animatic driven by real input capture, then a final lighting/animation pass. Sign off silhouette, intention, contact, causality and recovery in that order. Do not approve only the most attractive still frame.

# 17 | Audio and music production

## Sound is evidence

Every major mechanism has an identity that survives the journey from machine to body: shutter closure, drum repetition, deck compensation, carrier balance, root strain and Ward footing. The player should recognize at least one rhythm before its human source is revealed. Reuse timing signatures and resonant relationships rather than exposing obvious repeated audio files.

The world has four sonic scales: Ivo's close body; nearby mechanisms and contacts; architectural transmission; distant weather and life. The climax changes their relationship. Ivo's effort becomes audible throughout the Ward, then the ending separates human steps from mechanical rhythm.

The audio design is original. Do not imitate INSIDE's specific drones or reproduce its recorded techniques as an aesthetic shortcut. Its shared-state and gameplay-feedback ideas are useful precedents; THE HELD's states and sound materials are its own. [R05, R06]

## Functional mix hierarchy

Highest priority: imminent physical danger, correct interaction feedback, breath/air boundary and support confirmation. Next: Ivo's movement and important nearby human reaction. Then: structural response, environmental storytelling and ambience. Music occupies the remaining space rather than competing for the same cue.

The brace has restrained acquisition, denial, personal sustain, range warning, anchor transfer, mechanical relief and dead-contact sounds. These cannot be indistinguishable variations of one click. Every essential cue has a visible equivalent: vane, cable, contact, waterline, pose or support mark.

Custodian sensing uses logical noise events from surfaces and actions. It does not sample the user's output volume. Muting foley, changing a mix preset or using captions must not change enemy behavior.

## Ambience and music plan

| Region | Ambient layers | Musical posture | Signature silence |
|---|---|---|---|
| Terrace | Rain, spoon, neighboring plumbing, cloth | Very thin domestic unease | Immediately after Anja's two taps |
| Gardens | Wind, reeds, runoff, bird, distant rail | Sparse open harmonics, not constant drone | Porter disappears beneath the underpass |
| Laundry | Ventilation, cloth, water, hidden effort | Rhythmic pressure emerging from machinery | Finger flex after the ceramic shard |
| Exchange | Upper footfall, lower restraints, tram mass | Order becoming uncomfortable | Bodies relax at different times |
| Cutting | Wind, grit, cable and large-space reflection | Wider intervals and thinner density | Between impact onset and final settling |
| Drowned street | Filtered structure, hose, bubbles, distant contact | Slow pressure with safe pockets left clear | First full breath inside the bell |
| Burden House | Familiar rhythms as bodies, cloth, close air | Intimate dissonance, little bass spectacle | Anja refuses the replacement |
| Seawall | Ordinary sea, exposed wind, controlled test flow | Relief that is not yet resolution | The low horizon reveal |
| Ward / ending | Footing, room objects, independent people, discharge | Strain follows support; restrained final tonal release | The root stops and ordinary steps remain |

Use approximately three reusable musical layer roles per region: pressure, fragile tonal material and transition/resolve. The actual cue list can reuse material across regions when memory is intended. No full song is required. Nonverbal breath and exertion are performance assets; critical meaning is not carried by background intelligible dialogue.

## Implementation

Create an AudioEventDefinition library with stable IDs, clip pool, routing bus, priority, loop behavior, variation, attenuation, occlusion policy and restart policy. A simple project-local AudioRouter on Unity audio is the baseline; it may be replaced behind the same interface by licensed middleware after a measured need, not because INSIDE used it. DSP scheduling is appropriate for layered music and coordinated sustained cues; responsive one-shots remain resident and immediate. [R17]

The authoritative gameplay tick publishes motion phase, load, contact, water state, wetness, breath reserve and narrative facts. The presentation layer selects sound. Breath audio may return a cosmetic inhale/exhale phase to animation; it cannot delay a lethal mechanism or suspend the breath budget. A missing clip must not block gameplay.

Use pooled sources and explicit voice limits. Start with 48 active spatial voices plus a small music/ambience allocation, subject to profiling. Critical voices steal from low-priority ambience, never the reverse. Occlusion uses a bounded set of meaningful barriers and room portals, not hundreds of rays per frame. Underwater and air-pocket mixes follow the head's authoritative region state.

Master source recordings at 48 kHz / 24-bit where practical. Deliver dry source, edited asset and in-game event metadata separately. Loop seams, leading silence, clicks, mono compatibility and long repetition are QA tasks. Proposed output target is no clipping and at least 1 dB true-peak headroom after limiting; measure actual sessions rather than assuming a fixed integrated loudness suits all scenes.

## Death, pause and transition policy

Ambient beds can continue across a short local restart if their sources remain plausible. Danger cues, breath and motion-linked loops must restore from the checkpoint phase. A Porter reach sound cannot continue while the restored rig is parked. Audio tails may bridge a fade without retaining misleading spatial information.

Pausing freezes logical danger and breath. Use a paused mix snapshot; music scheduling and cosmetic breath resume from a defined phase or crossfade to a coherent state. On device changes, reconstruct routing without emitting a burst of stacked one-shots. Stream long ambiences, keep critical short cues resident and prewarm the next acoustic space before crossing its threshold.

## Audio acceptance

Test the game on headphones, stereo speakers, mono, low volume and a reduced-dynamic-range preset. Complete all critical puzzles with sound muted and with captions enabled. Run a ten-minute idle loop in every region to catch obvious repetition. Record full finale playthroughs and verify that the small domestic sounds remain audible without overpowering movement and support cues.

# 18 | Engineering architecture and implementation contracts

## Stack and compatibility gate

Start the technical spike with **Unity 6.3 LTS, C#, URP, the Input System, Cinemachine, Timeline and local Addressables**. These are a proposed compatible family, not a prevalidated package lock. Resolve exact package versions together in M00; commit the editor version, manifest and lockfile, and prove a clean-machine packaged build before content production. Unity lists 6.3 LTS support through December 2027. The schedule in this package may outlast that window, so the producer must reserve an engine-support review before alpha; an upgrade is a separately tested branch, never an automatic production update. [R09–R14]

Use Git with large-file storage and locking for nonmergeable binary source assets. The studio may substitute its established version-control system, but not operate without revision history, asset locking and reproducible builds. Keep third-party packages and licenses in a reviewed dependency inventory. No remote account or network connection is required to play the shipped campaign. Analytics are local and opt-in during development tests; distribution of telemetry needs a separate privacy decision.

The recommended baseline does not require a bespoke renderer, ECS conversion, dependency-injection framework, arbitrary node-based programming language or multiplayer-style deterministic rollback. The technical challenge is integrating a bounded set of carefully authored interactions. Add infrastructure only when a measured production problem justifies it.

## Project layout and ownership boundaries

Use assembly definitions to enforce these dependencies:

| Assembly / folder | Responsibility | Must not own |
|---|---|---|
| Held.Core | Stable IDs, clock, typed commands/events, small data structures, logging | Scene objects, audio sources, character animation |
| Held.Gameplay | Motor, Hold ownership, mechanisms, physical constraints, interactions, AI decisions | Menu layout or cinematic-only state |
| Held.Content | ScriptableObject definitions, sequence configurations, route and support graphs | Mutable runtime save data inside shared assets |
| Held.Persistence | Snapshot schemas, version migration, transactions, restore orchestration | Unvalidated direct manipulation of every prefab |
| Held.Presentation | Animation, camera, audio, VFX, UI and view proxies | Authoritative puzzle success, lethal collision or root release |
| Held.Tools.Editor | Validators, fixture builders, previews, inspectors, import automation | Runtime dependencies in player builds |
| Held.Tests | EditMode, PlayMode, packaged-route and content validation tests | Shipping story or art data that tests accidentally change |

Suggested asset roots: `Assets/Held/Code`, `Content/Chapters/C01…C09`, `Content/Shared`, `Art/Characters`, `Art/Environments`, `Animation`, `Audio`, `VFX`, `UI`, `Settings` and `Tests`. Source DCC files live under a separately versioned source-art root; exported runtime assets have a recorded source path. Avoid one folder containing every material, prefab and script.

An application bootstrap scene creates the clock, save service, content registry, input router and presentation routers. Chapter scenes provide data and actors. The bootstrap persists across chapter loads. A single authoritative Ivo actor moves between resident chunks; scenes must not instantiate their own competing player or root installation.

## Runtime actors and authoring definitions

A `MechanismDefinition` contains ID, motion family, legal coordinate range, driver limits, contact sockets, support sockets, collision profile, audio/VFX tags and persistence version. A spawned `MechanismRuntime` owns the current coordinate, velocity, driver phase, load owner, latch/support state and pending transaction. The definition remains immutable.

An `InteractionDefinition` specifies required hands, posture, lane, socket, allowable state, approach clearance, cancel rules and success event. Its runtime interaction reports a reason for denial: out of reach, hands occupied, unsupported, blocked, inaccessible or wrong connection. The animator receives that reason and can express it without altering logic.

A `SequenceDefinition` references its actors, checkpoints, camera volumes, puzzle facts, exit predicate and content bundles. A `NarrativeLedger` records durable facts such as `BraceOwned`, `OrrenReleased`, `DischargeProved`, `WardSupported`, `CohortEvacuated`, `RootHandoverComplete` and `RootReleased`. Facts use stable IDs and explicit prerequisites. They are not strings invented independently by every designer.

For each important family create one reusable prefab and a small number of variants. A shutter in C01 and a shutter in C04 share the same authoritative component, though timing, art and interaction sockets differ. Do not duplicate scripts per room to avoid addressing a framework defect.

## Simulation and frame order

Run authoritative gameplay at an initial **60 Hz fixed step**. Interpolate visible motion at the rendering rate. Never integrate critical motion with an arbitrary render delta or skip a dangerous mechanism's simulation because it is offscreen. Unity's fixed-step guidance supports using a consistent step for physics; this does not establish bitwise determinism across devices. [R16]

At each simulation tick: capture the latest buffered action intent; validate and commit pending interaction/ownership transactions; advance authored mechanism drivers; resolve moving-platform deltas and Ivo's motor; perform critical swept collision and water/head tests; update AI perception and decisions; evaluate puzzle facts; publish immutable presentation events; then offer a coherent snapshot to the checkpoint service. Animators, cameras, sound and effects read the completed state afterward.

An event generated by presentation cannot retroactively change the tick that generated it. An animation event may report a foot contact or request an already-authorized latch sound; it cannot decide whether a bridge is supported. Avoid dependence on Unity component update order as an undocumented game rule. Use an explicit simulation coordinator or clearly ordered systems.

During a large frame stall, do not silently fast-forward Ivo through a hazard while only drawing the last state. Bound catch-up work, monitor missed-time conditions and pause safely during exceptional recovery. Performance faults should be visible in development logs and corrected, not hidden by unpredictable time scaling.

## Motor and collision implementation

Use a kinematic capsule motor with explicit ground probes, slope classification, step-up and depenetration limits. The engine CharacterController is an acceptable spike implementation; retain it only if moving-platform, ledge, water and crush fixtures pass. Its documented behavior is a tool baseline, not a finished character-feel solution. [R15]

Movement is expressed along the active lane spline with a local tangent and vertical axis. Depth connectors are authored transitions with start/end eligibility, camera support and collision clearance. Normal input never allows Ivo to walk arbitrarily into a background performance. Reversal changes acceleration immediately; orientation and animation blend independently within safe contact limits.

A moving platform supplies its previous/current transform and angular contribution at Ivo's support point. The motor applies that delta before desired travel. Launch velocity may inherit an explicitly clamped platform contribution; every launch puzzle records that choice. On landing, solve relative motion rather than snapping the capsule to an interpolated render pose.

Ledge detection requires an allowed ledge tag, a valid hand point, torso clearance and a stable destination. A vault or climb uses a reserved motion corridor and short root-motion-assisted segment, while the motor remains authoritative. Cancel into a safe drop when the support changes. Do not let a clip pull the capsule through a ceiling. One-handed emergency catches are separate, authored interactions; they do not silently permit all climbing while Holding.

Use swept tests for shutters, rail carriers, the Porter cradle and Ward support shoes. Lethal crushing requires a closing pair that actually leaves insufficient clearance; a cosmetic prop touching Ivo is not sufficient. Small debris cannot pin or kill the player. Configure collision layers for player, mechanism, AI, cosmetic physics, sensor, interaction and water. Maintain a matrix in settings and validate it in CI.

## Hold transaction implementation

A Hold request identifies a candidate, requested owner and input intent token. Validation checks identity, exposed contact, range/route, current owner, required hands and legal mechanism state. A successful request becomes an atomic transaction at the next simulation boundary.

Transfer moves ownership from Personal to a specified Anchor without an intermediate unowned state. Release returns control to the correct driver using the stored coordinate and legal resumable velocity. When a mechanical support catches the load, it becomes the sustaining state and clears stale release velocity. An anchor is not a magical infinite slot; its compatibility, occupation and structural capacity are authored and visible.

The ownership API should return a structured result, not only `true/false`: accepted transaction ID; denied reason; affected actors; resulting owner; and required presentation reaction. Repeated commands with the same transaction ID must not transfer twice. A scene unload cannot destroy the only active owner; the streaming dependency graph pins every actor in the active load relationship.

Run unit tests for two simultaneous transfer requests, release during transfer, leaving range during an interaction, an anchor destroyed by an authored event, loading a snapshot with a missing owner and pausing on every transaction boundary. Invalid saved ownership must resolve to a known safe checkpoint, never an unowned falling assembly.

## Water, buoyancy and the bell

A water region stores surface level, permitted bounds, connections to other bounded regions, flow direction and exposure state. Its visual shader samples the same region surface used by swimming and floating objects. Art may distort reflections and normals but cannot show dry air where the head test considers Ivo submerged.

The garden float and air bell use constrained buoyancy models. Their position is solved from region level, guide coordinate, displacement and authored limits; neither relies on many loosely connected rigid bodies. Critical hinges, guides and stops are authoritative. Floating background chairs and small fragments can use cheaper physics without affecting puzzle validity.

The bell's air pocket is a moving volume derived from its pose, water level and retained-air state. A hose supplies air only while connected and unpinched. The obsolete retrieval dock rotates the bell beyond its retention angle and spills the pocket. The hazard is not merely “the bell went deeper,” which would contradict its purpose. Capture and tilt are visibly telegraphed. A failed attempt restores bell pose, winch phase, pocket, hose and Ivo's breath together.

Implement underwater filtering through explicit acoustic and visual regions. Do not turn all sound off underwater; preserve readable transmitted mechanisms and critical cues. Test water transitions at the surface repeatedly for flicker, breath exploit loops and animation state thrashing.

## Walking Ward implementation

Build the Ward as a **guided articulated relocation rig**, not a free-running quadruped simulation. The authored route contains support nodes, reachable edges, receiving-pad identities, clearance envelopes and stable retry poses. Four relocation shoes follow a gait planner that transfers load only through validated contacts. The visible building body has controlled heave, pitch and crouch coordinates.

Horizontal input requests travel along the route. Vertical input requests posture within a state-dependent range. Hold arrests the authorized assembly. Contextual Interact engages a reachable support or exits a mechanically parked cradle. Neutral input completes only the minimum safe settling phase; it does not autonomously solve the next puzzle. Input direction remains consistent while the camera widens.

At the narrow support, the support graph and center-of-mass envelope determine a legal advance. At the girder, the clearance envelope requires a lowered posture before advancing. The player chooses and understands these actions; inverse kinematics handles individual shoes. Deliberate wrong input produces visible strain and recoverable contact limits before any failure. Avoid opaque balancing meters or arbitrary hidden failure thresholds.

Interior people and props live in local room coordinates. Critical inhabitants use authored brace/catch/recover reactions, not uncontrolled ragdolls. A limited pool of dishes, doors and light fixtures responds to acceleration. Each interior has containment bounds and sleep rules. At the final landing, all twelve cohort slots transfer from Ward interior presentation to the exit route through one authoritative evacuation service.

The Ward begins and ends at states compatible with saving. `FirstStepSeen` protects the reveal from unnecessary replay; it does not skip required mechanical states. The camera's reveal curve is tied to route progress and an event phase, not a wall-clock timer that runs while paused. A reduced-motion mode preserves scale revelation with less pitch and camera travel, without removing information.

## Camera, animation, audio and event interfaces

Camera volumes provide focus targets, view span, lead, safe margins, depth masks and transitions. Cinemachine is used to implement these controlled views, not as permission for automatic framing that hides a puzzle. Timeline may coordinate a short in-world event, but the event controller owns its phase and pause/reload behavior. [R12, R13]

Animation receives speed, acceleration, grounded/support state, hands occupied, load strain, breath, wetness, attention target and interaction phase in a presentation snapshot. Audio reads the same snapshot and mechanism phase. Critical cues can be scheduled accurately, but gameplay remains authoritative if an audio device fails or a voice is virtualized. DSP-scheduled music must be re-aligned after pause/restore; it is not the save clock. [R17]

Use typed events such as `LoadOwnershipChanged`, `SupportEngaged`, `WaterRegionChanged`, `CohortMemberReleased` and `RootReleaseCommitted`. Every event includes source ID, sequence ID, simulation tick, transaction ID and payload version. A one-shot listener tracks the event's unique identity. Avoid unstructured global messages such as `SendMessage("Open")` or a universal event bus with undocumented string keys.

## Tools that make production faster

Create a sequence fixture builder that spawns the defined mechanism families, a player start, camera bounds, checkpoints and a test exit. Add a live Hold graph viewer showing owners and pinned dependencies. A support-envelope overlay draws reachable pads, legal Ward poses and crush volumes. A water/bell overlay draws actual head-air tests and retained-air volume. AI debug shows perception sources, last known position, rail reach and detection timing.

An event scrubber should load approved snapshots and replay deterministic authored phases without pretending to scrub arbitrary unconstrained physics. A camera contact-sheet exporter captures every narrative and puzzle composition in standard and accessibility settings. An asset validator checks naming, scale, collision, socket IDs, LODs, shader variants, missing licenses and references. A content dashboard exposes each sequence's prerequisite facts, current state and exit predicate.

Build these as small editor tools serving actual fixtures. Do not spend months on a general-purpose game-making framework. The first tool must save time on a real Laundry or Ward task before it is generalized.

## Performance and optimization contract

Select and record the minimum-spec fixture at the vertical slice, including CPU/GPU/RAM, operating system, driver, storage and resolution. Until then, “1080p60” is a target, not a tested hardware claim. Record uncapped CPU and GPU frame times as well as capped frame pacing. A frame that averages 16 ms but frequently spikes to 80 ms does not meet the cinematic target.

Initial working envelopes: main-thread gameplay plus engine work under roughly 8 ms, render-thread work under roughly 5 ms and GPU under roughly 13 ms on the floor fixture, leaving headroom in the 16.67 ms frame. These are separate parallel measurements, not additive budgets. A provisional resident-memory alarm at 6 GB on an 8 GB-RAM test configuration forces review; set actual shipping limits from measured OS and GPU needs. No number here guarantees compatibility before profiling.

Budget transparencies, fog, water reflections, dynamic shadows, skinned inhabitants and Ward interior props explicitly. Use baked/static lighting where appropriate, simple collision, LODs, sensible texture residency and pooled transient effects. Keep only nearby high-detail rooms active; distant rooms may use presentation proxies that cannot participate in logic. No critical hazard sleeps merely because it leaves the camera.

Track zero unexpected per-frame allocations in steady critical loops as an engineering goal, but optimize measured hot paths rather than applying obsolete blanket rules. Profile release-like packaged builds, not only the editor. Include cold disk runs, rapid retries, long sessions, repeated water entry and the maximum Ward/crowd view. Low-quality settings may reduce reflections, fog and incidental debris, but never hide contacts, danger cues or water boundaries.

## System delivery index

Milestones below identify first proof/review. Later dependencies may use synthetic fixtures at that proof, but must be integrated with real campaign facts by M14. The full system dependency graph is in the register.


| System / first proof | Accountable discipline | Acceptance |
| --- | --- | --- |
| SYS-01 · Bootstrap and service lifetime / M00 | Engineering | Single clock/player/save authority; clean startup and return to menu without duplicate services |
| SYS-02 · Input and accessibility routing / M01 | Gameplay/UI | Remap and toggle work; canceled input is not voluntary release; focus/device tests pass |
| SYS-03 · Lane capsule motor / M01 | Gameplay | Run/turn/jump/crouch/step pass contact gym at 30/60/120 fps |
| SYS-04 · Ledge and ladder interaction / M01 | Gameplay/animation | Clearance and hand constraints validated; blocked climb returns safely |
| SYS-05 · Contextual interaction resolver / M01 | Gameplay | Stable socket selection and informative denial; no target switching during committed action |
| SYS-06 · Hold ownership transactions / M02 | Gameplay | One personal owner, atomic transfer, legal release, support capture and idempotence tests pass |
| SYS-07 · Mechanism drivers / M02 | Gameplay/physics | Bounded slider/hinge/rotator/track coordinates resume consistently after Hold |
| SYS-08 · Supports and load graph / M03 | Gameplay | Mechanical support removes bearer requirement; no orphan owner or cyclic unsupported state |
| SYS-09 · Moving support and crush / M03 | Gameplay/physics | Relative platform motion and swept closing volumes pass all frame-rate fixtures |
| SYS-10 · Puzzle facts and sequence exits / M04 | Design/engineering | Exit depends on physical predicate; sequence jump cannot bypass root prerequisites |
| SYS-11 · Checkpoint snapshot service / M04 | Engineering | Coherent state restores after every ownership/support boundary |
| SYS-12 · Save integrity and migration / M10 | Engineering | Interrupted write preserves prior generation; supported schemas migrate and invalid data fails safely |
| SYS-13 · Local streaming and residency / M07 | Engineering | Active relationships pin chunks; no activation deadlock or unbalanced asset handle |
| SYS-14 · Camera volumes and leads / M07 | Technical art | Route/threat/interaction all legible at standard and alternate aspect ratios |
| SYS-15 · Animation presentation state / M01 | Animation/engineering | Responsive motor plus additive contact/gaze/breath; animation never owns puzzle outcome |
| SYS-16 · Foot/hand contact IK / M07 | Animation/technical art | Contacts meet moving sockets; correction cannot drag capsule through obstruction |
| SYS-17 · Audio router and mixes / M05 | Audio/engineering | Critical cue allocation and dry/wet/breath state remain synchronized through restart |
| SYS-18 · VFX reaction bundles / M07 | VFX/technical art | Connected response with scalable cosmetic pools; Hold never freezes unrelated particles |
| SYS-19 · Custodian perception and pursuit / M06 | Gameplay/AI | Sight/hearing/last known route explain capture; covered and exposed harness rules visible |
| SYS-20 · Harness restraint and awareness / M06 | Gameplay/animation | Body channel arrests while eyes/breath persist; no immunity introduced for convenience |
| SYS-21 · Porter rail rescue AI / M06 | Gameplay/AI | Detect/reach/secure/retract cycle stays bounded; sack demonstration and three encounter contexts agree |
| SYS-22 · Sheet concealment / M05 | Design/AI | Wet thin silhouette differs from thick cover; visibility derives from tagged blockers not arbitrary camera state |
| SYS-23 · Water volume graph / M08 | Gameplay/technical art | Level/flow/head and rendered surface agree; bounded overflow and drainage are recoverable |
| SYS-24 · Swimming and breath / M08 | Gameplay/animation | Surface hysteresis, one-hand swim, warnings, refill and assistance pass timed routes |
| SYS-25 · Bell air pocket and winch / M08 | Gameplay/physics | Pocket follows pose/level; tipping spills air; saved hose/pocket/player remain coherent |
| SYS-26 · Wet-cloth mass / M13 | Gameplay/technical art | Saturation and drainage drive predictable rack/lift position without uncontrolled fluid simulation |
| SYS-27 · Reciprocal balance station / M09 | Gameplay/animation | Same travel/posture/Hold vocabulary on carrier, room and Ward; only safe exit permitted |
| SYS-28 · Ward support/gait planner / M09 | Gameplay/technical art | Authored support edges and clearances prevent impossible steps; narrow support and crouch puzzles pass |
| SYS-29 · Ward local-room presentation / M09 | Technical art/animation | Interior actors/props move locally and stay contained; readable domestic consequences |
| SYS-30 · Survivor roster and safe routes / M14 | Gameplay/AI | Twelve unique slots; independent movement on safe routes; no duplicates or stranded mandatory actors |
| SYS-31 · Narrative event phases / M04 | Design/engineering | Idempotent opening/reveals/ending survive interruption and do not steal unrelated control |
| SYS-32 · Final root release guard / M09 | Engineering/UI | Pause/focus/disconnect/quit never commits release; prerequisites and postrelease persistence enforced |
| SYS-33 · UI and settings / M10 | UI/engineering | Menus, slots, caption settings and readable save errors work on controller and keyboard |
| SYS-34 · Localization and captions / M13 | UI/audio | No audio-only required solution; text expansion and sound direction caption layouts pass |
| SYS-35 · Sequence/ownership debug tools / M04 | Tools/engineering | Designers inspect live owner/support graph and jump to approved fixtures without editing scripts |
| SYS-36 · Camera/storyboard capture tool / M07 | Tools/technical art | Standard/reduced-effects contact sheets generated for each sequence review |
| SYS-37 · Asset import validation / M07 | Tools/technical art | Scale/sockets/collision/shader/LOD/source checks catch bad exports before merge |
| SYS-38 · Build and regression automation / M00 | Engineering/QA | Clean checkout packages; EditMode/PlayMode reports and build provenance archived |
| SYS-39 · Performance capture and route replay / M07 | Engineering/QA | Packaged cold/warm route captures include frame time, allocation, memory and streaming stalls |
| SYS-40 · Release packaging and recovery / M18 | Production/engineering | Clean install/update/uninstall, valid saves, credits/licenses and debug-stripping checks pass |


# 19 | Save, checkpoint, streaming and recovery design

## Three different kinds of state

**Durable narrative state** records irreversible facts: a person was released, a receiving pad was installed, the Ward was supported, or the root was released. **Encounter state** records the coherent arrangement from which the current reasoning unit restarts: mechanisms, owners, water, AI and player placement. **Presentation state** records enough event phase to avoid replaying an important revelation unnecessarily, without preserving every cosmetic particle.

Do not confuse these layers. A chase death must not undo the mechanically supported staircase from the prior sequence. A completed narrative event must not leave the next encounter's geometry in an unsolved state. Cosmetic debris need not be restored individually unless it carries gameplay meaning; critical debris must be an authored mechanism with serialized state.

A save file contains a schema version, build/content version, campaign slot, timestamp, current sequence/checkpoint IDs, ledger, player state, actor snapshots, streaming dependencies, cohort roster, event phases, settings reference and an integrity check. Save actor snapshots by stable GUID, not scene hierarchy index or runtime instance ID. Reference missing actors explicitly as errors during validation.

## Checkpoint placement

Each sequence card defines a primary checkpoint and additional internal reasoning milestones where needed. `CK-CC-NN` is the sequence-level checkpoint identity; internal variants add a suffix such as `-A` or `-B`. Entry snapshots begin before a readable safe observation. Completion snapshots occur after the player reaches stable ground and ownership has settled, not halfway through a transfer.

During chases, target replay of roughly 15–45 seconds; a longer encounter may contain its own safe recovery threshold. During puzzles, preserve the solved setup before the risky traversal. At the signature First Step, preserve `FirstStepSeen` and resume a failed maneuver from the next stable support, not from the beginning of the reveal. The player should repeat the decision they failed, not the emotional scene preceding it.

A checkpoint is accepted only when its dependency set is resident, no transaction is half-committed, Ivo has a valid support/air condition, and the next threat cannot immediately kill him before control returns. Unsafe state requests are deferred to the next approved boundary. A designer may explicitly author a moving-platform checkpoint, but it must restore relative pose and motion, not place Ivo at an old world coordinate.

## Suspend-on-quit and crash behavior

Normal quit writes a suspend snapshot at a coherent simulation boundary. Mid-interaction and paired-station states require all involved actors to be serialized together. Where a complex authored event cannot be suspended safely, quit records the nearest approved event phase and returns to that phase on resume; the menu should not promise exact-frame suspension. Progress loss must remain short and documented in the test matrix.

Write to a temporary file, validate its structure/checksum, flush as supported by the platform and replace the active save through the safest supported atomic replacement method. Retain at least one previous valid generation. Do not claim identical filesystem guarantees on every platform; test the chosen implementation under interrupted writes and full disk conditions. A failed save preserves the old file and shows a nonintrusive but legible error.

A crash returns to the most recent valid committed state. The game must not silently create a new campaign when a save is unreadable. Offer recovery from the prior generation and make the limitation clear. Settings are stored separately so a corrupt progress file does not erase accessibility choices. Never include personal identifiers or unnecessary external account tokens in offline saves.

## Restore order

Pause simulation and cancel live input intents. Read and validate schema, migrate supported older versions and choose the intended checkpoint or suspend phase. Load required local scenes/assets; register authoritative actors; apply the narrative ledger; restore mechanism coordinates, owners and supports; restore water and bell volumes; restore cohort and AI; place Ivo relative to his valid support or station; restore event phase; rebuild presentation; run consistency checks; then enable input and simulation.

Do not start actors' default patrols or motors before snapshots are applied. Do not restore an anchor after allowing its owned platform to fall for one tick. A silent verification frame may be used before fade-in. Audio ambience can bridge the transition, but any mechanic cue must correspond to the restored phase. Existing transient audio voices and VFX are cleared or re-seeded deliberately.

## Streaming topology

Use a persistent bootstrap plus local additive content chunks. A chapter is an organizational unit, not necessarily one large scene. Begin with two to four chunks per chapter, adjusted to measured memory and visibility. Keep the active chunk, necessary neighbors, current load dependencies and any visible long-distance proxy resident. Prefetch before a sightline or fast movement can expose the next area.

The hostel landmark uses low-detail proxies in earlier chapters, all referencing the same visual identity but carrying no physical authority. During the finale, activate the authoritative Ward and disable overlapping proxies. The root installation and survivor roster likewise have one authority; distant appearances are views, not duplicate actors.

Addressables scene activation has a documented queue interaction: leaving a scene load unactivated can block other asynchronous operations. The baseline therefore loads/activates scenes with gameplay actors gated off, then applies state and enables them deliberately. Do not wait on another queued asset while holding an unactivated scene in a way that deadlocks loading. Retain and release asset handles in a paired ownership policy. [R14]

One-way transitions can retire distant chunks only when their persistent state has been committed and no active connection crosses the boundary. The final root-return culvert remains in the finale's dependency set. A falling structure cannot unload the scene containing its sustaining anchor. In debug builds, show the reason each chunk is pinned so accidental retention is discoverable.

## The final release is a protected transaction

The root sequence has explicit states: `MotherOwnsRoot`, `HandoverAvailable`, `IvoOwnsGovernor`, `ReleaseArmed`, `ReleaseCommitted` and `EscapeComplete`. Its prerequisites are `DischargeProved`, `WardSupported`, `CohortEvacuated` and a valid handover. The root governor is mechanically unloaded by prior preparation; Ivo is not personally sustaining the whole basin.

In sustained-Hold mode, the player performs a deliberate hold after handover to arm release. Only a corresponding voluntary release of that gameplay action while the application is focused, unpaused and using a connected device can commit. Input cancellation, focus loss, device removal, menu opening, remapping or accessibility changes **disarm** the release and preserve ownership. On resume, require a fresh deliberate input. Never interpret a canceled Input System action as the story's choice.

In toggle/accessibility mode, use an explicit contextual release action with a short confirmation affordance after handover. Do not add a different ending or punish players for using assistive controls. The confirmation is part of this irreversible interaction only; ordinary Hold remains immediate.

Once committed, write `RootReleased` and the post-release escape checkpoint as one coherent progression transaction. Subsequent deaths cannot resurrect Anja or replay her death as routine failure. The root motion can resume at a safe authored event phase if a crash interrupts the event. Pause freezes settling clocks. A speedrunner cannot activate the release before evacuation by reaching the socket through unintended geometry.

## Cohort consistency

The twelve survivor slots store identity, release fact, current safe route stage, active presentation and evacuation status. Only one live representation per slot is permitted. A person in the Ward cannot simultaneously appear walking along a background route. The evacuation service checks all twelve valid exits before `CohortEvacuated` becomes true, with each transition driven by completed safe-route movement rather than an arbitrary timer.

Critical cohort traversal is authored and robust. If a cosmetic collision prevents progress, move the person through a concealed, prevalidated recovery transition; log the fault. Do not leave a released person permanently stuck behind a decorative bucket. The player is not responsible for managing twelve independent pathfinding bugs.

## Migration and delivery tests

During development, content snapshots may become invalid after geometry changes. Mark incompatible internal saves clearly and provide a debug chapter entry; never let a changed prefab silently reinterpret old coordinates. Before beta, establish the versions that the release build will migrate. Retain fixture saves for every chapter, paired station, air bell, Ward support state and root phase.

Test interrupted writes, missing chunks, missing actor IDs, conflicting owners, duplicate cohort IDs, full disk, read-only location, controller removal, system sleep, pause during breath warning, quit on a transfer frame and repeated reload during the root handover. The release gate requires a successful complete run from a clean installation and a second run assembled from every supported checkpoint/suspend category.

# 20 | Asset-production plan and handoff standards

## How to commission this game

The asset register is a **work-package list**, not a claim that the game contains only that many meshes. An environment kit includes its modules and variants; a rig includes its movable parts, sockets and collision; an audio family includes variations and event metadata. The register contains the complete important-family baseline, while the animation and audio registers expose additional task-level scope. Do not add their counts together as though they measure the same unit.

Begin with greybox geometry and the actual gameplay camera. Approve silhouette, scale, reach, support contacts and route before expensive detailing. A model that looks attractive in a turntable but hides a contact from the game camera is not approved. The final asset must include source file, export, materials, collision/LOD policy, sockets, import preset and a test-scene placement.

`SM_` names static meshes, `SK_` skinned meshes, `MAT_` materials, `T_` textures, `PF_` prefabs, `ANM_` clips, `AUD_` audio exports and `SO_` data definitions. Stable register IDs remain metadata rather than being replaced by a filename. A variant suffix expresses a meaningful difference: exposed/covered, dry/wet, supported/unsupported or near/far. Do not create uncontrolled `final_v2_new_fixed` chains.

## Delivery gates for a single asset

**Blockout:** scale, pivot, collision and sockets work with the controller. **Gameplay art:** silhouette/materials communicate the correct state in an actual sequence. **Presentation complete:** animation, audio, effects and camera integration agree. **Validated:** save/restore, performance, accessibility and alternate state tests pass. **Approved:** source, license, naming and production sign-off are recorded.

An artist does not need to implement every system personally, but the handoff must identify which sockets and state changes the engineer will bind. Engineers must not silently move a pivot or resize collision after animation approval. Changes flow back to the source asset and its dependent fixtures.

## Characters and rigs

Ivo needs one hero skeleton with reliable fingers, shoulders, hips and foot contacts. His brace hand stays consistent across mirrored animations. Anja's normal, transported and root presentations share an identifiable cuff and hand shape. Orren's identity is carried by his coat and shoe as well as his body. Adult variants can share a skeleton and locomotion base, but their constrained poses and post-release reactions must not look like a synchronized crowd loop.

Custodian A and B share the AI/animation framework and differ in physically readable port coverage. The Porter is one human character plus one rescue rig, not three unrelated monsters for garden, quarry and water. The Ward uses a single landmark design across far proxies, static appearances and final articulated rig. These reuse decisions are fundamental production controls.

The animation register lists initial authored clips/poses. Some can become additive layers or reusable transitions after testing; others, such as the mother's refusal and final offered hand, need specific contact choreography. Approve hero contacts from the gameplay camera at normal speed and frame-by-frame. Keep original capture/source curves so later socket revisions are possible.

## Environment kits and modularity

Use a 0.5 m structural grid with smaller authored offsets for contacts. Primary rooms use 1, 2 and 4 m wall/floor increments where composition allows; hero irregularity is added deliberately, not through random transforms. The grid is a production convenience, not a visible aesthetic requirement. Stair dimensions follow controller metrics and are tested before dressing.

Each chapter kit needs floor/wall transitions, ends/corners, supports, background masses, occlusion pieces and a small original prop vocabulary. Reuse pipe, rail, door and lamp families across chapters, while changing layout, scale, materials and acoustic behavior. The quarry should not look like the laundry painted white. The drowned street should preserve domestic proportions beneath later structural layers.

The Ward interior must be designed in both static and moving states. Every loose prop receives one of three policies: fixed dressing, bounded cosmetic physics or authored hero action. Only the last category is allowed to carry a critical narrative beat. Cupboards, beds, curtains and inhabitants require local contact/containment coordinates. Avoid filling invisible rooms merely to satisfy an imagined complete building.

## VFX and material authoring

Effects must answer to state: wind remains independent of Hold; cable strain responds to load; water marks follow water level; dust continues falling around an arrested assembly. Keep the effect graph shallow and inspect particle counts in the maximum finale view. A critical interaction cannot rely on bloom, reflection or volumetric settings that may be disabled.

Use a small material family with explicit per-instance values rather than unique 4K textures on every prop. Preserve broad surfaces and controlled roughness. The white porcelain contact is a material/shape distinction, not an emissive waypoint. Reserve warm light for practical lamps, domestic reminders and selected contact reflections. No decorative lightning tether belongs to the approved Hold mechanic.

## Audio and UI delivery

Audio packages include clean source, edited variations, loop metadata, event tags, spatial policy, caption needs and rights. Variation counts in the register are starting allocations for performance and production estimation, not quotas to fill with near-duplicates. A good six-variation family is preferable to eighteen indistinguishable files.

UI work includes boot, settings, pause, continue/slot recovery, captions, glyphs, save errors, credits and the protected final-release affordance. There is no persistent gameplay HUD by default. Essential accessibility can add unobtrusive status information, including breath assistance or captions, without changing the ending. Text is localization-ready even though spoken exposition is absent.

## Counts and estimating

The workbook leaves person-day estimates blank until a responsible owner estimates the package using measured slice throughput. Blank is not zero. Estimate source creation, integration, review and likely rework separately in the team's scheduling tool. The tracker provides a scope baseline, not a completed commercial budget.

The full asset-family list below is mirrored in `assets.json` and the workbook. Full clip/pose and cue-family lists are provided in their dedicated registers. No font binaries, reference screenshots, proprietary game assets or finished engine project are included in this package.

## CHR asset-family register


| ID | Required subassets / deliverable |
| --- | --- |
| CHR-IVO | 1.52 m boy mesh; ash-blue jacket; bare/shod hand sockets; brace fit; wet material; four additive strain presentations; close hand LOD |
| CHR-ANJA | Repair-worker mesh; identifiable double-stitched cuff; normal/transport presentations; matching integrated hand presentation |
| CHR-ORREN | Elderly worker mesh; bent shoe; missing coat button; constrained/free/recovered states on shared adult skeleton |
| CHR-CUST-A | Covered-contact Custodian; waterproof coat; padded harness; torch; visibly closed protective port |
| CHR-CUST-B | Exposed-contact Custodian; same adult skeleton; readable porcelain socket; conscious facial micro-motion |
| CHR-PORTER | Adult rescue-worker body and head fitted to rig; independent gaze and breathing; wet/dry variants |
| CHR-ROOT | Anja-root visible body proxies; hand and cuff fidelity; irreversible integration visible without gore; shared identity, not new monster |
| CHR-BEARER-01 | Queue worker base body A; leaning constraint poses; eyes and fingers independent of forced torso |
| CHR-BEARER-02 | Laundry attendant base body B; standing strain; wrist/drum relationship; released stumble |
| CHR-BEARER-03 | Local bearer base body C; overhead support posture; load-release recovery |
| CHR-BEARER-04 | Adult base body D for cohort variation; layered work clothes; nonuniform gait and recovery |
| CHR-BEARER-HAND | Readable hand/forearm insert; porcelain shell alignment; fingernail motion; single reveal variant |
| CHR-RESIDENTS | Background resident variants assembled from adult bases; groceries and terrace gestures; no independent survival logic |
| CHR-SURVIVORS | Twelve roster-based presentation prefabs assembled from bearer bases and Orren; no twelve additional unique sculpts |


## FAUNA asset-family register


| ID | Required subassets / deliverable |
| --- | --- |
| FAUNA-WADER | Small coastal bird; forage/idle/flee; disconnected from Hold and harmless to stealth |
| FAUNA-FISH | Sparse fish silhouettes; idle and disturbance response; no collectible or combat function |


## ENV asset-family register


| ID | Required subassets / deliverable |
| --- | --- |
| ENV-TERRACE | Kitchen wall/window/door modules; apartment hall; landing; risers; exterior facade; trim; roof silhouette; repair alcove |
| ENV-SERVICE | Concrete corridor straight/corner; door frame; stairwell; crawl throat; railing; utility recess; handrail conduit |
| ENV-GARDENS | Raised beds; drain channel; bank corners; exposed ledges; allotment retaining walls; reed patch; stone refuges; loading grate |
| ENV-CULVERT | Low drain tunnel; grate openings; crawl slope; daylight exit; root-return service culvert; drip ledges |
| ENV-LAUNDRY | Tall column bays; gantry rail; machine plinths; drying-frame track; brick/concrete walls; lower catch shelf; upper search catwalk |
| ENV-EXCHANGE | Public concourse; restrained waiting bay; tram platform edge; luggage recess; under-track supports; ticket/window silhouettes |
| ENV-CUT | Chalk walls; excavation ledges; counterweight shafts; receiving sockets; exposed track; salvage rack; large distant mass silhouettes |
| ENV-DROWNED | Submerged shop fronts; old tram stop; submerged windows; stairs; dry landing; bell guide shaft; waterline portals |
| ENV-BURDEN | Reverse apartment walls; service slits; body-link bays; exposed bearing chambers; root approach; safe cohort exits |
| ENV-SEAWALL | Retaining gates; inspection walkway; ocean-facing aperture; basin wall; discharge duct; deflector pit; inland support piers |
| ENV-WARD-INTERIOR | Three-story room kit; kitchen; dormitory; stair spine; service cradle; front porch; window/curtain sockets; containment bounds |
| ENV-INLAND | Dry receiving platform; ordinary gate wall; embankment steps; rail path; distant coast; final quiet walking lane |
| ENV-HOSTEL-PROXY | Distant hostel LOD/proxy with two chimneys and pale curtain; no duplicate gameplay authority |
| ENV-SHARED-PIPES | Straight/elbow/tee/valve pipe kit; wall and ceiling mounts; scale convention |
| ENV-SHARED-RAILS | Railing/handrail/conduit modular kit; socket-compatible corners and damaged ends |
| ENV-SHARED-DOORS | Domestic/service doors and frames; clearance and grip sockets; closed/open variants |
| ENV-SHARED-FIXTURES | Lamps, meters, terminal housings and signs; limited readable civic icon set |


## GME asset-family register


| ID | Required subassets / deliverable |
| --- | --- |
| GME-LEVER | Shared one-hand lever family; rest/travel/latched states; visible mechanical linkage; interaction sockets |
| GME-TRAM | Suspended transit carriage; bogie and support linkage; interior silhouettes; load-bearing deck interface |
| GME-BRACE | Portable restraint mesh; palm contact; ceramic vane; range-tension animation; nonmagical signal cue; hand-fit rig |
| GME-WALL-FITTING | Standard single contact; exposed and covered mounting; cable socket; state vane; damaged porcelain reveal variant |
| GME-ANCHOR | Transfer socket; compatible load plate; occupied/free readable states; concealed bearer connection |
| GME-SHUTTER | Sliding shutter family; track; motor; contact; safe recess markers; swept crush volume; lower and upper stops |
| GME-ROTATOR | Four-orientation rotating maintenance tread; axle; contact; walkable surfaces; bounded angle driver |
| GME-LANDING | Hinged apartment landing; capture/support sockets; damaged edge; underfloor collision; transport load connection |
| GME-WINDSCREEN | Broad hinged panel; wind driver; connected contact; recoverable fall shelf; clear walkable face |
| GME-SLUICE | Main gate; guide; wheel/one-hand latch; level linkage; visible high/low overflow markers |
| GME-DIVERSION | Latched branch gate; channel geometry; one-hand control; direction-readable flow outlet |
| GME-FLOAT | Rail-guided work float; lower/upper stops; bounded buoyancy; stable foot surface |
| GME-PORTER-DRIVE | Rail motor and exposed restraint contact; linked grate detector; actuator phase display through motion |
| GME-BRIDGE | Laundry bridge assembly; hinge; transfer contact; receiving support; railings; clear traversal face |
| GME-DRYING-FRAME | Sliding/rotating fabric rack; grip sockets; travel stops; interaction/camera clearance envelope |
| GME-WET-RACK | Blanket rack with dry/wet mass state; drainage geometry; bounded weight coordinate; attached cables |
| GME-RINSE | Redirectable rinse outlet; lever; readable stream; saturated-cloth driver link |
| GME-LIFT | Counterweighted service lift; guide; car floor; gate; support socket; constrained vertical driver |
| GME-TILT-DECK | Exchange deck; pivot; queue linkage; support point; controlled tilt; occupancy-safe limits |
| GME-JACK | Mechanical service jack; crank requiring free hands; clear supported-state pawl; load plate |
| GME-GATE-CART | Track-guided barrier cart; two-hand grip; one-hand brake; fixed end stop; obstruction collision |
| GME-HARNESS | Exposed restraint brace; locked skeletal channels; torso control plus independent eyes/breath; shielded variant |
| GME-STAIR-PAWL | Stair support ratchet; lever; visible engaged teeth; released-body linkage |
| GME-SWEEP-DRIVE | Bounded counterweight sweep; safe floor pockets; contact and timed motor phases |
| GME-PAIRED-STATION | Two-hand/foot interface; accessible approach; control pose; visible support and exit lock; safe cancellation |
| GME-COUNTERWEIGHT | Suspended masonry mass; suspension frame; authoritative drop coordinate; no cosmetic destruction dependency |
| GME-RECEIVING-CRADLE | Guided catch cradle; support stops; accepts released mass; linked lift cable; no bounce softlock |
| GME-LIFT-WALKWAY | Walkable raised segment; cable linkage; receiving stop; bounded vertical movement |
| GME-SALVAGE-RELEASE | One-hand release lever; suspended bundle; visible Porter capture path; persistent diverted state |
| GME-EXIT-PLATFORM | Rail-driven escape platform linked to Porter motor; fixed alignment window; ride-safe collision |
| GME-WATER-VOLUME | Bounded water regions; head-surface tests; port links; swimming/wetness/audio region definitions |
| GME-AIR-BELL | Guided open-bottom bell; pocket shell; viewing gap; internal latch; hose socket; roof guide |
| GME-AIR-POCKET | Moving retained-air volume; water-level/pose dependency; head-space preview; dock spill state |
| GME-BELL-WINCH | Guided winch; lower/upper catches; contact; resumable phase; hose accommodation |
| GME-DOCK-CRADLE | Obsolete retrieve-and-tip dock; clear rotation hazard; tipped bell spill relationship; limit stops |
| GME-DRAIN-PUMP | Chamber drain valve/pump; bounded water-level change; exposed wall record; safe outlet |
| GME-BODY-LINK | Visible restraint linkage between mechanism and bearer; torso correction channel; tension-only presentation cable |
| GME-RECEIVING-FRAME | Domestic support frame; movable in guided slot; clear lock; supports room without bearer |
| GME-BASIN-GATES | Retained-water gates; supported/personal/root relationships; controlled opening phase; contact and seals |
| GME-ROOT-SERVICE | Root handover mounting; Anja socket; portable governor contact; protected release input affordance |
| GME-TEST-VALVE | Limited proof-flow control; pressure gauge as readable movement; resettable test state; no irreversible early flood |
| GME-DEFLECTOR | Guided discharge deflector; receiving stops; latched safe angle; visible unsafe/tested outlet paths |
| GME-DEBRIS-RACK | Authored removable flow blockage; clear controls; guided debris state; pooled cosmetic fragments |
| GME-RECEIVING-PAD | Inland foundation pad family; support ID; height/readability marks; activated/deployed state |
| GME-RELOCATION-PIN | Obsolete hostel restraint; release handle; visible released/installed state; sequenced dependency |
| GME-GIRDER | Low overhead obstruction; clearance envelope; visual underside scrape cues; no break-through solution |
| GME-PORCH | Ward entrance ramp; kneel-to-ground relationship; cohort exit portal; collision lock at support |
| GME-SUPPORT-LOCK | Ward mechanical lock; load-transfer indicator; prevents station exit before safe support |
| GME-ROOT-GOVERNOR | Unloaded final sequencing governor; single contact; guarded handover/release state; root gate dependency |
| GME-ESCAPE-STAIR | Settling stair route; short authored collapses; stable retry ledges; post-release state variants |
| GME-ORDINARY-GATE | Dead-terminal exit gate; manual hinge; Orren grip sockets; voluntary hold and release |


## RIG asset-family register


| ID | Required subassets / deliverable |
| --- | --- |
| RIG-TRANSPORT | Anja transport carriage; harness; rail wheels; transfer connection; two Custodian handling sockets |
| RIG-PORTER | Overhead rescue rail carriage; arms made of machinery; catch cradle; hose; rail reach and capture envelopes |
| RIG-CARRIER | Small quarry balance carrier; articulated shoes; paired station mount; parking lock; tilt/route controls |
| RIG-DOMESTIC-ROOM | Movable room assembly; constrained wall/floor; paired interface; receiving-frame contact; local props |
| RIG-ROOT | Integrated root installation; mechanical collar; distributed contacts; Anja proxies; force-state presentation |
| RIG-WARD | Hostel shell; four hydraulic relocation shoes; guided gait; two chimneys; service cradle; rooms; crouch; porch; support locks |


## PRP asset-family register


| ID | Required subassets / deliverable |
| --- | --- |
| PRP-CHAIR | Lightweight kitchen chair; grip; safe slide; cover access; shared noncritical chair variations |
| PRP-CUP | Cup/spoon domestic motif; small impact and vibration; Ward contained-physics variant |
| PRP-ANJA-CUFF | Double-stitched sleeve identifier matched across human and integrated presentations |
| PRP-REED-SCREEN | Lightweight garden screening; wind deformation; distinct from connected puzzle panel |
| PRP-SACK | Supply sack; first Porter demonstration target; catch-compatible shape; soft-looking but bounded motion |
| PRP-GROCERY | Resident basket and parcels; background ordinary life; noninteractive collision-free dressing |
| PRP-LAUNDRY-CART | Trolley shell; wheels; cloth piles; optional guided push; readable solid cover |
| PRP-SHEET | Thin wet translucent and thick opaque variants; silhouette behavior authored for stealth |
| PRP-BLANKET | Dry/wet material and shape; rack attachment; mass-state visual cue |
| PRP-PORCELAIN-SHARD | Tiny broken cover piece; snag/reveal interaction; readable shape without sparkle |
| PRP-LUGGAGE | Bags/cases/cart loads for exchange; restricted silhouette clutter; no random route blockage |
| PRP-ORREN-PROPS | Bent shoe and missing-button coat variants; continuous identity at release/evacuation/gate |
| PRP-GANTRY | Steel background gantry family; cable guides; readable distant support mass |
| PRP-FLOAT-CHAIR | Guided decorative floating chair; water-level response; harmless to swimmer route |
| PRP-FLOOD-MARK | Old waterline decals; salt band; repaint layering; consistent height across connected spaces |
| PRP-OLD-HARNESS | Removed restraint silhouettes; mounting scars; abandoned covers; visual institutional history |
| PRP-BED | Dormitory bed; local Ward contact points; survivor brace socket; no free heavy projectile |
| PRP-CUPBOARD | Ward cupboard with bounded hinged door; catch and settle states; controlled interior clutter |
| PRP-PALE-CURTAIN | Landmark curtain with consistent tear and color; far proxy, near cloth and Ward-motion variants |
| PRP-PORCELAIN-COVERS | Intact/cracked/removed cover states for repeated institutional fitting language |
| PRP-TOOLS | Anja's screwdriver, cover fasteners and small repair tray; opening contact scale |
| PRP-SIGNAGE | Original evacuation/relief/safety symbols and sparse local text; localization-safe optional language |
| PRP-HANDRAIL | Human-worn hand-contact finish and double-tap sound surface; reused throughout route |
| PRP-INTERIOR-LOOSE | Controlled Ward dishes, books and small parcels; containment pools, no lethal projectiles |


## FX asset-family register


| ID | Required subassets / deliverable |
| --- | --- |
| FX-RAIN | Sparse rain layers; contact splashes; always moves during Hold; quality-scalable without hiding routes |
| FX-DUST | Falling dust/motes; Hold distinction; no global freeze; bounded pooled emitter |
| FX-WIND | Reed/cloth motion field and grit; decorative motion independent of restraint |
| FX-WATER-FLOW | Inlet/diversion/discharge stream meshes and particles; parameters from water graph |
| FX-CABLE | Cable tension and small oscillation; owner/load response; no luminous energy tether |
| FX-CONTACT | Tiny contact glint, ceramic vane response and fingertip pressure; clear without bloom dependence |
| FX-CHALK | Pale quarry dust, grit and chips; impact response at receiving mass |
| FX-IMPACT | Material impact particles; bounded debris pools; ground contact lighting response |
| FX-BUBBLES | Swim/bell bubble cues; air loss and breathing event tags; capped particle count |
| FX-SILT | Underwater local disturbance with recovery fade; never hides essential destination indefinitely |
| FX-WATER-MARK | Exposed wet/dry edge following drained region; environmental record reveal |
| FX-DRIPS | Persistent droplets and water trails after leaving submerged area; wetness decay |
| FX-SEA | Calm outside sea surface and sparse foam; distinct from retained basin; low horizon movement |
| FX-DISCHARGE | Final gate outflow, spray and debris response; follows proofed route and authored phase |
| FX-WARD-DUST | Foundation dust and interior settling on First Step; per-support origins; controlled opacity |
| FX-SETTLE | Post-release small structural settling; no undeclared lethal cosmetic rubble |
| FX-FOOT-CONTACT | Surface-specific dust/splash traces; animation foot-contact event integration |
| FX-LIGHT-RESPONSE | Selected fixture flicker/rim response to mass impacts; no random epilepsy-inducing strobe |


## MAT asset-family register


| ID | Required subassets / deliverable |
| --- | --- |
| MAT-SURFACES | Shared matte concrete, chalk, painted steel, wet stone, cloth, skin and porcelain masters; bounded local wear |
| MAT-WATER | Bounded water shader, reflection/refraction quality levels, surface/head alignment debug |
| MAT-GLASS | Simple pane/frosted-glass material; transparent sorting reviewed in sheet and water scenes |
| MAT-FOG | Layered depth fog and local light shafts; quality and accessibility variants |


## LGT asset-family register


| ID | Required subassets / deliverable |
| --- | --- |
| LGT-PROFILES | Nine chapter lighting profiles plus reveal/underwater/root presets; grayscale read tests |


## UI asset-family register


| ID | Required subassets / deliverable |
| --- | --- |
| UI-BOOT | Title, initial brightness, input device prompt and first-run accessibility entry |
| UI-MAIN | New/continue/slots/settings/credits/quit screens; keyboard/controller focus; safe-area support |
| UI-PAUSE | Resume/restart/settings/quit; clear restart confirmation and protected root behavior |
| UI-SETTINGS | Remap, toggle Hold/grip, breath assist, reduced motion, captions, mix, brightness and display menus |
| UI-GLYPHS | Licensed or original keyboard/controller glyph atlas; switch by active device, readable scales |
| UI-CAPTIONS | Directional non-dialogue sound captions; size/background controls; critical cue priority |
| UI-SAVE | Small saving/failure/recovery indicators; no intrusive checkpoint ceremony |
| UI-ERROR | Corrupt save, disk failure and incompatible version recovery panels; preserve old progress |
| UI-CREDITS | Scroll and licenses; skippable after ending; no required lore or sequel reveal |
| UI-ROOT-CONFIRM | Accessible deliberate release affordance; re-arm after pause/focus/device loss |
| UI-INPUT-HELP | Minimal contextual first-use prompts; fade after confirmed use; replayable help in pause |


## CIN asset-family register


| ID | Required subassets / deliverable |
| --- | --- |
| CIN-OPENING | Event-relative kitchen/landing/transport camera and interaction phase asset |
| CIN-FINGER | Porcelain snag, fragment and living fingernail reveal; optional observation hold |
| CIN-EYES | Conscious restraint gaze event; body/micro-motion separation test |
| CIN-ANJA | Cuff recognition, two taps, failed extraction and refusal sequence; interrupt-safe phases |
| CIN-SEA | Camera reveal contrasting retained basin with calm lower sea; continuous control |
| CIN-FIRST-STEP | Progress-driven pullback; room reactions; domestic prop cue; reduced-motion variant |
| CIN-ROOT | Handover, goodbye, deliberate release and postrelease recovery phase assets |
| CIN-END | Ordinary gate and offered hand; final walking and fade; no loss of agency before gesture |


## DATA asset-family register


| ID | Required subassets / deliverable |
| --- | --- |
| DATA-COHORT | Twelve stable survivor IDs, look variants, release facts and route presentation configurations |
| DATA-CAMERA | Sequence camera volumes, emphasis targets, occlusion masks and reveal paths |
| DATA-PUZZLES | Thirty-one puzzle definitions, initial states, support graphs and exit predicates |
| DATA-CHECKPOINTS | Forty primary checkpoint definitions plus authored internal safe phases |
| DATA-AUDIO | Cue router definitions, buses, mixes, priorities, captions and phase mapping |
| DATA-LOCALIZATION | Stable strings, glyph metadata, captions and UI layout expansion tests |


## BUILD asset-family register


| ID | Required subassets / deliverable |
| --- | --- |
| BUILD-STORE | Original key art/capsule plan, truthful screenshots/trailer capture, description, disclosures and credits |
| BUILD-LICENSES | Third-party inventory, source permissions, legal notices and attribution records |


## Animation allocation by category

The complete named clip/pose list is in `animation.json`, CSV and the workbook. These are tasks, not a claim that every item requires a separate long motion capture.


| Category | Initial tasks |
| --- | --- |
| Locomotion | 24 |
| Hands and traversal | 24 |
| Hold and load | 23 |
| Water | 19 |
| Narrative and reactions | 22 |
| Mother | 13 |
| Custodian shared | 18 |
| Porter rig and person | 17 |
| Shared bearer/cohort | 19 |
| Orren | 9 |
| Ward rig authored poses | 17 |
| Ambient life | 6 |


## Audio cue-family register

Initial variations include one-shots, loop layers and music stems; counts are for planning and should change with testing, not become padding quotas. Full driver/caption notes are in the audio register.


| Cue family | Scope | Initial variations |
| --- | --- | --- |
| FOL-STONE | Dry stone step/run/land | 12 |
| FOL-METAL | Metal plate/grate/rail contact | 12 |
| FOL-WOOD | Domestic timber/damp boards | 8 |
| FOL-WET | Wet steps and droplets decaying after water | 12 |
| FOL-CLOTH | Jacket/grip/crouch cloth movement | 12 |
| FOL-HANDS | Porcelain, rail and tool hand contacts | 10 |
| VOC-IVO | Breath/rest/effort/fear/recover nonverbal set | 18 |
| VOC-WATER | Swim breath/warning/surface recovery | 10 |
| VOC-ANJA | Effort, transport, root breathing and final exhale | 8 |
| VOC-CUST | Effort, restrained breathing, capture reactions | 10 |
| VOC-BEARER | Individual strained/free breaths and recovery | 16 |
| SIG-TAPS | Two taps on hand, rail and root contact | 6 |
| SFX-BRACE | Acquire/release/deny/range warning | 8 |
| SFX-ANCHOR | Transfer vane and sustaining strain | 6 |
| SFX-SHUTTER | Motor/stop/load/catch/impact layers | 8 |
| SFX-ROTATOR | Rotation axle/stop/strain | 6 |
| SFX-SLUICE | Gate guide, lever and restrained water load | 7 |
| SFX-FLOAT | Guide creak and lower/upper stop | 4 |
| SFX-RACK | Drying frame slide, hinge and catch | 8 |
| SFX-WET-RACK | Saturation drip, cable tension, draining | 6 |
| SFX-JACK | Crank, pawl and supported settling | 6 |
| SFX-CART | Brake, wheel roll, stop and guard obstruction | 6 |
| SFX-TRAM | Suspended tram strain and floor lean | 6 |
| SFX-COUNTER | Cable travel, falling mass and cradle catch | 10 |
| SFX-PAIRED | Contact, shift, brace, park and exit | 8 |
| SFX-PORTER | Detect, rail move, reach, secure, retract, tip | 14 |
| SFX-CUST-STEPS | Floor and stair pursuit footsteps | 12 |
| SFX-TORCH | Torch handling and sheet search movement | 6 |
| SFX-BELL | Winch, hull, internal latch and guide catch | 8 |
| SFX-AIR | Hose flow, bubble loss and pocket spill | 8 |
| SFX-DRAIN | Drain startup, level fall and final trickle | 6 |
| SFX-ROOT | Distributed strain, breath-linked structure, relaxation | 10 |
| SFX-WARD | Support shoes, hydraulic strain, room creaks, settling | 16 |
| SFX-DOMESTIC | Cup/spoon/cupboard/bed/cloth small events | 12 |
| SFX-DISCHARGE | Governor, gates, flow, channel impacts | 12 |
| SFX-GATE | Ordinary manual gate and voluntary release | 4 |
| AMB-TERRACE | Interior room, rain outside, distant evacuation | 4 |
| AMB-GARDENS | Wind, reeds, runoff and distant town | 5 |
| AMB-LAUNDRY | Ventilation, distant rollers and sheet movement | 5 |
| AMB-EXCHANGE | Public upper hall and restrained lower bays | 4 |
| AMB-CUT | Wind across pale void, grit and cables | 4 |
| AMB-DROWNED | Transmitted creaks, water pressure, pocket interior | 5 |
| AMB-BURDEN | Small mechanical breath rhythms in wall cavities | 4 |
| AMB-SEAWALL | Retained basin versus ordinary calm sea | 5 |
| AMB-INLAND | Unsynchronized footsteps, dry wind, settling distance | 4 |
| FAU-BIRD | Wader call, feet and wing departure | 5 |
| MUS-PRESSURE | Low tension and irregular tonal strain stems | 4 |
| MUS-RECOGNITION | Fragile sparse motif around familiar gestures | 3 |
| MUS-DEPTH | Submerged texture with clear breath space | 3 |
| MUS-CARRY | Ward effort tonal layer and subtraction on support | 4 |
| MUS-RELEASE | Very sparse release and ending tail | 3 |
| UI-SELECT | Focus, accept, cancel, error and save failure | 6 |


# 21 | Development roadmap and acceptance gates

## Schedule model

The schedule is a **120-week planning scenario**, not a guaranteed delivery date. Weeks are relative to a properly staffed kickoff. It assumes nine sustained core roles: director/lead level designer; two gameplay/technical engineers; one technical artist; two environment artists; one character animator; one producer with embedded QA coordination; and one sound designer. Specialist character art, additional animation, accessibility review, localization and external QA are contracted when their work is ready. One person may cover more than one role only if capacity is explicitly reduced elsewhere.

Nine people over 120 weeks represent 1,080 gross person-weeks, not 1,080 weeks of uninterrupted asset production. A provisional 62% hands-on production factor yields about 670 person-weeks after allowing for coordination, leave, review, integration and rework; this is an estimating assumption to replace with actual data. It does not price the game. Local rates, taxes, equipment, licenses, outsourcing, marketing, distribution and contingency require a separate funded budget.

Milestone windows overlap because prototypes and content work can proceed in parallel. Listed dependencies mean required evidence/ready components before the gate is accepted, not that every task must wait for the previous window to finish. A prototype may use clearly labeled synthetic state; the full end-to-end gate may not. Systems and asset registers identify their first review or proof milestone, not necessarily final completion.

The first risk to retire is **the shared carrier-to-Ward control language**. The second is **water and air-pocket fairness**. The third is **the conscious-bearer revelation**. Do not spend a year producing corridors before testing these.

## What counts as the vertical slice

M13 is the actual twenty-four-minute Laundry chapter at representative shipping quality: transfer bridge, hanging corridor, wet-cloth counterweight and living-finger reveal. It must include movement, puzzles, threat, full animation, lighting, effects, sound, captions, save/reload, streaming and performance. A montage or isolated beautiful room is not the slice.

Because the Laundry does not contain the final transformation, M13 also requires a separate three-to-six-minute First Step quality benchmark, built on the M09 mechanical proof. This exposes the cost of occupied-room reactions, camera expansion, support animation and domestic sound before bulk production. It is not counted as additional campaign duration.

The first fifteen-minute and thirty-minute builds are chronological onboarding tests, not substitutes for the slice. The first complete chapter is the eighteen-minute Upper Terrace. The full end-to-end build occurs before alpha and must reach the real ending. Alpha means planned feature/content completeness; beta means a stable representative experience; release requires evidence, not just completion of a calendar week.

At every gate record the build hash, platform, owners, unresolved defects, test evidence and scope changes. A rejected gate creates a corrective plan and date reforecast. Never relabel a failed prototype “alpha” to preserve the schedule.

| Gate | Window | Playable / review focus |
| --- | --- | --- |
| M00 · Project foundation and reference capture | Weeks 1–2 | Packaged executable opens a metric room and exits cleanly on two machines. |
| M01 · Movement and interaction prototype | Weeks 3–5 | A five-minute traversal loop with no debug-only movement and a controller/keyboard alternative. |
| M02 · Central Hold mechanic prototype | Weeks 4–7 | A repeatable gym that arrests, transfers, resumes and physically supports the same mechanisms. |
| M03 · First complete puzzle prototype | Weeks 6–9 | A six-to-eight-minute room sequence with an actual solution and recoverable failed approaches. |
| M04 · Core gameplay loop and narrative-state prototype | Weeks 8–11 | Ten-minute continuous route including a transfer and an early hint of a hidden bearer. |
| M05 · Horror and tension prototype | Weeks 10–13 | An eight-minute tension route with one safe teaching moment, one threat and one quiet realization. |
| M06 · Custodian and Porter prototypes | Weeks 11–16 | Separate representative Custodian and Porter encounters with correct retries. |
| M07 · First integrated environment and pipeline | Weeks 12–17 | Five-to-eight-minute packaged environment with genuine transitions rather than editor teleport. |
| M08 · Swimming and air-bell risk prototype | Weeks 14–20 | A ten-minute underwater route from first swim to moving air pocket and escape from the retrieve-and-tip apparatus. |
| M09 · Reciprocal balance and Walking Ward risk proof | Weeks 14–22 | A twelve-to-fifteen-minute progression from small carrier to First Step and two Ward maneuvers. |
| M10 · First fifteen-minute chronological build | Weeks 18–22 | The actual first fifteen minutes from a new game, not a montage of later rooms. |
| M11 · First complete chapter | Weeks 21–25 | The full approximately eighteen-minute Upper Terrace chapter in a packaged build. |
| M12 · First thirty-minute continuous build | Weeks 24–28 | First thirty active minutes without debug jumps; the remaining garden route may continue beyond this test boundary. |
| M13 · Shipping-quality vertical slice and flagship benchmark | Weeks 25–34 | Continuous twenty-four-minute Laundry chapter from entry to exit, plus separate flagship benchmark. Neither is passed by a trailer or static screenshot. |
| M14 · Full end-to-end playable campaign | Weeks 35–56 | New game to final fade with no editor commands, teleport, placeholder win button or skipped climax. |
| M15 · Alpha — feature and content complete | Weeks 57–78 | Whole campaign with all player-facing systems and content represented; only polish/optimization/localization fixes remain. |
| M16 · Beta — stable representative experience | Weeks 79–94 | Complete representative game suitable for an external test cohort under controlled distribution. |
| M17 · Optimization and final polish | Weeks 95–106 | Full game at agreed quality/performance tiers with final-length transitions and release candidate content. |
| M18 · Release candidate and delivery rehearsal | Weeks 107–112 | Exact candidate build distributed through the intended test channel and played from a clean machine to ending. |
| M19 · Final production build and launch | Weeks 113–116 | Public release candidate identical to signed artifact; complete campaign and settings available offline. |
| M20 · Reserve, stabilization and post-release review | Weeks 117–120 | Stable supported build; fixes preserve existing player progress and canonical ending. |


## M00 | Project foundation and reference capture

**Weeks 1–2. Evidence dependencies:** Kickoff approval.


**1. Build.** Create repository, clean build pipeline, editor/package lock, naming rules, ID registry, input shell and ownership of every first-sprint task. Capture a licensed local INSIDE reference session and compare observations to the proposed metrics.


**2. Required assets.** Metric block meshes, temporary Ivo capsule, neutral material, original placeholder glyphs, reference review template.


**3. Working systems.** Bootstrap, build automation, test runner and basic settings; no external account needed to launch.


**4. Playable deliverable.** Packaged executable opens a metric room and exits cleanly on two machines.


**5. Tests.** Clean checkout/build, controller recognition, package compatibility, source-license inventory and initial frame-time capture.


**6. Problems to watch.** Unreproducible local setup, unsupported package combination, accidental external-service dependency, copied reference assets.


**7. Exit gate.** Technical lead signs a reproducible clean-machine build; director signs evidence-versus-assumption reference sheet; producer assigns M01–M09 owners.


## M01 | Movement and interaction prototype

**Weeks 3–5. Evidence dependencies:** M00.


**1. Build.** Build the controller gym: run/stop/turn, gaps, slopes, steps, ledges, ladders, crouch, chair push and rejected heavy interaction. Establish socket and hand-occupation rules.


**2. Required assets.** Temporary Ivo rig, locomotion/interaction clips, simple contact surfaces and grip points.


**3. Working systems.** Input, lane motor, buffering, ledge queries, interaction resolver, initial presentation state.


**4. Playable deliverable.** A five-minute traversal loop with no debug-only movement and a controller/keyboard alternative.


**5. Tests.** Thirty, sixty and 120 fps; reversal responsiveness; capsule clearance; wrong approach; remapping; sustained-input assistance.


**6. Problems to watch.** Sliding feet, delayed valid jumps, inconsistent step height, root-motion penetration, ambiguous target choice.


**7. Exit gate.** Routine gap and stop tests pass repeatedly; fresh users can move and interact without verbal coaching; movement values are recorded, not hidden in prefabs.


## M02 | Central Hold mechanic prototype

**Weeks 4–7. Evidence dependencies:** M00, M01.


**1. Build.** Implement slider/rotator drivers, one personal owner, transfer anchor, support capture, range warning and resumable release. Add the live ownership graph.


**2. Required assets.** Shutter, tread, single socket, anchor, brace vane and support block; temporary sounds and hand poses.


**3. Working systems.** Mechanism drivers, atomic transactions, ownership validation, hand requirements and initial state serialization.


**4. Playable deliverable.** A repeatable gym that arrests, transfers, resumes and physically supports the same mechanisms.


**5. Tests.** Transfer/release on adjacent ticks, two requests for one owner, leaving range, pause/device cancellation, reload while held.


**6. Problems to watch.** Double owners, free-fall transfer frame, unlimited stored impulse, random target changes, water/time-freeze ambiguity.


**7. Exit gate.** Ownership and release invariants pass automated fixtures; a tester describes what stops and what continues; no random power failures.


## M03 | First complete puzzle prototype

**Weeks 6–9. Evidence dependencies:** M01, M02.


**1. Build.** Build first shutter/tread and a small support-relief fixture. Include entry observation, wrong-angle recovery, solved-state checkpoint and exit predicate.


**2. Required assets.** Gameplay-grade shutter/tread collision, support pawl, marker-free camera volumes and basic foot/hand audio.


**3. Working systems.** Moving support, swept crush, support graph, puzzle facts and local reset.


**4. Playable deliverable.** A six-to-eight-minute room sequence with an actual solution and recoverable failed approaches.


**5. Tests.** Watch unfamiliar players without hints; attempt wrong order and edge jumps; restart before/after support.


**6. Problems to watch.** Puzzle only understandable from debug labels, unstable physics, excessive waiting, unnecessary repeat traversal.


**7. Exit gate.** Solution follows visible causality; repeated success does not depend on a lucky collision; reset restores a solvable arrangement.


## M04 | Core gameplay loop and narrative-state prototype

**Weeks 8–11. Evidence dependencies:** M02, M03.


**1. Build.** Join arrival, observation, manipulation, bodily response, traversal and consequence. Implement sequence facts and event phases, not only disconnected test rooms.


**2. Required assets.** Small service route, bearer-hand placeholder, first contextual after-motion, coherent ambient bed.


**3. Working systems.** Sequence exits, ledger, checkpoints, idempotent events, debug fixture loading.


**4. Playable deliverable.** Ten-minute continuous route including a transfer and an early hint of a hidden bearer.


**5. Tests.** Quit/reload at each event phase; distinguish useful action from disturbing consequence; measure dead time.


**6. Problems to watch.** Narrative props unrelated to puzzle, event duplication, camera taking control for too long, compulsory confusion.


**7. Exit gate.** Full loop works from menu to checkpoint resume; player understanding and uncertainty match the intended stage.


## M05 | Horror and tension prototype

**Weeks 10–13. Evidence dependencies:** M04.


**1. Build.** Build thin-sheet/thick-blanket visibility and a restrained-body reveal. Tune anticipation, pause, approach and release rather than adding random scares.


**2. Required assets.** Two cloth types, search light, restrained torso with eyes/breath, directional sound layers and caption alternatives.


**3. Working systems.** Visibility tags, camera composition, audio state and interruptible narrative reaction.


**4. Playable deliverable.** An eight-minute tension route with one safe teaching moment, one threat and one quiet realization.


**5. Tests.** Muted audio, low brightness, grayscale and reduced-motion modes; ask what the player believed was alive and aware.


**6. Problems to watch.** Unreadable cover, scare sting doing all the work, apparent robot rather than person, repetition exposing scripted trick.


**7. Exit gate.** Players explain the danger before failure and notice continuing awareness without exposition; sensory cues agree.


## M06 | Custodian and Porter prototypes

**Weeks 11–16. Evidence dependencies:** M03, M05.


**1. Build.** Implement both threat families, including covered/exposed harnesses and Porter detect/reach/secure/retract. Build sack demonstration, chase obstruction and rescue-dock behavior in fixtures.


**2. Required assets.** Rough adult rigs, Porter carriage/rail/hose, exposed socket, capture poses, readable warning sounds.


**3. Working systems.** Perception, route pursuit, harness restraint, swept capture and Porter load zones.


**4. Playable deliverable.** Separate representative Custodian and Porter encounters with correct retries.


**5. Tests.** Sight obstruction, last-known position, no teleport, one-Hold allocation, capture from moving supports, repeated pause.


**6. Problems to watch.** Unexplained detection, unavoidable rail reach, decorative shields treated as immunity, capture through barriers.


**7. Exit gate.** Each encounter can be predicted from its teaching event and debug trace; ten repeated retries remain solvable.


## M07 | First integrated environment and pipeline

**Weeks 12–17. Evidence dependencies:** M04, M05.


**1. Build.** Bring a Laundry bay to representative environment quality while creating reusable import, lighting, camera and streaming workflows.


**2. Required assets.** One final-quality wall/column/rail kit, Ivo material benchmark, laundry cart, sheet, anchor, lighting and VFX bundle.


**3. Working systems.** Streaming, camera, contact IK, pooled audio/VFX, asset validator and capture tool.


**4. Playable deliverable.** Five-to-eight-minute packaged environment with genuine transitions rather than editor teleport.


**5. Tests.** Lighting-only readability, floor-device profiling, cold load, backwards movement, material scale and socket import.


**6. Problems to watch.** Photorealistic noise, hidden path, texture inconsistency, hitches, hand penetration, art requiring bespoke scripts.


**7. Exit gate.** Art/audio leads approve gameplay-camera benchmark; import and performance evidence are repeatable on clean assets.


## M08 | Swimming and air-bell risk prototype

**Weeks 14–20. Evidence dependencies:** M02, M03, M06.


**1. Build.** Build bounded water, head-air tests, breath/recovery, one-arm Hold swimming, guided bell and obsolete tipping dock.


**2. Required assets.** Swim poses, basic water shader, bell/winch/hose, pocket debug volume and submerged Porter variant.


**3. Working systems.** Water graph, swimming motor, breath assistance, buoyancy constraints and coherent water snapshots.


**4. Playable deliverable.** A ten-minute underwater route from first swim to moving air pocket and escape from the retrieve-and-tip apparatus.


**5. Tests.** Surface thrash, breath exploit, timed swim legs, bell pose restore, input switching, accessibility and low effects.


**6. Problems to watch.** Invisible air rules, camera hiding the next opening, pocket that never spills, cheap drowning, free physics softlocks.


**7. Exit gate.** New players understand where breath exists; route margins and coherent reloads pass; dock danger is visibly caused by tipping.


## M09 | Reciprocal balance and Walking Ward risk proof

**Weeks 14–22. Evidence dependencies:** M02, M03.


**1. Build.** Build the quarry carrier, movable room and rough inhabited Ward on a support route. Implement narrow support, crouch and protected final release using synthetic prerequisite facts initially.


**2. Required assets.** Greybox hostel with two chimneys/curtain, four supports, cradle, simple occupants, girder, receiving pads, domestic sound cue.


**3. Working systems.** Shared station input, support graph, guided gait, room-local presentation, root-input guard; integrate real roster later.


**4. Playable deliverable.** A twelve-to-fifteen-minute progression from small carrier to First Step and two Ward maneuvers.


**5. Tests.** Do players transfer controls without a new tutorial? Do they care about occupants? Pause, release, off-focus and support restore.


**6. Problems to watch.** Comedy robot tone, unrelated vehicle controls, impossible unsupported steps, tedious foot micromanagement, accidental ending.


**7. Exit gate.** Director/engineering/animation approve controllable and emotionally legible reversal; blocking risks resolved before bulk campaign art.


## M10 | First fifteen-minute chronological build

**Weeks 18–22. Evidence dependencies:** M04, M06, M07.


**1. Build.** Integrate actual kitchen, landing, transport, brace pickup, shutter and tread; stage the beginning of pursuit at the fifteen-minute boundary.


**2. Required assets.** Ivo/Anja production rigs, domestic props, landing/transport hardware, opening contacts and two-tap audio.


**3. Working systems.** Full opening event phases, saved brace ownership, controller UI, camera transition and checkpoints.


**4. Playable deliverable.** The actual first fifteen minutes from a new game, not a montage of later rooms.


**5. Tests.** Onboarding with no coaching, opening control within seconds, child/mother relationship, restart at transport phases.


**6. Problems to watch.** Exposition dependency, lengthy noninteractive intro, lost brace, confusing target, mother animations preventing progress.


**7. Exit gate.** Fresh players know whom they are following and can use Hold; every opening interruption resumes coherently.


## M11 | First complete chapter

**Weeks 21–25. Evidence dependencies:** M10.


**1. Build.** Finish C01 including full pursuit, exterior transition and hostel landmark. Add complete chapter save/quit/retry handling.


**2. Required assets.** Final C01 art/audio pass, Custodian doorway catch, garden threshold and landmark proxy.


**3. Working systems.** All chapter systems including streamed exit and durable DoorBlocked/BraceOwned state.


**4. Playable deliverable.** The full approximately eighteen-minute Upper Terrace chapter in a packaged build.


**5. Tests.** Entire chapter on keyboard/controller, low-spec preliminary profile, capture retries and fast traversal into next chunk.


**6. Problems to watch.** Chapter exit hitch, pursuit too hard after successful tutorial, landmark oversold, duplicated guards.


**7. Exit gate.** No blocker/softlock; all C01 sequence cards have signed design/engineering/art/audio/QA review.


## M12 | First thirty-minute continuous build

**Weeks 24–28. Evidence dependencies:** M11, M06.


**1. Build.** Add the Gardens through its early Porter encounter, preserving the actual chronological path and weather/acoustic transition.


**2. Required assets.** Garden kit, windscreen, wader, sluice/float, loading terrace and Porter presentation.


**3. Working systems.** Flow diversion, natural ambient behavior, Porter teaching, streaming and cross-chapter ledger.


**4. Playable deliverable.** First thirty active minutes without debug jumps; the remaining garden route may continue beyond this test boundary.


**5. Tests.** Pacing, mechanic recurrence versus repetition, environmental variety, route inference and memory of Anja.


**6. Problems to watch.** Open area feels empty, reused angle puzzle overstays, water rules conflict, story urgency disappears.


**7. Exit gate.** C01–C02 transition works without a loading screen or reset; fresh-player timing data identifies revisions before art lock.


## M13 | Shipping-quality vertical slice and flagship benchmark

**Weeks 25–34. Evidence dependencies:** M07, M08, M09, M12.


**1. Build.** Finish all four Laundry sequences at representative shipping quality. In parallel finish a three-to-six-minute First Step quality benchmark to prove the late-game art/animation/audio cost.


**2. Required assets.** Final Ivo, transfer bridge, sheet/rack/blanket systems, hand reveal, Custodian, room kit, full audio/mix/lighting; Ward hero interior and reveal subset.


**3. Working systems.** Movement, Hold, puzzles, stealth, saves, streaming, captions, performance capture and integrated presentation; final-quality Ward subset.


**4. Playable deliverable.** Continuous twenty-four-minute Laundry chapter from entry to exit, plus separate flagship benchmark. Neither is passed by a trailer or static screenshot.


**5. Tests.** At least two rounds of unfamiliar players, packaged floor-machine tests, long retry soak, pause/reload matrix, sensory sign-off and actual task-time logging.


**6. Problems to watch.** Beautiful but unreadable image, gameplay not matching benchmark, hand reveal missed, late-game feature hidden from budget, unrepeatable quality.


**7. Exit gate.** All disciplines sign a representative result; known blockers closed; measured throughput produces a revised staffing/schedule estimate before bulk production.


## M14 | Full end-to-end playable campaign

**Weeks 35–56. Evidence dependencies:** M13.


**1. Build.** Build all nine chapters in greybox or gameplay-grade art, including real underwater route, Anja reveal, discharge proof, twelve-person evacuation and canonical ending.


**2. Required assets.** Complete functional collision/rig/socket set; readable stand-in art/audio for all beats; no missing story-critical actor.


**3. Working systems.** All mandatory mechanics and dependencies integrated; synthetic finale flags replaced with real progression.


**4. Playable deliverable.** New game to final fade with no editor commands, teleport, placeholder win button or skipped climax.


**5. Tests.** Full fresh runs, chapter times, prerequisite graph, all checkpoints and story comprehension. Record per-sequence stalls and recurring failures.


**6. Problems to watch.** Late route contradiction, repetitive puzzle grammar, impossible body/hand use, unearned transformation, incomplete ending.


**7. Exit gate.** Every sequence has a working route, coherent reset and event chain; campaign reaches the actual ending. Content may be visually unfinished, but design is complete enough to estimate.


## M15 | Alpha — feature and content complete

**Weeks 57–78. Evidence dependencies:** M14.


**1. Build.** Finish every planned feature, sequence, mandatory asset family and supported setting; replace critical stand-ins; freeze new mechanics.


**2. Required assets.** All character/environment/puzzle assets present at alpha quality; complete animation and audio coverage; menus, captions and credits.


**3. Working systems.** Feature-complete gameplay, persistence, streaming, cohort, Ward, localization pipeline and release guard.


**4. Playable deliverable.** Whole campaign with all player-facing systems and content represented; only polish/optimization/localization fixes remain.


**5. Tests.** Regression suite, unsupported-order play, long-run memory, controller hotplug, all root phases and save migration fixtures.


**6. Problems to watch.** Feature creep, borrowed placeholder rights, missing accessibility, art that requires changed collision, content only working in editor.


**7. Exit gate.** No missing required feature or sequence; scope frozen; bug severity and polish backlog triaged; engine-support review completed.


## M16 | Beta — stable representative experience

**Weeks 79–94. Evidence dependencies:** M15.


**1. Build.** Resolve major usability/logic defects and bring the whole campaign close to intended final sensory quality. Conduct full external playtesting and localization review.


**2. Required assets.** Near-final lighting/animation/audio/VFX; localized UI/captions; approved reference screenshots and content disclosures.


**3. Working systems.** Stable saves and integrated quality settings; measured performance and recovery paths.


**4. Playable deliverable.** Complete representative game suitable for an external test cohort under controlled distribution.


**5. Tests.** Fresh full-playthrough median, narrative interviews, missed reveals, comfort/accessibility, minimum-spec matrix and save compatibility.


**6. Problems to watch.** Duration inflated by confusion, subtle cues unreadable, ending interpreted as arbitrary punishment, Ward repetition, low-spec lost information.


**7. Exit gate.** No progression blockers or reproducible save loss; key comprehension targets met; remaining work is bounded fixes/polish rather than redesign.


## M17 | Optimization and final polish

**Weeks 95–106. Evidence dependencies:** M16.


**1. Build.** Optimize measured CPU/GPU/memory bottlenecks and polish contact, camera, sound transitions and brief failures without changing the creative contract.


**2. Required assets.** LOD/texture/shader refinements, compressed audio policy, final contact clips, quality-tier profiles.


**3. Working systems.** Stable frame pacing, asset residency, pooling, loading, audio priorities and reduced-effects equivalents.


**4. Playable deliverable.** Full game at agreed quality/performance tiers with final-length transitions and release candidate content.


**5. Tests.** Cold/warm routes, maximum Ward view, long sessions, repeat respawns, shader warmup and hardware-specific faults.


**6. Problems to watch.** Optimizations alter physics, low settings hide danger, stripped animation events break puzzles, memory growth across reloads.


**7. Exit gate.** Measured budgets met on documented fixtures; all gameplay regressions rerun; no content removed silently to win a benchmark.


## M18 | Release candidate and delivery rehearsal

**Weeks 107–112. Evidence dependencies:** M17.


**1. Build.** Produce versioned candidates, freeze content, verify installation/update/uninstall and backup/restore. Finish rights, credits, store materials and support procedures.


**2. Required assets.** Final package, original captures/key art, licenses, credits, disclosures and known-issue/support templates.


**3. Working systems.** Shipping configuration, debug stripping, save compatibility, error reporting and reproducible artifact archive.


**4. Playable deliverable.** Exact candidate build distributed through the intended test channel and played from a clean machine to ending.


**5. Tests.** Clean install and offline launch, missing/corrupt save, full disk, input devices, ending resume and update from supported prior save.


**6. Problems to watch.** Development-only dependency, incorrect build hash, absent notice, store claim not matching game, new last-minute content regression.


**7. Exit gate.** Zero open ship-blocking defects; evidence and sign-offs archived; rollback candidate exists and support owner is assigned.


## M19 | Final production build and launch

**Weeks 113–116. Evidence dependencies:** M18.


**1. Build.** Sign off the exact shipping build, archive source/build provenance and perform release smoke checks. Release only after gates, not merely because the week arrives.


**2. Required assets.** Approved executable/content, storefront assets, credits and support documentation.


**3. Working systems.** All shipping services/configuration and local save behavior verified in final distribution form.


**4. Playable deliverable.** Public release candidate identical to signed artifact; complete campaign and settings available offline.


**5. Tests.** Final install/continue/new-game/critical scenes/ending smoke on distribution build; verify no content differs from approved candidate.


**6. Problems to watch.** Wrong package uploaded, accidental debug flag, launch hotfix without regression, unowned support queue.


**7. Exit gate.** Director, technical lead, producer and QA approve artifact hash; rollback and hotfix triage are ready; no known blocker waived by schedule alone.


## M20 | Reserve, stabilization and post-release review

**Weeks 117–120. Evidence dependencies:** M19.


**1. Build.** Use reserve before launch when gates slip; otherwise handle verified defects, compatibility reports and a production retrospective. No unplanned expansion is assumed.


**2. Required assets.** Targeted corrected assets only; archived repro saves and support captures.


**3. Working systems.** Hotfix branch, regression selection, save migration safety and release notes.


**4. Playable deliverable.** Stable supported build; fixes preserve existing player progress and canonical ending.


**5. Tests.** Every fix includes reproducible test plus affected chapter/root/save regression; monitor patterns rather than isolated preference.


**6. Problems to watch.** Reserve consumed by scope growth, risky engine upgrade, patch invalidates saves, reactive redesign of locked story.


**7. Exit gate.** Critical issues resolved or transparently documented; final archive and retrospective identify maintainable owners and future port decision.


# 22 | Testing, accessibility and acceptance strategy

## Tests are requirements, not passed results

The test register includes puzzle-route checks, misuse/recovery checks, narrative interruption cases and system acceptance records. All game tests begin as **Not run**. This package validates its own references and totals; it does not fabricate an engine test result. Implement executable tests with the locked Unity Test Framework where suitable, plus human observation for feel, comprehension and visual staging. [R18]

Use EditMode tests for data validation, ownership transitions, prerequisite graphs, save schemas and migrations. Use PlayMode tests for motor/collision, motion drivers, water/head tests, support states and restore order. Use packaged-build routes for performance, loading, input devices and platform behavior. Use fresh humans for puzzle comprehension, emotional pacing, recognition and the First Step. No automated test can certify that a reveal is moving.

Every bug report contains build hash, sequence/checkpoint, device/settings, steps, expected/actual behavior, recurrence, video or save fixture, and severity. Blocker means no reliable progression/recovery, save loss, unavoidable required failure or unsafe irreversible input. High severity includes incorrect rules, inaccessible required input, severe pacing/readability defects and major performance failure. Cosmetic defects are still tracked but do not mask systemic risk.

## Fresh-player rounds

For early rooms, recruit approximately five unfamiliar players per iteration and watch silently. These small rounds identify obvious problems; they are not statistical proof. For the slice, use at least two independent rounds, mixing controller familiarity and accessibility needs. For campaign beta, seek a larger set of complete runs, provisionally 20–30 where budget permits, with target-audience variety. Keep previous testers separate when measuring first-time understanding.

Record active travel, reasoning, retries, idle observation and unexplained stall time. Ask neutral questions afterward: What were you trying to do? What did you think the fitting affected? Why did the person move? What made the building safe? Avoid leading questions that reveal the intended answer. Permission, participant comfort and the ability to stop testing are part of the session plan, especially with bereavement and captivity content.

Working comprehension gates: most players should infer the first Hold without coaching; recognize that held humans remain conscious by the Exchange; understand the small paired interface before the Ward; and explain that final release is safe because of preparation. At beta, aim for at least 80% of the observed test sample to explain these essential causal facts. This is an internal target, not a claim about a future population. The origin of the technology may remain uncertain.

For the First Step, record more than surprise. Ask what the player thought about immediately after the camera widened. The intended response includes the occupants and the need to keep them safe. A response limited to “I got a cool robot” signals a staging problem. For Anja, confusion about irreversible integration must be addressed before the final release, not patched by credits text.

## Accessibility baseline

Provide remapping, controller and keyboard support, Hold/grip toggles, no rapid tapping, no mandatory precise simultaneous triggers, adjustable subtitle/caption size and backing, reduced motion/shake, brightness calibration, independent mix controls, reduced dynamic range and longer breath assistance. Optional interaction emphasis must preserve the original art direction where possible while making essential objects perceivable.

No required puzzle depends solely on color, hearing, camera shake, haptics or reading a tiny prop label. Thick versus thin cover uses silhouette and material behavior, not only tint. Breath warnings have body/visual and caption equivalents. A single-action assistance path handles sustained grip and Hold where needed. Final release confirmation adapts to the input mode without becoming a different moral choice.

Test pause during every danger class, controller hotplug, focus loss, ultrawide letterboxing policy, text expansion, low volume and low effects. Settings must survive restart and remain available from the first menu. Do not add assistance only after all animations assume one exact two-hand input scheme.

## Complete regression routes

Maintain short replay routes for the controller gym, shutter/transfer/support gym, Custodian obstruction, Porter loading grate, wet-rack lift, water/bell, paired carrier, room support, Ward narrow pier/crouch and root release. Record inputs where repeatable, but assert state and tolerance rather than claiming cross-hardware bitwise identity.

Before each major build, run the opening-to-Gardens route, the complete Laundry, water-to-Burden route and the entire final thirty minutes. Before beta and release, run a clean new game to ending without debug commands, plus a checkpoint-resume pass across all supported save categories. Preserve a bank of reference saves for every root state, paired station and moving air pocket.

A content audit checks every sequence card against the actual game: route, solution, threat, camera, audio, story fact, checkpoint and exit. Any intentional difference updates the master and registers. Do not let the document become a fictional description of a game that quietly changed beneath it.

## Duration and polish decisions

The campaign target is the median first active experience, not an achievement for making players wait. If a chapter is too short, first ask whether it lacks a meaningful physical or narrative beat. If it is too long, distinguish enjoyable experimentation from obscurity. Remove redundant retries and dead walking before cutting essential context. The story can tolerate different individual completion times.

Contact and camera polish comes before decorative density. In final review, play without developer commentary, at normal speed, on the floor fixture. Watch hands, feet, load transitions, waterlines, curtains, sound changes and the time between decision and response. Small inconsistencies in these elements can undo much more expensive visual work.

# 23 | First sprint, risk ownership and release operations

## Start building in this order

The first sprint should produce a clean project, a metric controller gym, one slider, one rotator, one ownership transfer and a rough support-pawl fixture. In parallel, block the Ward silhouette/support route and the bell's pocket/tipping relationship. These are risk prototypes, not art-production orders.

The first-sprint register assigns twenty tasks with dependencies and explicit done criteria. Estimates are intentionally blank until the actual team assigns capacity. The initial director/engineer/artist review should resolve scale, lane orientation, hand occupation, interface shapes, stable IDs and prototype ownership. Do not commission all nine environment kits before the mechanic and flagship proof are credible.

Daily work should converge into a playable integration branch. Review a small build at least weekly, with one person outside the current task playing it. Keep tasks small enough to integrate before they become incompatible private branches. Binary art is locked while edited; code and text changes receive peer review; sequence changes require a route/save regression.

## Risks and scope protection

The risk register assigns an owner, review gate, mitigation and fallback to each major uncertainty. The most important risks are Ward coherence/cost, water fairness, Anja's causal clarity, accidental final release, physics inconsistency, cohort blocking, animation capacity and insufficient production-rate evidence.

Fallbacks preserve the core argument. Reduce decorative rooms, background actor variation, incidental debris or redundant traversal before removing the First Step, paired-control rehearsal, conscious restraint or final voluntary help. Do not cut the small carrier and then expect players to understand the Ward. Do not cut discharge proof and retain the same ending, because that would remove the reason release is safe.

No fallback authorizes unlicensed assets, broken saves, unpredictable controls or known accidental root release. A schedule slip is preferable to shipping a finale that kills Anja because the player disconnected a controller.

## Production budget and outsourcing

Build a bottom-up budget after the vertical slice: remaining work packages multiplied by measured creation/integration/review effort, plus staff availability, external services, equipment, licenses, QA, localization, marketing and a separately visible contingency. Do not use a competitor's apparent visual simplicity as evidence of cheap production.

Outsource bounded packages with a working example, source requirements, camera-distance references, naming, socket/rig standards, iteration allowance, license terms and an acceptance scene. Retain integration ownership internally. Large hero rigs, final movement systems and narrative-critical contacts need close daily collaboration rather than a one-time asset delivery.

Staff turnover risk is mitigated by build instructions, source files, decision logs and shared fixtures. A contractor's private file must not be the only editable copy of Anja's hand or the Ward rig. Back up the repository and production records with a tested restore procedure.

## Release checklist

Before release, freeze the exact candidate, archive its build hash and provenance, and test the distributed package rather than a local development build. Verify installation, offline launch, continue/new game, settings, supported save migration, disk failure messaging, input changes, full ending and postrelease checkpoint behavior. Remove debug cheats, internal telemetry endpoints, reference captures and unlicensed placeholders.

Finish original store artwork, truthful gameplay captures, description, content disclosures, credits, third-party notices and support contact. Do not market concept art as footage of implemented gameplay. Confirm distribution and legal requirements with the appropriate qualified parties; this creative document is not a substitute for their approval.

Keep a rollback candidate and a hotfix branch. Every hotfix gets a reproducible defect case and the affected save/root/sequence regression. Do not force an unplanned engine upgrade during launch stabilization without a serious need and a tested recovery path. Record known issues honestly.

## What the team receives—and what it still must create

This package contains the complete creative/technical build specification, structured production registers, schemas, state examples and a runnable consistency validator. It does **not** contain a finished Unity project, licensed third-party packages, final meshes, rigged animations, recorded sound, rendered storyboards or validated playtest/performance results.

The work is ready to enter implementation because the decisions, relationships, expected behavior and acceptance gates are explicit. The team's next evidence is a playable prototype—not another promise that the unbuilt game is already exceptional.

## First-sprint task register


| Task / owner | Dependencies | Done when |
| --- | --- | --- |
| SP-01 · Create source repository and binary locking / Engineering | None | Clean checkout with documented editor version and no copied proprietary assets |
| SP-02 · Resolve engine/package matrix / Technical lead | SP-01 | Locked manifest builds and launches on second machine |
| SP-03 · Define stable IDs and register importer contract / Engineering/design | SP-01 | Duplicate/missing-ID tests fail clearly |
| SP-04 · Build metric floor/gap/slope gym / Level design | None | 2 m gap, steps and slopes visibly labeled in debug only |
| SP-05 · Implement basic lane motor / Gameplay engineer | SP-02, SP-04 | Run/turn/jump at 30/60/120 fps with recorded tuning |
| SP-06 · Import temporary Ivo rig and locomotion / Animator | SP-04 | Scale/feet align to capsule without delaying valid jump |
| SP-07 · Create input actions and toggle intent model / Gameplay/UI | SP-02 | Pause/focus/device canceled input is distinguishable from release |
| SP-08 · Build slider and rotator runtime / Gameplay engineer | SP-03 | Fixed-step q/v driver captures and resumes bounded states |
| SP-09 · Implement Hold ownership unit fixtures / Technical lead | SP-07, SP-08 | No double owner or unowned transfer frame |
| SP-10 · Build first shutter safe-observation room / Level design | SP-05, SP-08 | Full motion can be observed before lethal crossing |
| SP-11 · Block support/pawl relief room / Level design | SP-04 | Mechanical support visibly replaces a held load |
| SP-12 · Capture licensed reference session / Director/animator | None | Observation sheet separates measured footage from assumptions |
| SP-13 · Approve nonphotoreal material swatches / Art lead | SP-04 | Matte concrete/steel/cloth/porcelain read from gameplay camera |
| SP-14 · Draft nine-area geographic elevation / Director/environment art | None | Garden/laundry/exchange/cut/water/root/hostel connections are physically coherent |
| SP-15 · Block Ward silhouette and support route / Technical artist | SP-04 | Two chimneys/curtain, four shoes and clear receiving supports fit proposed envelope |
| SP-16 · Prototype paired input on small carrier / Gameplay/technical art | SP-08, SP-15 | Travel/posture/Hold mapping works without per-foot commands |
| SP-17 · Define water/bell test geometry / Level design/engineering | SP-04 | Guided bell and tipping dock explain pocket survival/loss |
| SP-18 · Create audio state and cue naming sheet / Audio lead | SP-03 | Foot/breath/load cues share authoritative tags; critical caption candidates marked |
| SP-19 · Set automated build and test smoke / Engineering/QA | SP-02 | Clean packaged build and test report archived with commit ID |
| SP-20 · Review risks and next sprint estimates / Producer/all leads | SP-09, SP-12, SP-15, SP-17, SP-19 | Owners, unresolved questions and evidence-based next tasks signed; no bulk asset order |


## Risk ownership and fallback register


| Risk / owner / gate | Mitigation | Fallback |
| --- | --- | --- |
| RSK-01 · Walking Ward feels like unrelated vehicle / Director / M09 | Test small-to-large control transfer before art; keep same inputs and human stakes | Cut incidental interior physics, not reciprocal control or First Step |
| RSK-02 · Ward costs exceed small-team capacity / Producer / M13 | Measure one support/room/reveal workflow; bound route and rig | Reduce visible rooms and decorative props while keeping twelve roster slots |
| RSK-03 · Hold physics is inconsistent / Technical lead / M02 | Author coordinates and ownership transactions; differential frame-rate tests | Remove uncontrolled joints from critical assemblies |
| RSK-04 · Water creates unfair deaths / Designer / M08 | Visible air pockets, timed leg margins, breath assistance and coherent reset | Shorten swims and simplify bell route, not water clarity |
| RSK-05 · Anja fate feels arbitrary / Narrative director / M14 | Distinguish removable harness from irreversible root; establish no healing/time rewind | Strengthen visual causal evidence, not exposition dump |
| RSK-06 · Final release occurs accidentally / Technical lead / M09 | Separate canceled input from deliberate arm/release; restore disarmed | Block shipping until every focus/device/pause test passes |
| RSK-07 · Survivor path bugs block ending / AI engineer / M14 | Unique roster, authored safe routes and concealed recovery | Reduce background dynamic navigation, preserve independent choice |
| RSK-08 · Environmental repetition / Lead designer / M12 | Track reasoning language and palette/scale changes per sequence | Merge weak repeats and strengthen transitions rather than slow traversal |
| RSK-09 · Campaign duration too short/long / Director/producer / M14 | Fresh timed runs with solve/stall separation | Reallocate authored beats; no forced waits to meet 225 minutes |
| RSK-10 · Visuals drift toward photorealism / Art lead / M07 | Gameplay-camera matte/simple-form benchmark, grayscale review | Remove high-frequency textures and uncontrolled gloss |
| RSK-11 · Readable subtlety becomes invisibility / Art/audio leads / M13 | Low brightness, reduced effects, captions and no-audio tests | Strengthen posture/composition; avoid neon markers by default |
| RSK-12 · Animation backlog exceeds capacity / Producer/animation lead / M13 | Reuse adult skeleton; separate authored hero contacts from reusable layers | Reduce decorative variants before core contact and finale animation |
| RSK-13 · Streaming breaks active relationships / Engineering / M07 | Dependency pin graph and single authoritative actor | Smaller chunks or simpler proxies; never unload live owner |
| RSK-14 · Engine support expires during schedule / Technical lead / M15 | Compatibility lock and planned support review; tested upgrade branch | Upgrade before late stabilization or procure appropriate support after review |
| RSK-15 · No production-rate evidence / Producer / M13 | Log actual integration/rework time per slice task | Rebaseline staffing/date instead of preserving invented estimate |
| RSK-16 · Rights or distribution requirements missed / Producer / M18 | Asset/license inventory, qualified review and truthful captures | Replace unlicensed content before candidate approval |
| RSK-17 · Accessibility added too late / UI/design lead / M01 | Toggle/remap/captions/breath/reduced-motion built into prototypes | Never fork story outcomes by assistance settings |
| RSK-18 · Key specialist unavailable / Producer / M00 | Shared documentation, source files, cross-training and contractor buffer | Reduce concurrent content work rather than abandon technical ownership |


# 24 | Data-contract appendix and integration recipes

## Supplied implementation aids

The `implementation` directory contains JSON Schemas and examples for mechanism snapshots, authoritative events, protected root release and sequence-card interchange. These establish data shapes, not physical correctness. The root-level Python validator checks the package's references, uniqueness, time totals and dependency graphs, and optionally checks JSON Schema shapes when `jsonschema` is installed.

Run `python validate_package.py` from the extracted package. A successful result means the planning data is internally linked. It does not mean any unbuilt engine feature has passed its game test. All entries in the test register remain Not run until a development team records evidence.

## Mechanism-state recipe

A captured hinge has an actor GUID, family, coordinate in radians, velocity in radians per second, driver phase, owner kind/ID and support state. A slider uses meters instead. Definitions contain legal bounds. Runtime validation requires exactly one compatible sustaining owner or its ordinary free driver. If a support engages, its ID must exist and its contact must actually bear the assembly; velocity is cleared so later release does not replay stale motion.

Before restoring an actor, load its owner/support dependencies. Apply ownership and coordinates together. Rebuild render interpolation from the restored simulation pose, rather than interpolating from a stale pre-load pose. Notify audio/VFX through a restore-aware state event, not by replaying every historical one-shot.

## Root state recipe

The protected flow is MotherOwnsRoot → HandoverAvailable → IvoOwnsGovernor → ReleaseArmed → ReleaseCommitted → EscapeComplete. Handover requires the discharge, supported Ward and evacuated cohort facts. Focus loss, pause, controller removal and input remapping transition ReleaseArmed back to IvoOwnsGovernor with a fresh-arm requirement. They never transition to ReleaseCommitted.

The postrelease ledger and safe escape phase commit together. A repeat event with the same transaction ID is ignored. A missing prerequisite rejects the action with a coherent state rather than starting half the discharge. The accessible toggle path uses a deliberate contextual confirmation, not a simulated mouse-up.

## Durable narrative facts

These IDs are the authored progression vocabulary. A fact can be recorded only when its physical/event predicate is complete. Story interpretation remains richer than the ledger; the ledger merely prevents contradictory progression.


| Fact / source sequence | Prerequisites | Meaning |
| --- | --- | --- |
| BraceOwned / SQ-01-02 | None | Brace acquired from reachable floor; player equipment restored on load. |
| TransferLearned / SQ-03-01 | BraceOwned | Successful external anchor transfer observed. |
| LaundryLoadsRelieved / SQ-03-03 | TransferLearned | Required laundry loads parked on mechanical supports; three attendants remain confined until route opens. |
| QueueReleased / SQ-04-02 | TransferLearned | Jack supports tilted deck; six constrained queue people may leave by safe route. |
| OrrenReleased / SQ-04-04 | TransferLearned | Stair pawl supports Orren load. |
| BalanceLearned / SQ-05-02 | TransferLearned | Carrier safely parked and open station exited. |
| BellRouteCleared / SQ-06-03 | BraceOwned | Upper bell guide secured after escape from obsolete dock. |
| AnjaRecognized / SQ-07-03 | BalanceLearned | Cuff/taps recognition and refusal phase completed. |
| CohortRoutesOpen / SQ-07-04 | LaundryLoadsRelieved, QueueReleased, OrrenReleased | Two local bearers relieved and safe paths to hostel opened. |
| RootLoadReduced / SQ-07-04 | AnjaRecognized | Mechanical receiving frame takes local load. |
| DischargeProved / SQ-08-02 | RootLoadReduced | Limited proof flow follows latched deflector to safe outlet. |
| WardPadsPrepared / SQ-08-03 | DischargeProved | Receiving support pads and root-return culvert available. |
| WardOccupied / SQ-08-04 | CohortRoutesOpen | All twelve live cohort slots at their assigned safe interior bays. |
| FirstStepSeen / SQ-09-02 | BalanceLearned, WardPadsPrepared, WardOccupied | Progress-driven reveal completed without implying a different rig. |
| WardSupported / SQ-09-05 | FirstStepSeen, WardPadsPrepared | Mechanical locks carry the hostel on inland supports. |
| CohortEvacuated / SQ-09-05 | WardSupported, WardOccupied | All twelve slots have completed their visible safe exit route. |
| RootHandoverComplete / SQ-09-06 | DischargeProved, CohortEvacuated, WardSupported | Unloaded governor transferred from mother to Ivo. |
| RootReleased / SQ-09-07 | RootHandoverComplete | Deliberate armed gameplay release; postrelease escape phase committed. |
| EndingComplete / SQ-09-08 | RootReleased | Voluntary gate help, offered hand and final walking/fade completed. |


## Register authority and update workflow

Design changes first update the relevant sequence and dependency, then affected actors/systems/tests, then estimates and milestone gate. Re-export JSON/CSV and rerun validation. Re-render the master and spot-check changed layouts. The workbook is an editable planning surface; it is not automatically synchronized with the document or a future engine importer. Keep a change log and stable IDs.


# 25 | Sources and research boundaries

Sources checked for this revision on 8 September 2026. Technical documentation may change; use the versions pinned by the project after the compatibility spike. Titles and scope notes identify what was actually inspected. No claim of a complete instrumented INSIDE playthrough is made. All game dimensions, budgets, fiction, puzzles, timing and milestones in this package are proposed original design decisions unless explicitly attributed.


**[R01] Marek Bogdan / Playdead — The Lighting of INSIDE.** [Open source](https://blog.playdead.com/articles/the_lighting_of_inside/lighting_of_inside.html)

Article and lighting stills inspected; art-directed reference principle, not copied implementation.


**[R02] Marek Bogdan / Playdead — The Bits and Pieces.** [Open source](https://blog.playdead.com/articles/the_bits_and_pieces/bits_and_pieces.html)

Developer model-design account; subtraction and composition.


**[R03] Playdead — Ebeltoft animation presentation.** [Open source](https://docs.google.com/presentation/d/1QN99FZUQl3KE4c7eg9-GLLEl3Og0FqreJbiTrCc8ZAk/htmlpresent)

Published Danish slides inspected; animation/input/contact principles, not measured gameplay.


**[R04] Playdead / GDC — Huddle up! Making the [SPOILER] of INSIDE.** [Open source](https://gdcvault.com/play/1024472/Huddle-up-Making-the-SPOILER)

Session description inspected; no claim of full video playback.


**[R05] Jakob Schmid — The Boy from INSIDE — AES 2016.** [Open source](https://www.schmid.dk/talks/2016-02-11-aes/schmid-AES_2016-The_Boy_from_INSIDE.pdf)

PDF text and selected diagrams/screenshots inspected; contextual character audio.


**[R06] Martin Stig Andersen / GDC — A Game That Listens — The Audio of INSIDE.** [Open source](https://www.gdcvault.com/play/1023731/A-Game-That-Listens-The)

Session description inspected; game/audio feedback and respawn continuity.


**[R07] Playdead — Tools, Tricks and Technologies for Reaching Stutter-Free 60 FPS in INSIDE.** [Open source](https://docs.google.com/presentation/d/1dew0TynVmtQf8OMLEz_YtRxK32a_0SAZU9-vgyMRPlA/htmlpresent)

Published performance slides; use high-level profiling/streaming lessons, not obsolete blanket micro-optimization rules.


**[R08] Marek Bogdan / Playdead — The Weight of Detail.** [Open source](https://blog.playdead.com/articles/the_weight_of_detail/weight_of_detail.html)

Article inspected; motion fetch unavailable, no claim to have watched GIFs.


**[R09] Unity — Unity 6 releases and support.** [Open source](https://unity.com/releases/unity-6/support)

6.3 LTS support through December 2027 checked; production upgrade review required.


**[R10] Unity — URP introduction, Unity 6.3.** [Open source](https://docs.unity3d.com/6000.3/Documentation/Manual/urp/urp-introduction.html)

Official rendering documentation; package family recommendation requires compatibility spike.


**[R11] Unity — Input System manual.** [Open source](https://docs.unity3d.com/Packages/com.unity.inputsystem@1.17/manual/index.html)

Official action/input reference; exact project version locked in M00.


**[R12] Unity — Cinemachine manual.** [Open source](https://docs.unity3d.com/Packages/com.unity.cinemachine@3.1/manual/index.html)

Official camera package reference; directed content still authored by team.


**[R13] Unity — Timeline manual.** [Open source](https://docs.unity3d.com/Packages/com.unity.timeline@1.8/manual/index.html)

Official timeline reference; not authority for durable narrative state.


**[R14] Unity — Addressables: loading scenes.** [Open source](https://docs.unity3d.com/Packages/com.unity.addressables@2.7/manual/LoadingScenes.html)

Scene activation queue behavior and handle lifecycle; confirm against locked package.


**[R15] Unity — Character Controller component reference.** [Open source](https://docs.unity3d.com/6000.3/Documentation/Manual/class-CharacterController.html)

Controller candidate only; custom moving-platform/contact requirements still need tests.


**[R16] Unity — Physics.Simulate.** [Open source](https://docs.unity3d.com/6000.3/Documentation/ScriptReference/Physics.Simulate.html)

Fixed-step guidance; no cross-hardware bitwise-determinism claim.


**[R17] Unity — AudioSource.PlayScheduled.** [Open source](https://docs.unity3d.com/6000.3/Documentation/ScriptReference/AudioSource.PlayScheduled.html)

DSP scheduling reference; gameplay state remains authoritative.


**[R18] Unity — Unity Test Framework manual.** [Open source](https://docs.unity3d.com/Packages/com.unity.test-framework@1.4/manual/index.html)

Official EditMode/PlayMode/player testing reference; exact version tested in M00.


**[R19] Playdead — INSIDE official page.** [Open source](https://playdead.com/games/inside/)

Official stills inspected; official trailer endpoint unavailable in this session.


## Final creative invariant

At the beginning, Anja holds a landing so Ivo can cross. In the middle, he discovers a town that has turned that protective response into captivity. At the climax, he gives an occupied building his balance so its people can leave. At the end, Orren holds an ordinary gate—and is free to let go.

**The spectacle is the building’s first step. The purpose is that, afterward, nobody should have to keep holding it.**
