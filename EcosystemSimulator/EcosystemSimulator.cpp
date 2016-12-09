#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "Simulator.h"


int main()
{
   Simulator s1(50, 20);

   s1.simulate_one_step();

   s1.show_world();
    
   _getch();
}