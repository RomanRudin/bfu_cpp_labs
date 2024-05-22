#include <SFML/Graphics.hpp>
#include "Circle.hpp"
#include "Game.hpp"

int main()
{
    mt::Game game(1125, 800, "Game");

    if (!game.Setup(5))
        return -1;

    game.LifeCycle();

    return 0;
}