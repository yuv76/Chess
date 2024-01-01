#include "Board.h"

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

	//delete all pieces:
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
function checks if castling is possible, if it is it does it.
input: turn - the curr turn of the player.
output: true if castle is possible and false if not.
*/
bool Board::Castle(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn)
{
	bool canCastle = false;
	if (((turn == BLACK && sourceRow == FIRST_ROW_BLACK && destRow == FIRST_ROW_BLACK) || (turn == WHITE && sourceRow == FIRST_ROW_WHITE && destRow == FIRST_ROW_WHITE)) && (sourceCol == START_KING_COL && destCol == START_TOWER_COL))
	{
		if (turn == WHITE && !_pieces[0][7]->getIfWalked() && !_pieces[0][3]->getIfWalked())
		{
			if (!checkIfChess(BLACK, _blackKingPosition[0], _blackKingPosition[1]) && isPathClear(sourceRow, sourceCol, destRow, destCol))
			{
				if (isPathChessed(sourceRow, sourceCol, destRow, destCol, BLACK))
				{
					canCastle = true;
				}
			}
		}
		if (turn == BLACK && !(_pieces[7][7]->getIfWalked()) && !(_pieces[7][3]->getIfWalked()))
		{
			if (!checkIfChess(WHITE, _blackKingPosition[0], _blackKingPosition[1]) && isPathClear(sourceRow, sourceCol, destRow, destCol))
			{
				if (isPathChessed(sourceRow, sourceCol, destRow, destCol, WHITE))
				{
					canCastle = true;
				}
			}
		}
	}
	
	if (canCastle)
	{
		Piece* eated = _pieces[destRow][destCol];
		changePieceLocation(sourceRow, sourceCol, destRow, destCol); //update king
		_pieces[sourceRow][sourceCol] = eated; //update tower
	}

	return canCastle;
}

/*
function checks if there is chess in path.
input: source and destination of the piece.
output: true if path is clear and false if not.
*/
bool Board::isPathChessed(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn)
{
	int row = 0, col = 0;
	int rowAdd = 0, colAdd = 0;
	int kingRow = 0, kingCol = 0;

	if (turn == WHITE)
	{
		kingRow = _whiteKingPosition[0];
		kingCol = _whiteKingPosition[1];
	}
	if (turn == BLACK)
	{
		kingRow = _blackKingPosition[0];
		kingCol = _blackKingPosition[1];
	}


	//find change in row (+, - or none).
	if (destRow > sourceRow)
	{
		rowAdd = 1;
	}
	else if (destRow < sourceRow)
	{
		rowAdd = -1;
	}
	else
	{
		rowAdd = 0;
	}

	//find change in col (+, - or none).
	if (destCol > sourceCol)
	{
		colAdd = 1;
	}
	else if (destCol < sourceCol)
	{
		colAdd = -1;
	}
	else
	{
		colAdd = 0;
	}

	col = sourceCol + colAdd; //col start
	for (row = sourceRow + rowAdd; row != destRow || col != destCol; row += rowAdd) //run until arrive to dest
	{
		if (_pieces[row][col] != nullptr) //if there is piece on the way
		{
			if (checkIfChess(turn, kingRow, kingCol))
			{
				return false;
			}
		}
		col += colAdd; //increase col counter
	}

	return true;
}

