#include "TestGame.h"

#include <Horatio/Game.h>

TestGame::TestGame(const std::string &config_file) : Game(config_file) { }

void TestGame::update()
{
    primary_window.poll_events();
    // do update stuff
}

void TestGame::render()
{
    primary_window.clear_buffer();
    // do render stuff
    primary_window.swap_buffers();
}