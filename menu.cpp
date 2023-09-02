#include "menu.hpp"

void elements::menu()
{
    ImGui::SetNextWindowSize(ImVec2(830, 470));
    ImGui::Begin("##menu_for_yougame_free", nullptr, ImGuiWindowFlags_MainMenu);
    {
        const ImVec2 position = ImGui::GetWindowPos();
        const float width = ImGui::GetWindowWidth();
        const float height = ImGui::GetWindowHeight();

        /* backend filled rect's */

        ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(position.x, position.y), ImVec2(position.x + width, position.y + 30), ImColor(24, 24, 24, 255), 0.0f);
        ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(position.x, position.y + 50), ImVec2(position.x + width, position.y + height), ImColor(24, 24, 24, 255), 0.0f);

        /* backend rect's */

        ImGui::GetBackgroundDrawList()->AddRect(ImVec2(position.x + 5, position.y + 55), ImVec2((position.x + width) - 4, (position.y + height) - 4), ImColor(0, 0, 0, 255), 0.0f, 0, 0.5f);
        ImGui::GetBackgroundDrawList()->AddRect(ImVec2(position.x + 5, position.y + 55), ImVec2((position.x + width) - 5, (position.y + height) - 5), ImColor(255, 255, 255, 255), 0.0f, 0, 0.5f);

        /* fade line */

        ImGui::GetBackgroundDrawList()->AddRectFilledMultiColor(ImVec2(position.x, position.y), ImVec2(position.x + (width / 2), position.y + 5), ImColor(255, 255, 255, 0), ImColor(255, 255, 255, 255), ImColor(255, 255, 255, 255), ImColor(255, 255, 255, 0));
        ImGui::GetBackgroundDrawList()->AddRectFilledMultiColor(ImVec2(position.x + (width / 2), position.y), ImVec2(position.x + width, position.y + 5), ImColor(255, 255, 255, 255), ImColor(255, 255, 255, 0), ImColor(255, 255, 255, 0), ImColor(255, 255, 255, 255));

        /* title text */

        ImGui::GetBackgroundDrawList()->AddText(titlefont, 13.f, ImVec2(position.x + 6, position.y + 11), ImColor(0, 0, 0, 255), "menu created by bluebird");
        ImGui::GetBackgroundDrawList()->AddText(titlefont, 13.f, ImVec2(position.x + 5, position.y + 10), ImColor(255, 255, 255, 255), "menu created by bluebird");

        /* tabs */

        ImGui::SetCursorPos(ImVec2(width - 305, 8));
        if (tab("rage", testt == 0))
        {
            testt = 0;
        }

        ImGui::SameLine();
        if (tab("legit", testt == 1))
        {
            testt = 1;
        }

        ImGui::SameLine();
        if (tab("visuals", testt == 2))
        {
            testt = 2;
        }

        ImGui::SameLine();
        if (tab("misc", testt == 3))
        {
            testt = 3;
        }

        ImGui::SameLine();
        if (tab("skins", testt == 4))
        {
            testt = 4;
        }

        ImGui::SameLine();
        if (tab("fonts", testt == 5))
        {
            testt = 5;
        }

        ImGui::SameLine();
        if (tab("lua", testt == 6))
        {
            testt = 6;
        }

        ImGui::SameLine();
        if (tab("mr", testt == 7))
        {
            testt = 7;
        }

        switch (testt)
        {
        case 0:
            ImGui::SetCursorPos(ImVec2(10, 60));
            checkbox("check box", &testtt);
            ImGui::SetCursorPos(ImVec2(10, 90));
            sliderfloat("slider float", &testttt, -25.0f, 25.0f, "%.2f", ImGuiSliderFlags_AlwaysClamp);
            ImGui::SetCursorPos(ImVec2(10, 120));
            sliderint("slider int", &testtttt, 0, 100, "%d", ImGuiSliderFlags_AlwaysClamp);
            ImGui::SetCursorPos(ImVec2(10, 150));
            button("button", ImVec2(60, 20));
            break;
        }
    }
    ImGui::End();
}

