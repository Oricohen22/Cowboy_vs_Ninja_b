#pragma once
#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *leader);
        // virtual
        void attack(Team *enemy) override;
        // void print() override;
        // Declaration
        static  bool compareCharactersByHealth(Character *character1, Character *character2);
        Character* findWeakestAliveEnemy(const std::vector<Character*>& enemyCharacters);
    };

}