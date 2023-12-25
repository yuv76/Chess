#include "Game.h"

/*
C'tor for game object
input: starting player according to colors enum
output: none
*/
Game::Game(Colors startPlayer) :
	_turn(startPlayer), _winner(UNDETERMINED), _gameBoard()
{}

/*
d'tor for game.
input: none
output: none
*/
Game::~Game()
{}

/*
returns who is the winner or if there in still no winner
input: none
output: the answer according to winState enum
*/
WinState Game::getWinState()
{
	return this->_winner;
}

/*
return who's player turn this is
input: none
output: the players turn according to the Colors enum
*/
Colors Game::getTurn()
{
	return this->_turn;
}

/*
returns the game's board
input: none
output: the board
*/
Board& Game::getGameBoard()
{
	return this->_gameBoard;
}

/*
std::string Game::decodeMsg(std::string msg)
{

}
*/

/*
void Game::sendNextMove()
{

}
*/

/*

*/
void Game::playGame(Colors FirstPlayer)
{
	std::string msg = "";
	bool legalTurn = false;
	MsgCode status;
	int* extractedMsg = nullptr;


	//start game by sending board to front

	while (this->getWinState() == UNDETERMINED)
	{
		this->_gameBoard.printBoard();
		while (!legalTurn)
		{
			std::cin >> msg;
			extractedMsg = this->checkMsg(msg, status);
			if (extractedMsg != nullptr)
			{
				this->turn(extractedMsg);
				if (status == CHECKMATE)
				{
					if (this->_turn == WHITE)
					{
						this->_winner = WHITE_WON;
					}
					else if (this->_turn == BLACK)
					{
						this->_winner == BLACK_WON;
					}
				}
				legalTurn = true;
			}
			else
			{
				//send front error code
			}
			legalTurn = false;
			delete[] extractedMsg;
		}
		//send front succes code
		
	}
	if (this->getWinState() == WHITE)
	{
		std::cout << "white won!";
	}
	else
	{
		std::cout << "black won!";
	}
}

/*
plays a turn: makes one move changes turn to the other player.
input: the move, an int array at size of 4.
output: none.
*/
void Game::turn(int* move)
{
	//make move
	this->_gameBoard.move(move[0], move[1], move[2], move[3], this->_turn);

	//next turn
	if (this->_turn == BLACK)
	{
		this->_turn = WHITE;
	}
	else
	{
		this->_turn = BLACK;
	}
}


/*
checks if massage is a valid move, returns the message as an array if it is
input: the massege as string, a message code to change according to the vlidity status
output: an int array pointer in size of 4, each cell contains the massege positions
*/
int* Game::checkMsg(std::string msg, MsgCode& code)
{
	int* extractedMsg = new int(4);

	//extract message
	extractedMsg[0] = msg[0] - ASCII_SUB_FOR_COL;
	extractedMsg[1] = msg[1] - ASCII_SUB_FOR_ROW;
	extractedMsg[2] = msg[2] - ASCII_SUB_FOR_COL;
	extractedMsg[3] = msg[3] - ASCII_SUB_FOR_ROW;

	//check all problem codes
	code = this->_gameBoard.checkIfCanMove(extractedMsg[0], extractedMsg[1], extractedMsg[2], extractedMsg[3], this->getTurn());

	//if a problen occured
	if (code != VALID || code != CHESS || code != CHECKMATE)
	{
		return nullptr;
	}

	return extractedMsg;
}
