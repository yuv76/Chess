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
function checks if knight can move in this direction.
input: source row and col, dest row and col.
output: true if can be moved and false if not.
*/
bool knight::canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const
{
	if (destRow - sourceRow == abs(2) && destCol - sourceCol == abs(1))
	{
		return true;
	}
	if (destRow - sourceRow == abs(1) && destCol - sourceCol == abs(2))
	{
		return true;
	}
	return false;
}


/*
the << operator, will print N uppercase if white or lowercase if black
input: stream, Knight
output: stream with the letter
*/
std::ostream& operator<<(std::ostream& os, knight& knig)
{
	char expression = ' ';

	if (knig.getColor() == WHITE)
	{
		expression = WHITE_KNIGHT;
	}
	else
	{
		expression = BlACK_KNIGHT;
	}
	os << expression;
	return os;
}