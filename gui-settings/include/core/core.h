#ifndef CORE_H
#define CORE_H

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <implot.h>

#include <GLFW/glfw3.h> 
#include <cstdio>

#include <nlohmann/json.hpp>

#define SIZEOF(array) (sizeof(array) / sizeof((array)[0]))

using json = nlohmann::json;

void draw_program();

#endif
