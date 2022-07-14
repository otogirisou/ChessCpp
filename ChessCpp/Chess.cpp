#include "Piece.h"
#include "Space.h"
#include "Board.h"
#include "Rules.h"
#include "ConsoleHelper.h"
#include "Game.h"

Game GetGame() //to add modularity
{
	return ConsoleHelper::InitialMenu();
}

int main() {
	Game game = GetGame();
	game.StartGame();
	return 0;
}

