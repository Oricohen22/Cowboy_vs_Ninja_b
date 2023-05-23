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

namespace ariel {
    class SmartTeam {
    private:
        std::vector<Character*> members;
    public:
        SmartTeam(Character* leader); 
        // ~SmartTeam();
        void add(Character* character);
        void attack(SmartTeam* enemy);
        int stillAlive() ;
        void print() ;
    };
}
