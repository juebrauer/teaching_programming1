#include <stdio.h>  // for the printf(), scanf() command
#include <conio.h>  // for the _getch() command

int main()
{
   int H,W;
 
   do
   {
      printf("\nHeight of rectangle? ");
      scanf_s("%d", &H);

      printf("Width of rectangle? ");
      scanf_s("%d", &W);

      for (int y = 0; y < H; y++)
      {
         if ((y==0) || (y==H-1))
         {
            for (int x = 0; x < W; x++)
               printf("#");
         }
         else
         {  
            for (int x = 0; x < W; x++)
            {
               if ((x==0) || (x==W-1))
                  printf("#");
               else
                  printf(" ");
            } // for x
         } // if
         
         printf("\n");

      } // for y


   } while ((H>0) && (W>0));  

   printf("\n\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}
