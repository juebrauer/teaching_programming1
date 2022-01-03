#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>

#include "person.h"
#include "employee.h"
#include "student.h"



// In C:   malloc() --> free()
// In C++: new() --> delete()


int main()
{
   // 1. Generate employees at runtime
   std::vector<person*> v;

   std::cout << "How many employees shall be generated?" << std::endl;
   unsigned int nr_employees;
   std::cin  >> nr_employees;
   std::cout << "Ok, I will generate " << nr_employees << " employees!" << std::endl;

   for (int i=0; i<nr_employees; i++)
   {
      std::string first_name = "employee #" + std::to_string(i);
      std::string family_name = "Simpson";
      double salary = 200;
      person* p = new employee(first_name, family_name, salary);

      v.push_back( p );
   }

  

   // 2. Generate students at runtime   
   std::cout << "How many student shall be generated?" << std::endl;
   unsigned int nr_students;
   std::cin  >> nr_students;
   std::cout << "Ok, I will generate " << nr_students << " students!" << std::endl;

   for (int i=0; i<nr_students; i++)
   {
      std::string first_name = "student #" + std::to_string(i);
      std::string family_name = "Maier";
      uint matricle_nr = 123+i;
      person* p = new student(first_name, family_name, matricle_nr);

      v.push_back( p );
   }


   // 3. show how many pointers are stored in the vector
   std::cout << "In vector v there are " << v.size() << " pointers stored."
             << std::endl;


   // 4. output first name of all persons
   for (int i=0; i<v.size(); i++)
   {
      // get next pointer to person from vector
      person* p = v[i];

      std::cout << "First name of next person is "
                << p->get_first_name() << std::endl;

      p->do_something();
   }

  
}

