#include <conio.h>
#include <stdio.h>
#include "Subject.h"
#include "enemy.h"
#include "claus.h"

#include "opencv2/opencv.hpp"
#include "data_containers.h"

using namespace cv;
using namespace std;


#define NR_ENEMIES_AT_START 2

int main()
{
   
    Mat world(WORLD_WIDTH, WORLD_HEIGHT, CV_8UC3);

    myvector<Subject*> all_subjects;

    claus* s1 = new claus();
    all_subjects.push_back(s1);

    for (int i = 0; i < NR_ENEMIES_AT_START; i++)
    {
        enemy* e;
        e = new enemy();
        printf("Enemy %d is stored at memory location: %p\n",
            i, e);
        all_subjects.push_back(e);
    }
    
    while (1)
    {
        // set complete world image to "white"
        world = Scalar(255, 255, 255);


        //vector<Subject*>::iterator it;        
        for (int i = 0; i<all_subjects.size(); i++)
        {
            Subject* obj = all_subjects[i];
            obj->update();
            obj->draw_into_image(world);
        }
        imshow("world", world);

        waitKey(1);
    }

    printf("End of program\n");
    _getch();
}