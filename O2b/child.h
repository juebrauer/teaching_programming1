#pragma once
#include "xmas_object.h"
#include "XmasTree.h"


class child :
   public xmas_object
{
public:
   child(XmasTree* t, char* name);
   ~child();

   void simulate();

private:
   char my_name[100];
   XmasTree* tree;
   std::vector<Present*> my_presents;
};

