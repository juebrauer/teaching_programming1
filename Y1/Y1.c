#include <stdio.h>   // for the printf(), scanf() command
#include <conio.h>   // for the _getch() command
#include <Windows.h> // for COORD, SetConsoleCursorPosition()

void set_cursor_position(int x, int y)
{
   //Initialize the coordinates
   COORD coord = { x, y };
   //Set the position
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

} // set_cursor_position       



#define H 20
#define W 60
char board[H][W];

void init_board()
{
   for (int y = 0; y < H; y++)
   {
      if ((y == 0) || (y == H - 1))
      {
         for (int x = 0; x < W; x++)
            board[y][x]='#';
      }
      else
      {
         for (int x = 0; x < W; x++)
         {
            if ((x == 0) || (x == W - 1))
               board[y][x] = '#';
            else
               board[y][x] = ' ';
         } // for x
      } // if
   } // for y
}


void add_single_block(int x, int y, int size)
{
   for (int oy = 0; oy < size; oy++)
   {
      for (int ox = 0; ox < size; ox++)
      {
         if ((x+ox>=W) || (y+oy>=H))
            break;
         board[y+oy][x+ox] = '#'; // press ALT+219 for getting this solid block ASCII character
      }
   }
}


void show_board()
{
   set_cursor_position(0,0);
   for (int y = 0; y<H; y++)
   {
      for (int x = 0; x<W; x++)
         printf("%c", board[y][x]);
      printf("\n");
   }   
}



int main()
{
   srand(time(NULL));
   do
   {
      init_board();
      for (int block=1; block<=20; block++)
         add_single_block(rand()%W, rand()%H, rand()%3+3);
      show_board();
      int c = _getch();
      if (c==29)
         break;
   } while (1);

   printf("Press any key to exit this program.");
   _getch();
}