#include <stdio.h>   // for the printf(), scanf() command
#include <conio.h>   // for the _getch() command
#include <stdlib.h>  // for rand()
#include <windows.h> // for COORD and SetConsoleCursorPosition()


// Set cursor position in console
// see http://www.dreamincode.net/forums/topic/153240-console-cursor-coordinates/ 
void set_cursor_position(int x, int y)
{
   //Initialize the coordinates
   COORD coord = { x, y };
   //Set the position
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

} // set_cursor_position


int main()
{
   do
   {
      system("cls");

      int middle_x = 20;
      int middle_y = 12;

      for (int H = 3; H <= 21; H+=2)
      {  
         int W = H;

         // draw rectangle of size H x H
         for (int y = 0; y < H; y++)
         {
            set_cursor_position(middle_x-H/2, middle_y-H/2 + y);

            if ((y == 0) || (y == H - 1))
            {
               for (int x = 0; x < W; x++)
                  printf("#");
            }
            else
            {
               for (int x = 0; x < W; x++)
               {
                  if ((x == 0) || (x == W - 1))
                     printf("#");
                  else
                     printf(" ");
               } // for x
            } // if

            printf("\n");

         } // for y

         Sleep(100);
   
      } // for (different rectangles sizes H)

   } while (1);

   printf("\n\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}
