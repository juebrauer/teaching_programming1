#pragma once
#include "xmas_object.h"

class Present :
   public xmas_object
{
   public:
      Present(char* name_of_present);

      ~Present();

      void simulate();

      char* get_present_name();

   private:
      char name[100]; 

};

