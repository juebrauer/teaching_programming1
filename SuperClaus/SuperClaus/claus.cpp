#include "claus.h"


claus::claus() : Subject(13, "santaclaus/Walk")
{
    position.x = 50;
    position.y = FLOOR_HEIGHT;
    WalkSpeed = 5;

    WalkCycleImgNr = 0;
    WalkDir = WalkingDirections::right;
}

void claus::update()
{
    int c = waitKeyEx(1);
    bool walked = false;
    switch (c)
    {
    case 2424832: // cursor left
        position.x += -WalkSpeed;
        WalkDir = WalkingDirections::left;
        walked = true;
        break;
    case 2555904: // cursor right
        position.x += +WalkSpeed;
        WalkDir = WalkingDirections::right;
        walked = true;
        break;
    }

    if (walked)
        Subject::update();
}