#include <iostream>
#include <time.h>
using namespace std;

int* playerInput(int* coord) //used for entering ship coordinates
{
	for (int i = 0; i < 4; i++)
	{
		cin >> coord[i];
		if (cin.fail() or coord[i] < 0 or coord[i] > 7)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Oops! One or more numbers you have entered are not in range?! Maybe try something between 0 and 7?" << endl;
			i--;
		}
	}
	return coord;
}

int dupCheck(int* x) //checks for duplicate elements
{
	int sameNumber = 0;
	for (int i = 0; i < 4; i++) //makes sure there are no duplicate numbers
	{
		for (int j = 0; j < 4; j++)
		{
			if (x[i] == x[j])
			{
				sameNumber++;
			}
		}
	}
	return sameNumber;
}

int guess(int* battleship)
{
	int guess[4], positions = 0, numbers = 0, tries = 14, sameNumber = 0;
	for (int i = 1; i <= 13; i++) //the 13 tries the player gets
	{
		cout << "Try to guess the ship's 4 digits. (from 0 to 7, no repeating digits)" << endl;
		playerInput(guess); //takes the player's guess
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
		sameNumber = dupCheck(guess); //checks for duplicate numbers
		if (sameNumber > 4)
		{
			cout << "There has been an error..? You have entered the same number twice?! Please try not to do it again! OK?" << endl;
			i--;
		}
		else
		{
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
		}
		positions = 0; //reseting values so the code doesn't break
		numbers = 0;
	}
	return tries; //returning the amount of tries it took to guess
}

void tutorial()
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
	}
	else
	{
		cout << "----------------------------------------------------------------\n";
		cout << "Oops, you have entered something wrong!? You know you have to enter just the symbol \'y\' or the symbol \'n\', right?" << endl; goto k;
	}
	cout << "Press ENTER to continue\n";
}

void exit()
{
	cout << "I hope you enjoyed out little game";
}

int* shipCoord(int* battleship) //a player enters the battleship's coordinates
{   
	int sameNumber = 0;
	do
	{
		sameNumber = 0;
		cout << "Enter the 4 ship digits (must be from 0 to 7, can't use a single number more than once)" << endl;
		playerInput(battleship); //used for inputting battleship coordinates
		sameNumber = dupCheck(battleship); //checks for duplicate numbers
		if (sameNumber > 4)
		{
			system("CLS");
			cout << "There has been an error..? You have entered the same number twice?! Please try not to do it again! OK?" << endl;
		}
	} while (sameNumber > 4);
	return battleship;
}

void credits() //displays our team
{
	cout << "Hello, soldier! I see you are interested in the developers of our game!" << endl;
	cout << "Well, I am quite amused!" << endl;
	cout << "Here is our team:\n" << endl;
	cout << "Scrum master:  Alexander Yanev / AZYanev18@codingburgas.bg " << endl;
	cout << "Frontend developer: Stefan Stratev / sdstratev18@codingburgas.bg " << endl;
	cout << "Backend developer: Teodor Angelov / ttangelov18@codingburgas.bg" << endl;
	cout << "QA Engineer: Yavor Karakolev / YAKarakolev18@codingburgas.bg " << endl;
	cout << "Documentation: Nevena Pavlova / NSPavlova18@codingburgas.bg " << endl;
	cout << "Code checker: Kaloyan Dimov / KDDimov18@codingburgas.bg\n\n " << endl;
	system("PAUSE");
	system("CLS");
}

int main()
{
	tutorial();
	cin.ignore();
	system("CLS");
	cout << "That's great! Let's begin." << endl;
	srand(time(NULL)); //seed for Random Number Generator
	int choice = -2, record = 14, lastPlay = 14, wins = 0, loses = 0;
	int battleship[4];
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
			shipCoord(battleship);
			system("CLS");
			lastPlay = guess(battleship);
			break;
		}
		case 2: //if the enemy is the computer
		{
			for (int i = 0; i < 4; i++) //picks random digits for the ship
			{
				battleship[i] = rand() % 8;
				for (int j = 0; j < i; j++)
				{
					if (battleship[i] == battleship[j]) //makes sure there are no duplicate numbers
					{
						i--;
					}
				}
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
			credits();
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
	exit();
}