#include "Bishop.h"

/*
C'tor for Bishop object
input: bishop's color, typerow and column
output: none.
*/
Bishop::Bishop(Colors color, Types type, int row, int col) :
	Piece(color, type, row, col)
{}

/*
D'tor for bishop object
input: none.
output: none.
*/
Bishop::~Bishop()
{}

/*

*/
bool Bishop::canBeMoved(int sourceRow, int sourceCol, int dest, int destCol)
{

}

/*

*/
bool Bishop::canEatKing(int row, int col)
{

}
