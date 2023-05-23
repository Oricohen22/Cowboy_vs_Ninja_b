#pragma once
#include "Point.hpp"
#include <string>

using namespace std;
namespace ariel
{

    class Character
    {
    private:
        string name;
        Point location;
        int life;
        bool inTeam;

    public:
        Character(string name,Point location, int life);
        Character();
        Character(const Character &) = delete;            
        Character &operator=(const Character &) = delete; 
        Character(Character &&) = delete;                 
        Character &operator=(Character &&) = delete;     

        
        virtual ~Character() = default;
        virtual string print() = 0;  //abstruct method 
        bool isAlive();
        double distance(Character *character) const;
        void hit(int hit_num);

        //getters and setters
        string getName();
        int getLife();
        bool getInTeam();
        void setInTeam(bool status);
        Point getLocation()const;
        void setName(string & Name_);
        void setLocation(const Point &location);
        void setLife(int life_);
        
    };
}