#pragma once

class Simulator
{
public:
            Simulator(int w, int h);
            ~Simulator();
   
   void     simulate_one_step();
   
   void     show_world();


private:
   int          width;
   int          height;
   char**       world;

   void         init();
};