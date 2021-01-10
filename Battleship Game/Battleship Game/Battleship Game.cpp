// ConsoleApplication85.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <time.h>
using namespace std;
int guess(int* battleship)
{
	int guess[4], positions = 0, numbers = 0, tries = 14;
	for (int i = 1; i <= 13; i++) //the 13 tries the player gets
	{
		cout << "Guess the ship's coordinates 4 digits (must be from 0 to 7)" << endl;
		for (int j = 0; j < 4; j++) //the 4 digits the player guesses
		{
			cin >> guess[j];
			if (cin.fail() or guess[j] < 0 or guess[j] > 7) //if the input is incorrect
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Oops! The number you have entered is not in range :( Maybe try something between 0 and 7?" << endl;
				j--;
			}
		}
		for (int ix = 0; ix < 4; ix++) //searches for correct numbers and positions
		{
			for (int jx = 0; jx < 4; jx++)
			{
				if (battleship[ix] == guess[jx])
				{
					numbers++;
					if (ix == jx)
					{
						positions++;
					}
				}
			}
		}

		if (positions == 4 and numbers == 4) //if the guess is fully correct
		{
			cout << "Congratulations, you have guessed all digits and their positions correctly!" << endl;
			tries = i;
			i = 14;
		}
		else //if the guess isn't fully correct
		{
			cout << "----------------------------------------------------------" << endl;
			cout << "||   Guessed    ||   ||   Player    ||   ||   Guessed   ||" << endl;
			cout << "||   Position   ||   ||   Guesses   ||   ||   numbers   ||" << endl;
			cout << "||   & numbers  ||   ||             ||   ||             ||" << endl;
			cout << "----------------------------------------------------------" << endl;
			cout << "||       " << positions << "      ||   ||   ";
			for (int j = 0; j < 4; j++)
			{
				cout << guess[j] << " ";
			}
			cout << "  ||   ||      " << numbers << "      ||" << endl;
			cout << "----------------------------------------------------------" << endl;
			cout << endl;
		}
		positions = 0; //reseting values so the code doesn't break
		numbers = 0;
	}
	return tries; //returning the amount of tries it took to guess
}
void Tutorial()
{
	char a;
	cout << "Hello, this is our take on the Battleship game named \"Bletchley\"" << endl;
k:
	cout << "If you are not familiar with the game, you might want to read the tutorial (y/n)" << endl;
	cout << "Your choice: ";
	cin >> a;
	if (a == 'y')
	{
		cout << "----------------------------------------------------------------\n";
		cout << "So your oponent (The Germans) has a ship that is going to destroy a passing civilian convoy.\nYour task is to find the coordinates of this ship, so the Royal Navy can take action! \n Here are the rules:\n";
		cout << "1. You only have 13 guesses.Three of the guesses will be by 4 numbers and last one will be the deciding blow." << endl;
		cout << "2. After each try, you will be presented with box which contains the following information:\n   Two digits one of which is the number of digits on the right position, and the second one is the count of all numbers you have found in the guess! " << endl;
		cout << "3. You can win only if you guess all the submarines and their positions, otherwise your oponent (The Germans) wins!\n\n";
		cout << "Its that simple try not to mess it up soldier. The war is in your hands\n";
		cout << "Ou yeah and DON'T CHEAT! !#%&* (It's not fun) \n\n";
		cout << "Got it?\n";
		cout << "----------------------------------------------------------------\n";
		cin.ignore();
	}
	else if (a == 'n')
	{
		cout << "Oh really?! That's great! Let's begin then....." << endl;
	}
	else
	{
		cout << "----------------------------------------------------------------\n";
		cout << "Oops, you have entered something wrong!? You know you have to enter just the sybol \'y\' or the symbol \'n\', right?" << endl; goto k;
	}
	cout << "Press ENTER to continue\n";
}
void Exit()
{
	cout << "I hope you enjoyed out little game";
}

int main()
{
	Tutorial();
	cin.ignore();
	system("CLS");
	cout << "That's great! Let's begin." << endl;
	srand(time(NULL)); //seed for Random Number Generator
	int choice = -2, record = 14, lastPlay = 14, wins = 0, loses = 0;
	int battleship[4] = { 1, 2, 3, 4 };
	do
	{
		cout << "Player vs Player (1)" << endl;
		cout << "Player vs Computer (2)" << endl;
		cout << "Current Best Play (3)" << endl; //outputs the best play
		cout << "Last Play results (4)" << endl; //outputs the last play
		cout << "Wins and loses (5)" << endl; //outputs the amount of wins and loses
		cout << "Credits (6)" << endl; //outputs credits (I want someone else to deal with this, please.)
		cout << "Quit (0)\n" << endl; //breaks the loop and exits
		cout << "Your choice: ";
		cin >> choice;
		system("CLS");
		if (cin.fail()) //for input that isn't numbers, makes sure the program doesn't break
		{
			choice = -2;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		switch (choice)
		{
		case 1: //if the enemy is a player
		{
			cout << "Enter the 4 ship digits (must be from 0 to 7)" << endl;
			for (int i = 0; i < 4; i++)
			{
				cin >> battleship[i];
				if (cin.fail() or battleship[i] < 0 or battleship[i] > 7)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Oops! One or more numbers you have entered are not in range?! Maybe try something between 0 and 7?" << endl;
					i--;
				}
			}
			system("CLS");
			lastPlay = guess(battleship);
			break;
		}
		case 2: //if the enemy is the computer
		{
			for (int i = 0; i < 4; i++) //picks random digits for the ship
			{
				battleship[i] = rand() % 8;
			}
			lastPlay = guess(battleship);
			break;
		}
		case 3: //outputs the best play
		{
			if (record > 13)
			{
				cout << "Hmm... There is nothing in here? Are you sure you won at least one game?" << endl;
			}
			else
			{
				cout << "This session's best play is only " << record << " guesses!" << endl;
			}
			break;
		}
		case 4: //outputs the last play
		{
			if (wins > 0 or loses > 0)
			{
				if (lastPlay > 13)
				{
					cout << "The enemy has won, you didn't guess it right in 13 tries." << endl;
				}
				else
				{
					cout << "You won last round in " << lastPlay << " tries!" << endl;
				}
			}
			else
			{
				cout << "Hmm... There is nothing in here? Are you sure you played at least one game?" << endl;
			}
			break;
		}
		case 5: //outputs the amount of wins and loses
		{
			cout << "You have " << wins << " wins and " << loses << " loses." << endl;
			break;
		}
		case 6:
		{
			break;
		}
		case 0: break;
		default: choice = -1;
		}
		if (choice == -1)
		{
			cout << "What?! Something is wrong! Are you sure you entered a number between 0 and 6?" << endl;
		}
		if (choice == 1 or choice == 2)
		{
			if (record > lastPlay)
			{
				record = lastPlay;
				cout << "New best play!" << endl;
			}
			if (lastPlay > 13)
			{
				loses++;
				cout << "The enemy wins!" << endl;
			}
			else
			{
				wins++;
			}
		}
	} while (choice != 0);
	Exit();
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
