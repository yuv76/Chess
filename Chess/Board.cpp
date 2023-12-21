#include "Board.h"

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Tower.h"

/*
C'tor for board object, arranging the pieces on the board array.
input; none
output: none
*/
Board::Board()
{
	int i = 0, j = 0;

	this->_pieces = new Piece** [ROWS];
	for (i = 0; i < ROWS; i++)
	{
		this->_pieces[i] = new Piece* [COLS];
	}
	
	//first white line
	this->_pieces[0][0] = new Tower(WHITE, TOWER, 0, 0);
	this->_pieces[0][1] = new knight(WHITE, KNIGHT, 0, 1);
	this->_pieces[0][2] = new Bishop(WHITE, BISHOP, 0, 2);
	this->_pieces[0][3] = new King(WHITE, KING, 0, 3);
	this->_pieces[0][4] = new Queen(WHITE, QUEEN, 0, 4);
	this->_pieces[0][5] = new Bishop(WHITE, BISHOP, 0, 5);
	this->_pieces[0][6] = new knight(WHITE, KNIGHT, 0, 6);
	this->_pieces[0][7] = new Tower(WHITE, TOWER, 0, 7);
	//pawn white line
	for (i = 0; i < COLS; i++)
	{
		this->_pieces[1][i] = new Pawn(WHITE, PAWN, 1, i);
	}
	//four blank lines
	for (i = 0; i < MUN_OF_BLANK_START_LINES; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			this->_pieces[i][j] = nullptr;
		}
	}
	//pawn black line
	for (i = 0; i < COLS; i++)
	{
		this->_pieces[6][i] = new Pawn(BLACK, PAWN, 6, i);
	}
	//black first line
	this->_pieces[7][0] = new Tower(BLACK, TOWER, 7, 0);
	this->_pieces[7][1] = new knight(BLACK, KNIGHT, 7, 1);
	this->_pieces[7][2] = new Bishop(BLACK, BISHOP, 7, 2);
	this->_pieces[7][3] = new King(BLACK, KING, 7, 3);
	this->_pieces[7][4] = new Queen(BLACK, QUEEN, 7, 4);
	this->_pieces[7][5] = new Bishop(BLACK, BISHOP, 7, 5);
	this->_pieces[7][6] = new knight(BLACK, KNIGHT, 7, 6);
	this->_pieces[7][7] = new Tower(BLACK, TOWER, 7, 7);
}

/*
D'tor for board object.
input: none
output: none
*/
Board::~Board()
{
	int i = 0, j = 0;

	for (i = 0, i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			if (this->_pieces[i][j] != nullptr)
			{
				delete this->_pieces[i][j];
			}
		}
	}
	for (i = 0; i < ROWS; i++)
	{
		delete[] this->_pieces[i];
	}
	delete[] this->_pieces;
}

/*
returns triple pointer to the pieces 2d array
input: none
output: the triple pointer
*/
Piece*** Board::getPieces()
{
	return this->_pieces;
}

/*

*/
bool Board::move(std::string move)
{

}

/*

*/
bool Board::isTaken(std::string dest)
{

}

/*

*/
bool Board::eat(std::string eatingPos, std::string eatedPos)
{

}

/*

*/
bool Board::isEating(std::string move)
{

}

/*

*/
bool Board::checkIfChess(std::string move)
{

}

/*

*/
bool Board::checkIfCheckmate(std::string move)
{

}

/*

*/
std::string Board::toString()
{

}
