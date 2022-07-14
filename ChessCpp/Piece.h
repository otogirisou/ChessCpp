#ifndef PIECE_H
#define PIECE_H

enum class pieceType {
	Pawn,
	Tower,
	Bishop,
	King,
	Queen,
	Knight
};

class Piece {
private:
	pieceType typeOfPiece;
	char letter{};
	bool white{};
	bool hasMoved{};

public:
	pieceType getPieceType();
	bool getHasMoved();
	void setHasMoved(bool input);
	char getLetter();
	bool getWhite();
	Piece(bool White, pieceType piecetype);
	Piece();
};

#endif // !PIECE_H

