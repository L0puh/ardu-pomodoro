#ifndef INPUT_H
#define INPUT_H

#include "core/core.h"


inline void input_key_callback(GLFWwindow *window, int key, int code, int action, int mods){
   switch(key){
      case GLFW_KEY_Q:
         glfwSetWindowShouldClose(window, true); 
         break;
   }
}


#endif
