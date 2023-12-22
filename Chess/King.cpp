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


/*
the << operator, will print K uppercase if white or lowercase if black
input: stream, king
output: stream with the letter
*/
std::ostream& operator<<(std::ostream& os, King& king)
{
	char expression = ' ';

	if (king.getColor() == WHITE)
	{
		expression = WHITE_KING;
	}
	else
	{
		expression = BlACK_KING;
	}
	os << expression;
	return os;
}
