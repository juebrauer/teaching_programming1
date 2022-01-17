#include <iostream>

#include "hke_vector.h"

int main()
{
    hke_vector* v = new hke_vector;

    v->add(10);
    v->add(-5);
    v->add(99);
    v->add(200);
    v->add(42);

    for (int i=0; i<v->size(); i++)
    {
        std::cout << "Element #" << i << " is " << v->get_element(i) << std::endl;
    }

    v->delete_element( 2 );
    v->delete_element( 2 );
    v->delete_element( 2 );
    v->delete_element( 0 );
    v->delete_element( 0 );

    for (int i=0; i<v->size(); i++)
    {
        std::cout << "Element #" << i << " is " << v->get_element(i) << std::endl;
    }
    
    delete v;

}