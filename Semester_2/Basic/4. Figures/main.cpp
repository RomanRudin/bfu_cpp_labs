#include <SFML/Graphics.hpp>
#include <Shapes.hpp>
#include <Game.hpp>
#include <iostream>

int main()
{
    int a; //insert a, a<10
    std::cin >> a;

    int x;
    std::cin >> x;
    if (x == 1)
    {
        mt::Game1 dota2(1240, 720, "dota2_beta");

        dota2.Setup(a);
        dota2.LifeCycle();
    }

    else if (x == 3)
    {
        mt::Game2 minecraft(1240, 720, "minecraft 1.7.10 forge optifine");

        minecraft.Setup(a);
        minecraft.LifeCycle();
    }

    else if (x == 2)
    {
        mt::Game3 hm2_wrng_num(1240, 720, "death Wish");

        hm2_wrng_num.Setup(a);
        hm2_wrng_num.LifeCycle();
    }

    else if (x == 4)
    {
        mt::Game4 brawl_stars(1240, 720, "showdown");

        brawl_stars.Setup(a);
        brawl_stars.LifeCycle();
    }


    return 0;
}