#include <iostream>

#include "hke_vector_template.h"


class person
{

};


int main()
{
    hke_vector_template<double>* v = new hke_vector_template<double>;


    hke_vector_template<person*>* v2 = new hke_vector_template<person*>;

    person* ptr_person = new person();
    v2->add( ptr_person );


    v->add(10.123);
    v->add(-5.123);
    v->add(99.123);
    v->add(200.123);
    v->add(42.123);

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