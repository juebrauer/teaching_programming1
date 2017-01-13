///
/// Exercise: O6
///
/// file: PacMan_OOP.cpp
///
/// PacMan project with a Ghost class.
///
/// ---
/// Prof. Dr.-Ing. Jürgen Brauer
///

#include <stdio.h> // printf()
#include <conio.h> // getch()
#include <windows.h>
#include <stdbool.h>
#include <vector>

#define H 30
#define W 60
#define NR_GHOSTS_START 5
#define PACMAN_SYMBOL '\1'
#define GHOST_SYMBOL  '\2'
#define FOOD_SYMBOL '.'
#define WALL_SYMBOL '#'
#define FOOD_TO_WIN 200

bool collision_with_ghost = false;
bool game_over = false;


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
   int food_collected;
};




struct PacMan myPacMan;

char playfield[H+1][W+1] =
{
   { "############################################################" },
   { "#                                                          #" },
   { "# ########  ######## #            ###############          #" },
   { "# #                # #            #                        #" },
   { "# #            ### # #            # ####### #####          #" },
   { "# #            # # # #            #                        #" },
   { "# # ########   # # # #            ### ###########          #" },
   { "# # # #    #   # # # #            # # #         #          #" },
   { "# # # #### #   # # # #            # # # ####### #          #" },
   { "# #        #   #   # #            # # #       # #          #" },
   { "# ##########  ###### #            # # ######### #          #" },
   { "#                    #            #             #          #" },
   { "#########  ###########            ######  #######          #" },
   { "#                                                          #" },
   { "#                     ######     ##########                #" },
   { "#                     #                   #                #" },
   { "#                     #                   #                #" },
   { "#                     #                   #                #" },
   { "#                     ##############  #####                #" },
   { "#                                                          #" },
   { "# ########    ############    ############  ############   #" },
   { "# #                                                    #   #" },
   { "# #      # #######  ######    ######################## #   #" },
   { "# #      # #             #    #                      # #   #" },
   { "# #      # #             #    #  #                   # #   #" },
   { "# #      # #             #    #  ##################### #   #" },
   { "# #      # #                  #                        #   #" },
   { "# ######## #######  ####################  ##############   #" },
   { "#                                                          #" },
   { "############################################################" }
}; // <-- CAUTION! Semicolon necessary!


class Ghost {

public:

   Ghost(int start_x, int start_y)
   {
      this->position.x = start_x;
      this->position.y = start_y;
      this->chasing = true;
      choose_random_direction();
   }

   void move()
   {
      // 1. where does the Ghost want to move to?
      int dx = position.x + vx;
      int dy = position.y + vy;

      // 2. what is at this place where we plan to move the Ghost to?
      char whats_there = playfield[dy][dx];

      // 3. is it a PacMan?
      if (whats_there == PACMAN_SYMBOL)
      {
         collision_with_ghost = true;
      }

      // 4. is the field free to move there?
      if (whats_there != WALL_SYMBOL)
      {
         playfield[position.y][position.x] = ' ';
         position.x = dx;
         position.y = dy;
         playfield[position.y][position.x] = GHOST_SYMBOL;
      }
      else
      {
         // field is not free, i.e. a wall:
         // so do not move Ghost at all in this step, but
         // randomly choose a new direction to move
         choose_random_direction();         
      }

      // randomize behavior of the Ghost
      if (rand()%30==0)
         choose_random_direction();

   } // move


   void choose_random_direction()
   {
      int r = rand() % 4;
      switch (r)
      {
         case 0: vx=+1; vy=0;  break;
         case 1: vx=0;  vy=1;  break;
         case 2: vx=-1; vy=0;  break;
         case 3: vx=0;  vy=-1; break;
      }
   }


private:
   struct coord position;
   int vx;
   int vy;
   bool chasing;
};


std::vector<Ghost*> allGhosts;



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


void add_new_ghost()
{
   // try to find a (x,y) coordinate randomly where a food piece is
   int x, y;
   do
   {
      x = 1 + rand() % (W - 1);
      y = 1 + rand() % (H - 1);

   } while (playfield[y][x] != FOOD_SYMBOL);

   allGhosts.push_back(new Ghost(x, y));
}

