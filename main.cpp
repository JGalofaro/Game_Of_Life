#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

const int maxSize = 20;
char board [maxSize][maxSize];
const char life = '*';
const char blank = ' ';

void createBoard()
{
	for( int i = 0; i <= maxSize; i++ )
		for( int j = 0; j <= maxSize; j++ )
			board[i][j] = blank;
}

void showBoard()
{
	for( int i = 0; i <= maxSize; i++ )
	{
		for( int j = 0; j <= maxSize; j++ )
			cout << board[i][j] << " ";
		cout << endl;
	}
}

void clearPrompt()
{
	system("clear");
}

//Needs to deal with game's boarders
int neighbourCount(int X, int Y)
{
	int count = 0;
	cerr << "NEIGHCOUNT-1" << endl;

	if( X == 0 && Y == 0 )
	{
		cerr << "NEIGHCOUNT-2" << endl;
		if( board[maxSize-1][maxSize+2] == life ) count++;
		if( board[maxSize-1][maxSize+1] == life ) count++;
		if( board[maxSize-1][maxSize-2] == life ) count++;
		if( board[maxSize-1][Y] == life ) count++;
		if( board[X+1][Y] == life ) count++;
		if( board[X+1][Y-1] == life ) count++;
		if( board[X][Y-1] == life ) count++;
		if( board[X-1][Y-1] == life ) count++;

	}
	else if( X == maxSize-1 && Y == maxSize-1 )
	{
		cerr << "NEIGHCOUNT-3" << endl;
		if( board[X+1][Y+1] == life ) count++;
		if( board[X][Y+1] == life ) count++;
		if( board[0][Y+1] == life ) count++;
		if( board[X+1][Y] == life ) count++;
		if( board[0][Y] == life ) count++;
		if( board[X+1][0] == life ) count++;
		if( board[X][0] == life ) count++;
		if( board[0][0] == life ) count++;

	}
	else if( X == 0 )
	{
		cerr << "NEIGHCOUNT-4" << endl;
		if( board[maxSize-1][Y+1] == life ) count++;
		if( board[X][Y+1] == life ) count++;
		if( board[X+1][Y+1] == life ) count++;
		if( board[maxSize-1][Y] == life ) count++;
		if( board[X+1][Y] == life ) count++;
		if( board[maxSize-1][Y-1] == life ) count++;
		if( board[X][Y-1] == life ) count++;
		if( board[X+1][Y-1] == life ) count++;
	}
	else if( X == maxSize-1 )
	{
		cerr << "NEIGHCOUNT-5" << endl;
		if( board[maxSize-2][Y+1] == life ) count++;
		if( board[maxSize-1][Y+1] == life ) count++;
		if( board[0][Y+1] == life ) count++;
		if( board[maxSize-2][Y] == life ) count++;
		if( board[0][Y] == life ) count++;
		if( board[maxSize-2][Y-1] == life ) count++;
		if( board[maxSize-1][Y-1] == life ) count++;
		if( board[0][Y-1] == life ) count++;
	}
	else if( Y == 0 )
	{
		cerr << "NEIGHCOUNT-6" << endl;
		if( board[X-1][Y+1] == life ) count++;
		if( board[X][Y+1] == life ) count++;
		if( board[X+1][Y+1] == life ) count++;
		if( board[X-1][Y] == life ) count++;
		if( board[X+1][Y] == life ) count++;
		if( board[X-1][maxSize-2] == life ) count++;
		if( board[X][maxSize-2] == life ) count++;
		if( board[X+1][maxSize-2] == life ) count++;
	}
	else if( Y == maxSize-1 )
	{
		cerr << "NEIGHCOUNT-7" << endl;
		if( board[X-1][1] == life ) count++;
		if( board[X][1] == life ) count++;
		if( board[X+1][1] == life ) count++;
		if( board[X-1][Y] == life ) count++;
		if( board[X+1][Y] == life ) count++;
		if( board[X-1][Y-1] == life ) count++;
		if( board[X][Y-1] == life ) count++;
		if( board[X+1][Y-1] == life ) count++;
	}
	else
	{
		cerr << "NEIGHCOUNT-8" << "\t" << X << "\t" << Y << endl;
		if( board[X-1][Y+1] == life ) count++;
		cerr << "NEIGHCOUNT-9" << endl;
		if( board[X][Y+1] == life ) count++;
		cerr << "NEIGHCOUNT-A" << endl;
		if( board[X+1][Y+1] == life ) count++;
		cerr << "NEIGHCOUNT-B" << endl;
		if( board[X-1][Y] == life ) count++;
		cerr << "NEIGHCOUNT-C" << endl;
		if( board[X+1][Y] == life ) count++;
		cerr << "NEIGHCOUNT-D" << endl;
		if( board[X-1][Y-1] == life ) count++;
		cerr << "NEIGHCOUNT-E" << endl;
		if( board[X][Y-1] == life ) count++;
		cerr << "NEIGHCOUNT-F" << endl;
		if( board[X-1][Y-1] == life ) count++;
	}
	return count;
}

