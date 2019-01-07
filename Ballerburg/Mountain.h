#pragma once

#include "opencv2/opencv.hpp"
using namespace cv;

class Mountain
{
public:

   Mountain(int floorheight, int middle, int width, int height);
 
   void draw(Mat& frame);

private:

   int floorheight;
   int middle;
   int width;
   int height;
};