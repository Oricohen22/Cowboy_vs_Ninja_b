#include "Ninja.hpp"
using namespace ariel;

Ninja::Ninja(string name, Point location, int life, int speed) : Character(name, location, life), speed(speed)
{
}

void Ninja::move(Character *enemy)
{
    this->setLocation(this->getLocation().moveTowards(this->getLocation(), enemy->getLocation(), this->speed));
}

void Ninja::slash(Character *enemy)
{
     if(this == enemy){
        throw runtime_error("try to attack himself");
    }
    if (!isAlive())
        throw runtime_error("ninja is dead");
    if (!enemy->isAlive())
        throw runtime_error("Enemy is dead ");
    if (isAlive() && getLocation().distance(enemy->getLocation()) < 1)
        enemy->hit(40);
}


int Ninja::getSpeed()
{
    return this->speed;
}

string Ninja::print()
{
    if (isAlive())
        return "name: N" + getName() + ", health: " + to_string(getLife()) +
               ", location: " + getLocation().print();
    return "name: (N" + getName() + "), location: " + getLocation().print();
}
