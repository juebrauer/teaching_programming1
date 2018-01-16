#include "Subject.h"
#include "opencv_tools.h"

Subject::Subject(int nr_images, string prefix)
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

Subject::Subject()
{

}


void Subject::draw_into_image(Mat world)
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

void Subject::update()
{
    WalkCycleImgNr++;
    if (WalkCycleImgNr == NrWalkCycleImages)
        WalkCycleImgNr = 0;
}
