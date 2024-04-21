#pragma once

#include <Horatio/Game.h>


class TestGame : public Horatio::Game
{
public:
    TestGame(const std::string& config_file);
    void update() override;
    void render() override;
};