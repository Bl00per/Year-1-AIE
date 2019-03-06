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

// Check if the marine is alive
bool Marine::isAlive()
{
	return health > 0;
}

// Set a random attack value for the marine between 6 and 12
int Marine::attack()
{
	return rand() % 7 + 6;
}

void Marine::takeDamage(int damage)
{
	// If the marines health falls into the negatives, set it to 0
	health -= damage;
	if (health <= 0)
		health = 0;
}


