#pragma once
#include "player.hpp"


class Piece
{
public:
	
	Piece() {};
	~Piece() {};

	virtual char getPiece() = 0;
	virtual bool isValidMove(Piece* GameBoard[8][8], int x, int y) = 0;
	virtual bool isAlive() = 0;
	
	void setColor(int col)
	{
		this->color = col;
	}

	int getColor()
	{
		return this->color;
	}

	int currX, currY;
	bool isCurr = false;
	int numMoves = 0;

private:
	int color;
};

class Pawn : public Piece
{
public:

	Pawn() {};
	~Pawn() {};

private:
	bool alive = true;

	char getPiece()
	{
		return 'P';
	}

	bool isValidMove(Piece* GameBoard[8][8], int x, int y)
	{
		if (this->getColor() == 0)
		{
			if (numMoves == 0 && x == currX && ((y == currY - 1) || (y == currY - 2)) && GameBoard[currX][y] == 0)
			{
				numMoves++;
				return true;
			}
			else if (numMoves && x == currX && y == currY - 1 && GameBoard[currX][y] == 0)
			{
				numMoves++;
				return true;
			}
			else return false;
		}
		else if (this->getColor() == 1)
		{
			if (numMoves == 0 && x == currX && ((y == currY + 1) || (y == currY + 2)) && GameBoard[currX][y] == 0)
			{
				numMoves++;
				return true;
			}
			else if (numMoves && x == currX && y == currY + 1 && GameBoard[currX][y] == 0)
			{
				numMoves++;
				return true;
			}
			else return false;
		}
		
	}

	bool isAlive()
	{
		return alive;
	}

};

class King : public Piece
{
public:
	King() {};
	~King() {};

private:
	bool alive = true;

	char getPiece()
	{
		return 'K';
	}
	bool isValidMove(Piece* GameBoard[8][8], int x, int y)
	{
		if ((this->currX == x - 1 || this->currX == x || this->currX == x + 1) && (this->currY == y - 1 || this->currY == y || this->currY == y + 1) && GameBoard[x][y] == 0)
			return true;
		else return false;
	}

	bool isAlive()
	{
		return alive;
	}
};

class Queen : public Piece
{
public:
	Queen() {};
	~Queen() {};

private:
	bool alive = true;

	char getPiece()
	{
		return 'Q';
	}
	bool isValidMove(Piece* GameBoard[8][8], int x, int y)
	{
		return true;
	}

	bool isAlive()
	{
		return alive;
	}
};

class Knight : public Piece
{
public:
	Knight() {};
	~Knight() {};

private:
	bool alive = true;

	char getPiece()
	{
		return 'N';
	}
	bool isValidMove(Piece* GameBoard[8][8], int x, int y)
	{	
		if ((this->currX == x - 1 || this->currX == x + 1) && (this->currY == y + 2 || this->currY == y - 2) && GameBoard[x][y] == 0)
			return true;
		else if ((this->currX == x - 2 || this->currX == x + 2) && (this->currY == y + 1 || this->currY == y - 1) && GameBoard[x][y] == 0)
			return true;
		else return false;
	}

	bool isAlive()
	{
		return alive;
	}
};

class Rook : public Piece
{
public:
	Rook() {};
	~Rook() {};

private:
	bool alive = true;

	char getPiece()
	{
		return 'R';
	}
	bool isValidMove(Piece* GameBoard[8][8], int x, int y)
	{
		if (this->currX == x && GameBoard[x][y] == 0)
		{
			if (this->currY < y)
			{
				for (int i = this->currY + 1; i < y; i++)
				{
					if (GameBoard[x][i] != 0)
						return false;
				}
				return true;
			}
			else if (this->currY > y)
			{
				for (int i = this->currY - 1; i > y; i--)
				{
					if (GameBoard[x][i] != 0)
						return false;
				}
				return true;
			}
			else return false;
		}
		else if (this->currY == y && GameBoard[x][y] == 0)
		{
			if (this->currX < x)
			{
				for (int i = this->currX + 1; i < x; i++)
				{
					if (GameBoard[i][y] != 0)
						return false;
				}
				return true;
			}
			else if (this->currX > x)
			{
				for (int i = this->currX - 1; i > x; i--)
				{
					if (GameBoard[i][y] != 0)
						return false;
				}
				return true;
			}
			else return false;
		}
		else return false;
	}

	bool isAlive()
	{
		return alive;
	}
};

class Bishop : public Piece
{
public:
	Bishop() {};
	~Bishop() {};

private:
	bool alive = true;

	char getPiece()
	{
		return 'B';
	}
	bool isValidMove(Piece* GameBoard[8][8], int x, int y)
	{
		if (x < currX && y < currY)
		{
			for (int i = currX; i >= x; i--)
			{
				for (int j = currY; j >= i; j--)
				{

				}
			}
			return true;
		}
		else if (x < currX && y > currY)
		{

		}
		else if (x > currX && y < currY)
		{

		}
		else if (x > currX && y > currY)
		{
			
		}
		else return false;
	}

	bool isAlive()
	{
		return alive;
	}
};