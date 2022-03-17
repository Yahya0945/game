#include<iostream>
#include<string>
#include "game.cpp"
using namespace std;


int main()
{
	// Step1: set the board
	

	int choice = 1;
	while (choice == 1) {

		TicTacToe game;

		game.Game();
		cout << "Press 1 to play again." << endl;
		cout << "Press 0 to exit the game." << endl;
		cin >> choice;
		if (choice == 0)
		{
			exit(0);
		}
		system("CLS");
		cout << endl;
	}
	system("pause");
	return 0;
};