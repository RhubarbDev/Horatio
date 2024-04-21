#include "Horatio/Window.h"

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
    static void window_close_callback(GLFWwindow* window)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(window))->should_close = true;
    }

    static void window_size_callback(GLFWwindow* window, int width, int height)
    {
        static_cast<Window*>(glfwGetWindowUserPointer(window))->projection.update_projection(0, width, 0, height);
    }

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if(action == GLFW_PRESS)
        {
            std::cout << "key pressed: " << static_cast<char>(key) << std::endl;
        }
    }

    Window::Window() : projection(0, 0, 0, 0)
    {
        window = nullptr;
    }

    Window::Window(const std::string &window_name, int width, int height, bool fullscreen, const std::vector<Hint> &window_hints) : projection(0, width, 0, height)
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

        glfwSetWindowUserPointer(window, this);

        glfwMakeContextCurrent(window);
        const auto error = glewInit();
        if(error != GLEW_OK)
        {
            throw std::runtime_error("Couldn't initialse GLEW: " + std::string(reinterpret_cast<char const*>(glewGetErrorString(error))));
        }

        glfwSetWindowCloseCallback(window, window_close_callback);
        glfwSetKeyCallback(window, key_callback);
    }

    Window::~Window()
    {
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