#include "Character.hpp"
using namespace ariel;

Character::Character(string name, Point location, int life)
{
    this->name = name;
    this->location = location;
    this->life = life;
    this->inTeam = false;
}

Character::Character()
{
    location = Point();
    name = "Bob";
}

bool Character::isAlive()
{
    
    if (this->life > 0)
    {
        return true;
    }
    return false;
}

double Character::distance(Character *character) const
{
    return this->location.distance(character->location);
}

void Character::hit(int damage)
{
    if (damage < 0)
        throw invalid_argument("the damage cant be less than 0");

    if (this->life < damage)
    {
        life = 0;
    }
    else if (life >= damage)
    {
        this->life = life - damage;
    }
}

string Character::getName()
{
    return name;
}

int Character::getLife()
{
    return this->life;
}

Point Character::getLocation() const
{
    return this->location;
}

bool Character::getInTeam(){
    return inTeam;
}

void Character::setInTeam(bool status){
    inTeam = status;
}

void Character::setName(string &Name_)
{
    this->name = Name_;
}

void Character::setLocation(const Point &location)
{
    Character::location = location;
}

void Character::setLife(int life_)
{
    this->life = life_;
}