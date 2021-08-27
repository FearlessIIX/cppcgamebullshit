//mazeGameBUILD2.0
//David Crosslin

#include <iostream>
#include <fstream>
// #include "conio.h"
#include <ncurses.h>
using namespace std;

// #define KEY_UP 72
// #define KEY_DOWN 80
// #define KEY_LEFT 75
// #define KEY_RIGHT 77



int main()
{
	/*
	***RUN SCRIPT TO FETCH DEPENDENCIES FOR DATA***

	***ONLY AS A BACKUP***

	***SCRIPT NAME: mazeDependencies.cpp
	*/

    initscr();

	int datrec = 1; int count = 1; int location = 12; char choice; int completed = 10; int genCount = 0; int altFile = 0;
	ifstream infile;
	ifstream comp1;
restartGen:

	if (completed == 20)	{
		infile.open("MAZE_SEED.DAT", ios::in);
		comp1.open("MAZE_SEED_COMP1.DAT", ios::in);
	}
	else	{
		infile.open("MAZE_SEED.DAT", ios::in);
	}
	system("cls");

	cout << location << endl;


continueGen:
	if (completed == 20) {

		if (altFile == 1) {
			comp1 >> datrec;
		}
		else
		{
			infile >> datrec;

		}
	}
	else
	{
		infile >> datrec;
	}

	if (datrec == 100)
	{
		if (completed == 20)
		{
			if (altFile == 0)
			{
				altFile = 1;
			}
			else
			{
				altFile = 0;
			}
		}
	}

	if (datrec == 100)
	{
		goto continueGen;
	}
	if (datrec == 0)
	{
		goto finishGen;
	}
	else
	{

		if (datrec == 1)
		{
			if (count % completed == 0)
			{
				cout << "#" << endl;
				count++;
			}
			else
			{
				cout << "#";
				count++;
			}
		}
		else if (count == location)
		{
			if (count % completed == 0)
			{
				cout << "0" << endl;
				count++;
			}
			else
			{
				cout << "0";
				count++;
			}
		}
		else
		{
			if (count % completed == 0)
			{
				cout << " " << endl;
				count++;
			}
			else
			{
				cout << " ";
				count++;
			}
		}
	}

	goto continueGen;

finishGen:
	count = 0;
	infile.close();
	comp1.close();

	infile.open("MAZE_SEED.DAT", ios::in);
	comp1.open("MAZE_SEED_COMP1.DAT", ios::in);

	do
	{
		if (completed == 20)
		{
		testNewLine:

			if (altFile == 1)
			{
				comp1 >> datrec;
				count++;
			}
			else
			{

				infile >> datrec;
				count++;
			}
			if (datrec == 100)
			{

				goto testNewLine;
				if (completed == 20)
				{
					if (altFile == 0)
					{
						altFile = 1;

					}
					else
					{
						altFile = 0;

					}

				}
			}
		}
		else
		{
			infile >> datrec;
			if (datrec == 100)
			{
				infile >> datrec;
			}
			count++;
		}


	} while (count != location);

	choice = getch();
    // choice = cin.get();
    // cout << choice << endl;

	if (choice == 72)
	{
		if (datrec == 2 || datrec == 5 || datrec == 8 || datrec == 9 || datrec == 12 || datrec == 13 || datrec == 15 || datrec == 16 || datrec == 17)
		{

		}
		else
		{
			location = location - 10;
		}
	}
	if (choice == 80)
	{
		if (datrec == 5 || datrec == 10 || datrec == 11 || datrec == 12 || datrec == 13 || datrec == 14)
		{

		}
		else
		{
			if (completed == 20)
			{

			}
			else
			{
				location = location + 10;
			}

		}
	}
	if (choice == 75)
	{
		if (datrec == 6 || datrec == 7 || datrec == 9 || datrec == 10 || datrec == 13 || datrec == 14 || datrec == 15 || datrec == 16)
		{

		}
		else
		{
			location = location - 1;
		}
	}
	if (choice == 77)
	{
		if (datrec == 4 || datrec == 6 || datrec == 8 || datrec == 11 || datrec == 12 || datrec == 14 || datrec == 15 || datrec == 17 || datrec == 3)
		{

		}
		else
		{
			if (location == 50)
			{

				if (completed == 20)
				{

				}
				else
				{
					completed = completed + 10;
					location = 91;
				}


			}
			location = location + 1;
		}
	}

	infile.close();
	comp1.close();
	datrec = 0; count = 1;

	goto restartGen;

	return endwin();
	// return 0;
}
