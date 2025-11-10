


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 头文件
// dllmain.cpp : 定义 DLL 应用程序的入口点。
// code from https://bbs.kanxue.com/thread-274426.htm
#include <Windows.h>
#include "./detours/detours.h"
#include "include/capi/cef_browser_capi.h"
#include "include/capi/cef_client_capi.h"
#include "include/internal/cef_types_win.h"
#include "include/internal/cef_win.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 导出函数
#pragma comment(linker, "/EXPORT:GetHandleVerifier=libcef_org.GetHandleVerifier,@1")
#pragma comment(linker, "/EXPORT:IsCrashReportingEnabledImpl=libcef_org.IsCrashReportingEnabledImpl,@2")
#pragma comment(linker, "/EXPORT:IsSandboxedProcess=libcef_org.IsSandboxedProcess,@3")
#pragma comment(linker, "/EXPORT:RelaunchChromeBrowserWithNewCommandLineIfNeeded=libcef_org.RelaunchChromeBrowserWithNewCommandLineIfNeeded,@4")
#pragma comment(linker, "/EXPORT:SetCrashKeyValueImpl=libcef_org.SetCrashKeyValueImpl,@5")
#pragma comment(linker, "/EXPORT:cef_add_cross_origin_whitelist_entry=libcef_org.cef_add_cross_origin_whitelist_entry,@6")
#pragma comment(linker, "/EXPORT:cef_api_hash=libcef_org.cef_api_hash,@7")
#pragma comment(linker, "/EXPORT:cef_base64decode=libcef_org.cef_base64decode,@8")
#pragma comment(linker, "/EXPORT:cef_base64encode=libcef_org.cef_base64encode,@9")
#pragma comment(linker, "/EXPORT:cef_basetime_now=libcef_org.cef_basetime_now,@10")
#pragma comment(linker, "/EXPORT:cef_begin_tracing=libcef_org.cef_begin_tracing,@11")
#pragma comment(linker, "/EXPORT:cef_binary_value_create=libcef_org.cef_binary_value_create,@12")
#pragma comment(linker, "/EXPORT:cef_browser_host_create_browser=libcef_org.cef_browser_host_create_browser,@13")
#pragma comment(linker, "/EXPORT:cef_browser_host_create_browser_sync=libcef_org.cef_browser_host_create_browser_sync,@14")
#pragma comment(linker, "/EXPORT:cef_browser_view_create=libcef_org.cef_browser_view_create,@15")
#pragma comment(linker, "/EXPORT:cef_browser_view_get_for_browser=libcef_org.cef_browser_view_get_for_browser,@16")
#pragma comment(linker, "/EXPORT:cef_clear_cross_origin_whitelist=libcef_org.cef_clear_cross_origin_whitelist,@17")
#pragma comment(linker, "/EXPORT:cef_clear_scheme_handler_factories=libcef_org.cef_clear_scheme_handler_factories,@18")
#pragma comment(linker, "/EXPORT:cef_command_line_create=libcef_org.cef_command_line_create,@19")
#pragma comment(linker, "/EXPORT:cef_command_line_get_global=libcef_org.cef_command_line_get_global,@20")
#pragma comment(linker, "/EXPORT:cef_cookie_manager_get_global_manager=libcef_org.cef_cookie_manager_get_global_manager,@21")
#pragma comment(linker, "/EXPORT:cef_crash_reporting_enabled=libcef_org.cef_crash_reporting_enabled,@22")
#pragma comment(linker, "/EXPORT:cef_create_context_shared=libcef_org.cef_create_context_shared,@23")
#pragma comment(linker, "/EXPORT:cef_create_directory=libcef_org.cef_create_directory,@24")
#pragma comment(linker, "/EXPORT:cef_create_new_temp_directory=libcef_org.cef_create_new_temp_directory,@25")
#pragma comment(linker, "/EXPORT:cef_create_temp_directory_in_directory=libcef_org.cef_create_temp_directory_in_directory,@26")
#pragma comment(linker, "/EXPORT:cef_create_url=libcef_org.cef_create_url,@27")
#pragma comment(linker, "/EXPORT:cef_currently_on=libcef_org.cef_currently_on,@28")
#pragma comment(linker, "/EXPORT:cef_delete_file=libcef_org.cef_delete_file,@29")
#pragma comment(linker, "/EXPORT:cef_dictionary_value_create=libcef_org.cef_dictionary_value_create,@30")
#pragma comment(linker, "/EXPORT:cef_directory_exists=libcef_org.cef_directory_exists,@31")
#pragma comment(linker, "/EXPORT:cef_display_convert_screen_point_from_pixels=libcef_org.cef_display_convert_screen_point_from_pixels,@32")
#pragma comment(linker, "/EXPORT:cef_display_convert_screen_point_to_pixels=libcef_org.cef_display_convert_screen_point_to_pixels,@33")
#pragma comment(linker, "/EXPORT:cef_display_convert_screen_rect_from_pixels=libcef_org.cef_display_convert_screen_rect_from_pixels,@34")
#pragma comment(linker, "/EXPORT:cef_display_convert_screen_rect_to_pixels=libcef_org.cef_display_convert_screen_rect_to_pixels,@35")
#pragma comment(linker, "/EXPORT:cef_display_get_alls=libcef_org.cef_display_get_alls,@36")
#pragma comment(linker, "/EXPORT:cef_display_get_count=libcef_org.cef_display_get_count,@37")
#pragma comment(linker, "/EXPORT:cef_display_get_matching_bounds=libcef_org.cef_display_get_matching_bounds,@38")
#pragma comment(linker, "/EXPORT:cef_display_get_nearest_point=libcef_org.cef_display_get_nearest_point,@39")
#pragma comment(linker, "/EXPORT:cef_display_get_primary=libcef_org.cef_display_get_primary,@40")
#pragma comment(linker, "/EXPORT:cef_do_message_loop_work=libcef_org.cef_do_message_loop_work,@41")
#pragma comment(linker, "/EXPORT:cef_drag_data_create=libcef_org.cef_drag_data_create,@42")
#pragma comment(linker, "/EXPORT:cef_enable_highdpi_support=libcef_org.cef_enable_highdpi_support,@43")
#pragma comment(linker, "/EXPORT:cef_end_tracing=libcef_org.cef_end_tracing,@44")
#pragma comment(linker, "/EXPORT:cef_execute_java_script_with_user_gesture_for_tests=libcef_org.cef_execute_java_script_with_user_gesture_for_tests,@45")
#pragma comment(linker, "/EXPORT:cef_execute_process=libcef_org.cef_execute_process,@46")
#pragma comment(linker, "/EXPORT:cef_format_url_for_security_display=libcef_org.cef_format_url_for_security_display,@47")
#pragma comment(linker, "/EXPORT:cef_get_current_platform_thread_handle=libcef_org.cef_get_current_platform_thread_handle,@48")
#pragma comment(linker, "/EXPORT:cef_get_current_platform_thread_id=libcef_org.cef_get_current_platform_thread_id,@49")
#pragma comment(linker, "/EXPORT:cef_get_extensions_for_mime_type=libcef_org.cef_get_extensions_for_mime_type,@50")
#pragma comment(linker, "/EXPORT:cef_get_mime_type=libcef_org.cef_get_mime_type,@51")
#pragma comment(linker, "/EXPORT:cef_get_min_log_level=libcef_org.cef_get_min_log_level,@52")
#pragma comment(linker, "/EXPORT:cef_get_path=libcef_org.cef_get_path,@53")
#pragma comment(linker, "/EXPORT:cef_get_temp_directory=libcef_org.cef_get_temp_directory,@54")
#pragma comment(linker, "/EXPORT:cef_get_vlog_level=libcef_org.cef_get_vlog_level,@55")
#pragma comment(linker, "/EXPORT:cef_image_create=libcef_org.cef_image_create,@56")
#pragma comment(linker, "/EXPORT:cef_initialize=libcef_org.cef_initialize,@57")
#pragma comment(linker, "/EXPORT:cef_is_cert_status_error=libcef_org.cef_is_cert_status_error,@58")
#pragma comment(linker, "/EXPORT:cef_is_rtl=libcef_org.cef_is_rtl,@59")
#pragma comment(linker, "/EXPORT:cef_label_button_create=libcef_org.cef_label_button_create,@60")
#pragma comment(linker, "/EXPORT:cef_launch_process=libcef_org.cef_launch_process,@61")
#pragma comment(linker, "/EXPORT:cef_list_value_create=libcef_org.cef_list_value_create,@62")
#pragma comment(linker, "/EXPORT:cef_load_crlsets_file=libcef_org.cef_load_crlsets_file,@63")
#pragma comment(linker, "/EXPORT:cef_log=libcef_org.cef_log,@64")
#pragma comment(linker, "/EXPORT:cef_media_router_get_global=libcef_org.cef_media_router_get_global,@65")
#pragma comment(linker, "/EXPORT:cef_menu_button_create=libcef_org.cef_menu_button_create,@66")
#pragma comment(linker, "/EXPORT:cef_menu_model_create=libcef_org.cef_menu_model_create,@67")
#pragma comment(linker, "/EXPORT:cef_now_from_system_trace_time=libcef_org.cef_now_from_system_trace_time,@68")
#pragma comment(linker, "/EXPORT:cef_panel_create=libcef_org.cef_panel_create,@69")
#pragma comment(linker, "/EXPORT:cef_parse_json=libcef_org.cef_parse_json,@70")
#pragma comment(linker, "/EXPORT:cef_parse_json_buffer=libcef_org.cef_parse_json_buffer,@71")
#pragma comment(linker, "/EXPORT:cef_parse_jsonand_return_error=libcef_org.cef_parse_jsonand_return_error,@72")
#pragma comment(linker, "/EXPORT:cef_parse_url=libcef_org.cef_parse_url,@73")
#pragma comment(linker, "/EXPORT:cef_post_data_create=libcef_org.cef_post_data_create,@74")
#pragma comment(linker, "/EXPORT:cef_post_data_element_create=libcef_org.cef_post_data_element_create,@75")
#pragma comment(linker, "/EXPORT:cef_post_delayed_task=libcef_org.cef_post_delayed_task,@76")
#pragma comment(linker, "/EXPORT:cef_post_task=libcef_org.cef_post_task,@77")
#pragma comment(linker, "/EXPORT:cef_preference_manager_get_global=libcef_org.cef_preference_manager_get_global,@78")
#pragma comment(linker, "/EXPORT:cef_print_settings_create=libcef_org.cef_print_settings_create,@79")
#pragma comment(linker, "/EXPORT:cef_process_message_create=libcef_org.cef_process_message_create,@80")
#pragma comment(linker, "/EXPORT:cef_quit_message_loop=libcef_org.cef_quit_message_loop,@81")
#pragma comment(linker, "/EXPORT:cef_register_extension=libcef_org.cef_register_extension,@82")
#pragma comment(linker, "/EXPORT:cef_register_scheme_handler_factory=libcef_org.cef_register_scheme_handler_factory,@83")
#pragma comment(linker, "/EXPORT:cef_remove_cross_origin_whitelist_entry=libcef_org.cef_remove_cross_origin_whitelist_entry,@84")
#pragma comment(linker, "/EXPORT:cef_request_context_create_context=libcef_org.cef_request_context_create_context,@85")
#pragma comment(linker, "/EXPORT:cef_request_context_get_global_context=libcef_org.cef_request_context_get_global_context,@86")
#pragma comment(linker, "/EXPORT:cef_request_create=libcef_org.cef_request_create,@87")
#pragma comment(linker, "/EXPORT:cef_resolve_url=libcef_org.cef_resolve_url,@88")
#pragma comment(linker, "/EXPORT:cef_resource_bundle_get_global=libcef_org.cef_resource_bundle_get_global,@89")
#pragma comment(linker, "/EXPORT:cef_response_create=libcef_org.cef_response_create,@90")
#pragma comment(linker, "/EXPORT:cef_run_main_with_preferred_stack_size=libcef_org.cef_run_main_with_preferred_stack_size,@91")
#pragma comment(linker, "/EXPORT:cef_run_message_loop=libcef_org.cef_run_message_loop,@92")
#pragma comment(linker, "/EXPORT:cef_run_winmain_with_preferred_stack_size=libcef_org.cef_run_winmain_with_preferred_stack_size,@93")
#pragma comment(linker, "/EXPORT:cef_scroll_view_create=libcef_org.cef_scroll_view_create,@94")
#pragma comment(linker, "/EXPORT:cef_server_create=libcef_org.cef_server_create,@95")
#pragma comment(linker, "/EXPORT:cef_set_crash_key_value=libcef_org.cef_set_crash_key_value,@96")
#pragma comment(linker, "/EXPORT:cef_set_data_directory_for_tests=libcef_org.cef_set_data_directory_for_tests,@97")
#pragma comment(linker, "/EXPORT:cef_set_osmodal_loop=libcef_org.cef_set_osmodal_loop,@98")
#pragma comment(linker, "/EXPORT:cef_shared_process_message_builder_create=libcef_org.cef_shared_process_message_builder_create,@99")
#pragma comment(linker, "/EXPORT:cef_shutdown=libcef_org.cef_shutdown,@100")
#pragma comment(linker, "/EXPORT:cef_stream_reader_create_for_data=libcef_org.cef_stream_reader_create_for_data,@101")
#pragma comment(linker, "/EXPORT:cef_stream_reader_create_for_file=libcef_org.cef_stream_reader_create_for_file,@102")
#pragma comment(linker, "/EXPORT:cef_stream_reader_create_for_handler=libcef_org.cef_stream_reader_create_for_handler,@103")
#pragma comment(linker, "/EXPORT:cef_stream_writer_create_for_file=libcef_org.cef_stream_writer_create_for_file,@104")
#pragma comment(linker, "/EXPORT:cef_stream_writer_create_for_handler=libcef_org.cef_stream_writer_create_for_handler,@105")
#pragma comment(linker, "/EXPORT:cef_string_ascii_to_utf16=libcef_org.cef_string_ascii_to_utf16,@106")
#pragma comment(linker, "/EXPORT:cef_string_ascii_to_wide=libcef_org.cef_string_ascii_to_wide,@107")
#pragma comment(linker, "/EXPORT:cef_string_list_alloc=libcef_org.cef_string_list_alloc,@108")
#pragma comment(linker, "/EXPORT:cef_string_list_append=libcef_org.cef_string_list_append,@109")
#pragma comment(linker, "/EXPORT:cef_string_list_clear=libcef_org.cef_string_list_clear,@110")
#pragma comment(linker, "/EXPORT:cef_string_list_copy=libcef_org.cef_string_list_copy,@111")
#pragma comment(linker, "/EXPORT:cef_string_list_free=libcef_org.cef_string_list_free,@112")
#pragma comment(linker, "/EXPORT:cef_string_list_size=libcef_org.cef_string_list_size,@113")
#pragma comment(linker, "/EXPORT:cef_string_list_value=libcef_org.cef_string_list_value,@114")
#pragma comment(linker, "/EXPORT:cef_string_map_alloc=libcef_org.cef_string_map_alloc,@115")
#pragma comment(linker, "/EXPORT:cef_string_map_append=libcef_org.cef_string_map_append,@116")
#pragma comment(linker, "/EXPORT:cef_string_map_clear=libcef_org.cef_string_map_clear,@117")
#pragma comment(linker, "/EXPORT:cef_string_map_find=libcef_org.cef_string_map_find,@118")
#pragma comment(linker, "/EXPORT:cef_string_map_free=libcef_org.cef_string_map_free,@119")
#pragma comment(linker, "/EXPORT:cef_string_map_key=libcef_org.cef_string_map_key,@120")
#pragma comment(linker, "/EXPORT:cef_string_map_size=libcef_org.cef_string_map_size,@121")
#pragma comment(linker, "/EXPORT:cef_string_map_value=libcef_org.cef_string_map_value,@122")
#pragma comment(linker, "/EXPORT:cef_string_multimap_alloc=libcef_org.cef_string_multimap_alloc,@123")
#pragma comment(linker, "/EXPORT:cef_string_multimap_append=libcef_org.cef_string_multimap_append,@124")
#pragma comment(linker, "/EXPORT:cef_string_multimap_clear=libcef_org.cef_string_multimap_clear,@125")
#pragma comment(linker, "/EXPORT:cef_string_multimap_enumerate=libcef_org.cef_string_multimap_enumerate,@126")
#pragma comment(linker, "/EXPORT:cef_string_multimap_find_count=libcef_org.cef_string_multimap_find_count,@127")
#pragma comment(linker, "/EXPORT:cef_string_multimap_free=libcef_org.cef_string_multimap_free,@128")
#pragma comment(linker, "/EXPORT:cef_string_multimap_key=libcef_org.cef_string_multimap_key,@129")
#pragma comment(linker, "/EXPORT:cef_string_multimap_size=libcef_org.cef_string_multimap_size,@130")
#pragma comment(linker, "/EXPORT:cef_string_multimap_value=libcef_org.cef_string_multimap_value,@131")
#pragma comment(linker, "/EXPORT:cef_string_userfree_utf16_alloc=libcef_org.cef_string_userfree_utf16_alloc,@132")
#pragma comment(linker, "/EXPORT:cef_string_userfree_utf16_free=libcef_org.cef_string_userfree_utf16_free,@133")
#pragma comment(linker, "/EXPORT:cef_string_userfree_utf8_alloc=libcef_org.cef_string_userfree_utf8_alloc,@134")
#pragma comment(linker, "/EXPORT:cef_string_userfree_utf8_free=libcef_org.cef_string_userfree_utf8_free,@135")
#pragma comment(linker, "/EXPORT:cef_string_userfree_wide_alloc=libcef_org.cef_string_userfree_wide_alloc,@136")
#pragma comment(linker, "/EXPORT:cef_string_userfree_wide_free=libcef_org.cef_string_userfree_wide_free,@137")
#pragma comment(linker, "/EXPORT:cef_string_utf16_clear=libcef_org.cef_string_utf16_clear,@138")
#pragma comment(linker, "/EXPORT:cef_string_utf16_cmp=libcef_org.cef_string_utf16_cmp,@139")
#pragma comment(linker, "/EXPORT:cef_string_utf16_set=libcef_org.cef_string_utf16_set,@140")
#pragma comment(linker, "/EXPORT:cef_string_utf16_to_lower=libcef_org.cef_string_utf16_to_lower,@141")
#pragma comment(linker, "/EXPORT:cef_string_utf16_to_upper=libcef_org.cef_string_utf16_to_upper,@142")
#pragma comment(linker, "/EXPORT:cef_string_utf16_to_utf8=libcef_org.cef_string_utf16_to_utf8,@143")
#pragma comment(linker, "/EXPORT:cef_string_utf16_to_wide=libcef_org.cef_string_utf16_to_wide,@144")
#pragma comment(linker, "/EXPORT:cef_string_utf8_clear=libcef_org.cef_string_utf8_clear,@145")
#pragma comment(linker, "/EXPORT:cef_string_utf8_cmp=libcef_org.cef_string_utf8_cmp,@146")
#pragma comment(linker, "/EXPORT:cef_string_utf8_set=libcef_org.cef_string_utf8_set,@147")
#pragma comment(linker, "/EXPORT:cef_string_utf8_to_utf16=libcef_org.cef_string_utf8_to_utf16,@148")
#pragma comment(linker, "/EXPORT:cef_string_utf8_to_wide=libcef_org.cef_string_utf8_to_wide,@149")
#pragma comment(linker, "/EXPORT:cef_string_wide_clear=libcef_org.cef_string_wide_clear,@150")
#pragma comment(linker, "/EXPORT:cef_string_wide_cmp=libcef_org.cef_string_wide_cmp,@151")
#pragma comment(linker, "/EXPORT:cef_string_wide_set=libcef_org.cef_string_wide_set,@152")
#pragma comment(linker, "/EXPORT:cef_string_wide_to_utf16=libcef_org.cef_string_wide_to_utf16,@153")
#pragma comment(linker, "/EXPORT:cef_string_wide_to_utf8=libcef_org.cef_string_wide_to_utf8,@154")
#pragma comment(linker, "/EXPORT:cef_task_runner_get_for_current_thread=libcef_org.cef_task_runner_get_for_current_thread,@155")
#pragma comment(linker, "/EXPORT:cef_task_runner_get_for_thread=libcef_org.cef_task_runner_get_for_thread,@156")
#pragma comment(linker, "/EXPORT:cef_test_server_create_and_start=libcef_org.cef_test_server_create_and_start,@157")
#pragma comment(linker, "/EXPORT:cef_textfield_create=libcef_org.cef_textfield_create,@158")
#pragma comment(linker, "/EXPORT:cef_thread_create=libcef_org.cef_thread_create,@159")
#pragma comment(linker, "/EXPORT:cef_time_delta=libcef_org.cef_time_delta,@160")
#pragma comment(linker, "/EXPORT:cef_time_from_basetime=libcef_org.cef_time_from_basetime,@161")
#pragma comment(linker, "/EXPORT:cef_time_from_doublet=libcef_org.cef_time_from_doublet,@162")
#pragma comment(linker, "/EXPORT:cef_time_from_timet=libcef_org.cef_time_from_timet,@163")
#pragma comment(linker, "/EXPORT:cef_time_now=libcef_org.cef_time_now,@164")
#pragma comment(linker, "/EXPORT:cef_time_to_basetime=libcef_org.cef_time_to_basetime,@165")
#pragma comment(linker, "/EXPORT:cef_time_to_doublet=libcef_org.cef_time_to_doublet,@166")
#pragma comment(linker, "/EXPORT:cef_time_to_timet=libcef_org.cef_time_to_timet,@167")
#pragma comment(linker, "/EXPORT:cef_trace_counter=libcef_org.cef_trace_counter,@168")
#pragma comment(linker, "/EXPORT:cef_trace_counter_id=libcef_org.cef_trace_counter_id,@169")
#pragma comment(linker, "/EXPORT:cef_trace_event_async_begin=libcef_org.cef_trace_event_async_begin,@170")
#pragma comment(linker, "/EXPORT:cef_trace_event_async_end=libcef_org.cef_trace_event_async_end,@171")
#pragma comment(linker, "/EXPORT:cef_trace_event_async_step_into=libcef_org.cef_trace_event_async_step_into,@172")
#pragma comment(linker, "/EXPORT:cef_trace_event_async_step_past=libcef_org.cef_trace_event_async_step_past,@173")
#pragma comment(linker, "/EXPORT:cef_trace_event_begin=libcef_org.cef_trace_event_begin,@174")
#pragma comment(linker, "/EXPORT:cef_trace_event_end=libcef_org.cef_trace_event_end,@175")
#pragma comment(linker, "/EXPORT:cef_trace_event_instant=libcef_org.cef_trace_event_instant,@176")
#pragma comment(linker, "/EXPORT:cef_translator_test_create=libcef_org.cef_translator_test_create,@177")
#pragma comment(linker, "/EXPORT:cef_translator_test_ref_ptr_library_child_child_create=libcef_org.cef_translator_test_ref_ptr_library_child_child_create,@178")
#pragma comment(linker, "/EXPORT:cef_translator_test_ref_ptr_library_child_create=libcef_org.cef_translator_test_ref_ptr_library_child_create,@179")
#pragma comment(linker, "/EXPORT:cef_translator_test_ref_ptr_library_create=libcef_org.cef_translator_test_ref_ptr_library_create,@180")
#pragma comment(linker, "/EXPORT:cef_translator_test_scoped_library_child_child_create=libcef_org.cef_translator_test_scoped_library_child_child_create,@181")
#pragma comment(linker, "/EXPORT:cef_translator_test_scoped_library_child_create=libcef_org.cef_translator_test_scoped_library_child_create,@182")
#pragma comment(linker, "/EXPORT:cef_translator_test_scoped_library_create=libcef_org.cef_translator_test_scoped_library_create,@183")
#pragma comment(linker, "/EXPORT:cef_uridecode=libcef_org.cef_uridecode,@184")
#pragma comment(linker, "/EXPORT:cef_uriencode=libcef_org.cef_uriencode,@185")
#pragma comment(linker, "/EXPORT:cef_urlrequest_create=libcef_org.cef_urlrequest_create,@186")
#pragma comment(linker, "/EXPORT:cef_v8context_get_current_context=libcef_org.cef_v8context_get_current_context,@187")
#pragma comment(linker, "/EXPORT:cef_v8context_get_entered_context=libcef_org.cef_v8context_get_entered_context,@188")
#pragma comment(linker, "/EXPORT:cef_v8context_in_context=libcef_org.cef_v8context_in_context,@189")
#pragma comment(linker, "/EXPORT:cef_v8stack_trace_get_current=libcef_org.cef_v8stack_trace_get_current,@190")
#pragma comment(linker, "/EXPORT:cef_v8value_create_array=libcef_org.cef_v8value_create_array,@191")
#pragma comment(linker, "/EXPORT:cef_v8value_create_array_buffer=libcef_org.cef_v8value_create_array_buffer,@192")
#pragma comment(linker, "/EXPORT:cef_v8value_create_bool=libcef_org.cef_v8value_create_bool,@193")
#pragma comment(linker, "/EXPORT:cef_v8value_create_date=libcef_org.cef_v8value_create_date,@194")
#pragma comment(linker, "/EXPORT:cef_v8value_create_double=libcef_org.cef_v8value_create_double,@195")
#pragma comment(linker, "/EXPORT:cef_v8value_create_function=libcef_org.cef_v8value_create_function,@196")
#pragma comment(linker, "/EXPORT:cef_v8value_create_int=libcef_org.cef_v8value_create_int,@197")
#pragma comment(linker, "/EXPORT:cef_v8value_create_null=libcef_org.cef_v8value_create_null,@198")
#pragma comment(linker, "/EXPORT:cef_v8value_create_object=libcef_org.cef_v8value_create_object,@199")
#pragma comment(linker, "/EXPORT:cef_v8value_create_promise=libcef_org.cef_v8value_create_promise,@200")
#pragma comment(linker, "/EXPORT:cef_v8value_create_string=libcef_org.cef_v8value_create_string,@201")
#pragma comment(linker, "/EXPORT:cef_v8value_create_uint=libcef_org.cef_v8value_create_uint,@202")
#pragma comment(linker, "/EXPORT:cef_v8value_create_undefined=libcef_org.cef_v8value_create_undefined,@203")
#pragma comment(linker, "/EXPORT:cef_value_create=libcef_org.cef_value_create,@204")
#pragma comment(linker, "/EXPORT:cef_version_info=libcef_org.cef_version_info,@205")
#pragma comment(linker, "/EXPORT:cef_waitable_event_create=libcef_org.cef_waitable_event_create,@206")
#pragma comment(linker, "/EXPORT:cef_window_create_top_level=libcef_org.cef_window_create_top_level,@207")
#pragma comment(linker, "/EXPORT:cef_write_json=libcef_org.cef_write_json,@208")
#pragma comment(linker, "/EXPORT:cef_xml_reader_create=libcef_org.cef_xml_reader_create,@209")
#pragma comment(linker, "/EXPORT:cef_zip_directory=libcef_org.cef_zip_directory,@210")
#pragma comment(linker, "/EXPORT:cef_zip_reader_create=libcef_org.cef_zip_reader_create,@211")
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


PVOID g_cef_browser_host_create_browser = nullptr;
PVOID g_cef_get_keyboard_handler = NULL;
PVOID g_cef_on_key_event = NULL;

void SetAsPopup(cef_window_info_t* window_info) {

    window_info->style =
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE;
    window_info->parent_window = NULL;
    window_info->bounds.x = CW_USEDEFAULT;
    window_info->bounds.y = CW_USEDEFAULT;
    window_info->bounds.width = CW_USEDEFAULT;
    window_info->bounds.height = CW_USEDEFAULT;
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 入口函数
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
        InstallHook();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
