#ifndef BOARD_H
#define BOARD_H

#include "Space.h"
class Board {
public:
	Space grid[64];
	void InitialSetup();
};

#endif // !BOARD_H