/*
function check is there is a piece in the curr piece path.
input: source and dest coordinations.
output: true if path is clear and false if not.
*/
bool Board::isPathClear(int sourceRow, int sourceCol, int destRow, int destCol)
{
	int row = 0, col = 0;
	int rowAdd = 0, colAdd = 0;

	//find change in row (+, - or none).
	if (destRow > sourceRow)
	{
		rowAdd = 1;
	}
	else if (destRow < sourceRow)
	{
		rowAdd = -1;
	}
	else
	{
		rowAdd = 0;
	}

	//find change in col (+, - or none).
	if (destCol > sourceCol)
	{
		colAdd = 1;
	}
	else if (destCol < sourceCol)
	{
		colAdd = -1;
	}
	else
	{
		colAdd = 0;
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
	
	return true;
}

/*
function checks if it's possible to move piece by the chess rules.
input: (sourceRow, sourceCol) - source row and col, (destRow, destCol) - dest row and col, turn - curr player's turn.
output: MsgCode - code to the front-end that explains the result of the move (errors or success).
*/
MsgCode Board::checkIfCanMove(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn)
{
	Piece* piece = nullptr;

	//check if move is out of range
	if (sourceRow < ROWS && sourceRow >= 0 && destRow < ROWS && destRow >= 0 && sourceCol < COLS && sourceCol >= 0 && destCol < COLS && destCol >= 0)
	{
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
			if (this->isTaken(sourceRow, sourceCol, BLACK) || this->_pieces[sourceRow][sourceCol] == nullptr)
			{
				return NO_PIECE;
			}
		}
		if (turn == BLACK)
		{
			if (this->isTaken(sourceRow, sourceCol, WHITE) || this->_pieces[sourceRow][sourceCol] == nullptr)
			{
				return NO_PIECE;
			}
		}
		
	
		piece = this->_pieces[sourceRow][sourceCol];

		//if is a tool that can walk more than one step and not the horse, check no pieces in their way
		if (_pieces[sourceRow][sourceCol]->getType() == QUEEN || _pieces[sourceRow][sourceCol]->getType() == BISHOP || _pieces[sourceRow][sourceCol]->getType() == TOWER || _pieces[sourceRow][sourceCol]->getType() == PAWN)
		{
			if (!isPathClear(sourceRow, sourceCol, destRow, destCol))
			{
				return ILLEGAL_TOOL_MOVE;
			}
		}

		if (piece->getType() == PAWN)
		{
			if (!((piece->canBeMoved(sourceRow, sourceCol, destRow, destCol) && _pieces[destRow][destCol] == nullptr) || (piece->canEat(sourceRow, sourceCol, destRow, destCol) && _pieces[destRow][destCol] != nullptr)))
			{
				return ILLEGAL_TOOL_MOVE;
			}
		}
		else
		{
			//check if piece can't it in this direction or can't move
			if (!(piece->canEat(sourceRow, sourceCol, destRow, destCol) || piece->canBeMoved(sourceRow, sourceCol, destRow, destCol)))
			{
				return ILLEGAL_TOOL_MOVE;
			}
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
void Board::changePieceLocation(int sourceRow, int sourceCol, int destRow, int destCol)
{
	//if one of the kings was moved, update his location.
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

	//changed walking status
	if (_pieces[sourceRow][sourceCol] != nullptr)
	{
		if (!_pieces[sourceRow][sourceCol]->getIfWalked())
		{
			_pieces[sourceRow][sourceCol]->changehasWalkedToTrue();
		}
	}

	//move
	_pieces[destRow][destCol] = _pieces[sourceRow][sourceCol];
	_pieces[sourceRow][sourceCol] = nullptr;
}

/*
function moves a piece from source to dest by the ruls of chess.
input: (sourceRow, sourceCol) - source row and col, (destRow, destCol) - dest row and col, turn - curr player's turn.
output: the move result according to the MsgCode enum.
*/
MsgCode Board::move(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn)
{
	Piece* piece = this->_pieces[sourceRow][sourceCol];
	MsgCode canMove = checkIfCanMove(sourceRow, sourceCol, destRow, destCol, turn);
	Piece* eated = this->_pieces[destRow][destCol];
	bool castled = Castle(sourceRow, sourceCol, destRow, destCol, turn);

	if (castled)
	{
		return CASTLING;
	}
	 
	if (canMove == VALID || castled)
	{
		if (!castled)
		{
			//check movement didn't cause self chess - if it didn't, it will move.
			if (turn == WHITE)
			{
				if (didMoveCauseChess(sourceRow, sourceCol, destRow, destCol, turn, _whiteKingPosition[0], _whiteKingPosition[1]))
				{
					return CAUSE_SELF_CHESS;
				}
				else
				{
					changePieceLocation(sourceRow, sourceCol, destRow, destCol);
					//if there is a piece in the location, eat it.
					if (eated != nullptr)
					{
						delete eated;
					}
				}
			}
			if (turn == BLACK)
			{
				if (didMoveCauseChess(sourceRow, sourceCol, destRow, destCol, turn, _blackKingPosition[0], _blackKingPosition[1]))
				{
					return CAUSE_SELF_CHESS;
				}
				else
				{
					changePieceLocation(sourceRow, sourceCol, destRow, destCol);
					//if there is a piece in the location, eat it.
					if (eated != nullptr)
					{
						delete eated;
					}
				}
			}
		}

		//if there was checkmate on the other king
		if (checkIfCheckmate(turn))
		{
			if (castled)
			{
				return CASTLING_AND_MATE;
			}
			return CHECKMATE;
		}
		

		//check if movement caused chess
		if (turn == WHITE && checkIfCanMove(destRow, destCol, _blackKingPosition[0], _blackKingPosition[1], WHITE) == VALID)
		{
			if (castled)
			{
				return CASTLING_AND_CHESS;
			}
			return CHESS;
		}
		else if (turn == BLACK && checkIfCanMove(destRow, destCol, _whiteKingPosition[0], _whiteKingPosition[1], BLACK) == VALID)
		{
			if (castled)
			{
				return CASTLING_AND_CHESS;
			}
			return CHESS;
		}

		//everything is valid
		if (castled)
		{
			return CASTLING;
		}
		return VALID;
	}
	else
	{
		return canMove;
	}
}


/*
function checks if location ([row][col]) is taken by the player that it's his turn (black/white).
input: row - row to check, col - col to check, turn - the curr player that it's his turn.
output: true if location is taken and false if not.
*/
bool Board::isTaken(int row, int col, Colors turn)
{
	if (this->_pieces[row][col] == nullptr) //if location is empty
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
	int row = 0, col = 0;

	//go over board
	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col  < COLS; col++)
		{
			if (_pieces[row][col] != nullptr) //if place is empty
			{
				if (this->checkIfCanMove(row, col, kingRow, kingCol, turn) == VALID)
				{
					return true;
				}
			}
		}
	}
	return false;
}

/*
function checks if the piece can move somewhere in the board.
input: row and col of the piece.
output: true if piece can move and false if not.
*/
bool Board::checkIfCanMoveSomewhere(int sourceRow, int sourceCol, Colors turn)
{
	int row = 0, col = 0;
	int kingRow = 0, kingCol = 0;

	if (turn == BLACK)
	{
		kingRow = _blackKingPosition[0];
		kingCol = _blackKingPosition[1];
	}
	if (turn == WHITE)
	{

		kingRow = _whiteKingPosition[0];
		kingCol = _whiteKingPosition[1];
	}

	//go over board
	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLS; col++)
		{
			if (this->checkIfCanMove(sourceRow, sourceCol, row, col, turn) == VALID && !didMoveCauseChess(sourceRow, sourceCol, row, col, turn, kingRow, kingCol))
			{
				return true;
			}
		}
	}
	return false;
}

