#pragma once
#include "Character.hpp"
using namespace std;

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        Cowboy(string, Point);
        void shoot(Character *) ;
        int getBullets();
        bool hasboolets() ;
        void reload();
        void setBullet(int number);
        string print()override;
        
    };
}