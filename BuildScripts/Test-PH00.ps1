param([string]$BuildDirectory='', [int]$Width=1280, [int]$Height=720)
$ErrorActionPreference='Stop'
$heldRoot=Split-Path $PSScriptRoot -Parent
if(-not $BuildDirectory){$BuildDirectory=Join-Path $heldRoot 'Builds/PH00/Windows'}
$heldExe=Join-Path $BuildDirectory 'TheHeld/Binaries/Win64/TheHeld.exe'
$heldSaved=Join-Path $BuildDirectory 'TheHeld/Saved'
$heldStart=Get-Date
$heldProcess=Start-Process -FilePath $heldExe -ArgumentList @('/Game/Foundation/L_PH00','-HeldSmoke','-RenderOffscreen','-windowed','-ForceRes',"-ResX=$Width","-ResY=$Height",'-unattended') -WindowStyle Hidden -PassThru
if(-not $heldProcess.WaitForExit(90000)){Stop-Process -Id $heldProcess.Id; throw 'PH00 smoke timed out'}
if($heldProcess.ExitCode -ne 0){throw "PH00 process exit: $($heldProcess.ExitCode)"}
$heldResultFile=Get-Item (Join-Path $heldSaved 'PH00-smoke.json')
if($heldResultFile.LastWriteTime -lt $heldStart){throw 'Stale smoke result'}
$heldResult=Get-Content $heldResultFile.FullName -Raw | ConvertFrom-Json
if(-not $heldResult.route_contact){throw 'Route/contact failed'}
$heldFrame=Get-ChildItem (Join-Path $heldSaved 'Screenshots/Windows') -Filter '*.png' | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if(-not $heldFrame -or $heldFrame.LastWriteTime -lt $heldStart){throw 'Missing fresh frame capture'}
$heldBytes=[IO.File]::ReadAllBytes($heldFrame.FullName)
$heldFrameWidth=([int]$heldBytes[16]*16777216)+([int]$heldBytes[17]*65536)+([int]$heldBytes[18]*256)+$heldBytes[19]
$heldFrameHeight=([int]$heldBytes[20]*16777216)+([int]$heldBytes[21]*65536)+([int]$heldBytes[22]*256)+$heldBytes[23]
if($heldFrameWidth -ne $Width -or $heldFrameHeight -ne $Height){throw "Resolution mismatch: $heldFrameWidth x $heldFrameHeight"}
Write-Output "PASS: route/contact and $Width x $Height capture. Physical input, listening and frame-time budgets require separate review."
