#include "robot_fast.h"
#include "params.h"


robot_fast::robot_fast()
{
    cout << "new robot_fast created\n";

    
    color = Scalar(0,0,255);
}


void robot_fast::move()
{
    //cout << "robot_fast::move() called.\n";

    compute_new_orientation();

    // update coordinates of robot
    x += 3*cos(theta);
    y += 3*sin(theta);

    coordinates_check();       
}