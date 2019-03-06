#include "Fighter.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
//#include <crtdbg.h>

void BubbleSort(Fighter fighterArray[], int teamSize);

const int buffer_size = 50;

struct fighterResultsStruct
{
	char string1[buffer_size];
	char string2[buffer_size];
	char string3[buffer_size];
	char string4[buffer_size];
	char string5[buffer_size];
	char string6[buffer_size];
	char string7[buffer_size];
	char string8[buffer_size];
	char string9[buffer_size];
	char string10[buffer_size];
	char string11[buffer_size];
	char string12[buffer_size];
};

void WriteRecordToFile(fighterResultsStruct resultsrecord);
void ReadRecordToConsole();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned int)time(NULL));

	const size_t team_size = 6;
	Fighter * team_one = new Fighter[team_size];
	Fighter * team_two = new Fighter[team_size];


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

	fighterResultsStruct resultsStored;

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
				//system("Pause");
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
				//system("Pause");
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

				std::stringstream newstringStream;
				newstringStream << team_one[hero_num].get_name() << " is dead.\n";
				std::string s = newstringStream.str();

				switch (hero_num)
				{
				case 0:
					strcpy(resultsStored.string1, s.c_str());
					break;
				case 1:
					strcpy(resultsStored.string2, s.c_str());
					break;
				case 2:
					strcpy(resultsStored.string3, s.c_str());
					break;
				case 3:
					strcpy(resultsStored.string4, s.c_str());
					break;
				case 4:
					strcpy(resultsStored.string5, s.c_str());
					break;
				case 5:
					strcpy(resultsStored.string7, s.c_str());
					break;
				default:
					break;
				}
			}
			else
			{
				std::cout << team_one[hero_num].get_name() << "'s health is: "
					<< team_one[hero_num].get_health() << std::endl;

				std::stringstream newstringStream;
				newstringStream << team_one[hero_num].get_name() << "'s health is: "
					<< team_one[hero_num].get_health() << std::endl;
				std::string s = newstringStream.str();

				switch (hero_num)
				{
				case 0:
					strcpy(resultsStored.string7, s.c_str());
					break;
				case 1:
					strcpy(resultsStored.string8, s.c_str());
					break;
				case 2:
					strcpy(resultsStored.string9, s.c_str());
					break;
				case 3:
					strcpy(resultsStored.string10, s.c_str());
					break;
				case 4:
					strcpy(resultsStored.string11, s.c_str());
					break;
				case 5:
					strcpy(resultsStored.string12, s.c_str());
					break;
				default:
					break;
				}
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

				std::stringstream newstringStream;
				newstringStream << team_two[hero_num].get_name() << " is dead.\n";
				std::string s = newstringStream.str();

				switch (hero_num)
				{
				case 0:
					strcpy(resultsStored.string1, s.c_str());
					break;
				case 1:
					strcpy(resultsStored.string2, s.c_str());
					break;
				case 2:
					strcpy(resultsStored.string3, s.c_str());
					break;
				case 3:
					strcpy(resultsStored.string4, s.c_str());
					break;
				case 4:
					strcpy(resultsStored.string5, s.c_str());
					break;
				case 5:
					strcpy(resultsStored.string7, s.c_str());
					break;
				default:
					break;
				}
			}
			else
			{
				std::cout << team_two[hero_num].get_name() << "'s health is: "
					<< team_two[hero_num].get_health() << std::endl;


				std::stringstream newstringStream;
				newstringStream << team_two[hero_num].get_name() << "'s health is: "
					<< team_two[hero_num].get_health() << std::endl;
				std::string s = newstringStream.str();

				switch (hero_num)
				{
				case 0:
					strcpy(resultsStored.string7, s.c_str());
					break;
				case 1:
					strcpy(resultsStored.string8, s.c_str());
					break;
				case 2:
					strcpy(resultsStored.string9, s.c_str());
					break;
				case 3:
					strcpy(resultsStored.string10, s.c_str());
					break;
				case 4:
					strcpy(resultsStored.string11, s.c_str());
					break;
				case 5:
					strcpy(resultsStored.string12, s.c_str());
					break;
				default:
					break;
				}
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
	WriteRecordToFile(resultsStored);
	ReadRecordToConsole();

	delete[] team_one;
	delete[] team_two;

	system("Pause");
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

void WriteRecordToFile(fighterResultsStruct resultsrecord) {
	std::ofstream file("fight.dat", std::ios::out | std::ios::binary);

	if (file.good()) {
		std::cout << "File fight.dat opened successfully\n";

	}
	else {
		std::ofstream file("fight.dat", std::ios::out | std::ios::binary);
		std::cout << "creating fight.dat\n";
		file.close();

		WriteRecordToFile(resultsrecord);
		return;
	}

	file.seekp(0, std::ios::end);
	file.write((char*)&resultsrecord, sizeof(fighterResultsStruct));

	file.close();
}

void ReadRecordToConsole() {
	fighterResultsStruct readFighterRecord;

	//open file from both read and write so you can seek
	std::ifstream file("fight.dat", std::ios::in | std::ios::binary);

	if (file.good()) {
		//file.seekg(-1 * sizeof(fighterResultsStruct), std::ios::end);
		file.read((char*)&readFighterRecord, sizeof(fighterResultsStruct));

		std::cout << readFighterRecord.string1 << "\n";
		std::cout << readFighterRecord.string2 << "\n";
		std::cout << readFighterRecord.string3 << "\n";
		std::cout << readFighterRecord.string4 << "\n";
		std::cout << readFighterRecord.string5 << "\n";
		std::cout << readFighterRecord.string6 << "\n";
		std::cout << readFighterRecord.string7 << "\n";
		std::cout << readFighterRecord.string8 << "\n";
		std::cout << readFighterRecord.string9 << "\n";
		std::cout << readFighterRecord.string10 << "\n";
		std::cout << readFighterRecord.string11 << "\n";
		std::cout << readFighterRecord.string12 << "\n";
		file.close();
	}
	else {
		std::cout << "Error opening file\n";
	}
}