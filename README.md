# libcef 开发者工具

![Build Status](https://github.com/cryzlasm/open_cef_dev_tool/actions/workflows/build.yml/badge.svg)

这个项目提供了一个DLL，可以为基于Chromium Embedded Framework (CEF)的应用程序添加开发者工具功能。通过DLL劫持和Detours库技术，用户可以通过按F12键打开CEF的开发者工具。

## 功能特性

- 通过F12键打开CEF开发者工具
- 使用DLL劫持技术，无需修改目标应用程序
- 基于Detours库实现API Hook
- 支持Windows 32位和64位系统

## 使用方法

### 1. 获取libcef文件
1. 访问 https://cef-builds.spotifycdn.com/index.html#windows32 找到对应版本的libcef
2. 下载对应版本的libcef包含文件

### 2. 替换目录
1. 将下载的libcef文件替换到`./src/libcef`目录中
2. 确保目录结构正确

### 3. 编译项目
有两种方式编译项目：

#### 方法1: 使用Visual Studio
1. 打开`libcef_dev_tool.sln`解决方案文件
2. 选择合适的配置(Release/Debug)和平台(Win32/x64)
3. 点击"生成解决方案"

#### 方法2: 使用GitHub Actions (推荐)
项目配置了GitHub Actions自动编译，支持Windows x86和x64平台。每次推送到main分支或创建Pull Request时都会自动编译。您也可以手动触发编译：
1. 转到项目的Actions页面
2. 选择"Build libcef Dev Tool"工作流
3. 点击"Run workflow"按钮
4. 编译完成后，可以在Artifacts中下载生成的二进制文件（包含x86和x64两个平台的版本）

### 4. 部署DLL
编译完成后，将生成的DLL文件部署到目标应用程序的目录中：
1. 将生成的`libcef_dev_tool.dll`重命名为`libcef.dll`
2. 将原始的`libcef.dll`重命名为`libcef_org.dll`
3. 确保两个文件都在目标应用程序的同一目录中

## 项目结构

```
├── src/
│   ├── worker.cpp                   # 主要实现文件（包含DLL导出转发和开发者工具Hook）
│   ├── exports.def                  # DLL导出定义文件
│   ├── detours/                     # Detours库
│   └── libcef/                      # CEF库文件
├── libcef_dev_tool.sln              # Visual Studio解决方案文件
├── libcef_dev_tool.vcxproj          # Visual Studio项目文件
└── README.md                        # 本文档
```

## 技术原理

1. **DLL劫持**: 通过将原`libcef.dll`重命名为`libcef_org.dll`，并将我们的DLL命名为`libcef.dll`，实现DLL劫持
2. **导出转发**: `exports.def`将所有原`libcef.dll`的导出函数转发到`libcef_org.dll`
3. **API Hook**: `worker.cpp`使用Detours库Hook CEF的API，在用户按下F12时显示开发者工具

## 注意事项

- 仅适用于Windows平台
- 需要与目标应用程序相同架构的版本(32位/64位)
- 使用前请确保遵守相关法律法规和软件许可协议
- 仅供学习和研究使用

## 许可证

本项目仅供学习和研究使用，请遵守相关法律法规。