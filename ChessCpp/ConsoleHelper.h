#ifndef CONSOLEHELPER_H
#define CONSOLEHELPER_H

#include <iostream>
#include <list> 
#include "Space.h"
#include "Board.h"
#include "Piece.h"
#include <algorithm>
#include <string>
#include <stdexcept>
#include "rang.hpp"

class Game;

class ConsoleHelper {
public:
	static Game InitialMenu();
	static int GetIndexFromInput();
	static void PrintBoard(const Board& board, const std::list<Piece>& deadWhitePieces, const std::list<Piece>& deadBlackPieces, int selectedPiece, bool whitesTurn, const std::list<int>& possibleMoves);

private:
	static int ParseFirstChar(char first);
	static int ParseSecondChar(char second);
	static void PrintTurnDisplay(bool whitesTurn);
	static void PrintSpace(const Space& space, bool selected);
	static void PrintDeadPieces(const std::list<Piece>& deadPieces);
	static void PrintRow(const Board& board, int selectedPiece, const std::list<int>& possibleMoves, int rowNumber);
	static rang::bg GetBackground(const Space& space, bool selected);
	static rang::fg GetForeground(const Space&);
	//void SaveGameAndExit(Game game);
};





#endif // !CONSOLEHELPER_H


