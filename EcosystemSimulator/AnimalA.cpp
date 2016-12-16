#include "AnimalA.h"
#include <stdlib.h>

#pragma once


AnimalA::AnimalA(int world_width,
                 int world_height,
                 int start_vx,
                 int start_vy) :
      Animal(world_width, world_height, start_vx, start_vy)
{
   visu = '\2';
}


void AnimalA::simulate()
{
   int rand_number = rand() % 6 + 1;

   // with a probability of 1/6 choose a new random
   // direction
   if (rand_number == 1)
   {
      vx = rand() % 2 ? -1 : 1;
      vy = rand() % 2 ? -1 : 1;
   }

   if (rand() % 2 == 0)
      x += vx;
   else
      vx = 0;

   if (rand() % 2 == 0)
      y += vy;
   else
      vy = 0;

   if (x<0) x=0;
   if (y<0) y=0;
   if (x>=wwidth) x=wwidth-1;
   if (y>=wheight) y=wheight-1;
}


char AnimalA::get_visual_appearance()
{
   return '\2';
}