int popCount()
{
	int count = 0;

	for( int i = 0; i <= maxSize; i++ )
		for( int j = 0; j <= maxSize; j++ )
			if( board[i][j] == life ) count++; 
	cerr << "POPCOUNT-1" << endl;
	return count;
}

void populate(int state)
{
	srand( time(NULL) );
	if( state == 1 )	//Creating life
	{
		for( int i = 0; i <= maxSize; i++ )
		{
			for( int j = 0; j <= maxSize; j++ )
			{
				if( ((rand() % 2) + 1) == 1 )
					board[i][j] = life;
			}
		}
	}
	//State 2 == every other cell
	//State 3 == three in a row alive, following two blank
}

void nextGen()
{
	cerr << "NEXTGEN-1" << endl;
	int neighCount = 0;
	char temp[maxSize][maxSize];

	for( int i = 0; i <= maxSize; i++)
		for( int j = 0; j <= maxSize; j++ )
			temp[i][j] = blank;

	for( int i = 0; i <= maxSize; i++ )
	{
		for( int j = 0; j <= maxSize; j++ )
		{
			neighCount = neighbourCount(i, j);
			if( board[i][j] == life ){
				/* Any live cell with fewer than two
				   living neighbours dies */
				if( neighCount < 2 )
				{
					temp[i][j] = blank;
				}
				/* Any live cell with 2 or 3 living
				   neighbours lives on */
				else if( neighCount == 2 || neighCount == 3 )
				{
					temp[i][j] = life;
				}
				/* Any live cell with more than 3 
				   neighbours dies */
				else if( neighCount > 3 )
				{
					temp[i][j] = blank;
				}
			}else{
				/* If a dead cell has 3 live neightbours
				   it becomes a live cell */
				if( neighCount == 3 )
				{
					temp[i][j] = life;
				}
			}
		}
	}
	cerr << "BOARDSWAP-1" << endl;
	for( int i = 0; i <= maxSize; i++ )
		for( int j = 0; j <= maxSize; j++ )
			board[i][j] = temp[i][j];
}
int main( int argc, char *argv[] )
{
	int genLevel = 0;
	int pop = 0;
	cout << "Conway's Game Of Life" << endl;
	
	createBoard();
	populate(1);
	pop = popCount();
	showBoard();

	clearPrompt();	
	cout.flush();
	while( 1 )
	{
		cout << "Conway's Game of Life \t\t Generation: ";
		cout << genLevel;
		cout << "\t\t Population Size: " << pop << endl;
		showBoard();
		sleep(1);
		if( pop == 0 ) break;
		clearPrompt();
		nextGen();
		pop = popCount();
		cout.flush();
		genLevel++;
	}
	return 0;
}
