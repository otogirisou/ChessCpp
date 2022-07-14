#ifndef GAME_H
#define GAME_H

#include <string>
#include <list>
#include "Piece.h"
#include "Board.h"

class Game {
private:
	//void SaveGameAndExit();
	int GetIndexFromUser();
	void DisplayBoard();
	void DisplayMessage(std::string message);
	Board currentBoard{};
	bool whitesTurn{};
	std::list<Piece> deadWhitePieces{};
	std::list<Piece> deadBlackPieces{};

public:
	void StartGame();
	void PerformMove(int firstInput, int secondInput);
	void DisplayMessage(std::string message);
	void DisplayBoard(Board board, std::list<Piece> deadWhitePieces, std::list<Piece> deadBlackPieces, int selectedPiece, bool whitesTurn, std::list<int> possibleMoves);

	bool getWhitesTurn();
	Board getCurrentBoard();
	std::list<Piece> getDeadWhitePieces();
	std::list<Piece> getDeadBlackPieces();
};
#endif // !GAME_H

