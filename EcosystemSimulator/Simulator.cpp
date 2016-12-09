#pragma once

#include "Simulator.h"
#include "helpers.h"
#include <stdio.h>

Simulator::Simulator(int w, int h)
{
   hidecursor();

   printf("Constructor of Simulator called.\n");
   width = w;
   height = h;

   // create a 2D array for storing the simulated world
   world = new char*[h];
   for (int y = 0; y<h; y++)
      world[y] = new char[w];

   init();

}



Simulator::~Simulator()
{
   printf("Destructor called\n\n");

   // release memory
   for (int y = 0; y<height; y++)
      delete world[y];
   delete world;

}


void Simulator::simulate_one_step()
{

}

void Simulator::show_world()
{
   set_cursor_position(0, 0);
   for (int y = 0; y<height; y++)
   {
      for (int x = 0; x<width; x++)
         printf("%c", world[y][x]);
      printf("\n");
   }
}

void Simulator::init()
{
   for (int y = 0; y<height; y++)
        for (int x = 0; x<width; x++)
         world[y][x] = '.';
}


