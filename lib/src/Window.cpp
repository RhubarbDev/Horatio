#include "Window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <filesystem>
#include <stdexcept>

namespace Horatio
{
    Window::Window(const std::string &window_name, int width, int height)
    {
        if(!glfwInit())
        {
            throw std::runtime_error("Failed to initialise GLFW");
        }

        window = glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr);

        if(!window)
        {
            glfwTerminate();
            throw std::runtime_error("Couldn't create window");
        }
    }
}