#pragma once
#include "xmas_object.h"
#include "XmasTree.h"

class SantaClaus : public xmas_object
{
   public:

      SantaClaus(XmasTree* t);

      void simulate();

   private:

      XmasTree* tree;
};
