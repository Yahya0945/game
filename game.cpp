#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class TicTacToe {
	
public:
	bool gameEnd = false;
	//constructor
	TicTacToe(){}

	// 
	void Menu()
	{
		char board[3][3];
		cout << "***----------------------*** Menu ***--------------------***\n\n";
		cout << "The positions in the borad are numbered as following matrix.\n You have to follow these position numbers for input." << endl;
		cout << "__________________\n\n";
		int tempCount = 1;
		for (int i = 0; i < 3; i++)
		{
			cout << "| ";
			for (int j = 0; j < 3; j++)
			{
				cout <<tempCount << "  |  ";
				tempCount++;
			}

			cout << endl;
			cout << "__________________\n";
			cout << endl;
		}
	}

	void printBoard(char board[][3])
	{
		cout << "__________________\n\n";
		for (int i = 0; i < 3; i++)
		{
			cout << "| ";
			for (int j = 0; j < 3; j++)
			{
				cout << board[i][j] << "  |  ";
			}

			cout << endl;
			cout << "__________________\n";
			cout << endl;
		}
	}

	
	int checkWin(char board[][3])
	{
		int c1 = 0, c2 = 0;
		// check rows
		for (int i = 0; i < 3; i++)
		{
			c1 = 0;
			c2 = 0;
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == 'X')
				{
					c1 += 1;
				}
				else if (board[i][j] == 'O')
				{
					c2 += 1;
				}
			}
			
			if (c1 == 3)
			{
				gameEnd = true;
				return 1;
			}
			else if (c2 == 3)
			{
				gameEnd = true;
				return 2;
			}
		}

		// check columns
		for (int i = 0; i < 3; i++)
		{
			c1 = 0;
			c2 = 0;
			for (int j = 0; j < 3; j++)
			{
				if (board[j][i] == 'X')
				{
					c1 += 1;
				}
				else if (board[j][i] == 'O')
				{
					c2 += 1;
				}
			}
			if (c1 == 3)
			{
				gameEnd = true;
				return 1;
			}
			else if (c2 == 3)
			{
				gameEnd = true;
				return 2;
			}

		}

		//check diagonals

		//check left diagonal
		c1 = 0;
		c2 = 0;
		for (int i = 0; i < 3; i++)
		{
			if (board[i][i] == 'X')
			{
				c1++;
			}
			if (board[i][i] == 'O')
			{
				c2++;
			}
		}
		if (c1 == 3)
		{
			gameEnd = true;
			return 1;
		}
		if (c2 == 3)
		{
			gameEnd = true;
			return 2;
		}

		c1 = 0;
		c2 = 0;
		// check right diagonal
		for (int i = 0, j = 2; i < 3; i++, j--)
		{
			if (board[i][j] == 'X')
			{
				c1++;
			}
			if (board[i][j] == 'O')
			{
				c2++;
			}
		}
		if (c1 == 3)
		{
			gameEnd = true;
			return 1;
		}
		else if (c2 == 3)
		{
			gameEnd = true;
			return 2;
		}

		// Check if the game is draw
		c1 = 0;
		c2 = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == 'X')
				{
					c1++;
				}
				if (board[i][j] == 'O')
				{
					c2++;
				}
			}
		}

		//Check Withdraw condition
		if (c1 + c2 == 9)
		{
			gameEnd = true;
			c1 = 0;
			c2 = 0;
			return -1;
		}
		return 0;
	}


	void Game()
	{
		// Step# 0 : Print the Menu
		Menu();
		
		int choice ;
		cout << "\n Press 1 to continue...";
		cout << "\n Press 0 to exit";
		cin >> choice;
		if (choice == 0)
		{
			exit(0);
		}
		
		//Step# 1: Draw the board
		char board[3][3];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = ' ';

			}
		}

		printBoard(board);

		// Step2: Set the players
		string player1;
		string player2;
		//Step#2: Set the players
		cout << "Enter the name of palyer 1: ";
		cin >> player1;
		cout << "Enter the name of player 2:";
		cin >> player2;


		//Step#3: Set the turns
		int turn = 1;
		int position;
		int win = 0;
		// Step#5: place the sign on the board
		
		while (gameEnd == false)
		{
			//Step#4: Take the player input
			system("CLS");
			printBoard(board);
			if (turn == 1)
			{
				cout << "\nIt's "<<player1<<" turn.\n";
			}
			else if (turn == 2)
			{
				cout << "\nIt's "<<player2<<" turn. \n";
			}
			cout << "Enter the position where you want to place your sign ";
			cin >> position;
			while (position < 1 || position> 9)
			{
				cout << "Invalid position. Please enter the correct position";
				cin >> position;
			}
			int row = (position-1) / 3;  // (1-1)/3 = 0  
			int col = (position-1) % 3;  // (1-1) % 3  = 0
			
			while ( position < 1 || position > 9)
			{
				if (board[row][col] != ' ')

				{
					
					cout << "\nThe position is invalid. Enter an empty position number please:  ";
					cin >> position;
				}
			}
			row = (position - 1) / 3;  // (1-1)/3 = 0  
			col = (position - 1) % 3;  // (1-1) % 3  = 0
			if (turn == 1)
			{
				if (board[row][col] == ' ')
				{
					board[row][col] = 'X';
					turn++;
				}
				
				
			}
			else {
				if (board[row][col] == ' ') {
					board[row][col] = 'O';
					turn--;
				}
			}

			// Check Win

			win = checkWin(board);
			if (win == -1 && gameEnd == true)
			{

				system("CLS");
				printBoard(board);
				cout << "The game is draw \n";
			}

			else if (gameEnd == true && win!=-1)
			{
				system("CLS");
				printBoard(board);
				if (win == 1)
				{
					cout <<player1 <<" has won the game." << endl;
				}
				if (win == 2)
				{
					cout << player2<<" has won the game." << endl;

				}

			}
		}
		

	}

};