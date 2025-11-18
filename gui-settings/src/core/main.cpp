#include "core/window.h"
#include "draw/tabs.h"

extern GLFWwindow* window;
static ImGuiWindowFlags flags;


void draw_program(){
   flags = (ImGuiWindowFlags_NoDecoration |
            ImGuiWindowFlags_AlwaysAutoResize  | 
            ImGuiWindowFlags_NoBackground |
            ImGuiWindowFlags_NoMove);


   ImGui::Begin("name", NULL, flags);
   draw_tabs();
   ImGui::End();
}

int main(int, char**)
{
   if (setup_window()) {
      printf("Error in window setup\n");
      return 1;
   }
   start_loop();
   stop_loop();
   return 0;
}
