#include <iostream>
#include <cassert>

using namespace std;

struct mob
{
	string name = "";
	int health = 0;
	int damage = 0;

	mob(string nme, int hlth, int dmg)
	{
		name = nme;
		health = hlth;
		damage = dmg;
	}

	void Attack(mob &target)
	{
		target.health -= damage;
		cout << "|==================================================|" << endl;
		cout << "The " << name << " hit the " << target.name << " for " << damage << " damage." << endl;
		cout << target.name << " has " << target.health << " health left." << endl;
		cout << "|==================================================|" << endl;
	}
};

void Battle(mob* a, mob* b);

int rng = rand() % 2;

int main()
{
	bool isBattling = true;

	int round = 1;
	int finalRound = 50;
	
	mob kuri = { "Liara", 250, 10 };

	mob ngeru = {"Millie", 300, 12};

	while (round < finalRound && isBattling)
	{
		cout << "Round: " << round << endl;
		Battle(&kuri,&ngeru);
		round++;
		if (kuri.health <= 0 || ngeru.health <= 0)
		{
			if (ngeru.health > kuri.health)
			{
				cout << "\n|==================================================|\n";
				cout << ngeru.name << " has won" << " at round " << round << endl;
				isBattling = false;
			}
			else if (kuri.health > ngeru.health)
			{
				cout << "\n|==================================================|\n";
				cout << kuri.name << " has won" << " at round " << round << endl;
				isBattling = false;
			}
			else
			{
				cout << "\n|==================================================|\n";
				cout << ngeru.name << " and " << kuri.name << " are even" << " at round " << round << endl;
				isBattling = false;
			}
		}
		else if (round == finalRound)
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
				cout << ngeru.name << " and " << kuri.name << " have drew in the final round" << round << endl;
			}
		}
	}

	cout << "\n|==================== END ==============================|\n";

}

void Battle(mob* a, mob* b)
{
	if (rng == 1)
	{
		a->Attack(*b);
	}
	else
	{
		b->Attack(*a);
	}
}