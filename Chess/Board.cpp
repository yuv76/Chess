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
	
	//first white line
	this->_pieces[0][0] = new Tower(WHITE, TOWER, 0, 0);
	this->_pieces[0][1] = nullptr;//new knight(WHITE, KNIGHT, 0, 1);
	this->_pieces[0][2] = nullptr;//new Bishop(WHITE, BISHOP, 0, 2);
	this->_pieces[0][3] = nullptr;//new King(WHITE, KING, 0, 3);
	this->_pieces[0][4] = nullptr;//new Queen(WHITE, QUEEN, 0, 4);
	this->_pieces[0][5] = nullptr;//new Bishop(WHITE, BISHOP, 0, 5);
	this->_pieces[0][6] = nullptr;//new knight(WHITE, KNIGHT, 0, 6);
	this->_pieces[0][7] = nullptr;//new Tower(WHITE, TOWER, 0, 7);
	/*
	//pawn white line
	for (i = 0; i < COLS; i++)
	{
		this->_pieces[1][i] = new Pawn(WHITE, PAWN, 1, i);
	}
	*/

	//four blank lines
	for (i = 2; i < MUN_OF_BLANK_START_LINES + 2; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			this->_pieces[i][j] = nullptr;
		}
	}
	/*
	//pawn black line
	for (i = 0; i < COLS; i++)
	{
		this->_pieces[6][i] = new Pawn(BLACK, PAWN, 6, i);
	}
	*/

	//black first line
	this->_pieces[7][0] = new Tower(BLACK, TOWER, 7, 0);
	this->_pieces[7][1] = nullptr;//new knight(BLACK, KNIGHT, 7, 1);
	this->_pieces[7][2] = nullptr;//new Bishop(BLACK, BISHOP, 7, 2);
	this->_pieces[7][3] = nullptr;//new King(BLACK, KING, 7, 3);
	this->_pieces[7][4] = nullptr;//new Queen(BLACK, QUEEN, 7, 4);
	this->_pieces[7][5] = nullptr;//new Bishop(BLACK, BISHOP, 7, 5);
	this->_pieces[7][6] = nullptr;//new knight(BLACK, KNIGHT, 7, 6);
	this->_pieces[7][7] = new Tower(BLACK, TOWER, 7, 7);
	
	this->_blackKingPosition[0] = 7;
	this->_blackKingPosition[1] = 3;

	this->_whiteKingPosition[0] = 0;
	this->_whiteKingPosition[1] = 3;

}

/*
D'tor for board object, free all memory.
input: none.
output: none.
*/
Board::~Board()
{
	int i = 0, j = 0;

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			if (this->_pieces[i][j] != nullptr)
			{
				delete this->_pieces[i][j];
			}
		}
	}
}

/*

*/
bool Board::move(std::string move)
{

}

/*

*/
MsgCode Board::isTaken(int row, int col, bool isSource)
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
MsgCode Board::checkIfChess(std::string move)
{

}

/*

*/
MsgCode Board::checkIfCheckmate(std::string move)
{

}

/*

*/
std::string Board::toString()
{

}

/*
returns a pointer to the Piece on the board on position[row][col]
input: the row and column indexes
output: the piece in the position's pointer
*/
Piece* Board::operator()(int rowIndex, int colIndex)
{
	return this->_pieces[rowIndex][colIndex];
}

/*
prints board to stream
input: none
output: none
*/
void Board::printBoard()
{
	int i = 0, j = 0;

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			if (this->_pieces[i][j] != nullptr)
			{
				std::cout << this->_pieces[i][j] << " ";
			}
			else
			{
				std::cout << BLANK_POS << " ";
			}
		}
		std::cout << std::endl;
	}
}

/*

*/
MsgCode canEatKing(int row, int col)
{

}