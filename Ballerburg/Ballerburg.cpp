#include "opencv2/opencv.hpp"
#include <conio.h>

using namespace cv;
using namespace std;

#define PLAYFIELD_WIDTH 800
#define PLAYFIELD_HEIGHT 800

void draw_line(Mat frame, Point p1, Point p2)
{
   float epsilon = 0.001f;
   Point dirVec = p2 - p1;
   for (float pos = 0.0; pos <= 1.0; pos += epsilon)
   {
      Point p = p1 + pos * dirVec;
      frame.at<Vec3b>(p) = Vec3b(0, 0, 255);
   }
}

void draw_line(Mat frame, Point middle, int radius)
{
   double pi = 3.14159;
   double epsilon = pi / 256.0;
   for (double alpha = 0.0; alpha <= 2 * pi; alpha += epsilon)
   {
      double dx = cos(alpha);
      double dy = sin(alpha);
      Point p = middle + Point(dx*radius, dy*radius);
      frame.at<Vec3b>(p) = Vec3b(0, 0, 255);
   }
}


int main()
{   
   Mat frame(PLAYFIELD_HEIGHT, PLAYFIELD_WIDTH, CV_8UC3);
  
   draw_line(frame, Point(300, 300), 50);

  imshow("Ballerburg", frame);
  waitKey(0);
  
  
 
}
