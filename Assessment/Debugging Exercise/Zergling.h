#pragma once

#include "Entity.h"
class Zergling : public Entity
{
public:
	Zergling();
	~Zergling();

	bool isAlive();
	int attack();
	void takeDamage(int damage);

private:
	int health;
};



