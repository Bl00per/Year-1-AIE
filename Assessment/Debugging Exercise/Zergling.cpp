#include "Zergling.h"
#include <iostream>



Zergling::Zergling()
{
	health = 20;
}


Zergling::~Zergling()
{
}

bool Zergling::isAlive()
{
	return health > 0;
}

int Zergling::attack()
{
	return rand() % 5 + 4;
}

void Zergling::takeDamage(int damage)
{
	health -= damage;
	if (health <= 0)
		health = 0;
}


