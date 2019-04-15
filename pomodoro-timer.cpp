// pomodoro timer.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include<ctime>			//For the timer
#include<iostream>
#include <windows.h>	//For the message window

int main()
{
	//cycles = amount of cycles
	//count = counter variable
	//redo = determines if loop shall continue or break
	int cycles, count = 1, redo;
	
	//function prototypes
	void work();
	void Break();

	

	do
	{
		system("cls");

		std::cout << "The Pomodoro technique is used to help you focus on something so your brain can learn it easier. "
			<< "The technique works by doing something (reading a book, for example) for 20 minutes then taking a short "
			<< "5 minute rest and then get back on the activity. This helps your brain stay focused; a focused brain "
			<< "holds informatin better.\n" << std::endl;
				
		std::cout << "Enter amount of Pomodoro cycles\t";
		std::cin >> cycles;


		while (cycles > 0)
		{
			system("cls");

			std::cout << "Cycles left:\t" << cycles << std::endl;

			work();
			Break();

			cycles--;
		}

	choice:
		system("cls");

		std::cout << "Redo? 1 = yes; 0 = no\t";
		std::cin >> redo;

		if (redo != 1 && redo != 0)
		{
			std::cout << "Please enter a valid option\n";
			system("pause");
			goto choice;
		}

	} while (redo != 0);

	system("pause");
    return 0;
}

void work()
{
	int workSec = 1200;
	std::cout << "\aWork time!\n";
	clock_t delay = workSec * CLOCKS_PER_SEC;
	
	clock_t start = clock();

	while (clock() - start < delay)
		;
}

void Break()
{
	int breakSec = 300;
	std::cout << "\aBreak time!\n";
	clock_t delay = breakSec * CLOCKS_PER_SEC;

	clock_t start = clock();

	while (clock() - start < delay)
		;

	//Message box
	MessageBox(nullptr, TEXT("Press Ok to continue..."), TEXT("Break Done"), MB_OK);

}
