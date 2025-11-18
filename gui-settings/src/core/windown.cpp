#include "GLFW/glfw3.h"
#include "core/window.h"
#include "input/inputs.h"

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}


void imgui_style_setup(){
   float main_scale = ImGui_ImplGlfw_GetContentScaleForMonitor(glfwGetPrimaryMonitor()); 
   ImGui::StyleColorsDark();

   ImGuiStyle& style = ImGui::GetStyle();
   style.ScaleAllSizes(main_scale);     
   style.FontScaleDpi = main_scale * 2.0f;    
}

int setup_window(){
   glfwSetErrorCallback(glfw_error_callback);
   if (!glfwInit())
      return 1;

   const char* glsl_version = "#version 130";
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

   float main_scale = ImGui_ImplGlfw_GetContentScaleForMonitor(glfwGetPrimaryMonitor()); 
   window = glfwCreateWindow((int)(1280 * main_scale), (int)(800 * main_scale), "Window", nullptr, nullptr);
   if (window == nullptr)
      return 1;
   glfwMakeContextCurrent(window);
   glfwSwapInterval(1); 

   IMGUI_CHECKVERSION();
   ImGui::CreateContext();
   ImGuiIO& io = ImGui::GetIO(); (void)io;
   io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     
   
   imgui_style_setup();

   ImGui_ImplGlfw_InitForOpenGL(window, true);
   ImGui_ImplOpenGL3_Init(glsl_version);

   return 0;
}

void start_loop(){
   ImGuiIO& io = ImGui::GetIO(); (void)io;
   
   while (!glfwWindowShouldClose(window)){
      glfwPollEvents();
      if (glfwGetWindowAttrib(window, GLFW_ICONIFIED) != 0)
      {
         ImGui_ImplGlfw_Sleep(10);
         continue;
      }

      ImGui_ImplOpenGL3_NewFrame();
      ImGui_ImplGlfw_NewFrame();
      ImGui::NewFrame();

      {
         draw_program();
      }

      ImGui::Render();
      int display_w, display_h;
      glfwGetFramebufferSize(window, &display_w, &display_h);
      glViewport(0, 0, display_w, display_h);
      glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
      glClear(GL_COLOR_BUFFER_BIT);
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

      glfwSwapBuffers(window);
   }
}
void stop_loop(){
   ImGui_ImplOpenGL3_Shutdown();
   ImGui_ImplGlfw_Shutdown();
   ImGui::DestroyContext();

   glfwDestroyWindow(window);
   glfwTerminate();
}

