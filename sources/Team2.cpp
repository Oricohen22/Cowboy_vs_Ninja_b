#include "Team.hpp"
#include <algorithm>
#include"Team2.hpp"
#include <limits>
using namespace ariel;

Team2::Team2(Character *leader)
    : Team(leader)
{
}


void Team2::attack(Team* enemy) {
    if (enemy == nullptr) {
        throw invalid_argument("cant attack an empty team");
    }
    if (!this->stillAlive() || !enemy->stillAlive()) {
        throw runtime_error("no one in the team still alive");
    }

    // if (!enemy->getLeader()->isAlive()) {
    //     enemy->setLeader(enemy->findClosestCharacter(enemy->getLeader()));
    // }
    if(!(this->getLeader())->isAlive()){
    this->setLeader(findClosestCharacter(this->getLeader()));
    }
    Character* victim = enemy->findClosestCharacter(this->getLeader());
    Ninja* ninja;
    Cowboy* cowboy;

    
    for (Character* character : this->getMembers())
        {
        if(!character->isAlive())
            continue;
        victim = enemy->findClosestCharacter(this->getLeader());
        if (victim ==nullptr) return;
        if ((cowboy = dynamic_cast<Cowboy*>(character))) {
            if (cowboy->hasboolets()) {
                cowboy->shoot(victim);
            } else {
                cowboy->reload();
            }
        }
        if ((ninja = dynamic_cast<Ninja*>(character))) {
            if (ninja->distance(victim) < 1) {
                ninja->slash(victim);

            } else {
                ninja->move(victim);
            }
        }
    }
}


void Team2::print()
{
    for (size_t i = 0; i < this->getSize(); ++i)
    {

        cout << this->getMembers()[i]->print() << endl;
    }
}