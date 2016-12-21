#include "XmasTree.h"
#include <windows.h>



XmasTree::XmasTree()
{
}


XmasTree::~XmasTree()
{
}

void XmasTree::simulate()
{
   printf("I am just a green xmas tree!\n");

   PlaySound(TEXT("sounds/xmastree.wav"), NULL, SND_FILENAME);
}

void XmasTree::add_present(Present * p)
{
   all_presents_stored.push_back( p );
}

Present * XmasTree::get_present()
{
   int N = all_presents_stored.size();
   if (N==0)
      return nullptr;
   
   // choose randomly a present from the list of all presents
   int rnd_present_idx = rand() % N;
   
   // get pointer to the selected present
   Present* ptr_selected_present = all_presents_stored[rnd_present_idx];

   // delete pointer to the selected present
   all_presents_stored.erase(all_presents_stored.begin() + rnd_present_idx);

   return ptr_selected_present;

}
