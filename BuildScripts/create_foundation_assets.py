"""Run through UnrealEditor-Cmd -run=pythonscript -script=<this file>. Editor only."""
import unreal
import os
import json

root = os.path.abspath(os.path.join(unreal.Paths.project_dir(), '../..'))
tools = unreal.AssetToolsHelpers.get_asset_tools()
folder = '/Game/Foundation'
unreal.EditorAssetLibrary.make_directory(folder)
colors = {
    'M_Stone': (.14,.19,.18), 'M_Dark': (.022,.031,.035),
    'M_AshBlue': (.12,.21,.27), 'M_Porcelain': (.65,.63,.55),
    'M_Brass': (.27,.24,.15), 'M_Skin': (.43,.36,.29),
    'M_Window': (.22,.31,.35)
}
for name, rgb in colors.items():
    path=folder+'/'+name
    if unreal.EditorAssetLibrary.does_asset_exist(path):
        continue
    mat=tools.create_asset(name,folder,unreal.Material,unreal.MaterialFactoryNew())
    c=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionConstant3Vector)
    c.set_editor_property('constant',unreal.LinearColor(*rgb,1))
    unreal.MaterialEditingLibrary.connect_material_property(c,'',unreal.MaterialProperty.MP_BASE_COLOR)
    rough=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionConstant)
    rough.set_editor_property('r',.65)
    unreal.MaterialEditingLibrary.connect_material_property(rough,'',unreal.MaterialProperty.MP_ROUGHNESS)
    if name=='M_Window':
        unreal.MaterialEditingLibrary.connect_material_property(c,'',unreal.MaterialProperty.MP_EMISSIVE_COLOR)
    unreal.MaterialEditingLibrary.recompile_material(mat)
    unreal.EditorAssetLibrary.save_loaded_asset(mat)

def import_file(filename,name,options=None):
    t=unreal.AssetImportTask()
    t.filename=filename; t.destination_path=folder; t.destination_name=name
    t.automated=True; t.replace_existing=True; t.save=True
    if options: t.options=options
    tools.import_asset_tasks([t])
    if not t.imported_object_paths: raise RuntimeError('Import failed: '+filename)
    return unreal.load_asset(t.imported_object_paths[0])

options=unreal.FbxImportUI()
options.import_mesh=True; options.import_as_skeletal=False; options.import_materials=False; options.import_textures=False
options.mesh_type_to_import=unreal.FBXImportType.FBXIT_STATIC_MESH
options.automated_import_should_detect_type=False
options.static_mesh_import_data.combine_meshes=True
tile=import_file(os.path.join(root,'SourceArt/PH00/SM_CalibrationTile.fbx'),'SM_CalibrationTile',options)
before=(tile.get_bounding_box().max - tile.get_bounding_box().min)
# Repeat source import to prove the actual export/reimport path preserves dimensions.
tile=import_file(os.path.join(root,'SourceArt/PH00/SM_CalibrationTile.fbx'),'SM_CalibrationTile',options)
after=(tile.get_bounding_box().max - tile.get_bounding_box().min)
assert abs(after.x-100)<.1 and abs(after.y-100)<.1 and abs(after.z-12)<.1, str(after)
assert abs(before.x-after.x)+abs(before.y-after.y)+abs(before.z-after.z)<.01
import_file(os.path.join(root,'SourceArt/PH00/A_Contact.wav'),'A_Contact')
if not unreal.EditorAssetLibrary.does_asset_exist(folder+'/L_PH00'):
    subsystem=unreal.get_editor_subsystem(unreal.LevelEditorSubsystem)
    subsystem.new_level(folder+'/L_PH00')
    start=unreal.get_editor_subsystem(unreal.EditorActorSubsystem).spawn_actor_from_class(unreal.PlayerStart,unreal.Vector(-720,0,78))
    start.set_actor_label('PH00_PlayerStart')
    subsystem.save_current_level()

required=[folder+'/'+n for n in colors]+[folder+'/SM_CalibrationTile',folder+'/A_Contact',folder+'/L_PH00']
def validate(paths): return [p for p in paths if not unreal.EditorAssetLibrary.does_asset_exist(p)]
assert validate(required)==[]
assert validate([folder+'/DeliberatelyMissingAsset'])==[folder+'/DeliberatelyMissingAsset']
out={'required_assets':required,'missing':validate(required),'negative_missing_reference_test':True,'tile_dimensions_cm':[after.x,after.y,after.z],'reimport_dimensions_match':True}
with open(os.path.join(root,'phase-reviews/PH00/asset-validation.json'),'w') as f: json.dump(out,f,indent=2)
unreal.log('PH00_ASSETS_VALIDATED')

