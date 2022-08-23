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
#include <list>

class Game {
private:
	//void SaveGameAndExit();
	int GetIndexFromUser();
	void DisplayBoard(const Board& board, const std::list<Piece>& deadWhitePieces, const std::list<Piece>& deadBlackPieces, int selectedPiece, bool whitesTurn, const std::list<int>& possibleMoves);
	void DisplayMessage(std::string message);
	Board currentBoard; //check here
	bool whitesTurn{};
	std::list<Piece> deadWhitePieces{};
	std::list<Piece> deadBlackPieces{};

public:
	void StartGame();
	void PerformMove(int firstInput, int secondInput);
	void SetUpBoard();
	bool getWhitesTurn();
	Board getCurrentBoard();
	std::list<Piece> getDeadWhitePieces();
	std::list<Piece> getDeadBlackPieces();
	Game(const std::list<Piece>& deadwhites, const std::list<Piece>& deadblacks);
	Game(const Board& board);
};
#endif // !GAME_H

