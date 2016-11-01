#include <stdio.h> // for the printf(), scanf() command
#include <conio.h> // for the _getch() command

int main()
{
   printf("\n\n1. With a for-loop:\n");
   for (int i=17; i<=29; i=i+3)
      printf("%d ",i);

   printf("\n\n2. With a while-loop:\n");
   int i = 17;
   while (i<=29)
   {
      printf("%d ", i);
      i=i+3;
   }

   printf("\n\n3. With a do-while-loop:\n");
   i = 17;
   do
   {
      printf("%d ", i);
      i = i + 3;
   } while (i<=29);

   printf("\n\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}
