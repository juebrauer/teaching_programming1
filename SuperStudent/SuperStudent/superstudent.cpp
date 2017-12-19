#include <conio.h>
#include <stdio.h>

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

#define NrWalkCycleImages 10

enum WalkingDirections {left, right};

struct coord2D
{
    int x;
    int y;
};

#define WORLD_WIDTH  800
#define WORLD_HEIGHT 800
#define FLOOR_HEIGHT WORLD_HEIGHT-200

// What is the effect of hitting an enemy?
enum damagetype {killing, energyreduction};


void overlayImage(const cv::Mat &background, const cv::Mat &foreground,
    cv::Mat &output, cv::Point2i location)
{
    background.copyTo(output);


    // start at the row indicated by location, or at row 0 if location.y is negative.
    for (int y = std::max(location.y, 0); y < background.rows; ++y)
    {
        int fY = y - location.y; // because of the translation

                                 // we are done of we have processed all rows of the foreground image.
        if (fY >= foreground.rows)
            break;

        // start at the column indicated by location, 

        // or at column 0 if location.x is negative.
        for (int x = std::max(location.x, 0); x < background.cols; ++x)
        {
            int fX = x - location.x; // because of the translation.

                                     // we are done with this row if the column is outside of the foreground image.
            if (fX >= foreground.cols)
                break;

            // determine the opacity of the foregrond pixel, using its fourth (alpha) channel.
            double opacity =
                ((double)foreground.data[fY * foreground.step + fX * foreground.channels() + 3])

                / 255.;


            // and now combine the background and foreground pixel, using the opacity, 

            // but only if opacity > 0.
            for (int c = 0; opacity > 0 && c < output.channels(); ++c)
            {
                unsigned char foregroundPx =
                    foreground.data[fY * foreground.step + fX * foreground.channels() + c];
                unsigned char backgroundPx =
                    background.data[y * background.step + x * background.channels() + c];
                output.data[y*output.step + output.channels()*x + c] =
                    backgroundPx * (1. - opacity) + foregroundPx * opacity;
            }
        }
    }
}


class Subject
{

    public:
    
    Subject(string prefix)
    {
        float rfac = 0.25f;
        for (int i = 1; i <= NrWalkCycleImages; i++)
        {
            char fname[500];
            sprintf_s(fname, sizeof(fname), "pics/%s (%d).png",
                      prefix.c_str(),
                      i);

            img[i - 1] = imread(fname, IMREAD_UNCHANGED);
            printf("Nr of channels for image #%d is %d\n",
                i, img[i - 1].channels());

            resize(img[i - 1], img[i - 1],
                Size((int)(img[i - 1].cols*rfac),
                (int)(img[i - 1].rows*rfac)));
        }
    }

    protected:

    struct coord2D              position;
    Mat                         img[NrWalkCycleImages];

};


class Enemy : public Subject
{
    private:
    
        enum damagetype damageeffect;

    public:

        // class constructor
        Enemy() : Subject("robot/Run")
        {            
            printf("New enemy was generated.\n");
            position.x = 0;
            position.y = 0;
            damageeffect = killing;
        }

        // class destructor
        ~Enemy()
        {
            printf("The object was deleted.\n");
        }

        void set_new_position(struct coord2D new_coord)
        {
            if ((new_coord.x < 0) || (new_coord.y < 0))
            {
                printf("Wrong 2D coordinate! I will not change the coordinates!\n");
            }
            else
                position = new_coord;
        }

        struct coord2D get_new_position()
        {
            return position;
        }

};


class student : public Subject
{
public:

    student() : Subject("santaclaus/Walk")
    {  
        position.x = 50;
        position.y = FLOOR_HEIGHT;

        WalkCycleImgNr = 0;
        WalkDir = WalkingDirections::right;
    }

    void update()
    {
        int c = waitKeyEx(0);
        switch (c)
        {
            case 2424832: // cursor left
                position.x += -5;              
                WalkDir = WalkingDirections::left;
                break;
            case 2555904: // cursor right
                position.x += +5;       
                WalkDir = WalkingDirections::right;
                break;
        }

        WalkCycleImgNr++;

        /*
        if (WalkCycleImgNr == -1)
            WalkCycleImgNr = NrWalkCycleImages - 1;
        */

        if (WalkCycleImgNr == NrWalkCycleImages)
            WalkCycleImgNr = 0;
    }

    void draw_into_image(Mat world)
    {
        //Mat dst_roi = world(Rect(position.x, position.y, img[0].cols, img[0].rows));
        //img[0].copyTo(dst_roi);

        Mat sprite;
        if (WalkDir == WalkingDirections::right)
            sprite = img[WalkCycleImgNr];
        else if (WalkDir == WalkingDirections::left)
        {
            cv::flip(img[WalkCycleImgNr], sprite, 1);
        }


        overlayImage(world, sprite, world, Point2i(position.x, position.y));
    }

private:
    
    int                         WalkCycleImgNr;
    enum WalkingDirections      WalkDir;

};



int main()
{
   
    Mat world(WORLD_WIDTH, WORLD_HEIGHT, CV_8UC3);
    student* s1 = new student();

    while (1)
    {
        // set complete world image to "white"
        world = Scalar(255, 255, 255);

        s1->update();

        s1->draw_into_image(world);

        imshow("world", world);

        waitKey(1);
    }

    printf("End of program\n");
    _getch();
}