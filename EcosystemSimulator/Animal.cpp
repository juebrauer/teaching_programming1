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
   return '§';
}

void Animal::make_sure_that_my_coords_are_valid()
{
   if (x<0) x = 0;
   if (y<0) y = 0;
   if (x >= wwidth) x = wwidth - 1;
   if (y >= wheight) y = wheight - 1;
}


void Animal::simulate()
{
   x = x + 1;
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