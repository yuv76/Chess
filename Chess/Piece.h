#pragma once
#include <string>
#include <iostream>


enum Types {TOWER, KING, QUEEN, BISHOP, KNIGHT, PAWN};
enum Colors {WHITE, BLACK};

#define MAX_ROW_AND_COL 8

class Piece
{
protected:
	Colors _color;
	Types _type;
	bool _hasWalked;

public:
	Piece(Colors color, Types type, int row, int col);
	virtual ~Piece();
	Types getType() const;
	Colors getColor() const;
	virtual bool canEat(int sourceRow, int sourceCol, int destRow, int destCol) const;
	bool getIfWalked() const;
	void changehasWalkedToTrue();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int destRow, int destCol) const = 0;
	virtual char getInitial(Colors color) = 0;

	friend std::ostream& operator<<(std::ostream& os, Piece& piece);
};