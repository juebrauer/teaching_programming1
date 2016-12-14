#include <conio.h>
#include <stdio.h>

#include "NumberBox.h"



int main()
{
   NumberBox myBox(10);
  
   myBox.add_a_number(1.0);
   myBox.add_a_number(4.0);
   myBox.add_a_number(7.0);
   myBox.add_a_number(-32.0);
   myBox.add_a_number(110.0);
   myBox.show_numbers();

   double minval, maxval;
   myBox.get_min_and_max(&minval, &maxval);
   printf("Minimum value of all numbers in box is: %.1f\n", minval);
   printf("Maximum value of all numbers in box is: %.1f\n", maxval);

   myBox.delete_specific_number(49.0);
   myBox.delete_specific_number(7.0);
   myBox.show_numbers();

   _getch();
}