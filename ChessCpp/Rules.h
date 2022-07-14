#ifndef RULES_H
#define RULES_H

#include "Board.h"
#include <list>

class Rules {
public:
	static std::list<int> PossibleMoves(int firstInput, Board board);
	static bool CheckMove(int firstInput, int secondInput, Board board);
	static bool CheckCheck(int firstInput, int secondInput, Board, bool whitesTurn);
private:
	static bool CheckPawn(int firstInput, int secondInput, Board board);
	static bool CheckTower(int firstInput, int secondInput, Board board);
	static bool CheckBishop(int firstInput, int secondInput, Board board);
	static bool CheckKnight(int firstInput, int secondInput, Board board);
	static bool CheckKing(int firstInput, int secondInput, Board board);
	static bool CheckQueen(int firstInput, int secondInput, Board board);
};

#endif // !RULES_H