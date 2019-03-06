#include "Entity.h"



Entity::Entity()
{
	health = 0;
}


Entity::~Entity()
{
}

int Entity::attack()
{
	return 10;
}

bool Entity::isAlive()
{

	if (health > 0) {
		return true;
	}
	else {
		return false;
	}

}
