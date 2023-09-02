#include "menu.hpp"

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
            tab_color = ImColor(60, 60, 60, 255);
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

    const ImColor checkbox_color_dropshadow = ImColor(0, 0, 0, 255);

    ImColor checkbox_color;

    if (*check)
    {
        checkbox_color = ImColor(255, 255, 255, 255);
    }
    else
    {
        if (ImGui::IsItemHovered())
        {
            checkbox_color = ImColor(200, 200, 200, 255);
        }
        else
        {
            checkbox_color = ImColor(60, 60, 60, 255);
        }
    }

    window->DrawList->AddRectFilledMultiColor(pos + ImVec2(2, 2), pos + ImVec2(11, 12), checkbox_color_dropshadow, checkbox_color_dropshadow, checkbox_color_dropshadow, checkbox_color_dropshadow);
    window->DrawList->AddRectFilledMultiColor(pos + ImVec2(2, 2), pos + ImVec2(10, 11), checkbox_color, checkbox_color, checkbox_color, checkbox_color);

    window->DrawList->AddText(menufont, 13.0f, pos + ImVec2(16, 0), checkbox_color_dropshadow, label_text);
    window->DrawList->AddText(menufont, 13.0f, pos + ImVec2(15, -1), checkbox_color, label_text);

    IMGUI_TEST_ENGINE_ITEM_INFO(id, label, window->DC.ItemFlags | ImGuiItemStatusFlags_Checkable | (*check ? ImGuiItemStatusFlags_Checked : 0));

    return pressed;
}