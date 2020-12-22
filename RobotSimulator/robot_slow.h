#pragma once

#include "robot.h"

class robot_slow : public robot
{
    public:

                    robot_slow();

            void    move()  override;

};