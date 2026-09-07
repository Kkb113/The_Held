param([string]$BuildDirectory='')
$ErrorActionPreference='Stop'
$heldRoot=Split-Path $PSScriptRoot -Parent
if(-not $BuildDirectory){$BuildDirectory=Join-Path $heldRoot 'Builds/PH01/Windows'}
$heldStart=Get-Date
$heldProcess=Start-Process -FilePath (Join-Path $BuildDirectory 'TheHeld/Binaries/Win64/TheHeld.exe') -ArgumentList @('-HeldRouteTest','-RenderOffscreen','-windowed','-ForceRes','-ResX=1280','-ResY=720','-unattended','"-ExecCmds=t.MaxFPS 60"') -WindowStyle Hidden -PassThru
if(-not $heldProcess.WaitForExit(200000)){Stop-Process -Id $heldProcess.Id;throw 'Connected route timed out'}
if($heldProcess.ExitCode -ne 0){throw 'Connected route process failed'}
$heldResultFile=Get-Item (Join-Path $BuildDirectory 'TheHeld/Saved/PH01-route.json')
if($heldResultFile.LastWriteTime -lt $heldStart){throw 'Stale route result'}
Copy-Item -LiteralPath $heldResultFile.FullName -Destination (Join-Path $heldRoot 'phase-reviews/PH01/route.json')
$heldResult=Get-Content $heldResultFile.FullName -Raw | ConvertFrom-Json
if(-not $heldResult.route_completed){throw "Route failed at X=$($heldResult.x)"}
Write-Output "PASS: connected forward route in $($heldResult.seconds) seconds (automated, not first-time-player pacing)."