bool elements::tab(const char* label_text, bool selected)
{
    ImGuiWindow* window = ImGui::GetCurrentWindow();

    if (window->SkipItems)
    {
        return false;
    }

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label_text);
    const ImVec2 label_size = ImGui::CalcTextSize(label_text, NULL, true);
    ImVec2 pos = window->DC.CursorPos;
    auto tab_size = ImVec2(5 + label_size.x, 5 + label_size.y);
    ImVec2 size = ImGui::CalcItemSize(tab_size, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);
    const ImRect bb(pos, ImVec2(pos.x + size.x, pos.y + size.y));

    ImGui::ItemSize(size, style.FramePadding.y);

    if (!ImGui::ItemAdd(bb, id))
    {
        return false;
    }

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, 0);

    const ImColor tab_color_dropshadow = ImColor(0, 0, 0, 255);

    ImColor tab_color;

    if (selected)
    {
        tab_color = ImColor(255, 255, 255, 255);
    }
    else
    {
        if (ImGui::IsItemHovered())
        {
            tab_color = ImColor(200, 200, 200, 255);
        }
        else
        {
            tab_color = ImColor(120, 120, 120, 255);
        }
    }

    window->DrawList->AddText(menufont, 13.0f, ImVec2(bb.Min.x + (size.x / 2 - ImGui::CalcTextSize(label_text).x / 2) + 1, bb.Min.y + (size.y / 2 - ImGui::CalcTextSize(label_text).y / 2) + 1), tab_color_dropshadow, label_text);
    window->DrawList->AddText(menufont, 13.0f, ImVec2(bb.Min.x + size.x / 2 - ImGui::CalcTextSize(label_text).x / 2, bb.Min.y + size.y / 2 - ImGui::CalcTextSize(label_text).y / 2), tab_color, label_text);

    return pressed;
}

bool elements::checkbox(const char* label_text, bool* check)
{
    ImGuiWindow* window = ImGui::GetCurrentWindow();

    if (window->SkipItems)
    {
        return false;
    }

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label_text);
    const ImVec2 label_size = ImGui::CalcTextSize(label_text, NULL, true);

    const ImVec2 pos = window->DC.CursorPos;
    const ImRect total_bb(pos, pos + ImVec2(label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x + 20 : 0.0f, label_size.y));

    ImGui::ItemSize(total_bb, style.FramePadding.y);

    if (!ImGui::ItemAdd(total_bb, id))
    {
        return false;
    }

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(total_bb, id, &hovered, &held);
    if (pressed)
    {
        *check = !(*check);
        ImGui::MarkItemEdited(id);
    }

    const ImColor color_dropshadow = ImColor(0, 0, 0, 255);

    ImColor checkbox_color;
    ImColor text_color;

    if (*check)
    {
        checkbox_color = ImColor(255, 255, 255, 255);
        text_color = ImColor(255, 255, 255, 255);
    }
    else
    {
        if (ImGui::IsItemHovered())
        {
            checkbox_color = ImColor(200, 200, 200, 255);
            text_color = ImColor(225, 225, 225, 255);
        }
        else
        {
            checkbox_color = ImColor(48, 48, 48, 255);
            text_color = ImColor(200, 200, 200, 255);
        }
    }

    window->DrawList->AddRectFilled(pos + ImVec2(2, 2), pos + ImVec2(11, 12), color_dropshadow);
    window->DrawList->AddRectFilled(pos + ImVec2(2, 2), pos + ImVec2(10, 11), checkbox_color);

    window->DrawList->AddText(menufont, 13.0f, pos + ImVec2(16, 0), color_dropshadow, label_text);
    window->DrawList->AddText(menufont, 13.0f, pos + ImVec2(15, -1), text_color, label_text);

    IMGUI_TEST_ENGINE_ITEM_INFO(id, label, window->DC.ItemFlags | ImGuiItemStatusFlags_Checkable | (*check ? ImGuiItemStatusFlags_Checked : 0));

    return pressed;
}

