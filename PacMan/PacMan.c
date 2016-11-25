///
/// PacMan.c
///   Live programming project during lecture in
///   Winter semester 2016/2017
/// *********************************************
///
/// This is the intermediate status of a
/// incremental programming project we augment live
/// at the end of each lecture "Programmming 1".
///
/// At the end of each lecture we try to
/// extend the code a little bit more in
/// order to come step by step to a complete PacMan game.
///
/// Didactic reasons:
///  - you shall see how to divide a large problem into
///    several smaller ones
///  - you shall learn how to realize a large software
///    project by small incremental steps
///  - you shall see how and where one can apply new
///    C syntax theory learned in the theory sections
///    of the lecture
///  - and last but not least: it's fun! =)
///
/// ---
/// Prof. Dr.-Ing. Jürgen Brauer
///

#include <stdio.h> // printf()
#include <conio.h> // getch()
#include <windows.h>
#include <stdbool.h>

#define H 30
#define W 60

struct coord
{
   int x;
   int y;
};

struct PacMan {
   struct coord position;
   int vx;
   int vy;
   int lives;
   bool chasing;
};

struct PacMan myPacMan = {
                           {
                              .x = 1,
                              .y = 1,                              
                           },
                           .vx = 0,
                           .vy = 0,
                           .lives = 3,
                           .chasing = false
                         };

char playfield[H][W] =
{
   { "############################################################" },
   { "#                                                          #" },
   { "# ################## #                                     #" },
   { "# ##               # #                                     #" },
   { "# ##          #### # #                                     #" },
   { "# ##          ## # # #                                     #" },
   { "# ##  ######  ## # # #                                     #" },
   { "# ##  #    #  ## # # #                                     #" },
   { "# ##  #### #  ## # # #                                     #" },
   { "# ##       #  ##   # #                                     #" },
   { "# ##########  ###### #                                     #" },
   { "#                    #                                     #" },
   { "######################                                     #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "############################################################" }
}; // <-- CAUTION! Semicolon necessary!


void initialize()
{
   // 1. replace each empty field in the playfield
   //    with a food field
   for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         if (playfield[i][j]==' ')
            playfield[i][j] = '.';
      }
   }

   // 2. set start position of PacMan
  

} // initialize


void user_input()
{
   if (_kbhit())
   {
      char c1 = _getch();

      if (c1 == -32)
      {
         char c2 = _getch();

         myPacMan.vx = 0;
         myPacMan.vy = 0;

         switch (c2)
         {
            case 72: myPacMan.vy = -1; break; // cursor up
            case 80: myPacMan.vy = +1; break; // cursor down
            case 75: myPacMan.vx = -1; break; // cursor left
            case 77: myPacMan.vx = +1; break; // cursor right            
         }
      }
      

      //printf("c1=%d c2=%d\n", c1, c2);
      
   }
}


void move_figures()
{
   // 1. delete PacMan from old position
   playfield[myPacMan.position.y][myPacMan.position.x] = ' ';

   // 2. move PacMan according to last set velocity vector
   myPacMan.position.x += myPacMan.vx;
   myPacMan.position.y += myPacMan.vy;

   // 3. put PacMan back again to playfield
   playfield[myPacMan.position.y][myPacMan.position.x] = '@';
}


void check_for_collisions()
{

}


void show_playfield()
{
   for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         printf("%c", playfield[i][j]);
      }
      printf("\n");
   }
}


// Set cursor position in console
// see http://www.dreamincode.net/forums/topic/153240-console-cursor-coordinates/ 
void set_cursor_position(int x, int y)
{
   //Initialize the coordinates
   COORD coord = { x, y };
   //Set the position
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

} // set_cursor_position


void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}


int main()
{
   hidecursor();
   initialize();

   while (1)
   {
      user_input();
      move_figures();
      check_for_collisions();
      show_playfield();

      Sleep( 1000 / 30 );
      set_cursor_position(0,0);
   }

} // main