#pragma once

#include "Animal.h"

class AnimalA : public Animal
{
   public:

      AnimalA(int world_width,
              int world_height,
              int start_vx,
              int start_vy);

      void simulate();

      char get_visual_appearance();
      
  
};
