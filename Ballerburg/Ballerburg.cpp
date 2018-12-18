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

void draw_circle(Mat frame, Point middle, int radius)
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

class Ellipse
{
protected:
   Point position;
   Size size;
   Scalar color;

public:



   Ellipse(Point _position, Size _size, Scalar _color)
   {
      position = _position;
      size = _size;
      color = _color;
   }

   virtual void draw(Mat& frame)
   {
      ellipse(frame, position, size, 0.0, 0.0, 360.0, color, 1);
   }

   void set_new_position(Point _position)
   {
      if ((_position.x < 0) || (_position.y < 0))
      {
         printf("Error! Invalid position specified!\n");
      }
      else
      {
         position = _position;
      }
   }
};


class Circle : public Ellipse
{
public:
   Circle(Point _position, int _radius, Scalar _color) :
      Ellipse(_position, Size(_radius, _radius), _color)
   {

   }

   void draw(Mat& frame)
   {
      ellipse(frame, position, size, 0.0, 0.0, 360.0, color, 5);
   }
  
};


int main()
{   
   Mat frame(PLAYFIELD_HEIGHT, PLAYFIELD_WIDTH, CV_8UC3);
  
   //draw_circle(frame, Point(300, 300), 50);
   //ellipse(frame, Point(300, 300), Size(200, 100), 0.0, 0.0, 360.0, Scalar(0, 0, 255));

   Ellipse e( Point(300,300), Size(200,100), Scalar(0,0,255) );
   e.draw(frame);
   e.set_new_position( Point(-500, 500) );
   e.draw(frame);

   Circle c( Point(500,500), 50, Scalar(255,0,0) );

   c.draw(frame);

   Ellipse* c2 = new Circle(Point(600, 600), 20, Scalar(255, 255, 255));
   c2->draw(frame);


   imshow("Ballerburg", frame);
   waitKey(0);
  
  
 
}
