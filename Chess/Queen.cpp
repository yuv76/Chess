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
bool Queen::canBeMoved(int sourceRow, int sourceCol, int dest, int destCol)
{

}

/*

*/
bool Queen::canEatKing(int row, int col)
{

}

/*
the << operator, will print Q uppercase if white or lowercase if black
input: stream, Knight
output: stream with the letter
*/
std::ostream& operator<<(std::ostream& os, Queen& que)
{
	char expression = ' ';

	if (que.getColor() == WHITE)
	{
		expression = WHITE_QUEEN;
	}
	else
	{
		expression = BLACK_QUEEN;
	}
	os << expression;
	return os;
}