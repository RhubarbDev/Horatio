#include "Window.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <filesystem>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

namespace Horatio
{
    Window::Window(const std::string &window_name, int width, int height, const std::vector<Hint>& window_hints)
    {
        if(!glfwInit())
        {
            throw std::runtime_error("Failed to initialise GLFW");
        }

        for(const Hint& hint : window_hints)
        {
            try {
                glfwWindowHint(hint.hint, hint.value);
            } catch (...) {
                std::cerr << "Unable to set hint: " << hint.hint << " with value: " << hint.value << std::endl;
            }
        }

        window = glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr);

        if(!window)
        {
            glfwTerminate();
            throw std::runtime_error("Couldn't create window");
        }
    }
}