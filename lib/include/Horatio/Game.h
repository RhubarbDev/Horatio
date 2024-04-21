#pragma once

#include "Window.h"

namespace Horatio
{
    class Game
    {
    public:
        Game(const std::string& config_file);
        virtual void update() = 0;
        virtual void render() = 0;
    private:
        Window primary_window; // a primary window is required
    };
}