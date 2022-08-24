#include "Space.h"

bool Space::getWhiteSpace() const
{
	return whiteSpace;
}

Space::Space(bool w)
	: whiteSpace(w), OccupyingPiece(nullptr)
{

}

Space::Space()
	: OccupyingPiece(nullptr)
{
}
