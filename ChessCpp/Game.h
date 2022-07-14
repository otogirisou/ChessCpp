#ifndef GAME_H
#define GAME_H

#include <string>
#include <list>
#include "Piece.h"
#include "Board.h"
#include "ConsoleHelper.h"
#include <algorithm>
#include <iostream>
#include "Rules.h"

class Game {
private:
	//void SaveGameAndExit();
	int GetIndexFromUser();
	void DisplayBoard(Board board, std::list<Piece> deadWhitePieces, std::list<Piece> deadBlackPieces, int selectedPiece, bool whitesTurn, std::list<int> possibleMoves);
	void DisplayMessage(std::string message);
	Board currentBoard{}; //check here
	bool whitesTurn{};
	std::list<Piece> deadWhitePieces{};
	std::list<Piece> deadBlackPieces{};

public:
	void StartGame();
	void PerformMove(int firstInput, int secondInput);
	bool getWhitesTurn();
	Board getCurrentBoard();
	std::list<Piece> getDeadWhitePieces();
	std::list<Piece> getDeadBlackPieces();
	Game(std::list<Piece> deadwhites, std::list<Piece> deadblacks);
	Game(Board board);
};
#endif // !GAME_H

