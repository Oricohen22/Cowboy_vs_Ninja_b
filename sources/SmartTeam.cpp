#include "Team.hpp"
#include "SmartTeam.hpp"
#include <algorithm>
#include <limits>
using namespace ariel;

SmartTeam::SmartTeam(Character *leader)
{
    members.push_back(leader);
}

// SmartTeam::~SmartTeam()
// {
//     for (auto member : members)
//     {
//         delete member;
//     }
// }

void SmartTeam::add(Character *Character)
{
}

void SmartTeam::attack(SmartTeam *enemy)
{
}

int SmartTeam::stillAlive() 
{
    return 0;
}

void SmartTeam::print(){
    
}