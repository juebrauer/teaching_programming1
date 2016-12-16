#pragma once
#include <vector>
#include "AnimalA.h"
#include "AnimalB.h"

class Simulator
{
public:
            Simulator(int w, int h, int nr_animalsA, int nr_animalsB);
            ~Simulator();
   
   void     simulate_one_step();
   
   void     show_world();


private:
   int                    width;
   int                    height;
   char**                 world;
   std::vector<Animal*>  all_animals;


   void         init();
};