bool elements::sliderscalar(const char* label, ImGuiDataType data_type, void* p_data, const void* p_min, const void* p_max, const char* format, ImGuiSliderFlags flags)
{
    ImGuiWindow* window = ImGui::GetCurrentWindow();

    if (window->SkipItems)
    {
        return false;
    }

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);
    const float w = ImGui::CalcItemWidth();

    const ImVec2 pos = window->DC.CursorPos;
    const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);
    const ImRect frame_bb(window->DC.CursorPos, window->DC.CursorPos + ImVec2(w, label_size.y + style.FramePadding.y * 1.50f));
    const ImRect total_bb(frame_bb.Min - ImVec2(label_size.x + style.ItemInnerSpacing.x, label_size.y + style.ItemInnerSpacing.y), frame_bb.Max);

    const bool temp_input_allowed = (flags & ImGuiSliderFlags_NoInput) == 0;

    ImGui::ItemSize(total_bb, style.FramePadding.y);

    if (!ImGui::ItemAdd(total_bb, id, &frame_bb, temp_input_allowed ? ImGuiItemFlags_Inputable : 0))
    {
        return false;
    }

    if (format == NULL)
    {
        format = ImGui::DataTypeGetInfo(data_type)->PrintFmt;
    }

    const bool hovered = ImGui::ItemHoverable(frame_bb, id, 0);
    bool temp_input_is_active = temp_input_allowed && ImGui::TempInputIsActive(id);
    if (!temp_input_is_active)
    {
        // Tabbing or CTRL-clicking on Slider turns it into an input box
        const bool input_requested_by_tabbing = temp_input_allowed && (g.LastItemData.StatusFlags & ImGuiItemStatusFlags_FocusedByTabbing) != 0;
        const bool clicked = hovered && ImGui::IsMouseClicked(0, id);
        const bool make_active = (input_requested_by_tabbing || clicked || g.NavActivateId == id);

        if (make_active && clicked)
        {
            ImGui::SetKeyOwner(ImGuiKey_MouseLeft, id);
        }

        if (make_active && temp_input_allowed)
        {
            if (input_requested_by_tabbing || (clicked && g.IO.KeyCtrl) || (g.NavActivateId == id && (g.NavActivateFlags & ImGuiActivateFlags_PreferInput)))
            {
                temp_input_is_active = true;
            }
        }

        if (make_active && !temp_input_is_active)
        {
            ImGui::SetActiveID(id, window);
            ImGui::SetFocusID(id, window);
            ImGui::FocusWindow(window);
            g.ActiveIdUsingNavDirMask |= (1 << ImGuiDir_Left) | (1 << ImGuiDir_Right);
        }
    }

    if (temp_input_is_active)
    {
        // Only clamp CTRL+Click input when ImGuiSliderFlags_AlwaysClamp is set
        const bool is_clamp_input = (flags & ImGuiSliderFlags_AlwaysClamp) != 0;
        return ImGui::TempInputScalar(frame_bb, id, label, data_type, p_data, format, is_clamp_input ? p_min : NULL, is_clamp_input ? p_max : NULL);
    }

    // Slider behavior
    ImRect grab_bb;
    const bool value_changed = ImGui::SliderBehavior(frame_bb, id, data_type, p_data, p_min, p_max, format, flags, &grab_bb);

    if (value_changed)
    {
        ImGui::MarkItemEdited(id);
    }

    char value_buf[64];
    const char* value_buf_end = value_buf + ImGui::DataTypeFormatString(value_buf, IM_ARRAYSIZE(value_buf), data_type, p_data, format);

    const ImColor color_dropshadow = ImColor(0, 0, 0, 255);

    ImColor slider_color;
    ImColor text_color;

    if (g.ActiveId == id)
    {
        slider_color = ImColor(255, 255, 255, 255);
        text_color = ImColor(255, 255, 255, 255);
    }
    else
    {
        if (ImGui::IsItemHovered())
        {
            slider_color = ImColor(200, 200, 200, 255);
            text_color = ImColor(225, 225, 225, 255);
        }
        else
        {
            slider_color = ImColor(48, 48, 48, 255);
            text_color = ImColor(200, 200, 200, 255);
        }
    }

    window->DrawList->AddText(menufont, 13.0f, ImVec2((frame_bb.Max.x + 1) - ImGui::CalcTextSize(value_buf).x, frame_bb.Min.y + 1), color_dropshadow, value_buf, value_buf_end);
    window->DrawList->AddText(menufont, 13.0f, ImVec2(frame_bb.Max.x - ImGui::CalcTextSize(value_buf).x, frame_bb.Min.y), text_color, value_buf, value_buf_end);

    if (label_size.x > 0.0f)
    { 
        window->DrawList->AddText(menufont, 13.0f, ImVec2(frame_bb.Min.x + 2, frame_bb.Min.y + 1), color_dropshadow, label);
        window->DrawList->AddText(menufont, 13.0f, ImVec2(frame_bb.Min.x + 1, frame_bb.Min.y), text_color, label);
    }


    window->DrawList->AddRectFilled(ImVec2(frame_bb.Min.x, frame_bb.Max.y + 4), ImVec2(grab_bb.Max.x + 2, grab_bb.Min.y + 14.5), color_dropshadow, style.GrabRounding);
    window->DrawList->AddRectFilled(ImVec2(frame_bb.Min.x, frame_bb.Max.y + 3), ImVec2(grab_bb.Max.x + 1, grab_bb.Min.y + 13.5), slider_color, style.GrabRounding);

    IMGUI_TEST_ENGINE_ITEM_INFO(id, label, g.LastItemData.StatusFlags | (temp_input_allowed ? ImGuiItemStatusFlags_Inputable : 0));
    return value_changed;
}

