#ifndef SPACE_H
#define SPACE_H

#include "Piece.h"

class Space {
public:
	Piece* OccupyingPiece; //check here constructor stuff
	bool getWhiteSpace();
	Space(bool w);
	Space();
private:
	bool whiteSpace{};
};
#endif // !SPACE_H
