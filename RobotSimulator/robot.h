#pragma once

#include <iostream>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

class robot
{

    // access specifier
    public:
                            robot();

        virtual     void    move();
    
                    void    draw(Mat img);

    protected:

        double          x;
        double          y;
        double          theta;      

        // a color triplet (Blue, Green, Red)
        Scalar          color;  


        void            compute_new_orientation();

        void            coordinates_check();
    
};