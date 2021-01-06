#include <iostream>
#include <time.h>
using namespace std;

int guess(int* battleship)
{
	int guess[4], positions = 0, numbers = 0, tries = -1;
	for (int i = 1; i <= 13; i++) //the 13 tries the player gets
	{
		cout << "Guess the ship's 4 digits (must be from 0 to 7)" << endl;
		for (int j = 0; j < 4; j++) //the 4 digits the player guesses
		{
			cin >> guess[j];
			if (cin.fail() or guess[j] < 0 or guess[j] > 7) //if the input is incorrect
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input" << endl;
				j--;
			}
			else //counts the correct numbers and positions
			{
				for (int ix = 0; ix < 4; i++)
				{
					for (int jx = 0; jx < 4; j++)
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
			}
		}
		system("CLS");
		if (positions == 4 and numbers == 4) //if the guess is fully correct
		{
			cout << "Congratulations, you have guessed all digits and their positions correctly!" << endl;
			tries = i;
			i = 14;
		}
		else //if the guess isn't fully correct
		{
			cout << numbers << " digits and " << positions << " of their positions are correct." << endl;
		}
		positions = 0; //reseting values so the code doesn't break
		numbers = 0;
	}
	return tries; //returning the amount of tries it took to guess
}

int main()
{
	srand(time(NULL)); //seed for Random Number Generator
	int choice = -2, record = 15, lastPlay = 15, wins = 0, loses = 0;
	int battleship[4];
	do
	{
		cout << "Player vs Player (1)" << endl;
		cout << "Player vs Computer (2)" << endl;
		cout << "Current Best Play (3)" << endl; //outputs the best play
		cout << "Last Play results (4)" << endl; //outputs the last play
		cout << "Credits (5)" << endl; //outputs credits (I want someone else to deal with this, please.)
		cout << "Quit (0)" << endl; //breaks the loop and exits
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
					cout << "Invalid input" << endl;
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
				cout << "There haven't been any wins.";
			}
			else
			{
				cout << "This session's best play is only " << record << " guesses!" << endl;
			}
			break;
		}
		case 4: //outputs the last play
		{
			if (lastPlay > 13)
			{
				cout << "The enemy has won, you didn't guess it right in 13 tries.";
			}
			else
			{
				cout << "You won last round in " << lastPlay << " tries!";
			}
			break;
		}
		case 5: //outputs credits (I want someone else to deal with this, please.)
		{

		}
		case 0: break;
		default: choice = -1;
		}
		if (choice == -1) 
		{ 
			cout << "Invalid input" << endl; 
		}
		else
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
}