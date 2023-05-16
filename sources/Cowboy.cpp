#include "Cowboy.hpp"
using namespace ariel;


Cowboy :: Cowboy(std:: string name,Point location):Character(name,location)
{
     this->numOfBullets = 6;
     this->demage_point = 110;
}

Cowboy :: Cowboy()
{
     this-> name = "clint eastwood";
     this-> location = Point();
     this->numOfBullets = 0;
     this->demage_point = 0;
}

void Cowboy:: shoot(Character * enemy)
{

}

bool Cowboy:: hasboolets()
{
    return false;
}

void Cowboy:: reload()
{

}
std::string Cowboy:: print()
{
    return "";
}
