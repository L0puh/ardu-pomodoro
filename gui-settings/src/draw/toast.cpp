#include "core/core.h"
#include "draw/draw.h"

static bool show_save_toast = false;
static float toast_timer = 0.0f;
static std::string toast_text;

void draw_toast(const std::string text){
    show_save_toast = true;
    toast_timer = 2.0f;
    toast_text = text;
}

void render_toast()
{
   if (!show_save_toast) return;

   toast_timer -= ImGui::GetIO().DeltaTime;

   ImVec2 pos = ImVec2(ImGui::GetIO().DisplaySize.x - 10.0f, 10.0f);
   ImVec2 pos_pivot = ImVec2(1.0f, 0.0f);
   ImGui::SetNextWindowPos(pos, ImGuiCond_Always, pos_pivot);

   float alpha = toast_timer / 2.0f;
   ImGui::PushStyleVar(ImGuiStyleVar_Alpha, alpha);

   if (ImGui::Begin("SaveToast", nullptr,
            ImGuiWindowFlags_NoDecoration |
            ImGuiWindowFlags_AlwaysAutoResize |
            ImGuiWindowFlags_NoSavedSettings |
            ImGuiWindowFlags_NoFocusOnAppearing |
            ImGuiWindowFlags_NoNav |
            ImGuiWindowFlags_NoMove))
   {
      //TODO:: add more colors and types (i.e. success, error, warning and info)
      ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "%s", toast_text.c_str());
   }
   ImGui::End();
   ImGui::PopStyleVar();

   if (toast_timer <= 0.0f)
      show_save_toast = false;
}
