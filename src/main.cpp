#include <iostream>

#include "TestGame.h"

int main()
{
    TestGame test_game("res/config.json");
    
    while(!test_game.finished())
    {
        test_game.update();
        test_game.render();
    }
}