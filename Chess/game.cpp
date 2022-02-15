#include "includes.h"

Piece* GameBoard[8][8];


BOOL Game::initGame()
{

	for (int rRow = 0; rRow < 8; rRow++)
	{
		for (int rCol = 0; rCol < 8; rCol++)
		{
			GameBoard[rRow][rCol] = 0;
		}
	}

	//black team
	for (int i = 0; i < 8; i++)
	{
		GameBoard[i][1] = new Pawn();
		GameBoard[i][1]->setColor(1);
	}

	//white team
	for (int i = 0; i < 8; i++)
	{
		GameBoard[i][6] = new Pawn();
		GameBoard[i][6]->setColor(0);
	}

	return TRUE;
}