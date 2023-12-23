#include "Tower.h"

/*
C'tor for Tower object
input: tower's color, type, row and column
output: none.
*/
Tower::Tower(Colors color, Types type, int row, int col) :
	Piece(color, type, row, col)
{}

/*
D'tor for tower object
input: none
output: none
*/
Tower::~Tower()
{}

/*

*/
bool Tower::canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol)
{
	if ((sourceRow == destRow || sourceCol == destCol) && destRow < MAX_ROW_AND_COL && destCol < MAX_ROW_AND_COL && sourceRow < MAX_ROW_AND_COL && sourceCol < MAX_ROW_AND_COL) //out of range
	{
		return true;
	}
	return false;
}

/*
the << operator, will print R uppercase if white or lowercase if black
input: stream, Knight
output: stream with the letter
*/
std::ostream& operator<<(std::ostream& os, Tower& tow)
{
	char expression = ' ';

	if (tow.getColor() == WHITE)
	{
		expression = WHITE_TOWER;
	}
	else
	{
		expression = BLACK_TOWER;
	}
	os << expression;
	return os;
}