void initialize()
{
   myPacMan.position.x = 1;
   myPacMan.position.y = 1;
   myPacMan.vx = 0;
   myPacMan.vy = 0;
   myPacMan.food_collected = 0;
   myPacMan.lives = 3;
   myPacMan.chasing = false;

   // 1. replace each empty field in the playfield
   //    with a food field
   for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         if (playfield[i][j] == ' ')
            playfield[i][j] = FOOD_SYMBOL;
      }
   }

   // 2. create some ghosts
   for (int i = 0; i < NR_GHOSTS_START; i++)
      add_new_ghost();

} // initialize


void user_input()
{
   if (_kbhit())
   {
      char c1 = _getch();
      if (c1 == 'a')
      {
         // stop moving
         myPacMan.vx = 0;
         myPacMan.vy = 0;
      }

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


void move_ghosts()
{
   // 1. move all Ghosts
   for (int i = 0; i < allGhosts.size(); i++)
   {
      allGhosts[i]->move();      
   }  
}

void move_pacman()
{
   // 1. delete PacMan from old position
   playfield[myPacMan.position.y][myPacMan.position.x] = ' ';

   // 2. compute new desired coordinate (nx,ny)
   int nx = myPacMan.vx + myPacMan.position.x;
   int ny = myPacMan.vy + myPacMan.position.y;

   // 3. test whether there is a wall at (nx,ny)  
   if (playfield[ny][nx] == '#')
   {
      // Damn! There is a wall! Stop PacMan!
      myPacMan.vx = 0;
      myPacMan.vy = 0;
   }

   // 4. update PacMan's coordinate
   myPacMan.position.x += myPacMan.vx;
   myPacMan.position.y += myPacMan.vy;

   if (playfield[ny][nx] == GHOST_SYMBOL)
      collision_with_ghost = true;
   else
   {
      if (playfield[ny][nx] == '.')
      {
         myPacMan.food_collected++;
      }

      // put PacMan back again to playfield
      playfield[myPacMan.position.y][myPacMan.position.x] = PACMAN_SYMBOL;
   }
   
} // move_pacman


void show_playfield()
{
   set_cursor_position(0, 0);
   for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         printf("%c", playfield[i][j]);
      }
      printf("\n");
   }

   printf("Score: %d - Lives:%d\n", myPacMan.food_collected, myPacMan.lives);

   printf("Sound effects used are from 'Cartoon Sound Effects Collection'\n");   
   printf("http://www.orangefreesounds.com");
}

void check_collisions()
{
   // did a collision between PacMan and Ghost happen?
   if (collision_with_ghost)
   {
      collision_with_ghost = false;

      myPacMan.lives--;

      PlaySound(TEXT("sounds/17-Cartoon-sound-effect.wav"), NULL, SND_FILENAME);

      // try to find a new (x,y) PacMan start coordinate randomly 
      int x, y;
      do
      {
         x = 1 + rand() % (W - 1);
         y = 1 + rand() % (H - 1);

      } while ((playfield[y][x] != FOOD_SYMBOL) && (playfield[y][x] != ' '));

      myPacMan.position.x = x;
      myPacMan.position.y = y;
      myPacMan.vx = 0;
      myPacMan.vy = 0;

      if (myPacMan.lives == 0)
         game_over = true;
   }
} // check_collisions





int main()
{
   // set console to code page 437 https://en.wikipedia.org/wiki/Code_page_437
   // and set font to "raster font"
   /*
   system("chcp 437");
   for (int i=0; i<255; i++)
   {
   printf("%c", i);
   if (i%25==0) printf("\n");
   }
   _getch();
   */

   system("cls");

   hidecursor();
   initialize();

   int steps=0;
   while (!game_over)
   {  
      move_ghosts();
      show_playfield();
      check_collisions();

      user_input();
      move_pacman();
      show_playfield();
      check_collisions();
            
      Sleep(5);

      if (++steps % 100 == 0)
      { 
         add_new_ghost();
         show_playfield();
         PlaySound(TEXT("sounds/46-Cartoon-sound-effect.wav"), NULL, SND_FILENAME);
      }

      if (myPacMan.food_collected == FOOD_TO_WIN)
      {
         set_cursor_position(W / 2 - 5, H / 2);
         printf("   YOU WON!   ");
         PlaySound(TEXT("sounds/4-Cartoon-sound-effect.wav"), NULL, SND_FILENAME);
         _getch();
         exit(0);
      }
   }

   set_cursor_position(W/2-5, H/2);
   printf("   GAME OVER!   ");
   PlaySound(TEXT("sounds/35-Cartoon-sound-effect.wav"), NULL, SND_FILENAME);
   _getch();

} // main