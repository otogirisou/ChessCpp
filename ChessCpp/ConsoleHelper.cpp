#include "ConsoleHelper.h"
#include "Game.h"

using namespace rang;



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
		PrintBoard(game.getCurrentBoard(), deadWhites, deadBlacks, -1, game.getWhitesTurn(), std::list<int>());
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

void ConsoleHelper::PrintRow(const Board& board, int selectedPiece, const std::list<int>& possibleMoves, int rowNumber)
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

rang::bg ConsoleHelper::GetBackground(const Space& space, bool selected)
{
	if (selected)
	{
		return bg::green;
	}
	else if (space.getWhiteSpace())
	{
		return bg::gray;
	}
	else
	{
		return bg::black;
	}
}

rang::fg ConsoleHelper::GetForeground(const Space& space)
{
	if (space.OccupyingPiece->getWhite())
	{
		return fg::blue;
	}
	else
	{
		return fg::red;
	}
}

void ConsoleHelper::PrintBoard(const Board& board, const std::list<Piece>& deadWhitePieces, const std::list<Piece>& deadBlackPieces, int selectedPiece, bool whitesTurn, const std::list<int>& possibleMoves)
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
	PrintTurnDisplay(whitesTurn);
}

void ConsoleHelper::PrintTurnDisplay(bool whitesTurn)
{
	std::cout << fg::black;
	if (whitesTurn)
	{
		std::cout << bg::cyan << "       Blues's turn " << '\n';
	}
	else
	{
		std::cout << bg::magenta << "       Reds's turn  " << '\n';
	}
	std::cout << bg::reset << fg::reset;

}

void ConsoleHelper::PrintSpace(const Space& space, bool selected)
{
	bg background = GetBackground(space, selected);
	if (space.OccupyingPiece != nullptr)
	{
		fg foreground = GetForeground(space);
		std::cout << foreground << background << space.OccupyingPiece->getLetter();
	}
	else
	{
		std::cout << background << ' ';
	}
	std::cout << background << ' ';
	std::cout << bg::reset << fg::reset;
}

void ConsoleHelper::PrintDeadPieces(const std::list<Piece>& deadPieces)
{
}
