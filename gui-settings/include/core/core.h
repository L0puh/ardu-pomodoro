#ifndef CORE_H
#define CORE_H

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h> 
#include <cstdio>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

void draw_program();

#endif
