/*
item.h

Used for declaration of Item class

"Item" classes are your traditional items in RPGs, used to
restore HP, cause extra damage, cure conditions, etc.

Once an item is used, it cannot be used again.
*/
#pragma once

#include <iostream>
#include <string>
using namespace std;


enum Effects
{
	HEAL = 0,
	ADD_PLAYER_DAMAGE,
	DEAL_DAMAGE
};


class Item
{
private:
	string name;
	int effect;
	int value;		// value is how much damange/HP/whatever it adds or subtracts
	int amount;		// this is how much of the item you have
public:
	Item();
	Item(string n, int eff, int val, int amt);

	// getter functions
	string get_name();
	int get_effect();
	int get_value();
	int get_amount();

	// setter functions
	bool use_item();
};