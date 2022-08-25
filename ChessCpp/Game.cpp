#include "Game.h"



int Game::GetFirstMove()
{
	while (true)
	{
		DisplayMessage("Where is the piece you want to move? (A-H)(1-8)");
		int firstMove = GetIndexFromUser();
		if (firstMove == -1)
		{
			DisplayMessage("Not a valid input! Try again");
		}
		else if (firstMove == -2)
		{
			SaveGameAndExit();
		}
		else if (currentBoard.grid[firstMove].OccupyingPiece == nullptr)
		{
			DisplayBoard(currentBoard, deadWhitePieces, deadBlackPieces, -1, (bool)whitesTurn, std::list<int>());
			DisplayMessage("There is no piece to move there! Try again");
		}
		else if (currentBoard.grid[firstMove].OccupyingPiece->getWhite() != whitesTurn) //dont have to check elsewhere but i think currently it does.(THIS COMMENT IS STRAIGHT FROM THE C#
		{
			DisplayBoard(currentBoard, deadWhitePieces, deadBlackPieces, -1, whitesTurn, std::list<int>());
			DisplayMessage("The piece there is not yours! Try again");
		}
		else
		{
			return firstMove;
		}
	}
}

int Game::GetSecondMove(int firstMove)
{
	while (true)
	{
		DisplayBoard(currentBoard, deadWhitePieces, deadBlackPieces, firstMove, (bool)whitesTurn, Rules::PossibleMoves(firstMove, currentBoard));
		DisplayMessage("Where do you want to move? (A - H)(1 - 8)");
		int secondMove = GetIndexFromUser();
		if (secondMove == -1)
		{
			DisplayBoard(currentBoard, deadWhitePieces, deadBlackPieces, -1, (bool)whitesTurn, std::list<int>());
			DisplayMessage("Not a valid input! Try again");
		}
		else if (secondMove == -2)
		{
			SaveGameAndExit();
		}
		else if (Rules::CheckMove(firstMove, secondMove, currentBoard))
		{
			if (!Rules::CheckCheck(firstMove, secondMove, currentBoard, (bool)whitesTurn))
			{
				DisplayBoard(currentBoard, deadWhitePieces, deadBlackPieces, -1, (bool)whitesTurn, std::list<int>());
				DisplayMessage("That move would leave your king checked! Try again");
			}
			else
			{
				return secondMove;
			}
		}
		else
		{
			DisplayBoard(currentBoard, deadWhitePieces, deadBlackPieces, -1, (bool)whitesTurn, std::list<int>());
			DisplayMessage("Not a valid move! Try again");
		}
		firstMove = GetFirstMove();
	}
}

void Game::StartGame() { //refactor this holy shit
	int firstMove;
	int secondMove;
	while (true)
	{
		firstMove = GetFirstMove();
		secondMove = GetSecondMove(firstMove);

		PerformMove(firstMove, secondMove);
		whitesTurn = !whitesTurn;
		DisplayBoard(currentBoard, deadWhitePieces, deadBlackPieces, -1, (bool)whitesTurn, std::list<int>());

	}
}

void Game::PerformMove(int firstInput, int secondInput)
{
	currentBoard.grid[firstInput].OccupyingPiece->setHasMoved(true);
	if (currentBoard.grid[secondInput].OccupyingPiece != nullptr)
	{
		if (currentBoard.grid[secondInput].OccupyingPiece->getWhite())
		{
			deadWhitePieces.push_back(*currentBoard.grid[secondInput].OccupyingPiece);
		}
		else
		{
			deadBlackPieces.push_back(*currentBoard.grid[secondInput].OccupyingPiece);
		}
	}
	currentBoard.grid[secondInput].OccupyingPiece = currentBoard.grid[firstInput].OccupyingPiece;
	currentBoard.grid[firstInput].OccupyingPiece = nullptr;
}

void Game::SetUpBoard()
{
	currentBoard.InitialSetup();
}

void Game::SaveGameAndExit()
{
}

int Game::GetIndexFromUser()
{
	return ConsoleHelper::GetIndexFromInput();
}


void Game::DisplayMessage(std::string message)
{
	std::cout << message << '\n';
}

void Game::DisplayBoard(const Board& board, const std::list<Piece>& deadWhitePieces, const std::list<Piece>& deadBlackPieces, int selectedPiece, bool whitesTurn, const std::list<int>& possibleMoves) const
{
	ConsoleHelper::PrintBoard(board, deadWhitePieces, deadBlackPieces, selectedPiece, whitesTurn, possibleMoves);
}

bool Game::getWhitesTurn() const
{
	return whitesTurn;
}

Board Game::getCurrentBoard() const
{
	return currentBoard;
}

std::list<Piece> Game::getDeadWhitePieces() const
{
	return deadWhitePieces;
}

std::list<Piece> Game::getDeadBlackPieces() const
{
	return deadBlackPieces;
}

Game::Game(const std::list<Piece>& deadwhites, const std::list<Piece>& deadblacks)
	: deadWhitePieces(deadwhites), deadBlackPieces(deadblacks), whitesTurn(true)
{
}

Game::Game(const Board& board)
{
	currentBoard = board;
}
