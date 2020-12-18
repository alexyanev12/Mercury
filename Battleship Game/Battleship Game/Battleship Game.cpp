#include <iostream>
#include <time.h>
using namespace std;

void guess(int* battleship)
{
	int guess[4], positions = 0, numbers = 0;
	for (int i = 1; i <= 13; i++)
	{
		cout << "Guess the ship's 4 digits (must be from 0 to 7)" << endl;
		for (int j = 0; j < 4; j++)
		{
			cin >> guess[j];
			if (cin.fail() or guess[j] < 0 or guess[j] > 7)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input" << endl;
				i--;
			}
			else
			{

			}
		}
	}
}

int main()
{
	srand(time(NULL));
	int choice = -3;
	int battleship[4];
	do
	{
		cout << "Player vs Player (1)" << endl;
		cout << "Player vs Computer (2)" << endl;
		cout << "Quit (0)" << endl;
		cin >> choice;
		system("CLS");
		if (cin.fail())
		{
			choice = -2;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		switch (choice)
		{
		case 1:
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
		}
		case 2:
		{
			for (int i = 0; i < 4; i++)
			{
				battleship[i] = rand() % 8;
			}
		}
		case 0: break;
		default: choice = -1;
		}
		if (choice == -1) 
		{ 
			cout << "Invalid input: Input wasn't a vaild choice" << endl; 
		}
		if (choice == -2)
		{
			cout << "Invalid input: Input wasn't a number" << endl;
		}
	} while (choice != 0);
}