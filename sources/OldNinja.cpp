#include "OldNinja.hpp"
using namespace ariel;


OldNinja::OldNinja (std::string name, Point location):Ninja(name,location)

{
    this -> speed = 8;
    this -> demage_point = 150;
}

