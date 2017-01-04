#pragma once

#pragma once

// Base class for all animals
class Animal
{
public:

   Animal(int world_width,
          int world_height,
          int start_vx,
          int start_vy);

   virtual void     simulate();
   void     set_to_pos(int newx, int newy);
   int      getposx();
   int      getposy();
   virtual char     get_visual_appearance();
   void make_sure_that_my_coords_are_valid();

protected:
   int x;
   int y;
   int vx;
   int vy;
   int wwidth;
   int wheight;
   char visu;

};
