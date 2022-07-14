#ifndef GAME_H
#define GAME_H

#include <string>
#include <list>
#include "Piece.h"
#include "Board.h"

class Game {
	void StartGame();
	void PerformMove(int firstInput, int secondInput);
	void DisplayMessage(std::string message);
	void DisplayBoard(Board board, std::list<Piece> deadWhitePieces, std::list<Piece> deadBlackPieces, int selectedPiece, bool whitesTurn, std::list<int> possibleMoves);
};
#endif // !GAME_H

