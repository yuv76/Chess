#pragma once
#include <string>
#include <iostream>

enum Types {TOWER, KING, QUEEN, BISHOP, KNIGHT, PAWN};
enum Colors {WHITE, BLACK};

#define MAX_ROW_AND_COL 8

class Piece
{
private:
	Colors _color;
	Types _type;
	// Might turn out to be unneeded
	int _letterLocation;
	int _numberLocation;

public:
	Piece(Colors color, Types type, int row, int col);
	virtual ~Piece();
	Types getType();
	Colors getColor();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const = 0;
};