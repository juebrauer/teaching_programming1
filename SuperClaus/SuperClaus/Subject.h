#pragma once

#include "opencv2/opencv.hpp"
#include <string>

using namespace cv;
using namespace std;

#define WORLD_WIDTH  800
#define WORLD_HEIGHT 800
#define FLOOR_HEIGHT WORLD_HEIGHT-200

struct coord2D
{
    int x;
    int y;
};

enum WalkingDirections { left, right };

// What is the effect of hitting an enemy?
enum damagetype { killing, energyreduction };

//#define MAX_NR_IMAGES 100

class Subject
{

public:

    Subject(int nr_images, string prefix);

    Subject();
   
    void draw_into_image(Mat world);

    virtual void update();

protected:

    static const int            MAX_NR_IMAGES = 100;

    struct coord2D              position;
    Mat                         img[MAX_NR_IMAGES];
    int                         WalkCycleImgNr;
    enum WalkingDirections      WalkDir;
    int                         NrWalkCycleImages;
    int                         WalkSpeed;

}; // class Subject
