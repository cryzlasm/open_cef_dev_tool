# PowerShell 构建脚本 for libcef_dev_tool

param(
    [Parameter(Mandatory=$false)]
    [ValidateSet("Debug", "Release")]
    [string]$Configuration = "Release",

    [Parameter(Mandatory=$false)]
    [ValidateSet("Win32", "x64")]
    [string]$Platform = "Win32"
)

Write-Host "正在编译 libcef 开发者工具..." -ForegroundColor Green
Write-Host "配置: $Configuration" -ForegroundColor Yellow
Write-Host "平台: $Platform" -ForegroundColor Yellow

# 检查是否安装了 Visual Studio
$msbuildPath = Get-Command msbuild -ErrorAction SilentlyContinue
if (-not $msbuildPath) {
    Write-Host "错误: 未找到 MSBuild。请确保已安装 Visual Studio。" -ForegroundColor Red
    exit 1
}

# 创建输出目录
if (!(Test-Path "bin")) { New-Item -ItemType Directory -Name "bin" | Out-Null }
if (!(Test-Path "obj")) { New-Item -ItemType Directory -Name "obj" | Out-Null }

# 使用 MSBuild 编译项目
$buildArgs = @(
    "libcef_dev_tool.sln",
    "/p:Configuration=$Configuration",
    "/p:Platform=$Platform",
    "/m",
    "/consoleloggerparameters:ErrorsOnly"
)

Write-Host "执行编译命令: msbuild $($buildArgs -join ' ')" -ForegroundColor Cyan

$result = & msbuild @buildArgs

if ($LASTEXITCODE -eq 0) {
    Write-Host ""
    Write-Host "编译成功完成！" -ForegroundColor Green
    Write-Host "输出文件位于 bin\$Configuration\ 目录中" -ForegroundColor Green
    exit 0
} else {
    Write-Host ""
    Write-Host "编译失败！请检查错误信息。" -ForegroundColor Red
    exit 1
}