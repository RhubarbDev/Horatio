#pragma once

#include "Window.h"

namespace Horatio
{
    class Game
    {
    public:
        Game(const std::string& config_file);
        bool finished() const;
        virtual void update() = 0;
        virtual void render() = 0;
    protected:
        Window* primary_window; // a primary window is required
    };
}