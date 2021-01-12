#pragma once

#include <iostream>
#include <opencv2/highgui.hpp>

#include <vector>

using namespace std;
using namespace cv;

class robot
{

    // access specifier
    public:
                            robot();


                            

            // pure virtual function = rein virtuelle Funktioin

            virtual void    move() = 0;
    
                    void    draw(Mat img);

    protected:

        double          x;
        double          y;
        double          theta;

        vector<Point>   trajectory;
        
        // a color triplet (Blue, Green, Red)
        Scalar          color;  


        void            compute_new_orientation();

        void            coordinates_check();
    
};