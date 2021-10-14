#include "PhysicsGame.h"

int main()
{
    PhysicsGame* game = new PhysicsGame();

    game->run("Physics Games", 1280, 720, false);

    delete game;

    return 0;
}
