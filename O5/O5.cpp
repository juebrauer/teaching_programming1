#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

class NumberBox
{
public:

   NumberBox()
   {
   }

   NumberBox(int MAX_NR)
   {
      boxsize = MAX_NR;
      numbers = new double[boxsize];
      printf("\nConstructor of class NumberBox was called.\n");
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
      if (counter == 0)
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
      if (counter == 0)
         return 0.0;
      double sum = 0.0;
      for (int i = 0; i<counter; i++)
         sum += numbers[i];
      return (sum / (double)counter);
   }

   NumberBox* copy()
   {
      NumberBox* the_copy = new NumberBox( boxsize );
      the_copy->counter = counter;

      for (int i=0; i<counter; i++)
         the_copy->numbers[i] = numbers[i];

      return the_copy;
   }


private:

   double* numbers;

   int boxsize;

   int counter;

};


int main()
{
   // 1. create a number box #1
   NumberBox* myBox1 = new NumberBox(10);
   myBox1->add_a_number(1.0);
   myBox1->add_a_number(4.0);
   myBox1->add_a_number(7.0);
   
   // 2. get a copy of the number box
   NumberBox* myBox2 = myBox1->copy();

   // 3. add some numbers to number box #2
   myBox2->add_a_number(14.0);
   myBox2->add_a_number(18.0);

   // 4. show content of number box #1 and #2
   printf("\n");
   printf("myBox1: ");
   myBox1->show_all_numbers_in_box();
   printf("myBox2: ");
   myBox2->show_all_numbers_in_box();

   _getch();
}