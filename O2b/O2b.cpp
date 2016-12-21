/// O2b.cpp
///
/// A Xmas party simulator!
///
/// Alternative solution developed live in exercise.
/// Original solution is: O2
///
/// all sounds are from https://www.freesound.org/
///
/// I wish you and your family a merry Xmas!
///
/// ---
/// by Prof. Dr. Jürgen Brauer, www.juergenbrauer.org
///

#include <conio.h>
#include <stdio.h>
#include <vector>

#include "xmas_object.h"
#include "SantaClaus.h"
#include "XmasTree.h"
#include "child.h"




int main()
{
   std::vector<xmas_object*> all_objects;

   XmasTree* t = new XmasTree();
   all_objects.push_back( t );

   Present* p1 = new Present("bike");
   Present* p2 = new Present("notebook");

   t->add_present( p1 );
   t->add_present( p2 );

   // generate a Santa Claus and
   // put it into the list of all xmas objects
   SantaClaus* s = new SantaClaus( t );
   all_objects.push_back( s );

   child* c1 = new child( t, "Julius" );
   child* c2 = new child( t, "Florian" );
   all_objects.push_back( c1 );
   all_objects.push_back( c2 );

   printf("\n\nLet's start the XMas party!\n\n");
   while (1)
   {
      // how many xmas objects are there currently?
      int N = all_objects.size();

      // choose randomly one of the objects
      int i = rand() % N;

      // let the chosen object do something
      xmas_object* ptr_obj = all_objects[i];

      ptr_obj->simulate();

      printf("---\n");
      printf("Press a key to choose and simulate randomly a next Xmas object!\n\n");
      _getch();
   }

   _getch();
}