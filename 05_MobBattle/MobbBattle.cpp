#include <iostream>
#include <cassert>

using namespace std;

struct mob
{
	// stats
	string name = "";
	int health = 0;
	int damage = 0;

	// constructor
	mob(string nme, int hlth, int dmg)
	{
		name = nme;
		health = hlth;
		damage = dmg;
	}

	// attack function
	void Attack(mob &target)
	{
		target.health -= damage;
		cout << "|==================================================|" << endl;
		cout << "The " << name << " hit the " << target.name << " for " << damage << " damage." << endl;
		cout << target.name << " has " << target.health << " health left." << endl;
		cout << "|==================================================|" << endl;
	}
};

void Battle(mob* a, mob* b);// declaration

int rng = rand() % 2;// simple randomizer

int main()
{
	bool isBattling = true;

	// round variables
	int roundCurrent = 1;
	int finalRound = 50;
	
	// the mods to fight
	mob kuri = { "Liara", 250, 10 };
	mob ngeru = {"Millie", 300, 12};

	// battle loop
	while (roundCurrent < finalRound && isBattling)
	{
		// outputs the current round, calls Battle, increments the current round
		cout << "round: " << roundCurrent << endl;
		Battle(&kuri,&ngeru);
		roundCurrent++;
		// checks is some has won the Battle
		if (kuri.health <= 0 || ngeru.health <= 0)// if wither fighter has reached 0 health
		{
			if (ngeru.health > kuri.health)
			{
				cout << "\n|==================================================|\n";
				cout << ngeru.name << " has won" << " at round " << roundCurrent << endl;
				isBattling = false;
			}
			else if (kuri.health > ngeru.health)
			{
				cout << "\n|==================================================|\n";
				cout << kuri.name << " has won" << " at round " << roundCurrent << endl;
				isBattling = false;
			}
			else
			{
				cout << "\n|==================================================|\n";
				cout << ngeru.name << " and " << kuri.name << " are even" << " at round " << roundCurrent << endl;
				isBattling = false;
			}
		}
		else if (roundCurrent == finalRound)// if fighters are still alive at the end of the round who ever has the most health wins
		{
			if (ngeru.health > kuri.health)
			{
				cout << "\n|==================================================|\n";
				cout << ngeru.name << " in the final round has won" << endl;
			}
			else if (kuri.health > ngeru.health)
			{
				cout << "\n|==================================================|\n";
				cout << kuri.name << " in the final round has won" << endl;
			}
			else
			{
				cout << "\n|==================================================|\n";
				cout << ngeru.name << " and " << kuri.name << " have drew in the final round" << roundCurrent << endl;
			}
		}
	}

	cout << "\n|==================== END ==============================|\n";

}

void Battle(mob* a, mob* b)
{
	if (rng == 1)// if rnd is 1 mob a attack if not b
	{
		a->Attack(*b);
	}
	else
	{
		b->Attack(*a);
	}
}