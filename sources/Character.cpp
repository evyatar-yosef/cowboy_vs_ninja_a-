#include "Character.hpp"
#include <cmath>
#include <iostream>
using namespace ariel;

    
    Character::Character(std:: string name,Point location)
    {
        this-> name = name;
        this-> location = location;
        //this->hit_points = 0; 
    }
    Character::Character()
    {
     //   this->hit_points =0 ;

    }
    
    bool Character:: isAlive()
    {
        return false;
    }
    double Character:: distance(Character * other)
    {
        return 0;
    }
    void Character:: hit(int demage)
    {

    }
    std:: string Character:: getName()
    {
        return name;
    }
    Point Character:: getLocation()
    {
        return Point();
    }
    std::string  Character::print()
    {
        return "";
    }
