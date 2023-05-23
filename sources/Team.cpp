#include "Team.hpp"
#include <algorithm>
#include <limits>
using namespace ariel;
using namespace std;

Team::Team(Character *leader) : leader(leader)
{
    if (leader->getInTeam())
    {
        throw runtime_error("Leader is already on a team");
    }
    if (!leader->isAlive())
    {
        throw runtime_error("Leader is dead");
    }

    Team_members.push_back(leader);
    leader->setInTeam(true);
    this->leader = leader;
    size = 1;
}

Team::~Team()
{
    for (Character *character : this->Team_members)
    {
        delete character;
    }
}
vector<Character *> Team::getMembers() const
{
    vector<Character *> members;
    for (Character *character : Team_members)
    {
        members.push_back(character);
    }
    return members;
}

void Team::add(Character *character)
{
    if (Team_members.size() == 10 || character->getInTeam())
        throw runtime_error(
            "the character alreeady in team or there is 10 character already");
    Team_members.push_back(character);
    character->setInTeam(true);
}

Character *Team::getLeader()
{
    return this->leader;
}

void Team::attack(Team *enemy)
{
    if (enemy == nullptr)
    {
        throw invalid_argument("cant attack an empty team");
    }
    if (!this->stillAlive() || !enemy->stillAlive())
    {
        throw runtime_error("no one in the team still alive");
    }
    if(!(this->leader)->isAlive()){
    this->leader = findClosestCharacter(this->leader);
    }
    

    Ninja *ninja;
    Cowboy *cowboy;

    // Loop over cowboys
    for (Character *character : Team_members)
    {

        if (!character->isAlive())
            continue;
        if ((cowboy = dynamic_cast<Cowboy *>(character)))
        {
            if (cowboy->hasboolets())
            {
                Character *victim = enemy->findClosestCharacter(this->leader);
                if (victim == nullptr)
                    return;

                cowboy->shoot(victim);
            }
            else
            {
                cowboy->reload();
            }
        }
    }

    // Loop over ninjas
    for (Character *character : Team_members)
    {
        if (!character->isAlive())
            continue;

        if ((ninja = dynamic_cast<Ninja *>(character)))
        {
            Character *victim = enemy->findClosestCharacter(this->leader);
            if(victim == nullptr) return;
            if (ninja->distance(victim) < 1)
            {
                ninja->slash(victim);
            }
            else
            {
                ninja->move(victim);
            }
        }
    }
    if (!enemy->getLeader()->isAlive())
    {
        enemy->setLeader(enemy->findClosestCharacter(enemy->getLeader()));
    }
}

int Team::stillAlive()
{
    int alive_mem = 0;
    // iterate over all team members
    for (auto ptr : this->Team_members)
    {
        if (ptr->isAlive())
        {
            alive_mem++;
        }
    }
    return alive_mem;
}

size_t Team::getSize()
{
    return this->size;
}

Character* Team::findClosestCharacter(Character* myLeader) {
    double minDistance = std::numeric_limits<double>::max();
    Character* closestCharacter = nullptr;

    for (Character* character : Team_members) {
        if (character->isAlive()) { // Add this condition to consider only alive characters
            double distance = myLeader->distance(character);
            if (distance < minDistance) {
                minDistance = distance;
                closestCharacter = character;
            }
        }
    }

    return closestCharacter;
}

void Team::print()
{
    cout << "Team details:" << endl;
    for (Character *member : Team_members)
    {
        if (Ninja *ninja = dynamic_cast<Ninja *>(member))
        {
            cout << ninja->print() << endl;
        }
    }

    for (Character *member : Team_members)
    {
        if (Cowboy *cowboy = dynamic_cast<Cowboy *>(member))
        {
            cout << cowboy->print() << endl;
        }
    }
}

void Team::setLeader(Character *new_leader)
{
    this->leader = new_leader;
}