#include "robot_slow.h"
#include "params.h"


robot_slow::robot_slow()
{
    cout << "new robot_slow created\n";

    color = Scalar(255,0,0);
}


void robot_slow::move()
{

    //cout << "robot_slow::move() called.\n";

    compute_new_orientation();

    // update coordinates of robot
    x += 0.5*cos(theta);
    y += 0.5*sin(theta);

    coordinates_check();       
}
