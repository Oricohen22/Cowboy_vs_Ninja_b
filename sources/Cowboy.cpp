#include "Character.hpp"
#include "Cowboy.hpp"
#include "Point.hpp"

using namespace ariel;

Cowboy::Cowboy(string name, Point location)
    : Character(name, location, 110),bullets(6)
{
}
void Cowboy::shoot(Character *enemy)
{
    if(bullets <=0){
        return;
    }
    if(this == enemy){
        throw runtime_error("no self harm");
    }
    if (!isAlive())
        throw runtime_error("Cowboy is dead");
    if (!enemy->isAlive())
        throw runtime_error("Enemy is dead cowboy");
    enemy->hit(10);
    this->bullets--;
}

bool Cowboy::hasboolets()
{
    if (this->getBullets() > 0)
    {
        return true;
    }
    return false;
}

void Cowboy::setBullet(int number){
    if(number > 0)
    {
        this->bullets = number;
    }
}

void Cowboy::reload()
{
    if (!isAlive())
    {
        throw runtime_error("cowboy is dead");
    }
    this->setBullet(6);
}

string Cowboy::print()
{
    if (isAlive())
        return "name: C" + getName() + ", life-- " + to_string(getLife()) +
               ", location: " + getLocation().print();
    return "name: (C" + getName() + "), location: " + getLocation().print();
}



int Cowboy::getBullets()
{
    return this->bullets;
}
