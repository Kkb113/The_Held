"""Editor-only PH01 asset recipe. Original geometry and temporary audio sources."""
import unreal, os, json, math, wave, struct, random
root=os.path.abspath(os.path.join(unreal.Paths.project_dir(),'../..'))
folder='/Game/Traversal';unreal.EditorAssetLibrary.make_directory(folder)
tools=unreal.AssetToolsHelpers.get_asset_tools()
colors={
 'M_Stone':((.14,.18,.17),.86), 'M_Dark':((.025,.032,.036),.65),
 'M_Foreground':((.008,.012,.014),.85),'M_Backdrop':((.07,.10,.12),.92),
 'M_AshBlue':((.09,.17,.22),.9),'M_Skin':((.36,.30,.24),.88),
 'M_Porcelain':((.58,.56,.49),.3),'M_Brass':((.19,.17,.12),.48),
 'M_PaintedMetal':((.06,.095,.10),.52),'M_Timber':((.12,.10,.075),.9),
 'M_Tile':((.22,.27,.25),.48),'M_Fabric':((.19,.23,.22),1),
 'M_Wet':((.08,.115,.12),.16),'M_Glass':((.12,.19,.23),.32),'M_Warm':((.45,.30,.14),.55)}
for name,(rgb,rough) in colors.items():
 path=folder+'/'+name
 if unreal.EditorAssetLibrary.does_asset_exist(path):continue
 mat=tools.create_asset(name,folder,unreal.Material,unreal.MaterialFactoryNew())
 c=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionConstant3Vector)
 c.set_editor_property('constant',unreal.LinearColor(*rgb,1))
 unreal.MaterialEditingLibrary.connect_material_property(c,'',unreal.MaterialProperty.MP_BASE_COLOR)
 r=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionConstant);r.r=rough
 unreal.MaterialEditingLibrary.connect_material_property(r,'',unreal.MaterialProperty.MP_ROUGHNESS)
 if name in ('M_Glass','M_Warm'):unreal.MaterialEditingLibrary.connect_material_property(c,'',unreal.MaterialProperty.MP_EMISSIVE_COLOR)
 if name=='M_Fabric':mat.set_editor_property('two_sided',True)
 unreal.MaterialEditingLibrary.recompile_material(mat);unreal.EditorAssetLibrary.save_loaded_asset(mat)
def import_file(src,name,options=None):
 t=unreal.AssetImportTask();t.filename=src;t.destination_path=folder;t.destination_name=name;t.automated=True;t.replace_existing=True;t.save=True
 if options:t.options=options
 tools.import_asset_tasks([t]);assert t.imported_object_paths,src
 return unreal.load_asset(t.imported_object_paths[0])
opt=unreal.FbxImportUI();opt.import_mesh=True;opt.import_as_skeletal=False;opt.import_materials=False;opt.import_textures=False;opt.mesh_type_to_import=unreal.FBXImportType.FBXIT_STATIC_MESH;opt.automated_import_should_detect_type=False
mesh=import_file(os.path.join(root,'SourceArt/PH01/SM_Cloth.fbx'),'SM_Cloth',opt)
import_file(os.path.join(root,'SourceArt/PH01/SM_Jacket.fbx'),'SM_Jacket',opt)
size=mesh.get_bounding_box().max-mesh.get_bounding_box().min
assert abs(size.x-360)<1 and 315<size.z<330,str(size)
rng=random.Random(101)
for name,duration,freq in [('A_Step',.12,95),('A_Land',.22,65),('A_Grip',.16,340)]:
 src=os.path.join(root,'SourceArt/PH01',name+'.wav')
 with wave.open(src,'wb') as w:
  w.setnchannels(1);w.setsampwidth(2);w.setframerate(48000)
  samples=[]
  for i in range(int(duration*48000)):
   t=i/48000;env=min(1,t/.004)*math.exp(-t/duration*7)
   v=(math.sin(2*math.pi*freq*t)*.65+rng.uniform(-1,1)*.35)*env
   samples.append(struct.pack('<h',int(v*6500)))
  w.writeframes(b''.join(samples))
 import_file(src,name)
if not unreal.EditorAssetLibrary.does_asset_exist(folder+'/L_PH01'):
 sub=unreal.get_editor_subsystem(unreal.LevelEditorSubsystem);sub.new_level(folder+'/L_PH01')
 actors=unreal.get_editor_subsystem(unreal.EditorActorSubsystem)
 actors.spawn_actor_from_class(unreal.PlayerStart,unreal.Vector(150,0,76))
 world=unreal.get_editor_subsystem(unreal.UnrealEditorSubsystem).get_editor_world()
 world.get_world_settings().set_editor_property('default_game_mode',unreal.load_class(None,'/Script/TheHeld.HeldTraversalMode'))
 sub.save_current_level()
required=[folder+'/'+n for n in colors]+[folder+'/SM_Cloth',folder+'/L_PH01',folder+'/A_Step',folder+'/A_Grip',folder+'/A_Land']
assert all(unreal.EditorAssetLibrary.does_asset_exist(p) for p in required)
os.makedirs(os.path.join(root,'phase-reviews/PH01'),exist_ok=True)
with open(os.path.join(root,'phase-reviews/PH01/assets.json'),'w') as f:json.dump({'required':required,'cloth_cm':[size.x,size.y,size.z],'source':'original Blender mesh and seeded temporary synthesis'},f,indent=2)
