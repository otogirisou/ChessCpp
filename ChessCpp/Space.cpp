#include "Space.h"

bool Space::getWhiteSpace()
{
	return false;
}

Space::Space(bool w)
	: whiteSpace(w), OccupyingPiece(nullptr)
{

}

Space::Space()
{
}
