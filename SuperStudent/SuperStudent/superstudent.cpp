#include <conio.h>
#include <stdio.h>

struct coord2D
{
    int x;
    int y;
};

// What is the effect of hitting an enemy?
enum damagetype {killing, energyreduction};


class Enemy
{
    private:
    
        struct coord2D position;

        enum damagetype damageeffect;

    public:

        // class constructor
        Enemy()
        {
            printf("New enemy was generated.\n");
            position.x = 0;
            position.y = 0;
            damageeffect = killing;
        }

        // class destructor
        ~Enemy()
        {
            printf("The object was deleted.\n");
        }

        void set_new_position(struct coord2D new_coord)
        {
            position = new_coord;
        }

        struct coord2D get_new_position()
        {
            return position;
        }

};


int main()
{
    Enemy* all_enemies[10];

    for (int i = 0; i < 10; i++)
        all_enemies[i] = new Enemy;
    
    struct coord2D pos;
    pos.x = 10;
    pos.y = 15;

    all_enemies[0]->set_new_position(pos);

    printf("enemy1 is now at coordinate: (%d,%d)\n",
        all_enemies[0]->get_new_position().x,
        all_enemies[0]->get_new_position().y);
        
    _getch();

    for (int i = 0; i < 10; i++)
        delete all_enemies[i];
    
    //enemy1->position = pos;
    //enemy1->damageeffect = killing;

    printf("End of program\n");
    _getch();
}