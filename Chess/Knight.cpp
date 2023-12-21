#include "Knight.h"

/*
C'tor for knight object
input: knight's color, type, row and column
output: none
*/
knight::knight(Colors color, Types type, int row, int col) :
	Piece(color, type, row, col)
{}

/*
D'tor for knight object
input: none
output: none
*/
knight::~knight()
{

}

/*

*/
bool knight::canBeMoved(int sourceRow, int sourceCol, int dest, int destCol)
{

}

/*

*/
bool knight::canEatKing(int row, int col)
{

}