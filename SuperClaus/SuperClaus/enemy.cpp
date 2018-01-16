#include "enemy.h"

enemy::enemy() : Subject(8, "robot/Run")
{
    printf("New enemy was generated.\n");
    position.x = WORLD_WIDTH / 2 + rand() % (WORLD_WIDTH / 2);
    position.y = FLOOR_HEIGHT;
    damageeffect = killing;
    WalkSpeed = 1 + rand() % 10;

    WalkCycleImgNr = 0;
    WalkDir = WalkingDirections::left;
}

   
void enemy::update()
{
    if (WalkDir == WalkingDirections::left)
        position.x -= WalkSpeed;
    else
        if (WalkDir == WalkingDirections::right)
            position.x += WalkSpeed;

    if (position.x <= 0)
        WalkDir = WalkingDirections::right;

    if (position.x >= WORLD_WIDTH)
        WalkDir = WalkingDirections::left;

    Subject::update();
}
