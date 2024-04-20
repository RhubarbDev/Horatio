#include "Window.h"

#include <GL/glew.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <filesystem>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

namespace Horatio
{
    static std::unordered_map<GLFWwindow*, Window*> current_windows;

    static void window_close_callback(GLFWwindow* window)
    {
        current_windows[window]->should_close = true;
    }

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if(action == GLFW_PRESS)
        {
            std::cout << "key pressed: " << static_cast<char>(key) << std::endl;
        }
    }

    Window::Window(const std::string &window_name, int width, int height, bool fullscreen, const std::vector<Hint>& window_hints)
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

        glfwSwapInterval(1);

        window = glfwCreateWindow(width, height, window_name.c_str(), fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);

        if(!window)
        {
            throw std::runtime_error("Couldn't create window");
        }

        current_windows[window] = this;

        if(glewInit() != GLEW_OK)
        {
            throw std::runtime_error("Couldn't initialse GLEW");
        }

        glfwSetWindowCloseCallback(window, window_close_callback);
        glfwSetKeyCallback(window, key_callback);
    }

    Window::~Window()
    {
        current_windows.erase(window);
        glfwDestroyWindow(window);
    }

    void Window::poll_events()
    {
        glfwPollEvents();
    }

    void Window::swap_buffers()
    {
        glfwSwapBuffers(window);
    }
    void Window::clear_buffer()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
}