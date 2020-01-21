#include <string>
#include <conio.h> // for function _getch()
#include <vector>

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


   // with "=0" a method becomes a "pure virtual function"
   virtual void fight()
   {
      printf("Warrior %s: I just fight.\n", name.c_str());
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
          int startposy) : Warrior(newname, startposx, startposy)
   {
      
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

   void fight()
   {
      printf("Wizard %s: I am a wizard and for this I conjure.\n",
             name.c_str());
   }

};

class Knight : public Warrior
{
public:
   Knight(std::string newname,
      int startposx,
      int startposy) : Warrior(newname, startposx, startposy)
   {
      sword_length = 50;

   }


   void fight()
   {
      printf("Knight %s: I am a knight and I fight with my "
             "sword which has length %d\n", name.c_str(), sword_length);
   }


private:
   int sword_length;
   int speed_horse;

};

int main()
{
   /*
   std::vector<int> v;

   int zahl;
   do
   {
      printf("Bitte gib eine Zahl ein: ");
      scanf_s("%d", &zahl);
      v.push_back( zahl );
   } while (zahl != 0);

   for (int i = 0; i < v.size(); i++)
      printf("%d.-te Zahl ist %d\n", i, v[i]);
   */



   
   //Warrior* w1 = new Warrior("Arragon", 100, 100);
   Wizard* z1 = new Wizard("Gandalf", 200,200);   
   Knight* k1 = new Knight("Uwe", 50, 50);

   std::vector<Warrior*> all_units;
   //all_units.push_back(w1);
   all_units.push_back(z1);
   all_units.push_back(k1);

   for (int i = 0; i < all_units.size(); i++)
   {
      Warrior* ptr = all_units[i];
      ptr->fight();
   }



   printf("Press a key to exit.\n");
   _getch();
}