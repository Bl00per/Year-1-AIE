// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

#include <iostream>
#include <vector>
#include <ctime>
#include <Windows.h>
#include "Marine.h"
#include "Zergling.h"

using std::vector;
using std::cout;
using std::endl;

bool marineAlive(vector<Marine> squad);
bool zerglingAlive(vector<Zergling> swarm);


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	vector<Marine> squad;
	vector<Zergling> swarm;

	// Initial squad and swarm sizes
	int squadSize = 10;
	int swarmSize = 20;

	// Set random value based on system time
	srand((unsigned int)time(NULL));

	// Set up the Squad and the Swarm at their initial sizes listed above
	for (int i = 0; i < squadSize; i++)
	{
		Marine m;
		squad.push_back(m);
	}


	for (int i = 0; i < swarmSize; i++)
	{
		Zergling z;
		swarm.push_back(z);
	}

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	// Attack each other until only one team is left alive
	while (marineAlive(squad) && zerglingAlive(swarm)) // If anyone is left alive to fight . . .
	{
		for (int i = 0; i < squadSize; i++) // go through the squad
		{
			if (zerglingAlive(swarm)) // if there's at least one marine alive
			{
				// each marine will attack the first zergling in the swarm
				cout << "A marine fires for " << squad[i].attack() << " damage.\n" << endl;
				int damage = squad[i].attack();
				swarm[0].takeDamage(damage);
				if (!swarm[0].isAlive()) // if the zergling dies, it is removed from the swarm
				{
					// If a zergling dies, decrease the swarm size & remove it from the vector array
					swarmSize--;
					cout << " ---The zergling target dies, " << swarmSize << " left---" << endl;
					swarm.erase(swarm.begin());
				}
			}
			Sleep(100);
		}
		
		// Lets the user know Zerglings are attacking next and waits for user input
		std::cout << "Marine attack complete. Commencing Zerg assault.\n";
		system("Pause");

		for (int i = 0; i < swarmSize; i++) // go through the squad
		{
			if (marineAlive(squad)) // if there's at least one zergling alive
			{
				// each zergling will attack the first marine in the swarm
				cout << "A zergling attacks for " << swarm[i].attack() << " damage.\n" << endl;
				int damage = swarm[i].attack();
				squad[0].takeDamage(damage);
				if (!squad[0].isAlive()) // if the marine dies, it is removed from the swarm
				{
					// If a marine dies, decrease the squad size & remove it from the vector array
					squadSize--;
					cout << " ---The marine target dies, " << squadSize << " left---" << endl;
					squad.erase(squad.begin());
				}
			}
			// Little bit of breathing room instead of an immediate wall of text
			Sleep(100);
		}

		// Lets the user know Marines are attacking next and waits for user input
		std::cout << "Zergling assualt complete. Launching counterattack.\n";
		system("Pause");
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "\nThe fight is over. ";
	if (marineAlive(squad))
	{
		cout << "The Marines win." << endl;
	} else 
	{
		cout << "The Zerg win." << endl;
	}

	std::cout << '\n';
	std::cin.get();
}

// Is there a Marine Alive?
bool marineAlive(vector<Marine> squad)
{
	return squad.size();
}

// Is there a zergling Alive
bool zerglingAlive(vector<Zergling> swarm)
{
	return swarm.size();
}
