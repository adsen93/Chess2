#include "Gameboard.h"

GameBoard::GameBoard()
{   
    whiteTurn = true;
    pieceTakenLastTurn = false;
    //Initialize the board
    /*
     [C] [M] [F] [Q] [K] [F] [M] [C]       0-7
     [F] [F] [E] [F] [F] [E] [F] [F]       8-15
     [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]       16-23
     [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]       24-31
     [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]       32-39 
     [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]       40-47 
     [F] [F] [E] [F] [F] [E] [F] [F]       48-55 
     [C] [M] [F] [Q] [K] [F] [M] [C]       56-63 
    */

    //Crows
    board[0] = Crow('c','w');
    board[7] = Crow('c', 'w');

    board[56] = Crow('c', 'b');
    board[63] = Crow('c', 'b');

    //Monkeys
    board[1] = Monkey('m', 'w');
    board[6] = Monkey('m', 'w');

    board[57] = Monkey('m', 'b');
    board[62] = Monkey('m', 'b');

    //Elephants
    board[10] = Elephant('e', 'w');
    board[13] = Elephant('e', 'w');

    board[50] = Elephant('e', 'b');
    board[53] = Elephant('e', 'b');

    //Fishes
    board[2] = Fish('f', 'w');
    board[5] = Fish('f', 'w');
    board[8] = Fish('f', 'w');
    board[9] = Fish('f', 'w');
    board[11] = Fish('f', 'w');
    board[12] = Fish('f', 'w');
    board[14] = Fish('f', 'w');
    board[15] = Fish('f', 'w');

    board[48] = Fish('f', 'b');
    board[49] = Fish('f', 'b');
    board[51] = Fish('f', 'b');
    board[52] = Fish('f', 'b');
    board[54] = Fish('f', 'b');
    board[55] = Fish('f', 'b');
    board[58] = Fish('f', 'b');
    board[61] = Fish('f', 'b');

    //Queens
    board[3] = Queen('q', 'w');
 
    board[59] = Queen('q', 'b');
  
    //Kings
    board[4] = King('k', 'w');

    board[60] = King('k', 'b');

    //Empty spaces, z
    for (int i = 16; i < 48; i++)
        board[i] = Piece('z', 'z');
}

void GameBoard::selectPiece(int boardSpot)
{
    if (whiteTurn && board[boardSpot].team == 'w')
    {
        currentPiece = board[boardSpot];
        currentPieceIndex = boardSpot;
        return;
    }


    if (!whiteTurn && board[boardSpot].team == 'b')
    {
        currentPiece = board[boardSpot];
    }
}

bool GameBoard::validateMove(int boardSpot) //Validates if a move is legal
{   
    bool validMove = false;
    switch (currentPiece.type) {
    case 'c':
        if (board[boardSpot].type == 'z')
            validMove = true;
            break;
    case 'e':
        if (board[boardSpot].team != currentPiece.team && (boardSpot == currentPieceIndex - 14 || currentPieceIndex - 18 || currentPieceIndex + 14 || currentPieceIndex + 18))
            validMove = true;
            break;
    case 'f':   
        if (board[boardSpot].team != currentPiece.team && (boardSpot == currentPieceIndex + 7 || currentPieceIndex + 8 || currentPieceIndex + 9))
            validMove = true;
            break;
    case 'k':
        if (board[boardSpot].team != currentPiece.team && (boardSpot == currentPieceIndex + 7 || currentPieceIndex + 8 || currentPieceIndex + 9 || currentPieceIndex - 1 || currentPieceIndex + 1 || currentPieceIndex - 9 || currentPieceIndex - 8 || currentPieceIndex - 7))
            validMove = true;
            break;
    //case 'm': return true;
    case 'q':
        if (board[boardSpot].team != currentPiece.team && queenCollisionCheck(boardSpot))
            validMove = true;
            break;
       // return false;
    }
    return validMove;
}

void GameBoard::movePiece(int boardSpot)
{
    if (validateMove(boardSpot))
    {
        if (board[boardSpot].team != currentPiece.team)
            pieceTakenLastTurn = true;

        if (whiteTurn)
            whiteTurn = false;

        board[boardSpot].type = currentPiece.type;
        board[boardSpot].team = currentPiece.team;
        board[currentPieceIndex].type = 'z';
        board[currentPieceIndex].team = 'z';

    }

}

//This method checks all of the possible queen movements for collisions. It only returns true if the path from the queen to the specified board spot has no collisions.
bool GameBoard::queenCollisionCheck(int boardSpot)  
{
    int nextSpot = currentPieceIndex;
    if ((currentPieceIndex - boardSpot) % 8 == 0)   //Check if queen is moving up/down the board
    { 
        if (boardSpot > currentPieceIndex) //If moving upwards, only need to check collision while moving upwards
        {
            do
            {
                nextSpot += 8;
                if (board[nextSpot].type != 'z')
                    return false;
            } while (nextSpot != boardSpot);
            return true;
        }

        else    //If the piece is not moving upwards, we check for collision going downwards
        {
            do 
            {
                nextSpot -= 8;
                if (board[nextSpot].type != 'z')
                    return false;
            } while (nextSpot != boardSpot);
            return true;
        }
    }
    int horizontalMoveCheck = currentPieceIndex - boardSpot;
    if (horizontalMoveCheck < 0)    //We need to check for the absolute value to make sure
        horizontalMoveCheck *= -1;
    if (horizontalMoveCheck < 8)   //Check if queen is moving horizontally
    {
        if (currentPieceIndex - boardSpot < 0)   //Check if moving towards the right
        {
            do
            {
                nextSpot += 1;
                if (board[nextSpot].type != 'z')
                    return false;
            } while (nextSpot != boardSpot);
            return true;
        }

        else    //else it is moving towards the left
        {
            do
            {
                nextSpot -= 1;
                if (board[nextSpot].type != 'z')
                    return false;
            } while (nextSpot != boardSpot);
            return true;
        }
    }
    if (currentPieceIndex < boardSpot)  //Queen moving downwards
    {
        if ((currentPieceIndex - boardSpot) % 9 == 0)    // if moving towards the right downwards
        {
            do
            {
                nextSpot += 9;
                if (board[nextSpot].type != 'z')
                    return false;
            } while (nextSpot != boardSpot);
            return true;
        }

        else    //else it is moving towards the left downwards
        {
            do
            {
                nextSpot += 7;
                if (board[nextSpot].type != 'z')
                    return false;
            } while (nextSpot != boardSpot);
            return true;
        }
    }

    else    //Queen moving upwards
    {
        if ((currentPieceIndex - boardSpot) % 9 == 0)    // if moving towards the right upwards
        {
            do
            {
                nextSpot -= 7;
                if (board[nextSpot].type != 'z')
                    return false;
            } while (nextSpot != boardSpot);
            return true;
        }

        else    //else it is moving towards the left upwards
        {
            do
            {
                nextSpot -= 9;
                if (board[nextSpot].type != 'z')
                    return false;
            } while (nextSpot != boardSpot);
            return true;
        }
    }

    return true;
}