#include <string>
#include <conio.h> // for function _getch()

//using namespace std;

class Warrior
{
   
protected:
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

   Warrior(std::string newname)
   {
      name = newname;
   }

   Warrior(std::string newname, int startposx, int startposy)
   {
      name = newname;
      x = startposx;
      y = startposy;
   }

   ~Warrior()
   {
      printf("Warrior %s will be deleted. Good bye!\n", name.c_str());
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


#define NR_SPELLS 10


class Wizard : public Warrior 
{
private:

   bool spell[NR_SPELLS];

public:
   Wizard(std::string newname,
          int startposx,
          int startposy)
   {
      
      name = newname;
      x = startposx;
      y = startposy;

      for (int i = 0; i < NR_SPELLS; i++)
      {
         spell[i] = false;
      }
   }

   void conjure(int spell_nr)
   {
      if (spell[spell_nr] == true)
      {
         printf("I am conjuring spell nr %d\n", spell_nr);
      }
      else
      {
         printf("Sorry! I am still a young wizard. Cannot conjure spell nr. %d\n", spell_nr);
      }
   }

   void learn_spell(int spell_nr)
   {
      spell[spell_nr] = true;
   }

};

int main()
{
   Warrior w1("Arragon", 100, 100);
   w1.show_infos();

   Wizard z1("Gandalf", 200,200);
   z1.learn_spell(7);
   z1.conjure(7);
   z1.show_infos();

   printf("Press a key to exit.\n");
   _getch();
}