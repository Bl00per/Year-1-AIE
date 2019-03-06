#pragma once
class Entity
{
public:
	Entity();
	~Entity();

	virtual int attack();
	virtual void takeDamage(int damage) = 0;
	virtual bool isAlive();

private:
	int health;
};

