#include <stdio.h> // for the printf(), scanf() command
#include <conio.h> // for the _getch() command

int main()
{
   for (int y = 0; y<10; y = y + 1)
   {
      for (int x = 0; x <= y; x = x + 1)
      {
         printf("%d ", x);
      }
      printf("\n");
   }

   for (int y = 0; y<10; y = y + 1)
   {
      for (int x = 0; x <= y; x = x + 1)
      {
         printf("* ");
      }
      printf("\n");
   }


   printf("\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}
