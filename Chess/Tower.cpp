#include "Tower.h"

/*
C'tor for Tower object.
input: tower's color, type, row and column.
output: none.
*/
Tower::Tower(Colors color, Types type, int row, int col) :
	Piece(color, type, row, col)
{}

/*
D'tor for tower object.
input: none.
output: none.
*/
Tower::~Tower()
{}

/*
function checks if tower can move in this direction.
input: source row and col, dest row and col.
output: true if can be moved and false if not.
*/
bool Tower::canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const
{
	if (sourceRow == destRow || sourceCol == destCol)
	{
		return true;
	}
	return false;
}

/*
the << operator, will print R uppercase if white or lowercase if black.
input: stream, Knight.
output: stream with the letter.
*/
std::ostream& operator<<(std::ostream& os, const Tower& tower)
{
	char expression = ' ';

	if (tower.getColor() == WHITE)
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

/*
prints tower's initial, according to its color.
input: the tower's color.
output: the initial.
*/
char Tower::getInitial(Colors color)
{
	char expression = ' ';

	if (color == WHITE)
	{
		expression = WHITE_TOWER;
	}
	else
	{
		expression = BLACK_TOWER;
	}
	return expression;
}
