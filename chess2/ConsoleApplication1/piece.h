#pragma once

class Piece {
public:
	char type;	//Type of piece
	char team;	//Black or White
	Piece();
	Piece(char type, char team);
	virtual bool move(Piece moveTo);
};