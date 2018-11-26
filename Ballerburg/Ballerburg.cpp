#include "opencv2/opencv.hpp"
#include <conio.h>

using namespace cv;
using namespace std;


int main()
{   
   Mat frame(800,800, CV_8UC3);
  

  
   Point p1(10, 10);
   Point p2(750, 150);

   frame.at<Vec3b>(p1) = Vec3b(0, 255, 0);
   frame.at<Vec3b>(p2) = Vec3b(255, 0, 0);

   int dist_x = p2.x - p1.x;
   int dist_y = p2.y - p1.y;
   int rel_xy = (int)(dist_y / dist_x);

   for (int i = 0; i <= p2.x - p1.x; i++)
   {
      Point p(p1.x + i, p1.y+rel_xy*i);
      frame.at<Vec3b>(p) = Vec3b(0, 0, 255);
   }

   //cv::rectangle(frame, Point(50,50), Point(100,100), cv::Scalar(0, 255, 0), -1);
   int width = frame.cols;
   int height = frame.rows;
   imshow("Ballerburg", frame);
   waitKey(0);
 
}
