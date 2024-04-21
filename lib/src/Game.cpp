#include "Horatio/Game.h"

#include "Horatio/Window.h"

#include <nlohmann/json.hpp>

#include <filesystem>
#include <stdexcept>
#include <fstream>

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

        std::ifstream file(config_file);
        nlohmann::json data = nlohmann::json::parse(file);

        // add validation        
        std::string name = data["window"]["window_name"];
        int width = data["window"]["width"];
        int height = data["window"]["height"];

        primary_window = new Window(name, width, height);
    }
}

bool Horatio::Game::finished() const
{
    // put other conditions for game to end here
    return primary_window->should_close;
}
