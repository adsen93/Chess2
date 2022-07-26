#include "piece.h"

Piece::Piece()
{
}

Piece::Piece(char type, char team)
{
	this->type = type;
	this->team = team;
}

bool Piece::move(Piece moveTo)
{
	return false;
}






