#include "Piece.h"

/*
C'tor for Piece object
input: Piece's color, type, row, column.
output: none.
*/
Piece::Piece(Colors color, Types type, int row, int col):
	_color(color), _type(type), _letterLocation(row), _numberLocation(col)
{}

/*
D'tor for Piece object
input: none.
output: none.
*/
Piece::~Piece()
{}

/*
returns Piece's type.
input: none.
output: the Piece's type (from Types enum)
*/
Types Piece::getType()
{
	return this->_type;
}

/*
Returns Piece's color.
input: none.
output: the color (from Colors enum)
*/
Colors Piece::getColor()
{
	return this->_color;
}