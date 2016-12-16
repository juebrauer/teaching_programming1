#pragma once

#include "Simulator.h"
#include "helpers.h"
#include <stdio.h>

Simulator::Simulator(int w, int h, int nr_animalsA, int nr_animalsB)
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

   // generate animals of type A
   for (int i = 0; i < nr_animalsA; i++)
   {
      int vx = 0;
      int vy = 0;
      int sx = rand() % w;
      int sy = rand() % h;
      AnimalA* new_animal = new AnimalA(width, height, vx, vy);
      new_animal->set_to_pos(sx,sy);

      // store pointer to new generated object
      all_animals.push_back( new_animal );
   
   }


   // generate animals of type B
   for (int i = 0; i < nr_animalsB; i++)
   {
      int vx = 0;
      int vy = 0;
      int sx = rand() % w;
      int sy = rand() % h;
      AnimalB* new_animal = new AnimalB(width, height, vx, vy);
      new_animal->set_to_pos(sx, sy);

      // store pointer to new generated object
      all_animals.push_back(new_animal);
   }
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
   for (int i = 0; i < all_animals.size(); i++)
   {
      // get pointer to i-th animal
      Animal* ptr = all_animals[i];

      // let the animal simulate one step
      ptr->simulate();
   }
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

   // draw all animals
   for (int i = 0; i < all_animals.size(); i++)
   {
      // get pointer to i-th animal
      Animal* ptr = all_animals[i];
      
      set_cursor_position(ptr->getposx(), ptr->getposy());
      printf("%c", ptr->get_visual_appearance() );     
   }


}

void Simulator::init()
{
   for (int y = 0; y<height; y++)
        for (int x = 0; x<width; x++)
         world[y][x] = '.';
}


