//@author--Omar Faruk

#include <bits/stdc++.h>
#define N_INF - 10000
#define P_INF 10000
using namespace std;

char human = 'X';
char AI = 'O';
char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char player1[10], player2[10];
int i, player, p=-1;
string str;
void check(char);

int decision()
{
	if ((board[0] == 'X' && board[1] == 'X' && board[2] == 'X') || (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') || (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') || (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') || (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') || (board[2] == 'X' && board[5] == 'X' && board[8] == 'X'))
		return (2);
	else if ((board[0] == 'O' && board[1] == 'O' && board[2] == 'O') || (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') || (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') || (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') || (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') || (board[2] == 'O' && board[5] == 'O' && board[8] == 'O'))
		return (3);
	else if ((board[2] == 'X' && board[4] == 'X' && board[6] == 'X') || (board[0] == 'X' && board[4] == 'X' && board[8] == 'X'))
		return (2);
	else if ((board[2] == 'O' && board[4] == 'O' && board[6] == 'O') || (board[0] == 'O' && board[4] == 'O' && board[8] == 'O'))
		return (3);
	else if (board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4' && board[4] != '5' && board[5] != '6' && board[6] != '7' && board[7] != '8' && board[8] != '9')
		return (4);
	else
		return 5;

}

bool isMovesLeft()
{
	for (int i = 0; i < 9; i++)
	{
		if (board[i] != 'O' && board[i] != 'X')
		{
			return true;
		}
	}

	return false;
}

int score(int dept)
{
	if ((board[0] == 'X' && board[1] == 'X' && board[2] == 'X') || (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') || (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') || (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') || (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') || (board[2] == 'X' && board[5] == 'X' && board[8] == 'X'))
		return -10 + dept;
	if ((board[0] == 'O' && board[1] == 'O' && board[2] == 'O') || (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') || (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') || (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') || (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') || (board[2] == 'O' && board[5] == 'O' && board[8] == 'O'))
		return +10 - dept;
	if ((board[2] == 'X' && board[4] == 'X' && board[6] == 'X') || (board[0] == 'X' && board[4] == 'X' && board[8] == 'X'))
		return -10 + dept;
	if ((board[2] == 'O' && board[4] == 'O' && board[6] == 'O') || (board[0] == 'O' && board[4] == 'O' && board[8] == 'O'))
		return +10 - dept;

	return 0;

}

int minimax(int dept, bool isMaximizing)
{
	int result = score(dept);
	if (result != 0)
	{
		return result;
	}

	if (isMovesLeft() == false)
	{
		return 0;
	}

	if (isMaximizing)
	{
		int bestScore = N_INF;
		for (int i = 0; i < 9; i++)
		{
			if (board[i] != 'X' && board[i] != 'O')
			{
				board[i] = AI;
				int score = minimax(dept - 1, false);
				board[i] = (i + 1 + '0');
				bestScore = max(bestScore, score);

			}
		}

		return bestScore;
	}
	else
	{
		int bestScore = P_INF;
		for (int i = 0; i < 9; i++)
		{
			if (board[i] != 'X' && board[i] != 'O')
			{
				board[i] = human;
				int score = minimax(dept + 1, true);
				board[i] = (i + 1 + '0');
				bestScore = min(bestScore, score);

			}
		}

		return bestScore;
	}
}

int findBestMove()
{
	int bestMove = -10000;
	int index = -1;
	for (int i = 0; i < 9; i++)
	{
		if (board[i] != 'X' && board[i] != 'O')
		{
			board[i] = AI;
			int moveValue = minimax(0, false);
			board[i] = (i + 1 + '0');
			if (moveValue > bestMove)
			{
				bestMove = moveValue;
				index = i;
			}
		}
	}

	return index;
}

void gamename()
{
	cout << "\t\t\t\tTic Tac Toe\n";
}

void display()
{
	printf("\n\t\t\t---------------------------------\n");
	printf("\t\t\t|          |          |         |\n");
	printf("\t\t\t|    %c     |    %c     |    %c    |\n", board[0], board[1], board[2]);
	printf("\t\t\t|          |          |         |\n");
	printf("\t\t\t|-------------------------------|\n");
	printf("\t\t\t|          |          |         |\n");
	printf("\t\t\t|    %c     |    %c     |    %c    |\n", board[3], board[4], board[5]);
	printf("\t\t\t|          |          |         |\n");
	printf("\t\t\t|-------------------------------|\n");
	printf("\t\t\t|          |          |         |\n");
	printf("\t\t\t|    %c     |    %c     |    %c    |\n", board[6], board[7], board[8]);
	printf("\t\t\t|          |          |         |\n");
	printf("\t\t\t--------------------------------\n");

}

void mode()
{
	cout << "\tIf you want to play with machine type yes otherwise no  :";
	cin >> str;
}

void symbol_name()
{
	cout << "\tPlayer 1 symbol: X\n";
	cout << "\tPlayer 2 symbol: O\n";
	mode();
	cout << "\tEnter player 1 name:";
	cin >> player1;
	scanf("");
	if (str == "yes") {}
	else if (str == "no")
	{
		cout << "\tEnter player 2 name:";
		cin >> player2;
	}
}

void start()
{
	cout << "\tEnter who will start the game : player 1 or player 2\n";
	scanf("%d", &player);
	getchar();
}

void play()
{
	char position;
	if (player == 1)
	{
		if (str == "yes" && p!=-1)
		{
			cout << "\t AI choose " << p + 1 << endl;
		}

		cout << "\t " << player1 << " enter the position\n";
		scanf("%s", &position);
		check(position);
	}
	else if (player == 2)
	{
		if (str == "yes")
		{
			p = findBestMove();
			position = p + 1 + '0';
			check(position);
		}
		else if (str == "no")
		{
			cout << "\t " << player2 << " enter the position\n";
			scanf("%s", &position);
			check(position);
		}
	}
}

void check(char position)
{
	int i;
	if (player == 1)
	{
		for (i = 0; i < 9; i++)
		{
			if (board[i] == position)
			{
				board[i] = 'X';
				player = 2;

			}
		}
	}
	else if (player == 2)
	{
		for (i = 0; i < 9; i++)
		{
			if (board[i] == position)
			{
				board[i] = 'O';
				player = 1;
			}
		}
	}
}

int main()
{
	int win, c, again = 1;
	system("clear");
	while (again)
	{
		win = 0;
		c = 1;
		system("clear");
		display();
		symbol_name();
		start();
		play();

		while (c)	//here c means the game will continue untill someone win//
		{
			system("clear");
			gamename();
			display();
			play();
			win = decision();
			system("clear");
			display();
			if (win == 2)
			{
				cout << "\n\t\t\t " << player1 << " You won the match\n\n";
				c = 0;
			}
			else if (win == 3)
			{
				if (str == "yes")
				{
					cout << "\t\tAI You won the match\n\n";
					c = 0;
				}
				else
				{
					cout << "\t\t " << player2 << " You won the match\n\n";
					c = 0;
				}
			}
			else if (win == 4)
			{
				cout << "\t\t This match is draw\n\t\tBoth of you played well!!\n\n";
				c = 0;
			}
			else
			{
				c = 1;
			}
		}

		cout << "Do you want to play again: If yes enter 1 otherwise enter 0\n";
		scanf("%d%*c", &again);
		if (again == 1)
		{
			board[0] = '1';
			board[1] = '2';
			board[2] = '3';
			board[3] = '4';
			board[4] = '5';
			board[5] = '6';
			board[6] = '7';
			board[7] = '8';
			board[8] = '9';
		}
	}

	printf("\tTHANKS FOR PLAYING\n");

}