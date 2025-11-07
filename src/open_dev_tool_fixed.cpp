// dllmain.cpp : 定义 DLL 应用程序的入口点。
// code from https://bbs.kanxue.com/thread-274426.htm
#include <Windows.h>
#include "detours/detours.h"
#include "libcef/include/capi/cef_browser_capi.h"
#include "libcef/include/capi/cef_client_capi.h"
#include "libcef/include/internal/cef_types_win.h"
#include "libcef/include/internal/cef_win.h"

PVOID g_cef_browser_host_create_browser = nullptr;
PVOID g_cef_get_keyboard_handler = NULL;
PVOID g_cef_on_key_event = NULL;

void SetAsPopup(cef_window_info_t* window_info) {

    window_info->style =
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE;
    window_info->parent_window = NULL;
    window_info->x = CW_USEDEFAULT;
    window_info->y = CW_USEDEFAULT;
    window_info->width = CW_USEDEFAULT;
    window_info->height = CW_USEDEFAULT;
}

int CEF_CALLBACK hook_cef_on_key_event(
    struct _cef_keyboard_handler_t* self,
    struct _cef_browser_t* browser,
    const struct _cef_key_event_t* event,
    cef_event_handle_t os_event) {

    OutputDebugStringA("[detours] hook_cef_on_key_event \n");

    auto cef_browser_host = browser->get_host(browser);

    // 键盘按下且是F12
    if (event->type == KEYEVENT_RAWKEYDOWN && event->windows_key_code == 123) {

        cef_window_info_t windowInfo{};
        cef_browser_settings_t settings{};
        cef_point_t point{};
        SetAsPopup(&windowInfo);
        OutputDebugStringA("[detours] show_dev_tools \n");

        // 开启调试窗口
        cef_browser_host->show_dev_tools
            (cef_browser_host, &windowInfo, 0, &settings, &point);
    }

    return reinterpret_cast<decltype(&hook_cef_on_key_event)>
        (g_cef_on_key_event)(self, browser, event, os_event);
}

struct _cef_keyboard_handler_t* CEF_CALLBACK hook_cef_get_keyboard_handler(
    struct _cef_client_t* self) {
    OutputDebugStringA("[detours] hook_cef_get_keyboard_handler \n");

    // 调用原始的修改get_keyboard_handler函数
    auto keyboard_handler = reinterpret_cast<decltype(&hook_cef_get_keyboard_handler)>
        (g_cef_get_keyboard_handler)(self);
    if (keyboard_handler) {

        // 记录原始的按键事件回调函数
        g_cef_on_key_event = keyboard_handler->on_key_event;

        // 修改返回值中的按键事件回调函数
        keyboard_handler->on_key_event = hook_cef_on_key_event;
    }
    return keyboard_handler;
}

int hook_cef_browser_host_create_browser(
    const cef_window_info_t* windowInfo,
    struct _cef_client_t* client,
    const cef_string_t* url,
    const struct _cef_browser_settings_t* settings,
    struct _cef_dictionary_value_t* extra_info,
    struct _cef_request_context_t* request_context) {

    OutputDebugStringA("[detours] hook_cef_browser_host_create_browser \n");

    // 记录原始的get_keyboard_handler
    g_cef_get_keyboard_handler = client->get_keyboard_handler;

    // 修改get_keyboard_handler
    client->get_keyboard_handler = hook_cef_get_keyboard_handler;


    return reinterpret_cast<decltype(&hook_cef_browser_host_create_browser)>
        (g_cef_browser_host_create_browser)(
        windowInfo, client, url, settings, extra_info, request_context);
}

// Hook cef_browser_host_create_browser
BOOL APIENTRY InstallHook()
{
    OutputDebugStringA("[detours] InstallHook \n");
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    g_cef_browser_host_create_browser =
        DetourFindFunction("libcef.dll", "cef_browser_host_create_browser");
    DetourAttach(&g_cef_browser_host_create_browser,
                 hook_cef_browser_host_create_browser);
    LONG ret = DetourTransactionCommit();
    return ret == NO_ERROR;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        InstallHook();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}