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

void Game::playGame(Colors FirstPlayer)
{
	std::string msg = "";
	bool legalMsg = false;

	//start game by sending board to front

	while (this->getWinState() == UNDETERMINED)
	{
		this->_gameBoard.printBoard();
		while (!legalMsg)
		{
			std::cin >> msg;
			legalMsg = this->checkMsg(msg);
		}
		this->turn(msg);
	}
}
*/

/*
MsgCode Game::turn(std::string move)
{

}
*/

/*
MsgCode Game::checkMsg(std::string msg)
{
	int extractedMsg[4] = { 0 };
	MsgCode valid = VALID;

	//check msg has valid chars
	if ((msg[0] >= 'a' && msg[0] <= 'h') && (msg[1] >= '1' && msg[1] <= '8') && (msg[3] >= 'a' && msg[3] <= 'h') && (msg[1] >= '1' && msg[1] <= '8'))
	{
		//extract message
		extractedMsg[0] = msg[0] - ASCII_SUB_FOR_COL;
		extractedMsg[1] = msg[1] - ASCII_SUB_FOR_ROW;
		extractedMsg[2] = msg[2] - ASCII_SUB_FOR_COL;
		extractedMsg[3] = msg[3] - ASCII_SUB_FOR_ROW;

		//check if a chess occured.
		valid = this->_gameBoard.checkIfChess(msg);
		//check if source position has player's piece
		valid = this->_gameBoard.isTaken(extractedMsg[0], extractedMsg[1], CHECK_SOURCE_POSITION);
		//check if destination position contains current player's piece
		valid = this->_gameBoard.isTaken(extractedMsg[2], extractedMsg[3], CHECK_DEST_POSITION);
		//check if move will result chess on current player

		//check if piece's move is legal

		//check if same position on source and destination

		//check if checkmate
		valid = this->_gameBoard.checkIfCheckmate(msg);
	}
	else
	{
		valid = INVALID_INDEXES;
	}

	//send 
}
*/


