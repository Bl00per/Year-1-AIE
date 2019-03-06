#include "Fighter.h"
#include <iostream>
#include <ctime>
//#include <crtdbg.h>

void BubbleSort(Fighter fighterArray[], int teamSize);


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned int)time(NULL));

	const size_t team_size = 6;

	Fighter team_one[team_size];
	Fighter team_two[team_size];



	// Assigned 'Team 1' with appropriate weapons/abilities
	team_one[0] = Fighter("Ironman", "Unibeam");
	team_one[1] = Fighter("War Machine", "Missle Launchers");
	team_one[2] = Fighter("Black Widow", "Black Widow's Bite");
	team_one[3] = Fighter("Black Panther", "Claws");
	team_one[4] = Fighter("The Vision", "Energy Blast");
	team_one[5] = Fighter("Spider-Man", "Webshooters");

	// Display 'Team 1' Name, weapon, health, and damage to the console (Stats)
/*	std::cout << team_one[5].get_name() << '\n' 
		<< team_one[5].get_weapon() << '\n' 
		<< team_one[5].get_health() << '\n' 
		<< team_one[5].get_damage() << '\n';*/
	
	// Assigned 'Team 2' with appropriate weapons/abilities
	team_two[0] = Fighter("Captain America", "Vibranium Shield");
	team_two[1] = Fighter("Hawkeye", "Recurve Bow");
	team_two[2] = Fighter("Falcon", "Steyr SPP");
	team_two[3] = Fighter("Bucky Barnes", "Bionic Arm");
	team_two[4] = Fighter("Ant-Man", "Giant Fists");
	team_two[5] = Fighter("Scarlet Witch", "Psionic Energy Manipulation");

	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "|                                                                  |\n";
	std::cout << "|                       Avengers: Civil War                        |\n";
	std::cout << "|                                                                  |\n";
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	int team1Size = 6;
	int team2Size = 6;
	bool fighting = true;
	while (fighting)
	{
		int attacking = 0;
		// Display attacked fighter's health
		//std::cout << "\n" << team_two[attacking].get_name() << "'s health is " << team_two[attacking].get_health();
		for (int index = 0; index < team_size; index++)
		{
			//Team 1 attacks
			// Sets the random variable
			if (team1Size > 0)
			{
				attacking = rand() % team1Size;
			}
			else
				attacking = 0;

			if (!team_two[attacking].isDead && team_one[index].get_health() != 0)
			{
				team_one[index].attack(team_two[attacking]);

				// Wait for user input to proceed to next fight
				std::cout << "\n";
				system("Pause");
				std::cout << "\n";
			}
			
			//Team 2 attacks
			// Gives a new random number
			if (team2Size > 0)
			{
				attacking = rand() % team2Size;
			}
			else
				attacking = 0;

			if (!team_one[attacking].isDead && team_one[index].get_health() != 0)
			{
				team_two[index].attack(team_one[attacking]);

				// Wait for user input to proceed to next fight
				std::cout << "\n";
				system("Pause");
				std::cout << "\n";
			}
		}

		// Bubble sort the health before displaying arrays
		BubbleSort(team_one, team_size);
		BubbleSort(team_two, team_size);

		// Display array of health for Team 1
		std::cout << "  ---Team 1's Health---\n";
		for (int hero_num = 0; hero_num < team_size; hero_num++)
		{
			if (team_one[hero_num].get_health() == 0)
			{
				std::cout << team_one[hero_num].get_name() << " is dead.\n";
				--team1Size;
			}
			else
			{
				std::cout << team_one[hero_num].get_name() << "'s health is: "
					<< team_one[hero_num].get_health() << std::endl;
			}
		}

		std::cout << "\n\n";

		// Display array of health for Team 2
		std::cout << "  ---Team 2's Health---\n";
		for (int hero_num = 0; hero_num < team_size; hero_num++)
		{
			if (team_two[hero_num].get_health() == 0)
			{
				std::cout << team_two[hero_num].get_name() << " is dead.\n";
				--team2Size;
			}
			else
			{
				std::cout << team_two[hero_num].get_name() << "'s health is: "
					<< team_two[hero_num].get_health() << std::endl;
			}
		}

		std::cout << "\n\n";
		system("Pause");

		if (team_one[0].get_health() == 0 &&
			team_one[1].get_health() == 0 &&
			team_one[2].get_health() == 0 &&
			team_one[3].get_health() == 0 &&
			team_one[4].get_health() == 0 &&
			team_one[5].get_health() == 0)
		{
			std::cout << "\n\n---Team 1 has been finished, the civil war is over!---\n\n";
			fighting = false;
			system("Pause");
		}
		else if (team_two[0].get_health() == 0 &&
			team_two[1].get_health() == 0 &&
			team_two[2].get_health() == 0 &&
			team_two[3].get_health() == 0 &&
			team_two[4].get_health() == 0 &&
			team_two[5].get_health() == 0)
		{
			std::cout << "\n\n---Team 2 has been finished, the civil war is over!---\n\n";
			fighting = false;
			system("Pause");
		}
		else
			fighting = true;

	}

	return 0;
}

// Function to bubble sort array
void BubbleSort(Fighter fighterArray[], int teamSize)
{
	// Flag for swap occurance
	bool swap_flag = true;
	while (swap_flag)
	{
		swap_flag = false;
		// Run the length of the array - 1
		for (size_t index = 0; index < teamSize - 1; index++)
		{
			// Check with neighbour's health
			if (fighterArray[index].get_health() < fighterArray[index + 1].get_health())
			{
				// Swap with neighbour
				Fighter temp = fighterArray[index];
				fighterArray[index] = fighterArray[index + 1];
				fighterArray[index + 1] = temp;
				// Reset flag
				swap_flag = true;
			}
		}
	}
}
