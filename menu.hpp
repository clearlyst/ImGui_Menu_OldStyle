#pragma once
#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_dx9.h>
#include <imgui_impl_win32.h>
#include <d3d9.h>
#include <tchar.h>
#include <string>

extern ImFont* titlefont;
extern ImFont* menufont;
extern ImFont* iconfont;
inline int testt = 0;
inline bool testtt = false;
inline float testttt = false;
inline int testtttt = false;

namespace elements
{
	void menu();
	bool tab(const char* label_text, bool selected);
	bool checkbox(const char* label_text, bool* check);
	bool sliderscalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format, ImGuiSliderFlags flags);
	bool sliderint(const char* label, int* v, int v_min, int v_max, const char* format, ImGuiSliderFlags flags);
	bool sliderfloat(const char* label, float* v, float v_min, float v_max, const char* format, ImGuiSliderFlags flags);
	bool buttonex(const char* label, const ImVec2& size_arg, ImGuiButtonFlags flags);
	bool button(const char* label, const ImVec2& size_arg);
};