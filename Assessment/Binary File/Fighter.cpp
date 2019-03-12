#include "Fighter.h"
#include <iostream>
#include <ctime>

Fighter::Fighter()
{
}


Fighter::Fighter(std::string a_name, std::string a_weapon)
{
	health = 100;
	min_damage = 5;
	max_damage = 95;

	damage = rand() % max_damage + min_damage;

	weapon = a_weapon;
	name = a_name;
}

const int Fighter::get_health() const
{
	return health;
}

const int Fighter::get_min_damage() const
{
	return min_damage;
}

const int Fighter::get_max_damage() const
{
	return max_damage;
}

const int Fighter::get_damage()
{
	return damage;
}
const std::string Fighter::get_name() const
{
	return name;
}

const std::string Fighter::get_weapon() const
{
	return weapon;
}

void Fighter::take_damage(const int a_damage)
{
	health -= a_damage;
	// If characters health goes into the negative, set to 0
	if (health <= 0)
	{
		health = 0;
		isDead = true;
		std::cout << "\n--- " << name << " has died!---\n\n";
	}
}


void Fighter::attack(Fighter& a_target) const
{
	a_target.take_damage(damage);
	std::cout << "\n" << name << " attacks " << a_target.name <<
		" with " << weapon << " and inflicts " << damage
		<< " damage.\n";
}
