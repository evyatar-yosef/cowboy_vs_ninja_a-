#pragma once
#include "Ninja.hpp"
#include <iostream>
#include <string>

 namespace ariel{ 

class OldNinja : public Ninja{

public:
    OldNinja(std::string name, Point location);
    int speed;
    int demage_point;



};
}