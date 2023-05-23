#pragma once
#include <string>
#include <iostream>
#include "Character.hpp"
using namespace std;

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(string name,Point location,int life,int speed);
        void move(Character *enemy);
        void slash(Character *enemy);
        string print()override;
        int getSpeed();
    };


}
