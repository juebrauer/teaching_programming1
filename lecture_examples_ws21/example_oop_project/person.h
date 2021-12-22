#pragma once

#include <iostream>
#include <string>

class person
{
   public:

      // constructor / Konstruktor
      person(std::string first_name, std::string family_name);
      ~person();
      
      std::string get_first_name();
      std::string get_family_name();
      bool set_first_name(std::string new_first_name);

   private: // access specifier
      std::string first_name;
      std::string family_name;
};