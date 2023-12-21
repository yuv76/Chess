#pragma once
#include <string>

enum Types {TOWER, KING, QUEEN, BISHOP, KNIGHT, PAWN};
enum Colors {WHITE, BLACK};

class Piece
{
private:
	Colors _color;
	Types _type;
	// Might turn out to be uneeded
	int _letterLocation;
	int _numberLocation;

public:
	Piece(Colors color, Types type, int row, int col);
	virtual ~Piece();
	Types getType();
	Colors getColor();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int dest, int destCol) = 0;
	virtual bool canEatKing(int row, int col) = 0;
};