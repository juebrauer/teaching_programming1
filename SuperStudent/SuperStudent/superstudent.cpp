#include <conio.h>
#include <stdio.h>

#include "opencv2/opencv.hpp"

using namespace cv;

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


class Enemy
{
    private:
    
        struct coord2D position;

        enum damagetype damageeffect;

    public:

        // class constructor
        Enemy()
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


class student
{
public:

    student()
    {
        img = imread("pics/student.png");
        float rfac = 0.25f;
        resize(img, img, Size((int)(img.cols*rfac), (int)(img.rows*rfac)));
        position.x = 50;
        position.y = FLOOR_HEIGHT;
    }

    void update()
    {
        int c = waitKeyEx(0);
        switch (c)
        {
            case 2424832: // cursor left
                position.x += -5;
                break;
            case 2555904: // cursor right
                position.x += +5;
                break;
        }
    }

    void draw_into_image(Mat world)
    {
        Mat dst_roi = world(Rect(position.x, position.y, img.cols, img.rows));
        img.copyTo(dst_roi);
    }

private:

    struct coord2D position;
    Mat            img;

};



int main()
{
   
    Mat world(WORLD_WIDTH, WORLD_HEIGHT, CV_8UC3);
    student s1;

    while (1)
    {
        // set complete world image to "white"
        world = Scalar(255, 255, 255);

        s1.update();

        s1.draw_into_image(world);

        imshow("world", world);

        waitKey(1);
    }

    printf("End of program\n");
    _getch();
}