bool elements::sliderint(const char* label, int* v, int v_min, int v_max, const char* format, ImGuiSliderFlags flags)
{
    return sliderscalar(label, ImGuiDataType_S32, v, &v_min, &v_max, format, flags);
}

bool elements::sliderfloat(const char* label, float* v, float v_min, float v_max, const char* format, ImGuiSliderFlags flags)
{
    return sliderscalar(label, ImGuiDataType_Float, v, &v_min, &v_max, format, flags);
}

bool elements::buttonex(const char* label, const ImVec2& size_arg, ImGuiButtonFlags flags)
{
    ImGuiWindow* window = ImGui::GetCurrentWindow();

    if (window->SkipItems)
    {
        return false;
    }

    ImGuiContext& g = *GImGui;
    const ImGuiStyle& style = g.Style;
    const ImGuiID id = window->GetID(label);
    const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

    ImVec2 pos = window->DC.CursorPos;

    if ((flags & ImGuiButtonFlags_AlignTextBaseLine) && style.FramePadding.y < window->DC.CurrLineTextBaseOffset) // Try to vertically align buttons that are smaller/have no padding so that text baseline matches (bit hacky, since it shouldn't be a flag)
    {
        pos.y += window->DC.CurrLineTextBaseOffset - style.FramePadding.y;
    }

    ImVec2 size = ImGui::CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

    const ImRect bb(pos, pos + size);
    ImGui::ItemSize(size, style.FramePadding.y);

    if (!ImGui::ItemAdd(bb, id))
    {
        return false;
    }

    if (g.LastItemData.InFlags & ImGuiItemFlags_ButtonRepeat)
    {
        flags |= ImGuiButtonFlags_Repeat;
    }

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, flags);

    const ImColor color_dropshadow = ImColor(0, 0, 0, 255);
    const ImColor color_light = ImColor(80, 80, 80, 255);

    ImColor button_color;
    ImColor text_color;

    if ((held && hovered))
    {
        button_color = ImColor(255, 255, 255, 255);
        text_color = ImColor(255, 255, 255, 255);
    }
    else
    {
        if (hovered)
        {
            button_color = ImColor(200, 200, 200, 255);
            text_color = ImColor(225, 225, 225, 255);
        }
        else
        {
            button_color = ImColor(28, 28, 28, 255);
            text_color = ImColor(200, 200, 200, 255);
        }
    }
 
    ImGui::RenderNavHighlight(bb, id);
    window->DrawList->AddRectFilled(bb.Min, ImVec2(bb.Max.x + 1, bb.Max.y + 1), color_dropshadow);
    window->DrawList->AddRectFilled(bb.Min, bb.Max, button_color);

    if (g.LogEnabled)
    {
        ImGui::LogSetNextTextDecoration("[", "]");
    }

    window->DrawList->AddText(menufont, 13.0f, ImVec2(bb.Min.x + (size.x / 2 - ImGui::CalcTextSize(label).x / 2) + 1, bb.Min.y + (size.y / 2 - ImGui::CalcTextSize(label).y / 2) + 1), color_dropshadow, label);
    window->DrawList->AddText(menufont, 13.0f, ImVec2(bb.Min.x + size.x / 2 - ImGui::CalcTextSize(label).x / 2, bb.Min.y + size.y / 2 - ImGui::CalcTextSize(label).y / 2), text_color, label, NULL);

    IMGUI_TEST_ENGINE_ITEM_INFO(id, label, g.LastItemData.StatusFlags);
    return pressed;
}

bool elements::button(const char* label, const ImVec2& size_arg)
{
    return buttonex(label, size_arg, ImGuiButtonFlags_None);
}