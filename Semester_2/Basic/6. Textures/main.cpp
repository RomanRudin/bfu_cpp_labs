#include <SFML/Graphics.hpp>
#include <Shapes.hpp>
#include <Game.hpp>
#include <iostream>

int main()
{
    int a = 7; //insert a, a<10
 

    int x;
    /*std::cin >> x;*/
    x = 1;
    if (x == 1)
    {
        mt::Game1 dota2(1240, 720, "dota2_beta");

        dota2.Setup(a);
        dota2.LifeCycle();
    }

    return 0;
}