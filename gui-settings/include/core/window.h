#ifndef WINDOW_H
#define WINDOW_H

#include "core/core.h"
#include "imgui.h"

static GLFWwindow* window;
static ImVec4 clear_color = ImVec4(0.133, 0.133, 0.149, 1.0f);

int setup_window();
void start_loop();
void stop_loop();


#endif 
