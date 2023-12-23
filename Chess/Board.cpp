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
	this->_pieces[2][1] = new Bishop(BLACK, BISHOP, 2, 1);

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
	for (i = 2; i < MUN_OF_BLANK_START_LINES + 2; i++)
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
MsgCode Board::move(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn)
{
	Piece* piece = nullptr;
	
	//invalid move, same pose to source and dest.
	if (sourceRow == destRow && sourceCol == destCol)
	{
		return SAME_POS;
	}

	//invalid move, can't go on the same pose as teammate. 
	if (this->isTaken(destRow, destCol, turn))
	{
		return PIECE_IN_DEST;
	}

	//invalid move, no piece of the curr player in source.
	if (turn == WHITE)
	{
		if (this->isTaken(sourceRow, sourceCol, BLACK))
		{
			return NO_PIECE;
		}
	}
	if (turn == BLACK)
	{
		if (this->isTaken(sourceRow, sourceCol, WHITE))
		{
			return NO_PIECE;
		}
	}

	//check if move is out of range
	if (sourceRow < ROWS && destRow < ROWS && sourceCol < COLS && destCol < COLS) 
	{
		piece = this->_pieces[sourceRow][sourceCol];
		
		if (piece->canEat(sourceRow, sourceCol, destRow, destCol) || piece->canBeMoved(sourceRow, sourceCol, destRow, destCol))
		{
			/*if (checkIfChess(sourceRow, sourceCol, destRow, destCol, turn)) //check if there was chess
			{
				_pieces[destRow][destCol] = _pieces[sourceRow][sourceCol];
				_pieces[sourceRow][sourceCol] = nullptr;
				return	CAUSE_CHESS;
			}
			*/

			//if there was mate
			/*if (checkIfCheckmate(sourceRow, sourceCol, destRow, destCol, turn))
			{
				_pieces[destRow][destCol] = _pieces[sourceRow][sourceCol];
				_pieces[sourceRow][sourceCol] = nullptr;
				return	CHECKMATE;
			}
			*/

			//everything is valid
			_pieces[destRow][destCol] = _pieces[sourceRow][sourceCol];
			_pieces[sourceRow][sourceCol] = nullptr;
		}
		
		else
		{
			return ILLEGAL_TOOL_MOVE;
		}
	}
	else
	{
		return INVALID_INDEXES;
	}
	return VALID;
}


/*
function checks if location ([row][col]) is taken by the player that it's his turn (black/white).
input: row - row to check, col - col to check, turn - the curr player that it's his turn.
output: true if location is taken and false if not.
*/
bool Board::isTaken(int row, int col, Colors turn)
{
	if (this->_pieces[row][col] == nullptr)
	{
		return false;
	}
	if (this->_pieces[row][col]->getColor() == turn) //if the location has a player from the same color.
	{
		return true;
	}
	return false;
}



/*
bool Board::isEating(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn)
{
	
}
*/

/*
MsgCode Board::checkIfChess(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn)
{
	* go over all the pieces and check if the can move to the king.
	* if at least one of them can it's chess
}
*/

/*
MsgCode Board::checkIfCheckmate(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn)
{
	* check if chess on all pf the king's routs and on his curr place
	* if yes then it's checkmate
}
*/

/*
std::string Board::toString()
{

}
*/

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

MsgCode canEatKing(int row, int col)
{

}
*/