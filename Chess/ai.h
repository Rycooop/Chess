#include "pieces.hpp"


struct Vec2
{
	float x, y;
};

namespace Ai
{
	Piece* getRandomPiece();
	void getBestMove(Piece* piece, Vec2& move);
}