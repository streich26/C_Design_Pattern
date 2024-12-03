#include <iostream>
#include <vector>

using namespace std;

class Creature
{
public:
	int Attack, Health;
	Creature(int attack, int health)
	{
		Attack = attack;
		Health = health;
	}
		
};
class CardGame
{
public:
	vector<Creature> Creatures;
	CardGame(const vector<Creature>& creatures)
	{
		Creatures = creatures;
	}
	int Combat(int creature1, int creature2)
	{

	}

};

int main()
{

}