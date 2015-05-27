#include "entity.h"
#include <iostream>
#include <string>
using namespace std;

/*
Entity: Default Constructor

Constructs a default Entity class

---

Parameters: None
Returns: Entity
*/
Entity::Entity()
{
	name = "DNE";
	hp = 10;
}


/*
Entity: Constructor

Constructs a custom Entity class

---

Parameters: string for the entity's name and an int for
			its health
Returns: Entity
*/
Entity::Entity(string name, int hp)
{
	this->name = name;
	this->hp = hp;
}


/*
Entity: get_name

Gets the name of an entity

---

Parameters: None
Returns: int
*/
string Entity::get_name()
{
	return name;
}

/*
Entity: set_name

Sets the name of an entity

---

Parameters: A string for the name
Returns: true
*/
bool Entity::set_name(string n)
{
	name = n;
	return true;
}


/*
Entity: get_hp

Gets the HP of an entity

---

Parameters: None
Returns: int
*/
int Entity::get_hp()
{
	return hp;
}


/*
Entity: set_hp

Sets the HP of an entity

---

Parameters: int for hp
Returns: true
*/
bool Entity::set_hp(int n)
{
	hp = n;
	return true;
}