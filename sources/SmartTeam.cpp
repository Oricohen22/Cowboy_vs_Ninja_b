#include "Team.hpp"
#include "SmartTeam.hpp"
#include <algorithm>
#include <limits>
using namespace ariel;

SmartTeam::SmartTeam(Character *leader)
    : Team(leader)
{
}

bool SmartTeam::compareCharactersByHealth(Character *character1,  Character *character2)
{
    return character1->getLife() < character2->getLife();
}

void SmartTeam::attack(Team* enemy)
{
    if (enemy == nullptr)
    {
        throw std::invalid_argument("Cannot attack an empty team");
    }
    if (!stillAlive() || !enemy->stillAlive())
    {
        throw std::runtime_error("No one in the team is still alive");
    }

    // Check if the leader is alive and find the closest character if not
    if (!getLeader()->isAlive())
    {
        setLeader(findClosestCharacter(getLeader()));
    }

    // Sort the team members by health in ascending order
    std::sort(getMembers().begin(), getMembers().end(), compareCharactersByHealth);

    // Loop over cowboys
    for (Character* character : getMembers())
    {
        if (!character->isAlive())
        {
            continue;
        }

        Cowboy* cowboy = dynamic_cast<Cowboy*>(character);
        if (cowboy != nullptr)
        {
            if (cowboy->hasboolets())
            {
                Character* victim = enemy->findClosestCharacter(getLeader());
                if (victim != nullptr)
                {
                    cowboy->shoot(victim);
                }
            }
            else
            {
                cowboy->reload();
            }
        }
    }

    // Loop over ninjas
    for (Character* character : getMembers())
    {
        if (!character->isAlive())
        {
            continue;
        }

        Ninja* ninja = dynamic_cast<Ninja*>(character);
        if (ninja != nullptr)
        {
            Character* victim = enemy->findWeakestAliveEnemy(getLeader());
            if (victim != nullptr)
            {
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
    }

    // Check if the enemy's leader is alive and find the closest character if not
    if (!enemy->getLeader()->isAlive())
    {
        enemy->setLeader(enemy->findWeakestAliveEnemy(enemy->getLeader()));
    }
}



Character* SmartTeam::findWeakestAliveEnemy(const std::vector<Character*>& enemyCharacters)
{
    Character* weakestEnemy = nullptr;
    int minHealth = std::numeric_limits<int>::max();

    for (Character* enemy : enemyCharacters)
    {
        if (enemy->isAlive() && enemy->getLife() < minHealth)
        {
            weakestEnemy = enemy;
            minHealth = enemy->getLife();
        }
    }

    return weakestEnemy;
}

