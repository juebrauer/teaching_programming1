#pragma once

class hke_vector
{
    public:

        hke_vector();

        ~hke_vector();
        

        void add(int number);

        unsigned int size();

        int get_element(int idx);

        void delete_element(int idx);


    private:

        int count;

        int* ptr_data;



};

