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


bool Board::isPathClear(int sourceRow, int sourceCol, int destRow, int destCol)
{
	int row = 0, col = 0;
	int rowAdd = 0, colAdd = 0;

	//find change in row (+, - or none).
	if (destRow > sourceRow)
	{
		rowAdd = 1;
	}
	else
	{
		if (destRow < sourceRow)
		{
			rowAdd = -1;
		}
		else
		{
			rowAdd = 0;
		}
	}

	//find change in col (+, - or none).
	if (destCol > sourceCol)
	{
		colAdd = 1;
	}
	else
	{
		if (destCol < sourceCol)
		{
			colAdd = -1;
		}
		else
		{
			colAdd = 0;
		}
	}

	col = sourceCol + colAdd; //col start
	for (row = sourceRow + rowAdd; row != destRow || col != destCol; row += rowAdd) //run until arrive to dest
	{
		if (_pieces[row][col] != nullptr) //if there is piece on the way
		{
			return false;
		}
		col += colAdd; //increase col counter
	}
	
	return true;;
}

/*
function checks if it's possible to move piece by the chess rules.
input: (sourceRow, sourceCol) - source row and col, (destRow, destCol) - dest row and col, turn - curr player's turn.
output: MsgCode - code to the front-end that explains the result of the move (errors or success).
*/
MsgCode Board::checkIfCanMove(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn)
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

		if (!(piece->canEat(sourceRow, sourceCol, destRow, destCol) || piece->canBeMoved(sourceRow, sourceCol, destRow, destCol)))
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
function changes the location of a piece on the board and updates the king if need.
input: (sourceRow, sourceCol) - source row and col, (destRow, destCol) - dest row and col, turn - curr player's turn.
output: none.
*/
void Board::changePieceLocation(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn)
{
	if (_pieces[destRow][destCol] != nullptr)
	{
		delete _pieces[destRow][destCol];
	}

	if (_pieces[sourceRow][sourceCol] != nullptr)
	{
		if (_pieces[sourceRow][sourceCol]->getType() == KING)
		{
			if (_pieces[sourceRow][sourceCol]->getColor() == WHITE)
			{
				_whiteKingPosition[0] = destRow;
				_whiteKingPosition[1] = destCol;
			}
			if (_pieces[sourceRow][sourceCol]->getColor() == BLACK)
			{
				_blackKingPosition[0] = destRow;
				_blackKingPosition[1] = destCol;
			}
		}
	}
	_pieces[destRow][destCol] = _pieces[sourceRow][sourceCol];
	_pieces[sourceRow][sourceCol] = nullptr;
}

/*
function moves a piece from source to dest by the ruls of chess.
input: (sourceRow, sourceCol) - source row and col, (destRow, destCol) - dest row and col, turn - curr player's turn.
output: MsgCode - code to the front-end that explains the result of the move (errors or success).
*/
MsgCode Board::move(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn)
{
	Piece* piece = this->_pieces[sourceRow][sourceCol];

	if (checkIfCanMove(sourceRow, sourceCol, destRow, destCol, turn) == VALID)
	{
		//if there was mate
		if (checkIfCheckmate(turn))
		{
			changePieceLocation(sourceRow, sourceCol, destRow, destCol, turn);
			return	CHECKMATE;
		}

		//if there was chess
		if ((turn == WHITE && checkIfChess(turn, _blackKingPosition[0], _blackKingPosition[1])) || (turn == BLACK && checkIfChess(turn, _whiteKingPosition[0], _whiteKingPosition[1])))
		{
			changePieceLocation(sourceRow, sourceCol, destRow, destCol, turn);
			return	CAUSE_CHESS;
		}
		

		//everything is valid
		if (_pieces[destRow][destCol] != nullptr)
		{
			delete _pieces[destRow][destCol];
		}
		_pieces[destRow][destCol] = _pieces[sourceRow][sourceCol];
		_pieces[sourceRow][sourceCol] = nullptr;
	}

	else
	{
		return checkIfCanMove(sourceRow, sourceCol, destRow, destCol, turn);
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
function checks if there is a chess on a king, (checks if there is a piece that threatens the king).
input: turn - the current player (white or black), kingRow - the king's row, kingCol - the king's col.
output: true if there was a chess and false if not.
*/
bool Board::checkIfChess(Colors turn, int kingRow, int kingCol)
{
	int i = 0, j = 0;

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			if (_pieces[i][j] != nullptr)
			{
				if (this->checkIfCanMove(i, j, kingRow, kingCol, turn) == VALID) //white's turn
				{
					return true;
				}
			}
		}
	}
	return false;
}

/*
function checks if there is checkmate on the opponent's king, (checks if there is chess on all the king's possible destinations).
input: turn - the current player (white or black).
output: true if there was a checkmate and false if not.
*/
bool Board::checkIfCheckmate(Colors turn)
{
	//* check if chess on all pf the king's routs and on his curr place
	//* if yes then it's checkmate
	bool isMate = true;
	int startPoseRow = 0, startPoseCol = 0;
	int i = 0, j  = 0;
	
	if (turn == WHITE)
	{
		startPoseRow = _blackKingPosition[0] - 1;
		startPoseCol = _blackKingPosition[1] - 1;
	}
	if (turn == BLACK)
	{
		startPoseRow = _whiteKingPosition[0] - 1;
		startPoseCol = _whiteKingPosition[1] - 1;
	}

	for (i = startPoseRow; i < (startPoseRow + 3); i++)
	{
		for (j = startPoseRow; j < (startPoseRow + 3); j++)
		{
			if (i != startPoseRow + 1 && j != startPoseCol + 1)
			{
				if (i < ROWS && j < COLS)
				{
					if (_pieces[i][j] != nullptr)
					{
						//if king can eat [i, j] it's not chess 
						if (_pieces[i][j]->getColor() == turn)
						{
							return false;
						}

					}
					if (!checkIfChess(turn, i, j))
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}


/*
returns a string that presents the board with initials of the pieces
input: none
output: the string
*/
std::string Board::toString()
{
	int i = 0, j = 0;
	std::string board = "";

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			if (this->_pieces[i][j] != nullptr)
			{
				board += this->_pieces[i][j]->getInitial(this->_pieces[i][j]->getColor());
			}
			else
			{
				board += BLANK_POS;
			}
		}
	}
	return board;
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
				std::cout << *this->_pieces[i][j] << " ";
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