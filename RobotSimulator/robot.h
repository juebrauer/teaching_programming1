#include <iostream>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

class robot
{
    // access specifier
    public:
                        robot(int world_height, int world_width);

                void    draw(Mat img);

                void    move();


    private:

        int             x;
        int             y;

        int             dir_x;
        int             dir_y;
    
};