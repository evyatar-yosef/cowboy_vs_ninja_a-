#pragma once
#include "point.hpp"
#include <string>
#include "Character.hpp"
 namespace ariel{


class Cowboy : public Character
{
private:
    

public:

int numOfBullets;
int demage_point;

Cowboy(std:: string name,Point location);
Cowboy() ;
Cowboy(const Cowboy&) = default;
Cowboy& operator=(const Cowboy&) = default;
Cowboy(Cowboy&&) = default;
Cowboy& operator=(Cowboy&&) = default;
~Cowboy() override = default;
void shoot(Character * enemy);
bool hasboolets();
void reload();
std::string print() override;
};
}