bool Board::checkIfKingTheOnlyOneCanMove(Colors turn)
{
	int row = 0, col = 0;
	Colors opTurn = WHITE;

	if (turn == WHITE)
	{
		opTurn = BLACK;
	}

	if (checkIfThereIsAPieceThatCanMove(opTurn))
	{
		return false;
	}
	if (turn == WHITE)
	{
		if (!checkIfCanMoveSomewhere(_whiteKingPosition[0], _whiteKingPosition[1], opTurn))
		{
			return false;
		}
	}
	if (turn == BLACK)
	{
		if (!checkIfCanMoveSomewhere(_blackKingPosition[0], _blackKingPosition[1], opTurn))
		{
			return false;
		}
	}

	return true;
}

bool Board::checkIfThereIsAPieceThatCanMove(Colors turn)
{
	int row = 0, col = 0;


	//go over board
	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLS; col++)
		{
			if (_pieces[row][col] != nullptr && _pieces[row][col]->getColor() == turn) //check if not empty and in the right turn
			{
				if (_pieces[row][col]->getType() != KING && checkIfCanMoveSomewhere(row, col, turn)) //check if not king can move somewhere
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
	int startPoseRow = 0, startPoseCol = 0;
	int kingRow = 0, kingCol = 0;
	int i = 0, j  = 0;
	bool gotToLoop = false;
	bool canOnlyKingMove = false;
	Colors opTurn = WHITE;

	if (turn == WHITE)
	{
		opTurn = BLACK;
	}
	
	if (checkIfThereIsAPieceThatCanMove(opTurn))
	{
		return false;
	}

	canOnlyKingMove = checkIfKingTheOnlyOneCanMove(turn);

	if (turn == WHITE)
	{
		startPoseRow = _blackKingPosition[0] - 1;
		kingRow = _blackKingPosition[0];
		startPoseCol = _blackKingPosition[1] - 1;
		kingCol = _blackKingPosition[1];
	}
	if (turn == BLACK)
	{
		
		startPoseRow = _whiteKingPosition[0] - 1;
		kingRow = _whiteKingPosition[0];
		startPoseCol = _whiteKingPosition[1] - 1;
		kingCol = _whiteKingPosition[1];
	}

	//check the 3x3 positions that the king is in the middle of
	for (i = startPoseRow; i < (startPoseRow + 3) && i < ROWS; i++)
	{
		for (j = startPoseCol; j < (startPoseCol + 3) && j < COLS; j++)
		{
			if ((i != kingRow || j != kingCol) && !canOnlyKingMove)
			{
				if (i < ROWS && j < COLS && i >= 0 && j >= 0) //run for all legal indexes around the king
				{
					if (_pieces[i][j] == nullptr || _pieces[i][j]->getColor() == turn)
					{
						if (!checkIfChess(turn, i, j)) //check if it's checkmate
						{
							return false;
						}
						gotToLoop = true;
					}
				}
			}
		}
	}
	return gotToLoop;
}


/*
returns a char array that presents the board with initials of the pieces
input: none
output: the char array
*/
char* Board::toString()
{
	int i = 0, j = 0, k = 0;
	char* board = new char[1024];

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			if (this->_pieces[i][j] != nullptr)
			{
				board[k] = this->_pieces[i][j]->getInitial(this->_pieces[i][j]->getColor());
			}
			else
			{
				board[k] = BLANK_POS;
			}
			k++;
		}
	}
	board[k] = '0';//change according to turn?
	board[k + 1] = '\0';
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

