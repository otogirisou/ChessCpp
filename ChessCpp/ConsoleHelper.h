#ifndef CONSOLEHELPER_H
#define CONSOLEHELPER_H

#include <iostream>
#include <list> //maybe??



class Game; //maybe not here...
class Board; //maybe not here
class Space; //maybe not here
class Piece; //maybe not here

Game InitialMenu();
int GetIndexFromInput();
int ParseFirstChar(char first);
int ParseSecondChar(char second);
void PrintRow(Board board, int selectedPiece, std::list<int> possibleMoves, int rowNumber);
void PrintBoard(Board board, std::list<Piece> deadWhitePieces, std::list<Piece> deadBlackPieces, int selectedPiece, bool whitesTurn, std::list<int> possibleMoves);
void PrintTurnDisplay(bool whitesTurn);
void PrintSpace(Space space, bool selected);
void PrintDeadPieces(std::list<Piece> deadPieces);

void TestPrint(int i) {}

//void SaveGameAndExit(Game game);
#endif // !CONSOLEHELPER_H


