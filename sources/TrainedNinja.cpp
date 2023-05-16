#include "TrainedNinja.hpp"
using namespace ariel;


TrainedNinja::TrainedNinja (std::string name, Point location):Ninja(name,location)

{
    this -> speed = 12;
    this -> demage_point = 120;
}