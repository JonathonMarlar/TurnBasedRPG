#include "item.h"
#include <iostream>
#include <string>
using namespace std;


/*
Item: Default Constructor

Constructs a default Item class

---

Parameters: None
Returns: Item
*/
Item::Item()
{
	name = "Blank";
	effect = HEAL;
	value = 10;
	amount = 1;
}


/*
Item: Constructor

Constructs a custom Item class

---

Parameters: None
Returns: Item
*/
Item::Item(string n, int eff, int val, int amt)
{
	name = n;
	effect = eff;
	value = val;
	amount = amt;
}

// getter functions
string Item::get_name() { return name; }
int Item::get_effect() { return effect; }
int Item::get_value() { return value; }
int Item::get_amount() { return amount; }

// setter functions
bool Item::use_item()
{
	amount -= 1;
	return true;
}