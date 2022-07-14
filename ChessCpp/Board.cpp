#include "Board.h"

void Board::InitialSetup() {
	bool whiteSpace = true;
	for (int i = 0; i < 64; i++)
	{
		if (i % 8 != 0)
		{
			whiteSpace = !whiteSpace;
		}
		grid[i] = Space(whiteSpace);
	}

	for (int i = 0; i < 8; i++)
	{
		grid[48 + i].OccupyingPiece = new Piece(true, pieceType::Pawn);
		grid[8 + i].OccupyingPiece = new Piece(false, pieceType::Pawn);
	}
	//white pieces
	grid[56].OccupyingPiece = new Piece(true, pieceType::Tower);
	grid[63].OccupyingPiece = new Piece(true, pieceType::Tower);
	grid[57].OccupyingPiece = new Piece(true, pieceType::Knight);
	grid[62].OccupyingPiece = new Piece(true, pieceType::Knight);
	grid[58].OccupyingPiece = new Piece(true, pieceType::Bishop);
	grid[61].OccupyingPiece = new Piece(true, pieceType::Bishop);
	grid[59].OccupyingPiece = new Piece(true, pieceType::King);
	grid[60].OccupyingPiece = new Piece(true, pieceType::Queen);
	//black pieces
	grid[0].OccupyingPiece = new Piece(false, pieceType::Tower);
	grid[7].OccupyingPiece = new Piece(false, pieceType::Tower);
	grid[1].OccupyingPiece = new Piece(false, pieceType::Knight);
	grid[6].OccupyingPiece = new Piece(false, pieceType::Knight);
	grid[2].OccupyingPiece = new Piece(false, pieceType::Bishop);
	grid[5].OccupyingPiece = new Piece(false, pieceType::Bishop);
	grid[3].OccupyingPiece = new Piece(false, pieceType::King);
	grid[4].OccupyingPiece = new Piece(false, pieceType::Queen);

}