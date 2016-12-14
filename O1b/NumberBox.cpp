#include <stdio.h>

#include "NumberBox.h"


NumberBox::NumberBox(int max_size)
{
   printf("Constructor NumberBox() called.\n");
   A = new double[max_size];

   maximum_size = max_size;
   current_size = 0;
}

NumberBox::~NumberBox()
{
   printf("Destructor ~NumberBox() called.\n");
   delete A;
}

void NumberBox::add_a_number(double n)
{
   if (current_size == maximum_size)
   {
      printf("Sorry! Your numberbox is already full!\n");
      printf("You can only store up to %d numbers.", maximum_size);
      return;
   }

   A[current_size] = n;
   current_size++;
   printf("Added number %.2f to number box.\n", n);
   printf("Space left: %d\n", maximum_size - current_size);
}

void NumberBox::show_numbers()
{
   printf("\nHere are all the numbers I have stored:\n");
   for (int i=0; i<current_size; i++)
      printf("A[%d]=%.2f\n", i, A[i]);
   printf("\n");
}


void NumberBox::get_min_and_max(double * minval, double * maxval)
{
   for (int i = 0; i < current_size; i++)
   {
      if (i == 0)
      {
         *minval = A[i];
         *maxval = A[i];
      }
      if ((i>0) && (A[i]<*minval))
         *minval = A[i];
      if ((i>0) && (A[i]>*maxval))
         *maxval = A[i];
   }
}


void NumberBox::delete_specific_number(double n)
{
   for (int i = 0; i < current_size; i++)
   {
      if (A[i] == n)
      {
         printf("Ok! I could find number %.2f\n", n);

         for (int j=i+1; j<current_size; j++)
            A[j-1] = A[j];

         current_size--;

         return;
      }
   }
   
   printf("Sorry! I could not find your number %.2f\n", n);

}
