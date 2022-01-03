#include "hke_vector.h"

#include <stdlib.h> // for malloc()
#include <iostream> // for cout


hke_vector::hke_vector()
{
    count = 0;
    ptr_data = nullptr;
}


hke_vector::~hke_vector()
{
    std::cout << "Deleting memory for storing all the " << count << " numbers" << std::endl;
    free( ptr_data );
}


void hke_vector::add(int number)
{
    if (count == 0)
    {
        // malloc
        ptr_data = (int*) malloc(1 * sizeof(int));
        ptr_data[0] = number;
        count = 1;
    }
    else
    {
        // realloc
        ptr_data = (int*) realloc(ptr_data, (count+1) * sizeof(int));

        ptr_data[count] = number;
        count++;
    }
}


unsigned int hke_vector::size()
{
    return count;
}


int hke_vector::get_element(int idx)
{
    return ptr_data[idx];
}