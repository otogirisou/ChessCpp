#include "Game.h"

void Game::StartGame() {

}

void Game::PerformMove(int firstInput, int secondInput)
{
}

int Game::GetIndexFromUser()
{
	return 0;
}

void Game::DisplayBoard()
{
}

void Game::DisplayMessage(std::string message)
{
}

void Game::DisplayBoard(Board board, std::list<Piece> deadWhitePieces, std::list<Piece> deadBlackPieces, int selectedPiece, bool whitesTurn, std::list<int> possibleMoves)
{
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
	: deadWhitePieces(deadwhites), deadBlackPieces(deadblacks)
{
}
