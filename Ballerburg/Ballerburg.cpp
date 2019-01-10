#include "opencv2/opencv.hpp"
#include <conio.h>

#include "Mountain.h"

using namespace cv;
using namespace std;

#define PLAYFIELD_WIDTH 800
#define PLAYFIELD_HEIGHT 800
#define FLOORHEIGHT PLAYFIELD_HEIGHT-100


int main()
{   
   Mat frame(PLAYFIELD_HEIGHT, PLAYFIELD_WIDTH, CV_8UC3);
  

   int difficulty = 2;
   Mountain* m = NULL;
   switch (difficulty)
   {
      case 1: m = new SimpleMountain(FLOORHEIGHT,
                                    PLAYFIELD_WIDTH / 2,
                                    (int)((1.0 / 3.0)*PLAYFIELD_WIDTH),
                                    PLAYFIELD_HEIGHT / 2);
              break;

      case 2: m = new ComplexMountain(FLOORHEIGHT,
                                    PLAYFIELD_WIDTH / 2,
                                    (int)((1.0 / 3.0)*PLAYFIELD_WIDTH),
                                    PLAYFIELD_HEIGHT / 2);
              break;   
   }
     
   m->draw( &frame );

   imshow("Ballerburg", frame);
   waitKey(0);
  
  
 
}
