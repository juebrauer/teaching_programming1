#include <opencv2/highgui.hpp>
#include <iostream>
#include "robot.h"
#include "params.h"

using namespace cv;
using namespace std;





int main( int argc, char** argv )
{    
    Mat image(WORLD_HEIGHT, WORLD_WIDTH, CV_8UC3);

    
    int simulation_step = 0;

    robot r1(WORLD_HEIGHT, WORLD_WIDTH);

    while (true)
    {
        // clear image with world color
        image = WORLD_COLOR; 

        r1.move();
        r1.draw( image );

        imshow( "Display window", image );
        waitKey(1);

        simulation_step++;

        //cout << "simulation_step:" << simulation_step << "\n";
    }    
    
}