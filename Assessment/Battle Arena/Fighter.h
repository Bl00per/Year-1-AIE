#pragma once

#include <string>

const size_t buffer_length = 80;

class Fighter
{
public:
	Fighter();

	Fighter(std::string a_name, std::string a_weapon);

	// Name and health Accessors
	const int get_health() const;
	const int get_min_damage() const;
	const int get_max_damage() const;
	const int get_damage();
	const std::string get_name() const;
	const std::string get_weapon() const;

	void attack(Fighter& a_target) const;

	bool isDead = false;

private:
	// Fighter health = 100%
	int health;
	// Minimum damage the Fighter can do = 5
	int min_damage;
	// Maximum damage the Fighter can do = 100
	int max_damage;
	int damage;
	// Stores the weapon name
	std::string weapon;
	// Stores the Fighter's name
	std::string name;

	void take_damage(const int a_damage);
};
