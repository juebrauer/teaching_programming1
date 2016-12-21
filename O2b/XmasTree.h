#pragma once
#include "xmas_object.h"
#include <vector>
#include "Present.h"

class XmasTree :
   public xmas_object
{
   public:
      XmasTree();
      ~XmasTree();

      void simulate();

      void add_present(Present* p);

      Present* get_present();

   private:
      std::vector<Present*> all_presents_stored;
};

