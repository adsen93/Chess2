#pragma once
#include "allPieces.h"

class GameBoard {
public:
	Piece board[64];
	Piece currentPiece;
	int currentPieceIndex;
	bool whiteTurn;
	GameBoard();
	void selectPiece(int boardSpot);
	bool validateMove(int boardSpot);
	void movePiece(int boardSpot);
	bool queenCollisionCheck(int boardSpot);
};

