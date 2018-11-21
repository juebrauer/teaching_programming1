#include "opencv2/opencv.hpp"
#include <conio.h>

using namespace cv;
using namespace std;


int main()
{   
   Mat frame(800,800, CV_8UC3);
   cv::rectangle(frame, Point(50,50), Point(100,100), cv::Scalar(0, 255, 0), -1);
   int width = frame.cols;
   int height = frame.rows;
   imshow("video frame", frame);
   waitKey(0);
 
}
