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

using namespace std;
namespace ariel
{
    class Team
    {
    private:
        std::vector<Character *> Team_members;
        Character *leader;
        size_t size;

    public:
        Team(Character *leader);
        virtual ~Team();
        Team(const Team &) = delete;
        Team &operator=(const Team &) = delete;
        Team(Team &&) = delete;
        Team &operator=(Team &&) = delete;
        virtual void add(Character *character);
        virtual void attack(Team *enemy);
        int stillAlive();
        
        Character* findClosestCharacter(Character *myLeader);
        virtual void print();
        // getters & setters
        Character* getLeader();
        size_t getSize();
        void setLeader(Character *newLeader);
        vector<Character*>getMembers() const;
    };
}