bool Board::didMoveCauseChess(int sourceRow, int sourceCol, int destRow, int destCol, Colors turn, int kingRow, int kingCol)
{
	Piece* eated = nullptr; //will probably need to save in another way, if pointer was deleted it wont matter it was saved.
	bool causedChess = true;
	Colors turnToCheck = WHITE;

	//calling with the reverse turn because the other pieces could not move (in checkIfChess).
	if (turn == WHITE)
	{
		turnToCheck = BLACK;
	}

	//if there is a piece in the destination, save it in case the action won't be legal.
	eated = this->_pieces[destRow][destCol];

	//update king location
	if (_pieces[sourceRow][sourceCol]->getType() == KING)
	{
		kingRow = destRow;
		kingCol = destCol;
	}

	//move the desired tool to the wanted destination. - will happen only if all the checks were made so won't need to check again.
	changePieceLocation(sourceRow, sourceCol, destRow, destCol);

	//check if a chess occurred to the current player, if it did not return true - else false.
	if (checkIfChess(turnToCheck, kingRow, kingCol)) // is turn for check if chess the turn to check if chess was on?
	{
		//return the moved piece and the eated piece if there was one to its old location(the source and destination respectively).

		causedChess = true;
	}
	else
	{
		causedChess =  false;
	}

	//move piece back
	changePieceLocation(destRow, destCol, sourceRow, sourceCol);
	this->_pieces[destRow][destCol] = eated;

	return causedChess;

}