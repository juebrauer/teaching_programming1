#include <stdio.h>
#include <conio.h>

class Warrior {
public:
   Warrior()
   {}
   virtual ~Warrior()
   {}
};

class Wizard : public Warrior {
public:
   Wizard()
   {}
   void conjure()
   {
      printf("I am conjuring spell %d! \n", spell_nr);
   }

private:
   int spell_nr = 42;
};

int main() {
   Warrior* AllWarriors[5];
   AllWarriors[0] = new Warrior();
   AllWarriors[1] = new Warrior();
   AllWarriors[2] = new Wizard();
   AllWarriors[3] = new Warrior();
   AllWarriors[4] = new Wizard();

   for (int i = 0; i < 5; i++) {
      Warrior* w = AllWarriors[i];

      // safe method:
      /*
      Wizard* z = dynamic_cast<Wizard*> (w);      
      if (z != NULL)
         z->conjure();
      */

      // unsafe method:
      Wizard* z = (Wizard*)w;
      z->conjure();
      
   }
   _getch();
}

