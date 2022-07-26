// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "piece.h"
#include "crow.h"
#include "Gameboard.h"
using namespace std;
int main()
{
    std::cout << "Hello World!\n";
    int const boardSize = 64;
    //Piece board[boardSize]; //1D array to represent the board
    GameBoard chessBoard = GameBoard();

   
  

    cout << chessBoard.board[0].type << " ";
    for (int i = 1; i < boardSize; i++)
    {
        if (i % 8 == 0)
            cout << endl;
        cout << chessBoard.board[i].type << " ";
    }

    cout << endl;
    cout << endl;
    cout << endl;

    int input = 0;
    while (true)
    {
        cout << "choose index" << endl;
        cin >> input;
        chessBoard.selectPiece(input);
        cout << "choose move spot" << endl;
        cin >> input;
        chessBoard.movePiece(input);
        cout << chessBoard.board[0].type << " ";
        for (int i = 1; i < boardSize; i++)
        {
            if (i % 8 == 0)
                cout << endl;
            cout << chessBoard.board[i].type << " ";
        }
        cout << endl;
    }

    chessBoard.selectPiece(0);
    chessBoard.movePiece(24);
    chessBoard.selectPiece(15);
    chessBoard.movePiece(22);
    chessBoard.selectPiece(10);
    chessBoard.movePiece(28);
    chessBoard.selectPiece(28);
    chessBoard.movePiece(10);
    cout << chessBoard.board[0].type << " ";
    for (int i = 1; i < boardSize; i++) 
 {
     if (i % 8 == 0)
         cout << endl;
     cout << chessBoard.board[i].type << " ";
 }
    //cout << (chessBoard.board[0].type);
   
    
    //Empty spaces, z
   // for (int i = 16; i < 48; i++)
    //    board[i]->type = ' ';


    //for (int i = 1; i < boardSize; i++) 
    //{
    //    if (i % 8 == 0)
    //        cout << endl;
    //    cout << board[i]->type << " ";
    //}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
