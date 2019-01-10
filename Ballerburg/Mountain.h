#pragma once

#include "opencv2/opencv.hpp"
using namespace cv;

class Mountain
{
public:

   Mountain(int floorheight, int middle, int width, int height,
            int interpoints, int rnd_range);
 
   void draw(Mat* frame);

private:

   int floorheight;
   int middle;
   int width;
   int height;
   int interpoints;
   int rnd_range;
};

class SimpleMountain : public Mountain
{
public:
   SimpleMountain(int floorheight, int middle, int width, int height) :
      Mountain(floorheight, middle, width, height, 5, 40)
   {

   }
};

class ComplexMountain : public Mountain
{
public:
   ComplexMountain(int floorheight, int middle, int width, int height) :
      Mountain(floorheight, middle, width, height, 30, 80)
   {

   }
};