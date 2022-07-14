#include "ConsoleHelper.h"
#include <iostream>

void ConsoleHelper::TestPrint(int i) {
	std::cout << i;
}

Game ConsoleHelper::InitialMenu()
{
	return Game();
}

int ConsoleHelper::GetIndexFromInput()
{
	return 0;
}

int ConsoleHelper::ParseFirstChar(char first)
{
	return 0;
}

int ConsoleHelper::ParseSecondChar(char second)
{
	return 0;
}

void ConsoleHelper::PrintRow(Board board, int selectedPiece, std::list<int> possibleMoves, int rowNumber)
{
}

void ConsoleHelper::PrintBoard(Board board, std::list<Piece> deadWhitePieces, std::list<Piece> deadBlackPieces, int selectedPiece, bool whitesTurn, std::list<int> possibleMoves)
{
}

void ConsoleHelper::PrintTurnDisplay(bool whitesTurn)
{
}

void ConsoleHelper::PrintSpace(Space space, bool selected)
{
}

void ConsoleHelper::PrintDeadPieces(std::list<Piece> deadPieces)
{
}
