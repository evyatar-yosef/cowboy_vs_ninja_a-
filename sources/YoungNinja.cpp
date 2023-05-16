#include "YoungNinja.hpp"
using namespace ariel;

YoungNinja::YoungNinja (std::string name, Point location):Ninja(name,location)

{
    this -> speed = 12;
    this -> demage_point = 120;
}