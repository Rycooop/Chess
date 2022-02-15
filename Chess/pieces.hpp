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
	bool isValidMove(int x, int y)
	{
		return true;
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
	bool isValidMove(int x, int y)
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
	bool isValidMove(int x, int y)
	{
		return true;
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
	bool isValidMove(int x, int y)
	{
		return true;
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
	bool isValidMove(int x, int y)
	{
		return true;
	}

	bool isAlive()
	{
		return alive;
	}
};