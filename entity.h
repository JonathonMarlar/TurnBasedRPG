/*
entity.h

Used for declaration of Entity class.

"Entity" classes are player and enemy party members in combat. They have their
own name and HP which represents how much damange they can take in battle.
*/
#pragma once

#include <iostream>
#include <string>
using namespace std;

class Entity
{
private:
	string name;
	int hp;

public:
	Entity();
	Entity(string, int);

	string get_name();
	bool set_name(string);

	int get_hp();
	bool set_hp(int);
};