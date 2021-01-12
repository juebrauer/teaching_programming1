#include <opencv2/highgui.hpp>
#include <iostream>
#include "robot_fast.h"
#include "robot_slow.h"
#include "params.h"

#include <time.h>

#include <vector>

using namespace cv;
using namespace std;




int main( int argc, char** argv )
{    
    // initialize the pseudo-random number generator
    // with something that seems to be "random" for us
    srand( time(NULL) );

    Mat image(WORLD_HEIGHT, WORLD_WIDTH, CV_8UC3);

    
    int simulation_step = 0;

    cout << "\nHow many fast robots do you want? ";
    int nr_fast_robots;
    scanf("%d", &nr_fast_robots);

    cout << "\nHow many slow robots do you want? ";
    int nr_slow_robots;
    scanf("%d", &nr_slow_robots);



    vector<robot*> all_robots;

    // create fast robots
    for (int i=0; i<nr_fast_robots; i++)
    {
        robot_fast* r1 = new robot_fast();
        all_robots.push_back( r1 );
    }

    // create slow robots
    for (int i=0; i<nr_slow_robots; i++)
    {
        robot_slow* r2 = new robot_slow();
        all_robots.push_back( r2 );
    }

    // create some "normal" robots
    /*
    for (int i=0; i<3; i++)
    {
        robot* r3 = new robot();
        all_robots.push_back( r3 );
    }
    */



    // simulation loop:
    while (true)
    {
        // clear image with world color
        image = WORLD_COLOR; 

        // let all robots move a little bit in the world
        // and let each robot draw itself into the world image
        for (unsigned int i=0; i<all_robots.size(); i++)
        {
            robot* ptr_to_robot = all_robots[i];
            ptr_to_robot->move();
            ptr_to_robot->draw( image );
        }

        imshow( "Display window", image );
        waitKey(10);

        simulation_step++;

        //cout << "simulation_step:" << simulation_step << "\n";
    }    
    
}