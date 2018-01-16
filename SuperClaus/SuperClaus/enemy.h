#pragma once

#include "Subject.h"

class enemy : public Subject
{
private:

    enum damagetype damageeffect;


public:

    // class constructor
    enemy();

    void update();

}; // class enemy
