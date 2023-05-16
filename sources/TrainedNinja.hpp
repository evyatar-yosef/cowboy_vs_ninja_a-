#pragma once
#include "Ninja.hpp"
#include <iostream>
#include <string>
namespace ariel{

class TrainedNinja : public Ninja{

public:
    TrainedNinja(std::string name, Point location);

    int speed;
    int demage_point;



};
}