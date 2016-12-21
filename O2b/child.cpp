#include "child.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>


child::child(XmasTree* t, char* name)
{
 tree = t;
 strcpy_s(my_name, sizeof(my_name), name);
}


child::~child()
{
}

void child::simulate()
{
   printf("Hurra! %s is the next one to choose a present from the tree\n",
           my_name);

   PlaySound(TEXT("sounds/child_hurra.wav"), NULL, SND_FILENAME);

   Present* p = tree->get_present();

   // only if there is a real present, put it in my present list
   if (p != nullptr)
      my_presents.push_back( p );

   printf("Here are all my presents so far:\n");
   for (unsigned int i=0; i<my_presents.size(); i++)
      printf("%s ", my_presents[i]->get_present_name() );
   printf("\n");

}
