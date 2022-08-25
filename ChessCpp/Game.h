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
	void SaveGameAndExit();
	static int GetIndexFromUser();
	void DisplayBoard(const Board& board, const std::list<Piece>& deadWhitePieces, const std::list<Piece>& deadBlackPieces, int selectedPiece, bool whitesTurn, const std::list<int>& possibleMoves) const;
	static void DisplayMessage(std::string message);
	Board currentBoard; //check here
	bool whitesTurn{};
	std::list<Piece> deadWhitePieces{};
	std::list<Piece> deadBlackPieces{};
	int GetFirstMove();
	int GetSecondMove(int firstMove);

public:
	void StartGame();
	void PerformMove(int firstInput, int secondInput);
	void SetUpBoard();
	bool getWhitesTurn() const;
	Board getCurrentBoard() const;
	std::list<Piece> getDeadWhitePieces() const;
	std::list<Piece> getDeadBlackPieces() const;
	Game(const std::list<Piece>& deadwhites, const std::list<Piece>& deadblacks);
	Game(const Board& board);
};
#endif // !GAME_H

