#include "Horatio/Game.h"

#include <filesystem>
#include <stdexcept>

namespace Horatio
{

    Game::Game(const std::string &config_file)
    {
        if(!std::filesystem::exists(config_file))
        {
            throw std::invalid_argument("Config file doesn't exists.");    
        }

        if(std::filesystem::path(config_file).extension() != ".json")
        {
            throw std::invalid_argument("Config file not JSON.");
        }

        primary_window = Window("test", 500, 500);
    }
}