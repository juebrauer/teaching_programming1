#include <stdio.h>  // for the printf(), scanf() command
#include <conio.h>  // for the _getch() command

int main()
{
   int nr_rows;

   do
   {
      printf("\nNumber of rows for triangle? ");
      scanf_s("%d", &nr_rows);

      int middle = 30;

      for (int row = 1; row <= nr_rows; row++)
      {
         int nr_stars_in_current_row = 2*row - 1;

         for (int space=1; space<=middle-nr_stars_in_current_row/2; space++)
            printf(" ");

         for (unsigned int star=1; star<=nr_stars_in_current_row; star++)
            printf("*");

         printf("\n");
      }
   } while (nr_rows > 0);
   
   printf("\n\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}