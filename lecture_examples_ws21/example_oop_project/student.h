#pragma once

#include "person.h"

#include <string>


class student : public person
{
   public:

      student(std::string first_name, std::string family_name, uint matricle_nr);

      uint get_matricle_nr();

      bool set_matricle_nr(uint new_matricle_nr);

      void augment_first_name();

      void do_something();


   private:

      uint matricle_nr;

};