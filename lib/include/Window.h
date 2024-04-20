#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

namespace Horatio
{
    class Window
    {
    public:
        Window(const std::string& window_name, int width, int height);
    private:
        GLFWwindow* window;
    };
}
