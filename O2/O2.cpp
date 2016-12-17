/// O2.cpp
///
/// A Xmas party simulator!
///
/// There are four important Xmas object types at Xmas:
///
///  - Xmas tree: which can store up to N presents
///
///  - Santa Claus: which produces presents and puts them
///                 under a Xmas tree
///
///  - Present: which can be socks, cat, dogs, and smartphones
///
///  - Child: which takes (consumes) xmas presents and puts
///           them in its private list
///
/// Here were simulate a Xmas party where in each step we
/// choose randomly one object instance and let it do_something()
///
/// all sounds are from https://www.freesound.org/
///
/// I wish you and your family a merry Xmas!
///
/// ---
/// by Prof. Dr. Jürgen Brauer, www.juergenbrauer.org
///

#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include <vector>
#include <string>
using namespace std;


class xmas_object
{
   public:
   
   virtual void do_something()
   {
   }

}; // class xmas_object



///              ((\o/))
///         .-----//^\\-----.
///         |    /`| |`\    |
///         |      | |      |
///         |      | |      |
///  jgs    |      | |      |
///         '------===------'
/// ASCII art by jgs
/// http://www.chris.com/ascii/index.php?art=holiday/christmas/other
///
class present : public xmas_object
{
   public:
      enum present_type {socks, cat, dog, smartphone, NR_PRESENT_CATEGORIES};

      present()
      {
         what = (present_type) (rand() % NR_PRESENT_CATEGORIES);
      }

      present(present_type t)
      {
         what = t;
      }

      void do_something()
      {
         switch (what)
         {
            case socks:
               // Hey! Socks cannot generate any sound, or?
               break;

            case cat:               
               PlaySound(TEXT("sounds/cat.wav"), NULL, SND_FILENAME);
               break;

            case dog:
               PlaySound(TEXT("sounds/dog.wav"), NULL, SND_FILENAME);
               break;

           case smartphone:
              PlaySound(TEXT("sounds/smartphone.wav"), NULL, SND_FILENAME);
              break;
         }

      } // do_something()


      string to_name()
      {
         switch (what)
         {
            case socks     : return "socks";
            case cat       : return "cat";
            case dog       : return "dog";
            case smartphone: return "smartphone";
         }
         return "unknown xmas present type";
      }

      present_type get_type()
      {
         return what;
      }

   private:
      present_type what;      

}; // class present



///     _\/_
///      /\
///      /\
///     /  \
///     /~~\o
///    /o   \
///   /~~*~~~\
///  o/    o \
///  /~~~~~~~~\~`
/// /__*_______\
///      ||
///    \====/
///     \__/
/// ASCII Art by Shanaka Dias
/// http://www.ascii-code.com/ascii-art/holiday-and-events/christmas/trees.php
///
class xmas_tree : public xmas_object
{
   public:

      xmas_tree(int max_nr)
      {
         max_nr_presents = max_nr;
      }

      void do_something()
      {
         printf("Xmas Tree:\n");
         printf("\t There are %d presents under the tree!\n\t ", all_presents.size() );
         for (unsigned int i=0; i<all_presents.size(); i++)
            printf("%s ", all_presents[i]->to_name().c_str() );
         printf("\n\n");
         PlaySound(TEXT("sounds/xmastree.wav"), NULL, SND_FILENAME);
      }

      present* get_present()
      {
         // 1. how many presents are there currently
         //    under the tree?
         int N = all_presents.size();

         // 2. are there are any xmas presents under
         //    the tree?
         if (N == 0)
         {
            printf("\t Sorry! There are no more Xmas presents under the Xmas tree.\n");
            return NULL;            
         }

         // 3. get random xmas present
         int rnd_idx = rand() % N;
         present* p = all_presents[rnd_idx];

         // 4. remove xmas present from list of presents
         all_presents.erase( all_presents.begin() + rnd_idx );

         // 5. let the present do_something()
         p->do_something();

         // 6. return the xmas present
         return p;

      } // get_present()


      void put_present_under_tree(present* p)
      {
         all_presents.push_back( p );
      }


   private:
      int max_nr_presents;
      vector<present*> all_presents;

}; // class xmas_tree



///  {} _  \
///        |__ \
///       /_____\
///       \o o)\)_______
///       (<  ) /#######\
///     __{'~` }#########|
///    /  {   _}_/########|
///   /   {  / _|#/ )####|
///  /   \_~/ /_ \  |####|
///  \______\/  \ | |####|
///   \__________\|/#####|
///snd |__[X]_____/ \###/ 
///    /___________\
///     |    |/    |
///     |___/ |___/
///    _|   /_|   /
///   (___,_(___,_)
///
/// ASCII art by Shanaka Dias:
/// http://www.ascii-code.com/ascii-art/holiday-and-events/christmas/santa-claus.php
///
class santa_claus : public xmas_object
{
   public:

      santa_claus(xmas_tree* which_tree)
      {
         tree = which_tree;
      }

