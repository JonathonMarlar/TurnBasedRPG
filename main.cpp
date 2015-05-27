#include "entity.h"
#include "item.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
using namespace std;

const int PLAYER_DAMAGE = 10;

int main(int argc, char** argv)
{
	// randomizer
	srand(time(NULL));

	// get the player's name
	string n;
	cout << "What is your name?" << endl << ": ";
	cin >> n;

	// make a player
	Entity player(n, 200);

	// make a player inventory
	vector<Item> inventory;

	Item potion("Potion", HEAL, 100, 3);
	inventory.push_back(potion);
	Item thunder("Thunder Flask", DEAL_DAMAGE, 10, 1);
	inventory.push_back(thunder);

	// make a list of enemies
	vector<Entity> enemies;

	Entity monster("Monster", 20);
	enemies.push_back(monster);
	Entity sea_creature("Sea Creature", 40);
	enemies.push_back(sea_creature);
	Entity ghost("Ghost", 30);
	enemies.push_back(ghost);

	// check if player ran away
	bool ran_away = false;

	// main battle loop
	cout << "Enemies!!" << endl;

	// Declare the battle cries!
	for (int i = 0; i < enemies.size(); i++)
	{
		cout << "An enemy " << enemies[i].get_name() << " appeared!" << endl;
	}

	// Loop until the game is over
	while (enemies.size() != 0)
	{
		// print stats
		cout << player.get_name() << ": " << player.get_hp() << endl << endl;
		for (int i = 0; i < enemies.size(); i++)
		{
			cout << enemies[i].get_name() << ": " << enemies[i].get_hp() << endl;
		}


		// Player's turn
		char choice;
		cout << "What will " << player.get_name() << " do?" << endl;
		cout << "A -- Attack" << endl;
		cout << "I -- Use Item" << endl;
		cout << "E -- Escape" << endl;
		cin >> choice;

		// Carry out player's choice
		switch (choice)
		{
			case 'A':
			{
				// Pick a target
				int target;
				cout << "Select an enemy to attack" << endl;
				for (int i = 0; i < enemies.size(); i++)
					cout << i << ": " << enemies[i].get_name() << endl;
				cin >> target;

				// Attack!
				system("clear");
				int p_damage = PLAYER_DAMAGE + (rand() % 5);
				cout << player.get_name() << " attacks " << enemies[target].get_name() << "! Deals " << p_damage << " damage!" << endl;
				int enemy_hp = enemies[target].get_hp() - p_damage;
				enemies[target].set_hp(enemy_hp);

				// Destroy the enemy if their HP is zero.
				if (enemies[target].get_hp() <= 0)
				{
					cout << player.get_name() << " defeated " << enemies[target].get_name() << "!" << endl;
					enemies.erase(enemies.begin() + target);
				}
			} break;
			case 'I':
			{
				// pick an item
				if (inventory.size() > 0)
				{
					int choice;
					cout << "Pick an item from your inventory: " << endl;
					for (int i = 0; i < inventory.size(); i++)
					{
						cout << i << ": " << inventory[i].get_name() << " x " << inventory[i].get_amount() << endl;
					}
					cout << ": ";
					cin >> choice;

					// use it
					system("clear");
					if (inventory[choice].get_effect() == HEAL)
					{
						cout << player.get_name() << " used a " << inventory[choice].get_name() << "! Healed for " << inventory[choice].get_value() << " points!" << endl;
						int n = player.get_hp() + inventory[choice].get_value();
						player.set_hp(n);

					}
					else if (inventory[choice].get_effect() == DEAL_DAMAGE)
					{
						cout << player.get_name() << " used a " << inventory[choice].get_name() << "! Thunder eroded the sky!" << endl;

						// deal damage to enemies
						for (int i = 0; i < enemies.size(); i++)
						{
							cout << "Dealt " << inventory[choice].get_value() << " damage to " << enemies[i].get_name() << "!" << endl;
							int enemy_hp = enemies[i].get_hp() - inventory[choice].get_value();
							enemies[i].set_hp(enemy_hp);

							// delete enemies from the list if they are defeated
							if (enemies[i].get_hp() <= 0)
							{
								cout << player.get_name() << " defeated " << enemies[i].get_name() << "!" << endl;
								enemies.erase(enemies.begin() + i);
							}
						}
					}

					// remove it from inventory if we don't have any more
					inventory[choice].use_item();
					if (inventory[choice].get_amount() == 0)
							inventory.erase(inventory.begin() + choice);
				}
				else
					cout << player.get_name() << " had no items and wasted time!" << endl;
				
			} break;
			case 'E':
			{
				// Run away
				cout << player.get_name() << " tried to run away!" << endl;
				enemies.clear();
				ran_away = true;
			} break;
		}

		// Enemies' turn
		for (int i = 0; i < enemies.size(); i++)
		{
			// random special attack
			int chance = (rand() % 10) + 1;
			int damage = 0;
			if (chance > 7)
			{
				damage = (rand() % 25) + 10;
				if (enemies[i].get_name() == "Monster")
					cout << "Monster let out a powerful roar! Deals " << damage << " damage to " << player.get_name() << "!" << endl;
				else if (enemies[i].get_name() == "Sea Creature")
					cout << "Sea Creature caused a typhoon! Deals " << damage << " damage to " << player.get_name() << "!" << endl;
				else if (enemies[i].get_name() == "Ghost")
					cout << "Ghost turned invisible for a sneak attack! Deals " << damage << " damage to " << player.get_name() << "!" << endl;
			}
			else
			{
				// normal attack
				damage = rand() % 20 + 1;
				cout << enemies[i].get_name() << " attacks! Deals " << damage << " damage to " << player.get_name() << "!" << endl;
			}
			// calculate damage
			int player_hp = player.get_hp() - damage;
			player.set_hp(player_hp);
		}

		// Check if the game is over
		if (player.get_hp() <= 0)
		{
			cout << player.get_name() << " is defeated! Game over, man! Game over!!" << endl;
			enemies.clear();
		}
		else if (enemies.size() == 0 && ran_away == false)
		{
			cout << player.get_name() << " won the battle!! Good job!!" << endl;
		}
		else if (ran_away == true)
		{
			cout << player.get_name() << " got away!" << endl;
		}
	}
	
	return 0;
}