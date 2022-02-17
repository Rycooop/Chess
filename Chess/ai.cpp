#include "includes.h"


Piece* Ai::getRandomPiece()
{
	Piece* curr;

	for (int i = 1; i < 20; i++)
	{
		curr = GameBoard[rand() % 8][rand() % 8];

		if (curr)
		{
			if (curr->getColor() == 1)
				return curr;
		}
	}

	return NULL;
}

void Ai::getBestMove(Piece* piece, Vec2& move)
{
	for (int i = 1; i < 100; i++)
	{
		int x = rand() % 8;
		int y = rand() % 8;

		if (piece->isValidMove(GameBoard, x, y))
		{
			move.x = x;
			move.y = y;
		}
	}
}
