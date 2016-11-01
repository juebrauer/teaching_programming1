#include <stdio.h>  // for the printf(), scanf() command
#include <conio.h>  // for the _getch() command

int main()
{
   int H, W;

   do
   {
      printf("\nHeight of rectangle? ");
      scanf_s("%d", &H);

      printf("Width of rectangle? ");
      scanf_s("%d", &W);

      int nr_fields = H*W;

      for (int f = 1; f <= nr_fields; f++)
      {
         if ( ((f>=1) && (f<=W)) ||
              (f>=(H-1)*W+1) ||
              (f % W == 1) ||
              (f % W == 0)
            )
            printf("#");
         else
            printf(" ");

         if (f % W == 0)
            printf("\n");
      }

   } while ((H>0) && (W>0));
   

   printf("\n\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}
