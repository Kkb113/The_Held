using UnrealBuildTool;
public class TheHeld : ModuleRules {
    public TheHeld(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new [] {"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput"});
    }
}
