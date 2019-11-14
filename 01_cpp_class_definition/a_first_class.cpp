#include <string>

//using namespace std;

class Warrior
{
   
private:
   int x;
   int y;
   std::string name;

public:

   Warrior()
   {
      x = 0;
      y = 0;
      name = "not defined";
   }

   Warrior(std::string newname, int startposx, int startposy)
   {
      name = newname;
      x = startposx;
      y = startposy;
   }

   void show_infos()
   {
      printf("Warrior %s is currently at (%d,%d)\n",
              name.c_str(), x, y);
   }
  

   void set_position(int xpos, int ypos)
   {
      if ((xpos < 0) || (xpos >= 1000) || (ypos < 0) || (ypos >= 1000))
      {
         printf("Invalid position! I will not change the position!");
         return;
      }

      x = xpos;
      y = ypos;
   }

   void set_name(std::string newname)
   {
      name = newname;
   }
   
};

int main()
{
   Warrior w1("Arragon", 100, 100);
   w1.show_infos();

   //w1.set_position(20, 10);
   //w1.set_name("Gandalf");
   //w1.show_infos();
   

   Warrior w2;
}