#include "robot.h"
#include "params.h"

#include <opencv2/imgproc.hpp>

robot::robot(int world_height, int world_width)
{
    cout << "new robot created\n";

    x = world_width/2;
    y = world_height/2;

    dir_x = 0;
    dir_y = 0;
}


void robot::draw(Mat img)
{
    circle(img, Point(x,y), ROBOT_RADIUS, ROBOT_COLOR);
}


void robot::move()
{
    if (rand() % 51 == 0)
    {
        dir_x = -1 + rand() % 3;
        dir_y = -1 + rand() % 3;
    }

    x += dir_x;
    y += dir_y;
}