#pragma once
#include "Entity.h"

class Marine : public Entity
{
public:
	Marine();
	~Marine();

	bool isAlive();
	int attack();
	void takeDamage(int damage);

private:
	int health;

};

