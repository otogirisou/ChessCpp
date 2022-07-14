#ifndef RULES_H
#define RULES_H

class Board; //maybe not here damne
bool CheckMove(int firstInput, int secondInput, Board board);
bool CheckCheck(int firstInput, int secondInput, Board, bool whitesTurn);
bool CheckPawn(int firstInput, int secondInput, Board board);
bool CheckTower(int firstInput, int secondInput, Board board);
bool CheckBishop(int firstInput, int secondInput, Board board);
bool CheckKnight(int firstInput, int secondInput, Board board);
bool CheckKing(int firstInput, int secondInput, Board board);
bool CheckQueen(int firstInput, int secondInput, Board board);

#endif // !RULES_H

