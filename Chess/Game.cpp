#include "Game.h"
#include "Pipe.h"
#include <thread>

/*
C'tor for game object.
input: starting player according to colors enum.
output: none.
*/
Game::Game(Colors startPlayer) :
	_turn(startPlayer), _winner(UNDETERMINED), _gameBoard()
{}

/*
d'tor for game.
input: none.
output: none.
*/
Game::~Game()
{}

/*
returns who is the winner or if there in still no winner.
input: none.
output: the answer according to winState enum.
*/
WinState Game::getWinState()
{
	return this->_winner;
}

/*
return who's player turn this is.
input: none.
output: the players turn according to the Colors enum.
*/
Colors Game::getTurn()
{
	return this->_turn;
}

/*
returns the game's board.
input: none.
output: the board.
*/
Board& Game::getGameBoard()
{
	return this->_gameBoard;
}

/*
Runs the entire game, communicates with front.
input: none.
output: none.
*/
void Game::playGame()
{
	std::string msg = "";
	bool legalTurn = false;
	MsgCode status;
	int* extractedMsg = nullptr;
	Pipe p;
	bool isConnect = p.connect();
	std::string ans;
	char codeChar = ' ';

	while (!isConnect)
	{
		std::cout << "cant connect to graphics" << std::endl;
		std::cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << std::endl;
		std::cin >> ans;

		if (ans == "0") 
		{
			std::cout << "trying connect again.." << std::endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}

	char* msgToGraphics;

	//start game by sending board to front
	msgToGraphics = this->_gameBoard.toString();
	p.sendMessageToGraphics(msgToGraphics);
	std::string msgFromGraphics = "";

	while (this->getWinState() == UNDETERMINED && msgFromGraphics != "quit")
	{
		std::cout << std::endl;
		this->_gameBoard.printBoard();
		std::cout << std::endl;
		do
		{
			msgFromGraphics = p.getMessageFromGraphics();
			if (msgFromGraphics != "quit")
			{
				extractedMsg = this->extractMsg(msgFromGraphics);

				if (extractedMsg != nullptr)
				{
					status = this->_gameBoard.move(extractedMsg[0], extractedMsg[1], extractedMsg[2], extractedMsg[3], this->_turn);
					if (status == VALID || status == CHESS || status == CASTLING || status == CASTLING_AND_CHESS)
					{
						this->nextTurn(extractedMsg);
					}
					if (status == CHECKMATE || status == CASTLING_AND_MATE)
					{
						if (this->_turn == WHITE)
						{
							this->_winner = WHITE_WON;
						}
						else if (this->_turn == BLACK)
						{
							this->_winner = BLACK_WON;
						}
					}
					if (status != VALID && status != CHECKMATE && status != CHESS && status != CASTLING && status != CASTLING_AND_MATE && status != CASTLING_AND_CHESS)
					{
						legalTurn = false;
					}
					else
					{
						legalTurn = true;
					}

					if (status == CASTLING_AND_CHESS)
					{
						codeChar = 'a'; //code for castling and chess
					}
					else if (status == CASTLING_AND_MATE)
					{
						codeChar = 'b'; //code for castling and mate
					}
					else
					{
						codeChar = std::to_string(status)[0]; //regular code
					}
					msgToGraphics[0] = codeChar;
					msgToGraphics[1] = '\0';
					p.sendMessageToGraphics(msgToGraphics);

					delete[] extractedMsg;
				}
			}
		} while (!legalTurn && msgFromGraphics != "quit");
	}
	if (this->getWinState() == WHITE_WON)
	{
		std::cout << "white won!" << std::endl;
	}
	else if (this->getWinState() == BLACK_WON)
	{
		std::cout << "black won!" << std::endl;
	}
	else
	{
		std::cout << "no winner..." << std::endl;
	}
	delete[] msgToGraphics;
	p.close();
}

/*
plays a turn: makes one move changes turn to the other player.
input: the move, an int array at size of 4.
output: none.
*/
void Game::nextTurn(int* move)
{
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
checks if massage is a valid move, returns the message as an array if it is.
input: the massege as string, a message code to change according to the vlidity status.
output: an int array pointer in size of 4, each cell contains the massege positions.
*/
int* Game::extractMsg(std::string msg)
{
	int* extractedMsg = new int[4];
	if (msg.length() >= 4)
	{
		//extract message
		extractedMsg[0] = msg[1] - ASCII_SUB_FOR_ROW;
		extractedMsg[0] -= ROWS - 1;
		extractedMsg[0] *= -1;

		extractedMsg[1] = msg[0] - ASCII_SUB_FOR_COL;

		extractedMsg[2] = msg[3] - ASCII_SUB_FOR_ROW;
		extractedMsg[2] -= ROWS - 1;
		extractedMsg[2] *= -1;

		extractedMsg[3] = msg[2] - ASCII_SUB_FOR_COL;
	}
	else
	{
		delete[] extractedMsg;
		extractedMsg = nullptr;
	}

	return extractedMsg;
}
