#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

class NumberBox
{
   public:

      NumberBox(int MAX_NR)
      {
         boxsize = MAX_NR;
         numbers = new double[boxsize];
         printf("Constructor of class NumberBox was called.\n");
         printf("I created a number box which can store up to %d numbers.\n\n", boxsize);
         counter = 0;
      }


      ~NumberBox()
      {
         delete numbers;
      }

      void add_a_number(double n)
      {
         if (counter < boxsize)
         {            
            numbers[counter] = n;
            printf("added number %.1f to your number box\n", numbers[counter]);
            counter++;
         }
         else
         {
            printf("Sorry! Cannot add another number to your box! The box is full!\n");
         }
      }

      void show_all_numbers_in_box()
      {
         printf("Numbers currently in the box: ");
         for (int i = 0; i < counter; i++)
            printf("%.1f ", numbers[i]);
         printf("\n\n");
      }

      void get_min_max(double* minval, double* maxval)
      {
         if (counter==0)
          return;

         *minval = numbers[0];
         *maxval = numbers[0];
         for (int i = 1; i < counter; i++)
         {
            if (numbers[i]<*minval) *minval = numbers[i];
            if (numbers[i]>*maxval) *maxval = numbers[i];
         }
      }

      double get_arithmetic_mean()
      {
         if (counter==0)
            return 0.0;
         double sum=0.0;
         for (int i=0; i<counter; i++)
            sum += numbers[i];
         return (sum/(double)counter);
      }

   private:
   
      double* numbers;

      int boxsize;

      int counter;

};


int main()
{
   NumberBox myBox(10);

   myBox.add_a_number(1.0);
   myBox.add_a_number(4.0);
   myBox.add_a_number(7.0);
   myBox.show_all_numbers_in_box();

   myBox.add_a_number(11.0);
   myBox.add_a_number(44.0);
   myBox.add_a_number(77.0);
   myBox.show_all_numbers_in_box();
   

   double minval, maxval;
   myBox.get_min_max(&minval,&maxval);
   printf("Minimum value of all numbers in box is: %.1f\n", minval);
   printf("Maximum value of all numbers in box is: %.1f\n", maxval);

   printf("Arithmetic mean of all numbers in box is: %.1f\n", myBox.get_arithmetic_mean());


   myBox.add_a_number(100.0);
   myBox.add_a_number(200.0);
   myBox.add_a_number(300.0);
   myBox.add_a_number(400.0);
   myBox.add_a_number(500.0);
   myBox.add_a_number(600.0);

   _getch();
}