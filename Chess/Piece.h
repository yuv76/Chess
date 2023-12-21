#pragma once

enum Types {TOWER, KING, QUEEN, BISHOP, KNIGHT, PAWN };
enum Colors {WHITE, BLACK};

class Piece
{
private:
	//int _letterLocation;
	//int _numberLocation;
	int _color;
	int _type;
public:
	Piece(int color, int type, int row, int col);
	virtual ~Piece();
	int getType();
	int getColor();
	virtual bool canBeMoved(int sourceRow, int sourceCol, int dest, int destCol) = 0;
	virtual bool canEatKing(int row, int col) = 0;
};