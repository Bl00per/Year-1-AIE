#include <iostream>
#include <Windows.h>
#include <crtdbg.h>

int binary_search(int a_numArray[], int left_side, int right_side, int tries);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//Define our data
	const int array_size = 100;
	int number_array[array_size];
	for (int i = 0; i < 99; i++)
	{
		number_array[i] = i;
	}

	Sleep(1000);
	std::cout << "I am the great Mysterio!\n";
	Sleep(1000);
	std::cout << "I can read your mind!\n";
	Sleep(1000);
	// Instructions for the user
	std::cout << "Simply think of a WHOLE number between 1 and 100 and press enter to be amazed!\n";
	std::cin.get();
	std::cin.clear();

	// Run fuction
	int tries = binary_search(number_array, 1, 100, 0);

	if (tries != -1)
	{
		// Print how many tries it took
		std::cout << "\nIt took the great Mysterio " << tries << " tries for him to guess your number.\n";
	}

	system("Pause");
	return 0;
}

// Do the binary search
int binary_search(int a_numArray[], int left_side, int right_side, int tries)
{
	char user_input = 0;
	// Figures out the pivot point (middle value)
	int pivot = (left_side + right_side) / 2;

	// Instructions for the user after guess
	std::cout << pivot << "\n\nWas the above number what you were thinking of?\nor was it higher, lower or correct? (>, <, or =)\n\n";
	std::cin >> user_input;
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');

	// Add +1 to tries after every user input
	++tries;

	//If the number was correct
	if (user_input == '=')
	{
		Sleep(1000);
		std::cout << "\nYour number is...\n\n";

		Sleep(500);
		std::cout << "\rDrum roll   " << std::flush;
		Sleep(500);	  
		std::cout << "\rDrum roll.  " << std::flush;
		Sleep(500);	  
		std::cout << "\rDrum roll.. " << std::flush;
		Sleep(500);	  
		std::cout << "\rDrum roll..." << std::flush;
		Sleep(500);	  
		std::cout << "\rDrum roll.  " << std::flush;
		Sleep(500);	  
		std::cout << "\rDrum roll.. " << std::flush;
		Sleep(500);	  
		std::cout << "\rDrum roll..." << std::flush;
		Sleep(500);
		std::cout << "\n\n" << pivot << "!\n";
		return tries;
	}
	// Cheat detection
	else if (right_side < left_side)
	{
		std::cout << "\nHey you can't change your number mid way, leave my show at once!\n";
		return -1;
	}
	else if (user_input == '>')
	{
		std::cout << std::endl;
		return binary_search(a_numArray, pivot + 1, right_side, tries);
	}
	else if (user_input == '<')
	{
		std::cout << std::endl;
		return binary_search(a_numArray, left_side, pivot - 1, tries);
	}
	else
	{
		std::cout << std::endl;
		return binary_search(a_numArray, left_side, right_side, tries);
	}
}