@echo off
echo 正在编译 libcef 开发者工具...

REM 检查是否安装了 Visual Studio
where msbuild >nul 2>&1
if %errorlevel% neq 0 (
    echo 错误: 未找到 MSBuild。请确保已安装 Visual Studio。
    pause
    exit /b 1
)

REM 创建输出目录
if not exist "bin" mkdir "bin"
if not exist "obj" mkdir "obj"

REM 使用 MSBuild 编译项目
msbuild libcef_dev_tool.sln /p:Configuration=Release /p:Platform=Win32 /m

if %errorlevel% equ 0 (
    echo.
    echo 编译成功完成！
    echo 输出文件位于 bin\Release\ 目录中
) else (
    echo.
    echo 编译失败！
    pause
    exit /b 1
)

pause