#include "ConsoleHelper.h"
#include "Game.h"



Game ConsoleHelper::InitialMenu()
{
	std::string userInput = "";
	do
	{
		printf("\033c"); //maybe????
		std::cout << "Enter 'new' to start a new game" << '\n';
		std::cout << "Enter 'load' to load previous game. Enter 'save' while playing to save" << '\n';
		std::cin >> userInput;
	} while (userInput != "new"); //&& userInput != "load");
	if (userInput == "new")
	{
		std::list<Piece> deadWhites;
		std::list<Piece> deadBlacks;
		Game game = Game(deadWhites, deadBlacks);
		game.SetUpBoard();
		return game;
	}
}

int ConsoleHelper::GetIndexFromInput()
{
	int firstPart{};
	int secondPart{};
	std::string userInput = "";

	std::cin >> userInput;

	firstPart = ParseFirstChar(userInput[0]);
	secondPart = ParseSecondChar(userInput[1]);

	return firstPart + secondPart;
}

int ConsoleHelper::ParseFirstChar(char first)
{
	switch (first)
	{
	case 'a':
		return 0;
	case 'b':
		return 1;
	case 'c':
		return 2;
	case 'd':
		return 3;
	case 'e':
		return 4;
	case 'f':
		return 5;
	case 'g':
		return 6;
	case 'h':
		return 7;
	default:
		return -1;
	}
}

int ConsoleHelper::ParseSecondChar(char second)
{
	std::string charToString(1, second);
	try {
		int i = std::stoi(charToString);
		switch (i)
		{
		case 1:
			return 0;
		case 2:
			return 8;
		case 3:
			return 16;
		case 4:
			return 24;
		case 5:
			return 32;
		case 6:
			return 40;
		case 7:
			return 48;
		case 8:
			return 56;
		default:
			return -1;
		}
	}
	catch (std::invalid_argument) {
		return -1;
	}
}

void ConsoleHelper::PrintRow(Board board, int selectedPiece, std::list<int> possibleMoves, int rowNumber)
{
	bool selected;
	for (int i = 0; i < 8; i++)
	{
		selected = false;
		bool found = (std::find(possibleMoves.begin(), possibleMoves.end(), i + (rowNumber * 8)) != possibleMoves.end());
		if (i + (rowNumber * 8) == selectedPiece || found)
		{
			selected = true;
		}
		PrintSpace(board.grid[i + rowNumber * 8], selected);
	}
}

void ConsoleHelper::PrintBoard(Board board, std::list<Piece> deadWhitePieces, std::list<Piece> deadBlackPieces, int selectedPiece, bool whitesTurn, std::list<int> possibleMoves)
{
	printf("\033c"); //maybe????
	for (int i = 0; i < 8; i++)
	{
		std::cout << i + 1 << " - ";
		PrintRow(board, selectedPiece, possibleMoves, i);
		/*if (i == 0)
		{
			Console.Write("  Dead blue pieces: ");
			PrintDeadPieces(deadWhitePieces);
		}
		else if (i == 1)
		{
			Console.Write("  Dead red pieces:  ");
			PrintDeadPieces(deadBlackPieces);
		}*/
		std::cout << '\n';
	}
	std::cout << "     A B C D E F G H" << '\n';
}

void ConsoleHelper::PrintTurnDisplay(bool whitesTurn)
{
}

void ConsoleHelper::PrintSpace(Space space, bool selected)
{
	if (space.OccupyingPiece != nullptr)
	{
		Piece thePiece = *space.OccupyingPiece;
		std::cout << thePiece.getLetter();
	}
	else
	{
		std::cout << ' ';
	}
	std::cout << ' ';
}

void ConsoleHelper::PrintDeadPieces(std::list<Piece> deadPieces)
{
}
