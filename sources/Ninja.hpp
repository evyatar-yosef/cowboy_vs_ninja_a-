#pragma once
#include "Character.hpp"
#include <string>
#include "point.hpp" 
 namespace ariel{ 

class Ninja : public Character
{
private:    

public:
Ninja (std :: string name, Point location);

int speed;
int demage_point;

void move(Character * enemy);
void slash(Character * enemy);
std::string print() override;


};
 }