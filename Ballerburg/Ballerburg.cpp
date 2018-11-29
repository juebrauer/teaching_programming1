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


int main()
{   
   Mat frame(PLAYFIELD_HEIGHT, PLAYFIELD_WIDTH, CV_8UC3);
  

   for (int i = 1; i < 1000; i++)
   {
      Point p1(rand() % PLAYFIELD_WIDTH, rand() % PLAYFIELD_HEIGHT);
      Point p2(rand() % PLAYFIELD_WIDTH, rand() % PLAYFIELD_HEIGHT);

      draw_line(frame, p1, p2);

      imshow("Ballerburg", frame);
      waitKey(0);
      //_getch();
   }

   //cv::rectangle(frame, Point(50,50), Point(100,100), cv::Scalar(0, 255, 0), -1);
   int width = frame.cols;
   int height = frame.rows;
  
 
}
