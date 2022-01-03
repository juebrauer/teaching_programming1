#pragma once

#include "person.h"

#include <string>

class employee : public person
{   

   
   public:

      employee(std::string first_name, std::string family_name, double salary);

      double get_salary();

      void do_something();

   private:
      double salary;

};