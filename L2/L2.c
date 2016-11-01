#include <stdio.h> // for the printf(), scanf() command
#include <conio.h> // for the _getch() command

int main()
{
   int n1, n2;

   n1 = 0;

   do
   {
      n1 = n1 + 1;
      n2 = 0;
      do
      {
         n2 = n2 + 1;
         printf("%d x %d = %d\t", n1, n2, n1*n2);
      } while (n2<10);
      printf("\n");
   } while (n1<10);

   printf("\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}
