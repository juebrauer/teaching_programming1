#include <conio.h>
#include <stdio.h>

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

#define MAX_NR_IMAGES 100

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
} // overlayImage


class Subject
{

    public:
    
    Subject(int nr_images, string prefix)
    {
        NrWalkCycleImages = nr_images;

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


    void draw_into_image(Mat world)
    {
        Mat sprite;
        if (WalkDir == WalkingDirections::right)
            sprite = img[WalkCycleImgNr];
        else if (WalkDir == WalkingDirections::left)
        {
            cv::flip(img[WalkCycleImgNr], sprite, 1);
        }
        overlayImage(world, sprite, world, Point2i(position.x, position.y));
    }

    void update()
    {
        WalkCycleImgNr++;
        if (WalkCycleImgNr == NrWalkCycleImages)
            WalkCycleImgNr = 0;
    }

    protected:

    struct coord2D              position;
    Mat                         img[MAX_NR_IMAGES];
    int                         WalkCycleImgNr;
    enum WalkingDirections      WalkDir;
    int                         NrWalkCycleImages;
    int                         WalkSpeed;

}; // class Subject


class enemy : public Subject
{
    private:
    
        enum damagetype damageeffect;


    public:

        // class constructor
        enemy() : Subject(8, "robot/Run")
        {            
            printf("New enemy was generated.\n");
            position.x = WORLD_WIDTH/2 + rand() % (WORLD_WIDTH/2);
            position.y = FLOOR_HEIGHT;
            damageeffect = killing;
            WalkSpeed = 1 + rand() % 10;

            WalkCycleImgNr = 0;
            WalkDir = WalkingDirections::left;
        }

        // class destructor
        ~enemy()
        {
            printf("The object was deleted.\n");
        }

        void update()
        {
            if (WalkDir == WalkingDirections::left)
                position.x -= WalkSpeed;
            else
            if (WalkDir == WalkingDirections::right)
                position.x += WalkSpeed;

            if (position.x <= 0)
                WalkDir = WalkingDirections::right;

            if (position.x >= WORLD_WIDTH)
                WalkDir = WalkingDirections::left;   

            Subject::update();
        }

}; // class enemy


class student : public Subject
{
public:

    student() : Subject(13, "santaclaus/Walk")
    {  
        position.x = 50;
        position.y = FLOOR_HEIGHT;
        WalkSpeed = 5;

        WalkCycleImgNr = 0;
        WalkDir = WalkingDirections::right;
    }

    void update()
    {
        int c = waitKeyEx(1);
        bool walked = false;
        switch (c)
        {
            case 2424832: // cursor left
                position.x += -WalkSpeed;              
                WalkDir = WalkingDirections::left;
                walked = true;
                break;
            case 2555904: // cursor right
                position.x += +WalkSpeed;
                WalkDir = WalkingDirections::right;
                walked = true;
                break;
        }

        if (walked)
            Subject::update();
    }

    

private:


}; // class student



int main()
{
   
    Mat world(WORLD_WIDTH, WORLD_HEIGHT, CV_8UC3);



    student* s1 = new student();
    enemy* e1 = new enemy();
    enemy* e2 = new enemy();

    while (1)
    {
        // set complete world image to "white"
        world = Scalar(255, 255, 255);

        s1->update();
        e1->update();
        e2->update();

        s1->draw_into_image(world);
        e1->draw_into_image(world);
        e2->draw_into_image(world);

        imshow("world", world);

        waitKey(1);
    }

    printf("End of program\n");
    _getch();
}