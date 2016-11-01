#include <stdio.h> // for the printf(), scanf() command
#include <conio.h> // for the _getch() command

int main()
{
   int i;
   
   printf("\nCounting from 1 to 10:\n");
   i=0;
   do
   {
      i = i + 1;
      printf("%d ", i);   
   } while (i<10);

   printf("\nCounting from -5 to -15:\n");
   i = -4;
   do
   {
      i = i - 1;
      printf("%d ", i);
   } while (i>-15);

   printf("\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}
