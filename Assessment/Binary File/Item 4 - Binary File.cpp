#include "Fighter.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
#include <Windows.h>
//#include <crtdbg.h>

// Bubble sort function
void BubbleSort(Fighter fighterArray[], int teamSize);

const int buffer_size = 50;

// Struct for storing the battle results
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

// Writes the battle results to the struct
void WriteRecordToFile(fighterResultsStruct resultsrecord);
// Read and display the results to the console
void ReadRecordToConsole();
// Read and display a line of the results to the console
void ReadRecord();

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

	// Assigned team sizes
	int team1Size = 6;
	int team2Size = 6;
	// While loop to keep fighting until a team is finished
	bool fighting = true;

	// Menu variables
	int menu_input = 0;
	int user_input = 0;
	bool menu_valid = false;

	fighterResultsStruct resultsStored;

	while (!menu_valid)
	{
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		std::cout << "|                                                                  |\n";
		std::cout << "|                       Avengers: Civil War                        |\n";
		std::cout << "|                                                                  |\n";
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

		std::cout << "\nWhat would you like to do today?\n[1] - Battle!\n[2] - Display last battle results\n[3] - Display certain fighter results\n\n";
		std::cin >> menu_input;

		if (menu_input == 1)
		{
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
						Sleep(300);
						team_one[index].attack(team_two[attacking]);

						std::cout << "\n";
						/*system("Pause");
						std::cout << "\n";*/
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
						Sleep(300);
						team_two[index].attack(team_one[attacking]);

						std::cout << "\n";
						/*system("Pause");
						std::cout << "\n";*/
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

			// Write the results of battle for team 1 into the struct
			for (int hero_num = 0; hero_num < team_size; hero_num++)
			{
				if (team_one[hero_num].get_health() == 0)
				{
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
						strcpy(resultsStored.string6, s.c_str());
						break;
					default:
						break;
					}
				}
				else
				{
					std::stringstream newstringStream;
					newstringStream << team_one[hero_num].get_name() << "'s health is: "
						<< team_one[hero_num].get_health() << std::endl;
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
						strcpy(resultsStored.string6, s.c_str());
						break;
					default:
						break;
					}
				}
			}

			// Write the results of battle for team 2 into the struct
			for (int hero_num = 0; hero_num < team_size; hero_num++)
			{
				if (team_two[hero_num].get_health() == 0)
				{
					std::stringstream newstringStream;
					newstringStream << team_two[hero_num].get_name() << " is dead.\n";
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

			WriteRecordToFile(resultsStored);

			delete[] team_one;
			delete[] team_two;

			menu_valid = true;

			system("Pause");
		}
		else if (menu_input == 2)
		{
			ReadRecordToConsole();
			std::cout << '\n';
			menu_valid = true;

			system("Pause");
		}
		else if (menu_input == 3)
		{
			ReadRecord();
			std::cout << '\n';
			menu_valid = true;

			system("Pause");
		}
		else
		{
			std::cout << "Invalid input, please try again.\n";
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			system("cls");
		}
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

void WriteRecordToFile(fighterResultsStruct resultsrecord) {
	std::ofstream file("fight.dat", std::ios::out | std::ios::binary);

	if (file.good()) {
		std::cout << "\nFile fight.dat opened successfully\n";
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
		file.read((char*)&readFighterRecord, sizeof(fighterResultsStruct));

		std::cout << "  ---Team 1's Health---\n";
		std::cout << readFighterRecord.string1;
		std::cout << readFighterRecord.string2;
		std::cout << readFighterRecord.string3;
		std::cout << readFighterRecord.string4;
		std::cout << readFighterRecord.string5;
		std::cout << readFighterRecord.string6 << "\n";
		std::cout << "  ---Team 2's Health---\n";
		std::cout << readFighterRecord.string7;
		std::cout << readFighterRecord.string8;
		std::cout << readFighterRecord.string9;
		std::cout << readFighterRecord.string10;
		std::cout << readFighterRecord.string11;
		std::cout << readFighterRecord.string12;
		file.close();
	}
	else {
		std::cout << "Error opening file\n";
	}
}

void ReadRecord() {
	fighterResultsStruct f;
	char myString[buffer_size];
	int user_input = 0;
	int lineIndex = 0;
	bool is_valid = false;

	while (!is_valid)
	{
		std::cout << "\nWhich string result would you like to view? (1 - 12)\n";
		std::cin >> user_input;
		std::cout << '\n';

		user_input -= 1;

		if (user_input < 0 || user_input > 11)
		{
			std::cout << "Please input a valid number between 1 - 12.\n\n";
			continue;
		}
		else
		{
			lineIndex = user_input * 50;
			is_valid = true;
		}
	}

	std::ifstream file("fight.dat", std::ios::in | std::ios::binary);

	if (file.good()) {
		file.seekg(lineIndex, std::ios::beg);
		file.getline(myString, sizeof(f.string1));
		file.close();
	}

	std::cout << myString << std::endl;
}
