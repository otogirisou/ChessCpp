#ifndef CONSOLEHELPER_H
#define CONSOLEHELPER_H

#include <iostream>
#include <list> 
#include "Space.h"
#include "Board.h"
#include "Piece.h"
#include "Game.h"
#include <algorithm>
#include <string>
#include <stdexcept>


class ConsoleHelper {
public:
	static Game InitialMenu();
	static int GetIndexFromInput();
	static void PrintBoard(Board board, std::list<Piece> deadWhitePieces, std::list<Piece> deadBlackPieces, int selectedPiece, bool whitesTurn, std::list<int> possibleMoves);

private:
	static int ParseFirstChar(char first);
	static int ParseSecondChar(char second);
	static void PrintTurnDisplay(bool whitesTurn);
	static void PrintSpace(Space space, bool selected);
	static void PrintDeadPieces(std::list<Piece> deadPieces);
	static void PrintRow(Board board, int selectedPiece, std::list<int> possibleMoves, int rowNumber);
	//void SaveGameAndExit(Game game);
};





#endif // !CONSOLEHELPER_H


