#pragma once

#include "Animal.h"
#include <stdlib.h>



Animal::Animal(int world_width,
   int world_height,
   int start_vx,
   int start_vy)
{
   wwidth = world_width;
   wheight = world_height;

   vx = start_vx;
   vy = start_vy;

   visu = '?';
}


char Animal::get_visual_appearance()
{
   return '?';
}


void Animal::simulate()
{

}

void Animal::set_to_pos(int newx, int newy)
{
   x = newx;
   y = newy;
}

int Animal::getposx()
{
   return x;
}

int Animal::getposy()
{
   return y;
}