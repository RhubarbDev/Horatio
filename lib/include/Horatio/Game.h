#pragma once

#include "Window.h"

#include <memory>

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
        std::unique_ptr<Window> primary_window; // a primary window is required
    };
}