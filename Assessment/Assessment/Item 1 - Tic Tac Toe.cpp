/* 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
| Program: Tic Tac Toe												   |
| Name: William Hart												   |
| Date Modified: 25/02/2019											   |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/* CODE BEGINS HERE */
#include <iostream>
#include <crtdbg.h>

// Display the board on the console
void display_board(char game_board[3][3], int size);
// User input function
void user_input(char player1);
void check_win();
void check_draw();


// Variables to check for wins or draw
bool game_playing = true;
bool player_won = false;
bool player_draw = false;

// Player variables
char player1 = 'X';
char player2 = 'O';
// 'X' goes first
char current_player = player1;
char current_move;

// Game board
char game_board[3][3] = 
{
	{ '1', '2', '3' },
	{ '4', '5', '6' },
	{ '7', '8', '9' }
};
	

// Game is two player
// X starts first and alternates till a player has won or total turns has run out
// Nine total turns

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Display the board within the console with a size of 3
	display_board(game_board, 3);

	// Continue to run the program until these conditions are met
	while (game_playing && !player_won && !player_draw)
	{
		// While loop so that it will continue to ask the user for a valid input
		bool valid_move = false;
		while (!valid_move)
		{
			user_input(current_player);

			// Validate input
			if (current_move == '0')
				std::cout << "Invalid Input.\n";
			else
			{
				if (current_player == player1)
				{
					for (int row = 0; row < 3; row++) {
						for (int col = 0; col < 3; col++) {
							//Check whether the number is within the array and change it to 'X'
							if (game_board[row][col] == current_move)
							{
								game_board[row][col] = 'X';
								valid_move = true;
							}
						}
					}
				}
				else if (current_player == player2)
				{
					for (int row = 0; row < 3; row++) {
						for (int col = 0; col < 3; col++) {
							//Check whether the number is within the array and change it to 'O'
							if (game_board[row][col] == current_move)
							{
								game_board[row][col] = 'O';
								valid_move = true;
							}
						}
					}
				}
			}
		}

		// Check for player win otherwise update and redisplay the game board
		display_board(game_board, 3);
		check_win();
		check_draw();

		if (player_won)
		{
			system("Pause");
		}

		// Go to next players turn after the currect player has had theirs
		if (current_player == player1)
			current_player = player2;
		else
			current_player = player1;
	}
}

// Function to display the board as a 3x3 array
void display_board(char game_board[3][3], int size)
{
	// Clear screen
	system("cls");

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			std::cout << game_board[x][y];
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// Funciton for the user input
void user_input(char player1)
{
	std::cout << "Enter your move " << current_player << ": ";
	std::cin >> current_move;
	std::cin.clear();
	std::cin.ignore(SHRT_MAX, '\n');
	display_board(game_board, 3);
}

// Function to check for win
void check_win()
{
	// Check win across 'X'
	if (game_board[0][0] == 'X' && game_board[0][1] == 'X' && game_board[0][2] == 'X')
	{
		std::cout << "Player X Wins!\n\n";
		player_won = true;
	}
	if (game_board[1][0] == 'X' && game_board[1][1] == 'X' && game_board[1][2] == 'X')
	{
		std::cout << "Player X Wins!\n\n";
		player_won = true;
	}
	if (game_board[2][0] == 'X' && game_board[2][1] == 'X' && game_board[2][2] == 'X')
	{
		std::cout << "Player X Wins!\n\n";
		player_won = true;
	}
	// Check win down 'X'
	if (game_board[0][0] == 'X' && game_board[1][0] == 'X' && game_board[2][0] == 'X')
	{
		std::cout << "Player X Wins!\n\n";
		player_won = true;
	}
	if (game_board[0][1] == 'X' && game_board[1][1] == 'X' && game_board[2][1] == 'X')
	{
		std::cout << "Player X Wins!\n\n";
		player_won = true;
	}
	if (game_board[0][2] == 'X' && game_board[1][2] == 'X' && game_board[2][2] == 'X')
	{
		std::cout << "Player X Wins!\n\n";
		player_won = true;
	}
	// Check win diagonally 'X'
	if (game_board[0][0] == 'X' && game_board[1][1] == 'X' && game_board[2][2] == 'X')
	{
		std::cout << "Player X Wins!\n\n";
		player_won = true;
	}
	if (game_board[2][0] == 'X' && game_board[1][1] == 'X' && game_board[0][2] == 'X')
	{
		std::cout << "Player X Wins!\n\n";
		player_won = true;
	}

	// Check win across 'O'
	if (game_board[0][0] == 'O' && game_board[0][1] == 'O' && game_board[0][2] == 'O')
	{
		std::cout << "Player O Wins!\n\n";
		player_won = true;
	}
	if (game_board[1][0] == 'O' && game_board[1][1] == 'O' && game_board[1][2] == 'O')
	{
		std::cout << "Player O Wins!\n\n";
		player_won = true;
	}
	if (game_board[2][0] == 'O' && game_board[2][1] == 'O' && game_board[2][2] == 'O')
	{
		std::cout << "Player O Wins!\n\n";
		player_won = true;
	}
	// Check win down 'O'
	if (game_board[0][0] == 'O' && game_board[1][0] == 'O' && game_board[2][0] == 'O')
	{
		std::cout << "Player O Wins!\n\n";
		player_won = true;
	}
	if (game_board[0][1] == 'O' && game_board[1][1] == 'O' && game_board[2][1] == 'O')
	{
		std::cout << "Player O Wins!\n\n";
		player_won = true;
	}
	if (game_board[0][2] == 'O' && game_board[1][2] == 'O' && game_board[2][2] == 'O')
	{
		std::cout << "Player O Wins!\n\n";
		player_won = true;
	}
	// Check win diagonally 'O'
	if (game_board[0][0] == 'O' && game_board[1][1] == 'O' && game_board[2][2] == 'O')
	{
		std::cout << "Player O Wins!\n\n";
		player_won = true;
	}
	if (game_board[2][0] == 'O' && game_board[1][1] == 'O' && game_board[0][2] == 'O')
	{
		std::cout << "Player O Wins!\n\n";
		player_won = true;
	}
}

// Function to check for draw
void check_draw()
{
	if (game_board[0][0] != '1' && game_board[0][1] != '2' && game_board[0][2] != '3' && game_board[1][0] != '4'
		&& game_board[1][1] != '5' && game_board[1][2] != '6' && game_board[2][0] != '7' && game_board[2][1] != '8' &&
		game_board[2][2] != '9' && !player_won)
		player_draw = true;
	if (player_draw)
	{
		std::cout << "The game is a draw! \n\n";
		system("Pause");
	}
}

