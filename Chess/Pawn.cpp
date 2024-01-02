#include "Pawn.h"


/*
C'tor for Pawn object
input: pawn's color, type, row and column
output: none
*/
Pawn::Pawn(Colors color, Types type, int row, int col) :
	Piece(color, type, row, col)
{}

/*
D'tor for pawn object
input: none
output: none
*/
Pawn::~Pawn()
{}

/*
function checks if pawn can move in this direction.
input: source row and col, dest row and col.
output: true if can be moved and false if not.
*/
bool Pawn::canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const
{
	if (this->_color == WHITE)
	{
		if (this->_hasWalked == false)
		{
			if (destRow - sourceRow == 2 && destCol - sourceCol == 0)
			{
				return true;
			}
		}
		if (destRow - sourceRow == 1 && destCol - sourceCol == 0)
		{
			return true;
		}
	}
	else
	{
		if (this->_hasWalked == false)
		{
			if (destRow - sourceRow == -2 && destCol - sourceCol == 0)
			{
				return true;
			}
		}
		if (destRow - sourceRow == -1 && destCol - sourceCol == 0)
		{
			return true;
		}
	}

	return false;
}


/*
function checks if pawn can eat in the route (from [sourceRow][sourceCol] to [destRow][destCol].
input: source row and col, dest row and col.
output: true if can eat and false if not.
*/
bool Pawn::canEat(int sourceRow, int sourceCol, int destRow, int destCol) const
{
	if (this->_color == WHITE)
	{
		if (destRow - sourceRow == 1 && abs(destCol - sourceCol) == 1)
		{
			return true;
		}
	}
	else
	{
		if (destRow - sourceRow == -1 && abs(destCol - sourceCol) == 1)
		{
			return true;
		}
	}
	return false;
}

/*
prints pawn's initial, according to its color
input: the pawn's color
output: the initial
*/
char Pawn::getInitial(Colors color)
{
	char expression = ' ';

	if (color == WHITE)
	{
		expression = WHITE_PAWN;
	}
	else
	{
		expression = BLACK_PAWN;
	}
	return expression;
}
