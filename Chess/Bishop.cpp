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

/*
the << operator, will print B uppercase if white or lowercase if black
input: stream, bishop
output: stream with the letter
*/
std::ostream& operator<<(std::ostream& os, Bishop& bish)
{
	char expression = ' ';

	if (bish.getColor() == WHITE)
	{
		expression = WHITE_BISHOP;
	}
	else
	{
		expression = BlACK_BISHOP;
	}
	os << expression;
	return os;
}
