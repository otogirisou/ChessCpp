#include "Piece.h"

pieceType Piece::getPieceType()
{
	return typeOfPiece;
}

bool Piece::getHasMoved() const
{
	return hasMoved;
}

void Piece::setHasMoved(bool input)
{
	if (!hasMoved)
		hasMoved = input;
}

char Piece::getLetter() const
{
	return letter;
}

bool Piece::getWhite() const
{
	return white;
}

Piece::Piece(bool White, pieceType piecetype)
	: typeOfPiece(piecetype), white(White), hasMoved(false) //maybe not false for json or whatever
{
	switch (piecetype)
	{
	case pieceType::Pawn:
		letter = 'p';
		break;
	case pieceType::Tower:
		letter = 't';
		break;
	case pieceType::Knight:
		letter = 'k';
		break;
	case pieceType::Bishop:
		letter = 'b';
		break;
	case pieceType::King:
		letter = 'K';
		break;
	case pieceType::Queen:
		letter = 'Q';
		break;
	default:
		return;
	}
}

Piece::Piece()
{
}
