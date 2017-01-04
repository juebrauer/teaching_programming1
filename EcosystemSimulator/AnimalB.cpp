#include "AnimalB.h"
#include <stdlib.h>

#pragma once


AnimalB::AnimalB(int world_width,
   int world_height,
   int start_vx,
   int start_vy) :
   Animal(world_width, world_height, start_vx, start_vy)
{
   visu = '\1';
}


void AnimalB::simulate()
{
   int rand_number = rand() % 6 + 1;

   // with a probability of 1/6 choose a new random
   // direction
   if (rand_number == 1)
   {
      vx = rand() % 2 ? -1 : 1;
      vy = rand() % 2 ? -1 : 1;
   }

   x += vx;
   y += vy;
  
   make_sure_that_my_coords_are_valid();
}


char AnimalB::get_visual_appearance()
{
   return '\1';
}