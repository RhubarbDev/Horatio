#pragma once

#include "Projection.h"

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
        Window() = default;
        Window(const std::string& window_name, int width, int height, bool fullscreen = false, const std::vector<Hint>& window_hints = {});
        ~Window();
        Projection projection;
        bool should_close = false;
        void poll_events();
        void swap_buffers();
        void clear_buffer();
    private:
        GLFWwindow* window;
    };
}