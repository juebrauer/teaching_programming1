#include <stdio.h> // for the printf(), scanf() command
#include <conio.h> // for the _getch() command

int main()
{
   printf("\nOutput for first for-loop:\n");
   for (int i = 75; i >= 15; i = i - 5)
   {
      printf("%d ", i);
   }

   printf("\n\nOutput for second for-loop:\n");
   for (int i = 0; i<50; i++)
   {
      if ((i%3==0) || (i%7==0))
         continue;
      printf("%d ", i);
   }
   
   
   printf("\n\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}
