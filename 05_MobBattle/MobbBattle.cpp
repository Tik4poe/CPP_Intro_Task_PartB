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
		name == nme;
		health == hlth;
		damage == dmg;
	}

	int Attack(mob target)
	{
		target.health -= damage;
		cout << "The " << name << " hit the " << target.name << " for " << damage << " damage." << endl;
	}
};

void Battle(mob a, mob b);

int rng = rand() % 2;

int main()
{

}

void Battle(mob a, mob b)
{
	if (rng == 1)
	{
		a.Attack(b);
	}
	else
	{
		b.Attack(a);
	}
}