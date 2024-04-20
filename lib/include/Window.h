#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <string>

namespace Horatio
{
    struct Hint
    {
        int hint, value;
    };

    class Window
    {
    public:
        Window(const std::string& window_name, int width, int height, const std::vector<Hint>& window_hints = {});
    private:
        GLFWwindow* window;
    };
}