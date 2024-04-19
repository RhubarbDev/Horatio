#include "Window.h"

#include <filesystem>
#include <stdexcept>

Window::Window(const std::string &config_path)
{
    if(!std::filesystem::exists(config_path))
    {
        throw std::invalid_argument("Invalid config_path provided.");
    }
}