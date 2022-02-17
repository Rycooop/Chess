#include "includes.h"


Piece* GameBoard[8][8];
bool whosTurn = true, aiActive = true;

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
		GameBoard[i][1]->currX = i;
		GameBoard[i][1]->currY = 1;
	}

	//white team
	for (int i = 0; i < 8; i++)
	{
		GameBoard[i][6] = new Pawn();
		GameBoard[i][6]->setColor(0);
		GameBoard[i][6]->currX = i;
		GameBoard[i][6]->currY = 6;
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
	
	for (int i = 0; i < 8; i++)
	{
		GameBoard[i][7]->setColor(0);
		GameBoard[i][7]->currX = i;
		GameBoard[i][7]->currY = 7;
	}

	//Black team
	GameBoard[0][0] = new Rook();
	GameBoard[1][0] = new Knight();
	GameBoard[2][0] = new Bishop();
	GameBoard[3][0] = new Queen();
	GameBoard[4][0] = new King();
	GameBoard[5][0] = new Bishop();
	GameBoard[6][0] = new Knight();
	GameBoard[7][0] = new Rook();

	for (int i = 0; i < 8; i++)
	{
		GameBoard[i][0]->setColor(1);
		GameBoard[i][0]->currX = i;
		GameBoard[i][0]->currY = 0;
	}

	return TRUE;
}

VOID Game::updateGame()
{
	Piece* currPiece = 0;
	int nextX, nextY;
	bool isMove = false, isTurn = true;

	while (true)
	{
		static POINT Mouse;
		GetCursorPos(&Mouse);
		Mouse.x -= gameX;
		Mouse.y -= gameY + 25;


		//AI ON
		if (aiActive)
		{
			if (!isTurn && !isMove)
			{
				currPiece = Ai::getRandomPiece();
				Vec2 move;
				if (currPiece)
				{
					Ai::getBestMove(currPiece, move);
					nextX = move.x;
					nextY = move.y;
					isMove = !isMove;
				}
			}

			if ((GetAsyncKeyState(VK_LBUTTON) & 1) && !isMove && isTurn)
			{

				if (Mouse.x >= 0 && Mouse.x <= 560 && Mouse.y >= 0 && Mouse.y <= 560)
				{
					if (currPiece != 0 && (GameBoard[(int)(Mouse.x / 70)][(int)(Mouse.y / 70)] == 0 || currPiece->getColor() != GameBoard[(int)(Mouse.x / 70)][(int)(Mouse.y / 70)]->getColor()))
					{
						nextX = (int)(Mouse.x / 70);
						nextY = (int)(Mouse.y / 70);
						isMove = true;
					}
					else
					{
						if (currPiece)
							currPiece->isCurr = false;

						if (GameBoard[(int)(Mouse.x / 70)][(int)(Mouse.y / 70)] != 0)
						{
							currPiece = GameBoard[(int)(Mouse.x / 70)][(int)(Mouse.y / 70)];
							currPiece->isCurr = true;
						}
					}
				}
			}
			else if (isMove)
			{
				if (currPiece != 0)
				{
					if (whosTurn && currPiece->getColor() != 0)
					{
						currPiece->isCurr = false;
						currPiece = 0;
						isMove = false;
					}
					else if (!whosTurn && currPiece->getColor() != 1)
					{
						currPiece->isCurr = false;
						currPiece = 0;
						isMove = false;
					}
					else if (currPiece->isValidMove(GameBoard, nextX, nextY))
					{
						currPiece->numMoves++;
						GameBoard[nextX][nextY] = GameBoard[currPiece->currX][currPiece->currY];
						GameBoard[currPiece->currX][currPiece->currY] = 0;
						currPiece->currX = nextX;
						currPiece->currY = nextY;
						whosTurn = !whosTurn;
						isTurn = !isTurn;
					}
					if (currPiece)
						currPiece->isCurr = false;

					currPiece = 0;
					isMove = false;

				}
			}
		}

		//AI NOT ON
		else if (!aiActive)
		{
			if ((GetAsyncKeyState(VK_LBUTTON) & 1) && !isMove)
			{

				if (Mouse.x >= 0 && Mouse.x <= 560 && Mouse.y >= 0 && Mouse.y <= 560)
				{
					if (currPiece != 0 && (GameBoard[(int)(Mouse.x / 70)][(int)(Mouse.y / 70)] == 0 || currPiece->getColor() != GameBoard[(int)(Mouse.x / 70)][(int)(Mouse.y / 70)]->getColor()))
					{
						nextX = (int)(Mouse.x / 70);
						nextY = (int)(Mouse.y / 70);
						isMove = true;
					}
					else
					{
						if (currPiece)
							currPiece->isCurr = false;

						if (GameBoard[(int)(Mouse.x / 70)][(int)(Mouse.y / 70)] != 0)
						{
							currPiece = GameBoard[(int)(Mouse.x / 70)][(int)(Mouse.y / 70)];
							currPiece->isCurr = true;
						}
					}
				}
			}

			else if (isMove)
			{
				if (currPiece != 0)
				{
					if (whosTurn && currPiece->getColor() != 0)
					{
						currPiece->isCurr = false;
						currPiece = 0;
						isMove = false;
					}
					else if (!whosTurn && currPiece->getColor() != 1)
					{
						currPiece->isCurr = false;
						currPiece = 0;
						isMove = false;
					}
					else if (currPiece->isValidMove(GameBoard, nextX, nextY))
					{
						currPiece->numMoves++;
						GameBoard[nextX][nextY] = GameBoard[currPiece->currX][currPiece->currY];
						GameBoard[currPiece->currX][currPiece->currY] = 0;
						currPiece->currX = nextX;
						currPiece->currY = nextY;
						whosTurn = !whosTurn;
					}
					if (currPiece)
						currPiece->isCurr = false;

					currPiece = 0;
					isMove = false;

				}
			}
		}
	}
}
