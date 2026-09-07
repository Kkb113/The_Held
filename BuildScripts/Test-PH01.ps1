param([int]$FPS=60,[int]$Width=1280,[int]$Height=720,[string]$BuildDirectory='')
$ErrorActionPreference='Stop'
$heldRoot=Split-Path $PSScriptRoot -Parent
if(-not $BuildDirectory){$BuildDirectory=Join-Path $heldRoot 'Builds/PH01/Windows'}
$heldExe=Join-Path $BuildDirectory 'TheHeld/Binaries/Win64/TheHeld.exe'
$heldSaved=Join-Path $BuildDirectory 'TheHeld/Saved'
$heldStart=Get-Date
$heldArgs=@('-HeldTraversalTest','-RenderOffscreen','-windowed','-ForceRes',"-ResX=$Width","-ResY=$Height",'-unattended',"`"-ExecCmds=t.MaxFPS $FPS`"")
$heldProcess=Start-Process -FilePath $heldExe -ArgumentList $heldArgs -WindowStyle Hidden -PassThru
if(-not $heldProcess.WaitForExit(120000)){Stop-Process -Id $heldProcess.Id;throw 'PH01 test timed out'}
if($heldProcess.ExitCode -ne 0){throw "PH01 process exited $($heldProcess.ExitCode)"}
$heldResultFile=Get-Item (Join-Path $heldSaved 'PH01-test.json')
if($heldResultFile.LastWriteTime -lt $heldStart){throw 'Stale test result'}
$heldReport=Join-Path $heldRoot "phase-reviews/PH01/test-$FPS-$Width-$Height.json"
Copy-Item -LiteralPath $heldResultFile.FullName -Destination $heldReport
$heldFrame=Get-ChildItem (Join-Path $heldSaved 'Screenshots/Windows') -Filter '*.png' | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if(-not $heldFrame -or $heldFrame.LastWriteTime -lt $heldStart){throw 'Missing fresh frame'}
$heldBytes=[IO.File]::ReadAllBytes($heldFrame.FullName)
$heldW=([int]$heldBytes[16]*16777216)+([int]$heldBytes[17]*65536)+([int]$heldBytes[18]*256)+$heldBytes[19]
$heldH=([int]$heldBytes[20]*16777216)+([int]$heldBytes[21]*65536)+([int]$heldBytes[22]*256)+$heldBytes[23]
Copy-Item -LiteralPath $heldFrame.FullName -Destination (Join-Path $heldRoot "phase-reviews/PH01/frame-$FPS-$Width-$Height.png")
if($heldW -ne $Width -or $heldH -ne $Height){throw "Wrong capture dimensions: $heldW x $heldH"}
$heldResult=Get-Content $heldReport -Raw | ConvertFrom-Json
if(-not $heldResult.all_checks_pass){throw "Integration checks failed; see $heldReport"}
Write-Output "PASS: PH01 integration fixtures at requested cap $FPS, frame $Width x $Height. Physical device and continuous-route review remain separate."
