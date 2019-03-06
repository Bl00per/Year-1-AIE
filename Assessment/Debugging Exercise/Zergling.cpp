#include "Zergling.h"
#include <iostream>



Zergling::Zergling()
{
	health = 20;
}


Zergling::~Zergling()
{
}

// Check if the zergling is alive
bool Zergling::isAlive()
{
	return health > 0;
}

// Set a random attack value for the zergling between 5 and 8
int Zergling::attack()
{
	return rand() % 5 + 4;
}

void Zergling::takeDamage(int damage)
{
	// If the zerglings health falls into the negatives, set it to 0
	health -= damage;
	if (health <= 0)
		health = 0;
}


