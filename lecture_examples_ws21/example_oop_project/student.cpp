#include "student.h"


student::student(std::string first_name, std::string family_name, uint matricle_nr) :
         person(first_name, family_name)
{
    this->matricle_nr = matricle_nr;
}


uint student::get_matricle_nr()
{
    return matricle_nr;
}

bool student::set_matricle_nr(uint new_matricle_nr)
{
    if ((new_matricle_nr == 0) || (new_matricle_nr > 1000000))
    return false;

    this->matricle_nr = new_matricle_nr;
    return true;
}


void student::augment_first_name()
{
    //this->first_name = "Student " + this->first_name;
    this->set_first_name( "Student " + this->get_first_name() );
}

void student::do_something()
{
    std::cout << "I am studying for the winter exams ..." << std::endl;
}