      void do_something()
      {  
         // generate a new present and put it unter the xmas tree
         present* p = new present();
         tree->put_present_under_tree(p);

         printf("Santa Claus:\n");
         printf("\t Ho ho ho! I have come to bring a new present (%s)!\n\n", p->to_name().c_str() );
         PlaySound(TEXT("sounds/santaclaus.wav"), NULL, SND_FILENAME);    
      }

   private:

      xmas_tree* tree;

}; // santa_claus




///                             .-(_)
///                            / _/
///                         .-'   \
///                        /       '.
///                      ,-~--~-~-~-~-,
///                     {__.._...__..._}             ,888,
///     ,888,          /\##"  6  6  "##/\          ,88' `88,
///   ,88' '88,__     |(\`    (__)    `/)|     __,88'     `88
///  ,88'   .8(_ \_____\_    '----'    _/_____/ _)8.       8'
///  88    (___)\ \      '-.__    __.-'      / /(___)
///  88    (___)88 |          '--'          | 88(___)
///  8'      (__)88,___/                \___,88(__)
///            __`88,_/__________________\_,88`__
///           /    `88,       |88|       ,88'    \
///          /        `88,    |88|    ,88'        \
///         /____________`88,_\88/_,88`____________\
///        /88888888888888888;8888;88888888888888888\
///       /^^^^^^^^^^^^^^^^^^`/88\\^^^^^^^^^^^^^^^^^^\
/// jgs  /                    |88| \============,     \
///     /_  __  __  __   _ __ |88|_|^  MERRY    | _ ___\
///     |;:.                  |88| | CHRISTMAS! |      |
///     |;;:.                 |88| '============'      |
///     |;;:.                 |88|                     |
///     |::.                  |88|                     |
///     |;;:'                 |88|                     |
///     |:;,                  |88|                     |
///     '---------------------""""---------------------'
/// 
/// ASCII Art by Joan Stark
/// http://www.ascii-code.com/ascii-art/holiday-and-events/christmas/other.php
///
class child : public xmas_object
{
   public:

      child(int child_id, xmas_tree* t)
      {
         id = child_id;
         tree = t;
      }

      void do_something()
      {
         printf("Child %d:\n", id);
         printf("\t I will try to get another present!\n");

         // 1. child tries to get a present from xmas tree
         present* p = tree->get_present();

         // 2. was there still a present?
         if (p == NULL)
         {
            printf("\t Ooooh no! There are no more presents!\n");
            PlaySound(TEXT("sounds/child_screaming.wav"), NULL, SND_FILENAME);
            return;
         }

         // 3. show xmas presents got so far
         printf("\t Here are all the presents I have so far:\n\t\t ");
         for (unsigned int i=0; i<my_presents.size(); i++)
            printf("%s ", my_presents[i]->to_name().c_str());

         // 4. generate reaction to new xmas present
         switch (p->get_type())
         {
            case present::present_type::socks :
               printf("\n\t Ooooh now! I hate getting socks!\n");
               PlaySound(TEXT("sounds/child_screaming.wav"), NULL, SND_FILENAME);
               break;
            default:
               printf("\n\t HURRAY! The new present is a %s!\n", p->to_name().c_str() );
               PlaySound(TEXT("sounds/child_hurra.wav"), NULL, SND_FILENAME);
               break;
         }     

         // 5. put new present in private list of presents
         my_presents.push_back(p);

      } // do_something()

   private:
      int              id;
      xmas_tree*       tree;     
      vector<present*> my_presents;
   
}; // child



int main()
{
   srand( (unsigned int) time(NULL) );

   printf("\nWelcome to the Xmas simulator!\n");

   vector<xmas_object*> all_xmas_objects;

   // 1. generate xmas objects

   // 1.1 there is one xmas tree ...
   xmas_tree* t = new xmas_tree(5);

   // 1.2 we all know: there is only one Santa Claus ...
   //     Santa Claus needs the information under which xmas-tree
   //     to put the presents.
   //     Santa Claus is a producer of presents
   xmas_object* claus = new santa_claus(t);
   all_xmas_objects.push_back( claus );

   // 1.3 now we can have a different number of children
   //     = consumer of xmas presents
   printf("How many children do you want to simulate? ");
   int nr_children;
   scanf_s("%d", &nr_children);
   for (int id=0; id<nr_children; id++)
   {
      all_xmas_objects.push_back( new child(id, t) );
   }


   // 2. Let's start with some (5) xmas presents under the tree
   t->put_present_under_tree( new present( present::present_type::socks ) );
   t->put_present_under_tree( new present( present::present_type::dog ) );
   t->put_present_under_tree( new present( present::present_type::cat ) );
   t->put_present_under_tree( new present( present::present_type::smartphone ) );
   t->put_present_under_tree( new present(present::present_type::socks) );
   

   // 3. now simulate Xmas!
   int step=0;
   bool NewYear;
   do
   {
      // show xmas presents lying now under the tree
      printf("\n");      
      t->do_something();

      // choose randomly an object and let it do something
      int N = all_xmas_objects.size();
      all_xmas_objects[rand() % N]->do_something();

      Sleep(2000);

      NewYear = ++step==1000;
   } while (!NewYear);

   printf("Xmas simulation finished. Merry Xmas!\n");
   printf("Press a key to exit!\n");
   _getch();
}