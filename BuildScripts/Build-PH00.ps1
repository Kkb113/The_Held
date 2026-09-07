param([string]$EngineRoot='C:/Program Files/Epic Games/UE_5.8',[switch]$CreateAssets,[string]$ArchiveDirectory='')
$ErrorActionPreference='Stop'
$heldRoot=Split-Path $PSScriptRoot -Parent
$heldProject=Join-Path $heldRoot 'Game/TheHeld/TheHeld.uproject'
if(-not $ArchiveDirectory){$ArchiveDirectory=Join-Path $heldRoot 'Builds/PH00'}
& "$EngineRoot/Engine/Build/BatchFiles/Build.bat" TheHeldEditor Win64 Development "-Project=$heldProject" -WaitMutex -NoHotReloadFromIDE -NoUBA
if($LASTEXITCODE -ne 0){throw 'Editor compilation failed'}
if($CreateAssets){
 & "$EngineRoot/Engine/Binaries/Win64/UnrealEditor-Cmd.exe" $heldProject -run=pythonscript "-script=$PSScriptRoot/create_foundation_assets.py" -unattended -nop4 -NullRHI
 if($LASTEXITCODE -ne 0){throw 'Asset creation failed'}
}
& "$EngineRoot/Engine/Build/BatchFiles/Build.bat" TheHeld Win64 Development "-Project=$heldProject" -WaitMutex -NoHotReloadFromIDE -NoUBA
if($LASTEXITCODE -ne 0){throw 'Game compilation failed'}
& "$EngineRoot/Engine/Build/BatchFiles/RunUAT.bat" BuildCookRun "-project=$heldProject" -noP4 -platform=Win64 -clientconfig=Development -skipbuildeditor -cook -stage -pak -archive "-archivedirectory=$ArchiveDirectory" -utf8output -unattended -noUBA
if($LASTEXITCODE -ne 0){throw 'Packaging failed'}
