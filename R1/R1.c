#include <stdio.h>  // for the printf(), scanf() command
#include <conio.h>  // for the _getch() command
#include <stdlib.h> // for rand()

int main()
{
   while (1)
   {
      srand(0);

      int lower;
      printf("Enter lower border: ");
      scanf_s("%d", &lower);

      int upper;
      printf("Enter upper border: ");
      scanf_s("%d", &upper);

      // exit?
      if (lower==upper)
         break;

      printf("I will generate 10 random numbers between %d and %d ...\n", lower, upper);      
      int range  = upper-lower+1;
      for (int i=1; i<=10; i++)
      {
         int number = rand() % range + lower;
         printf("%d\t", number);
      }
      printf("\n");
   }

   printf("\n\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}
