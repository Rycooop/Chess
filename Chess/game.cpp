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

	//White team
	GameBoard[0][7] = new Rook();
	GameBoard[1][7] = new Knight();
	GameBoard[2][7] = new Bishop();
	GameBoard[3][7] = new Queen();
	GameBoard[4][7] = new King();
	GameBoard[5][7] = new Bishop();
	GameBoard[6][7] = new Knight();
	GameBoard[7][7] = new Rook();
	GameBoard[0][7]->setColor(0);
	GameBoard[1][7]->setColor(0);
	GameBoard[2][7]->setColor(0);
	GameBoard[3][7]->setColor(0);
	GameBoard[4][7]->setColor(0);
	GameBoard[5][7]->setColor(0);
	GameBoard[6][7]->setColor(0);
	GameBoard[7][7]->setColor(0);

	//Black team
	GameBoard[0][0] = new Rook();
	GameBoard[1][0] = new Knight();
	GameBoard[2][0] = new Bishop();
	GameBoard[3][0] = new Queen();
	GameBoard[4][0] = new King();
	GameBoard[5][0] = new Bishop();
	GameBoard[6][0] = new Knight();
	GameBoard[7][0] = new Rook();
	GameBoard[0][0]->setColor(1);
	GameBoard[1][0]->setColor(1);
	GameBoard[2][0]->setColor(1);
	GameBoard[3][0]->setColor(1);
	GameBoard[4][0]->setColor(1);
	GameBoard[5][0]->setColor(1);
	GameBoard[6][0]->setColor(1);
	GameBoard[7][0]->setColor(1);

	return TRUE;
}