#include "Queen.h"

/*
C'tor for Queen object
input: queen's color, type, row and column
output: none
*/
Queen::Queen(Colors color, Types type, int row, int col) :
	Piece(color, type, row, col)
{}

/*
D'tor for Queen object
input: none
output: none
*/
Queen::~Queen()
{}

/*

*/
bool canBeMoved(int sourceRow, int sourceCol, int dest, int destCol)
{

}

/*

*/
bool canEatKing(int row, int col)
{

}