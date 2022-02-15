#pragma once
#include "player.hpp"


class Piece
{
public:
	
	Piece() {};
	~Piece() {};

	virtual char getPiece() = 0;
	virtual bool isValidMove(int x, int y) = 0;
	virtual bool isAlive() = 0;
	
	void setColor(int col)
	{
		this->color = col;
	}

	int getColor()
	{
		return this->color;
	}

private:
	int color;
};

class Pawn : public Piece
{
public:

	Pawn() {};
	~Pawn() {};

private:
	int color = 0;
	bool alive = true;

	char getPiece()
	{
		return 'P';
	}

	bool isValidMove(int x, int y)
	{
		return true;
	}

	bool isAlive()
	{
		return alive;
	}

};