#include "King.h"

/*
C'tor for king object
input: king's color, type, row and column
output: none
*/
King::King(Colors color, Types type, int row, int col) :
	Piece(color, type, row, col)
{}

/*
D'tor for king object
input: none
output: none
*/
King::~King()
{

}

/*

*/
bool King::canBeMoved(int sourceRow, int sourceCol, int dest, int destCol)
{

}

/*

*/
bool King::canEatKing(int row, int col)
{

}

