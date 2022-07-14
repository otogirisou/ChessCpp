#include "Game.h"



void Game::StartGame() {
	int firstMove;
	int secondMove;
	while (true)
	{
		DisplayMessage("Where is the piece you want to move? (A-H)(1-8)");
		firstMove = GetIndexFromUser();
		if (firstMove == -1)
		{
			DisplayMessage("Not a valid input! Try again");
			//temp
			continue;
		}
		else if (firstMove == -2)
		{
			//SaveGameAndExit();
			break;
		}
		else if (currentBoard.grid[firstMove].OccupyingPiece == nullptr)
		{
			std::list<int> emptyList;
			DisplayBoard(currentBoard, deadWhitePieces, deadBlackPieces, -1, whitesTurn, emptyList);
			DisplayMessage("There is no piece to move there! Try again");
			continue;
		}
		Piece firstPiece = *currentBoard.grid[firstMove].OccupyingPiece;
		if (firstPiece.getWhite() != whitesTurn) //dont have to check elsewhere but i think currently it does...
		{
			std::list<int> emptyList;
			DisplayBoard(currentBoard, deadWhitePieces, deadBlackPieces, -1, whitesTurn, emptyList);
			DisplayMessage("The piece there is not yours! Try again");
		}
		else
		{
			DisplayBoard(currentBoard, deadWhitePieces, deadBlackPieces, firstMove, (bool)whitesTurn, Rules::PossibleMoves(firstMove, currentBoard));
			DisplayMessage("Where do you want to move? (A - H)(1 - 8)");
			secondMove = GetIndexFromUser();
			if (secondMove == -1)
			{
				std::list<int> emptyList;
				DisplayBoard(currentBoard, deadWhitePieces, deadBlackPieces, -1, whitesTurn, emptyList);
				DisplayMessage("Not a valid input! Try again");
			}
			else if (secondMove == -2)
			{
				//SaveGameAndExit();
				break;
			}
			else if (Rules::CheckMove(firstMove, secondMove, currentBoard))
			{
				if (!Rules::CheckCheck(firstMove, secondMove, currentBoard, (bool)whitesTurn))
				{
					std::list<int> emptyList;
					DisplayBoard(currentBoard, deadWhitePieces, deadBlackPieces, -1, whitesTurn, emptyList);
					DisplayMessage("That move would leave your king checked! Try again");
				}
				else
				{
					PerformMove(firstMove, secondMove);
					whitesTurn = !whitesTurn;
					std::list<int> emptyList;
					DisplayBoard(currentBoard, deadWhitePieces, deadBlackPieces, -1, whitesTurn, emptyList);
				}
			}
			else
			{
				std::list<int> emptyList;
				DisplayBoard(currentBoard, deadWhitePieces, deadBlackPieces, -1, whitesTurn, emptyList);
				DisplayMessage("Not a valid move! Try again");
			}
		}
	}
}

void Game::PerformMove(int firstInput, int secondInput)
{
	Piece firstPiece = *currentBoard.grid[firstInput].OccupyingPiece;
	firstPiece.setHasMoved(true);
	if (currentBoard.grid[secondInput].OccupyingPiece != nullptr)
	{
		Piece secondPiece = *currentBoard.grid[secondInput].OccupyingPiece;
		if (secondPiece.getWhite())
		{
			deadWhitePieces.push_back(secondPiece);
		}
		else
		{
			deadBlackPieces.push_back(secondPiece);
		}
	}
	currentBoard.grid[secondInput].OccupyingPiece = currentBoard.grid[firstInput].OccupyingPiece;
	currentBoard.grid[firstInput].OccupyingPiece = nullptr;
}

void Game::SetUpBoard()
{
	currentBoard.InitialSetup();
}

int Game::GetIndexFromUser()
{
	return ConsoleHelper::GetIndexFromInput();
}


void Game::DisplayMessage(std::string message)
{
	std::cout << message;
}

void Game::DisplayBoard(Board board, std::list<Piece> deadWhitePieces, std::list<Piece> deadBlackPieces, int selectedPiece, bool whitesTurn, std::list<int> possibleMoves)
{
	ConsoleHelper::PrintBoard(board, deadWhitePieces, deadBlackPieces, selectedPiece, whitesTurn, possibleMoves);
}

bool Game::getWhitesTurn()
{
	return whitesTurn;
}

Board Game::getCurrentBoard()
{
	return currentBoard;
}

std::list<Piece> Game::getDeadWhitePieces()
{
	return deadWhitePieces;
}

std::list<Piece> Game::getDeadBlackPieces()
{
	return deadBlackPieces;
}

Game::Game(std::list<Piece> deadwhites, std::list<Piece> deadblacks)
	: deadWhitePieces(deadwhites), deadBlackPieces(deadblacks), whitesTurn(true)
{
}

Game::Game(Board board)
{
	currentBoard = board;
}
