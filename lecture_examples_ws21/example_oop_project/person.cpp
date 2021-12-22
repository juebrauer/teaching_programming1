#include "person.h"


// constructor / Konstruktor
person::person(std::string first_name, std::string family_name)
{
    std::cout << "A new person object is created!\n";  


    this->family_name = family_name;
    this->first_name  = first_name;                
}


// destructor / Destruktor
person::~person()
{
    std::cout << "A person object is being deleted\n";
}

std::string person::get_first_name()
{
    return first_name;
}

std::string person::get_family_name()
{
    return family_name;
}

bool person::set_first_name(std::string new_first_name)
{
    if (new_first_name == "")
    {
    std::cout << "You are not allowed to specify an empty name!\n";
    return false;
    }
    this->first_name = new_first_name;
    return true;
}