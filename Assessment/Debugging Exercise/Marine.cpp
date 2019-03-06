#include "Marine.h"
#include <iostream>
#include <ctime>



Marine::Marine()
{
	health = 50;
}


Marine::~Marine()
{
}

bool Marine::isAlive()
{
	return health > 0;
}

int Marine::attack()
{
	return rand() % 7 + 6;
}

void Marine::takeDamage(int damage)
{
	health -= damage;
	if (health <= 0)
		health = 0;
}


