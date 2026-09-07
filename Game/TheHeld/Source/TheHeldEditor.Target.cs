using UnrealBuildTool;
public class TheHeldEditorTarget : TargetRules {
    public TheHeldEditorTarget(TargetInfo Target) : base(Target) {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V7;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        ExtraModuleNames.Add("TheHeld");
    }
}

