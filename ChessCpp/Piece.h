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
	bool getHasMoved() const;
	void setHasMoved(bool input);
	char getLetter() const;
	bool getWhite() const;
	Piece(bool White, pieceType piecetype);
	Piece();
};

#endif // !PIECE_H

