#include "robot.h"
#include "params.h"

#include <opencv2/imgproc.hpp>

robot::robot()
{
    cout << "new robot created\n";

    x = WORLD_WIDTH/2;
    y = WORLD_HEIGHT/2;
    theta = 0.0;    

    color = Scalar(0,0,0);
}


void robot::draw(Mat img)
{
    circle(img, Point(x,y), ROBOT_RADIUS, color);

    line(img,
         Point(x,y),
         Point(x+cos(theta)*ROBOT_RADIUS,y+sin(theta)*ROBOT_RADIUS),
         color,
         1);
}


void robot::move()
{
    cout << "robot::move() called.\n";

    compute_new_orientation();

    // update coordinates of robot
    x += cos(theta);
    y += sin(theta);

    coordinates_check();    
}


void robot::compute_new_orientation()
{
    // from time to time change orientation
    // of our robot randomly
    if (rand() % 50 == 0)
    {
        // compute random orientation offset
        double delta_theta = (-3 + rand() % 7) / (2*M_PI);
        //cout << "double_theta = " << delta_theta << "\n";

        // update orientation of robot
        theta += delta_theta;
    }    
}



void robot::coordinates_check()
{
    // make sure, the robot does not leave the world
    if (x >= WORLD_WIDTH)
        x = 0;

    if (y >= WORLD_HEIGHT)
        y = 0;

    if (x < 0)
        x = WORLD_WIDTH-1;

    if ( y< 0)
        y = WORLD_HEIGHT-1;
}