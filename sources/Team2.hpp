#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Point.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {

    public:
        Team2(Character *leader);
        // void add(Character *character);
        void attack(Team *enemy)override;
        // int stillAlive();
        void print() override;
    };
}
