#include "Piece.h"

/*
C'tor for Piece object
input: Piece's color, type, row, column.
output: none.
*/
Piece::Piece(Colors color, Types type, int row, int col) :
	_color(color), _type(type), _letterLocation(row), _numberLocation(col), _hasWalked(false)
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
Types Piece::getType() const
{
	return this->_type;
}

/*
Returns Piece's color.
input: none.
output: the color (from Colors enum)
*/
Colors Piece::getColor() const
{
	return this->_color;
}

bool Piece::canEat(int sourceRow, int sourceCol, int destRow, int destCol) const
{
	if (this->canBeMoved(sourceRow, sourceCol, destRow, destCol))
	{
		return true;
	}
	return false;
}

/*
Returns whether the piece had moved already or not.
input: none.
output: true if already walked, false otherwise.
*/
bool Piece::getIfWalked() const
{
	return this->_hasWalked;
}

/*
changes hasWalked to true.
input: none.
output: none.
*/
void Piece::changehasWalkedToTrue()
{
	this->_hasWalked = true;
}

/*
the << operator, will print the piece's initial uppercase if white or lowercase if black
input: stream, Piece
output: stream with the letter
*/
std::ostream& operator<<(std::ostream& os, Piece& piece)
{
	Colors color = piece.getColor();
	os << piece.getInitial(color);
	return os;
}