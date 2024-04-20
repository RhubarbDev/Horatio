#include "Window.h"

#include <GL/glew.h>
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

        current_windows[window] = this;

        glfwSetWindowCloseCallback(window, window_close_callback);
        glfwSetKeyCallback(window, key_callback);

        if(!window)
        {
            glfwTerminate();
            throw std::runtime_error("Couldn't create window");
        }
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