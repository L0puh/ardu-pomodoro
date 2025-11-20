#include "core/core.h"

#include "imgui.h"
#include "draw/draw.h"
#include "settings/settings.h"

void draw_tabs(){
   if (ImGui::BeginTabBar("Tabs")){
      if (ImGui::BeginTabItem("Settings")){
         ImGui::Text("POMODORO TIMER");
         draw_settings_tab();
         ImGui::EndTabItem();
      }
      if (ImGui::BeginTabItem("Stats")){
         draw_stats_tab();
         ImGui::EndTabItem();
      }

      ImGui::EndTabBar();
   }
}


void draw_stats_tab(){
}

void draw_settings_tab(){
   static float work_minutes = 25.0f;

   ImGui::SeparatorText("TIME OF WORK");
   ImGui::PushItemWidth(150); 
   ImGui::PushID("#1");
   ImGui::InputFloat("", &work_minutes, 1.0f, 5.0f, "%.1f");
   ImGui::PopItemWidth();
   ImGui::PopID();

   ImGui::PushID("#2");
   ImGui::PushItemWidth(400); 
   ImGui::SliderFloat("", &work_minutes, 0.1f, 60*24);
   ImGui::PopItemWidth();
   ImGui::PopID();
   
   ImGui::Spacing();
   ImGui::SeparatorText("TIME OF REST");
   static float rest_minutes= 25.0f;
   ImGui::PushItemWidth(150); 
   ImGui::PushID("#3");
   ImGui::InputFloat("", &rest_minutes, 1.0f, 5.0f, "%.1f");
   ImGui::PopItemWidth();
   ImGui::PopID();

   ImGui::PushID("#4");
   ImGui::PushItemWidth(400); 
   ImGui::SliderFloat("", &rest_minutes, 0.1f, 60*24);
   ImGui::PopItemWidth();
   ImGui::PopID();

   settings_t settings;
   settings.work_minutes = work_minutes;
   settings.rest_minutes = rest_minutes;
   if (ImGui::Button("save")){
      save_settings(settings);
      draw_toast("The file is saved");
   }
}
