#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "Simulator.h"


int main()
{
   system("chcp 437");

   Simulator s1(50, 20, 5, 3);

   do
   {
      s1.simulate_one_step();
      s1.show_world();
      _getch();
   } while (1);
}