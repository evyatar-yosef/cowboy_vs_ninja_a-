
#include "Team.hpp"
using namespace ariel;

class Team2 : public Team {
public:
    // Constructor
    Team2(Character* leader){}
    Team2(){}
    // Destructor
    ~Team2(){}

    // Overridden methods from Team
    void add(Character* character) {}
    void attack(Team* enemy_team) {}
    int stillAlive() 
    {
        return 0;
    }
    void print() {}
};
