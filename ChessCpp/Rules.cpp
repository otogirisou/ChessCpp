#include "Rules.h"

std::list<int> Rules::PossibleMoves(int firstInput, Board board)
{
	std::list<int> possibleMoves;
	for (int i = 0; i < 64; i++)
	{
		if (CheckMove(firstInput, i, board))
		{
			possibleMoves.push_back(i); //maybe push front dont wanna think rn
		}
	}
	return possibleMoves;
}

bool Rules::CheckMove(int firstInput, int secondInput, Board board)
{
	Piece firstPiece = *board.grid[firstInput].OccupyingPiece;
	switch (firstPiece.getPieceType())
	{
	case pieceType::Pawn:
		return CheckPawn(firstInput, secondInput, board);
	case pieceType::Tower:
		return CheckTower(firstInput, secondInput, board);
	case pieceType::Knight:
		return CheckKnight(firstInput, secondInput, board);
	case pieceType::Bishop:
		return CheckBishop(firstInput, secondInput, board);
	case pieceType::King:
		return CheckKing(firstInput, secondInput, board);
	case pieceType::Queen:
		return CheckQueen(firstInput, secondInput, board);
	default:
		return false;
	}
}

bool Rules::CheckCheck(int firstInput, int secondInput, Board, bool whitesTurn)
{
	return false;
}

bool Rules::CheckPawn(int firstInput, int secondInput, Board board)
{
	Piece firstPiece = *board.grid[firstInput].OccupyingPiece;
	if (board.grid[secondInput].OccupyingPiece == nullptr) //maybe switches here?
	{
		if (firstPiece.getWhite()) //checks here because white pawns move up and black pawns move down
		{
			if (secondInput + 8 == firstInput  //dest is one up
				|| (secondInput + 16 == firstInput && !firstPiece.getHasMoved() && board.grid[secondInput].OccupyingPiece == nullptr)) //dest is two up and the pawn hasnt moved yet
			{
				return true;
			}
			return false;
		}
		else
		{
			if (secondInput == firstInput + 8 //dest is one down
				|| (secondInput == firstInput + 16 && !firstPiece.getHasMoved() && board.grid[firstInput + 8].OccupyingPiece == nullptr)) //dest is two down and the pawn hasnt moved yet
			{
				return true;
			}
			return false;
		}
	}
	else
	{
		Piece secondPiece = *board.grid[secondInput].OccupyingPiece;
		if (firstPiece.getWhite() == secondPiece.getWhite())
		{
			return false;
		}
		else
		{
			if (firstPiece.getWhite())
			{
				if ((firstInput == secondInput + 7 && (firstInput + 1) % 8 != 0) || (firstInput == secondInput + 9 && firstInput % 8 != 0)) //dest is diag-up left or right
				{
					return true;
				}
				return false;
			}
			else
			{
				if ((secondInput == firstInput + 7 && (firstInput + 1) % 8 != 0) || (secondInput == firstInput + 9 && firstInput % 8 != 0)) //dest is diag-down left or right
				{
					return true;
				}
				return false;
			}
		}
	}
}

bool Rules::CheckTower(int firstInput, int secondInput, Board board)
{
	Piece firstPiece = *board.grid[firstInput].OccupyingPiece;
	//towering probably by editing here
	if (board.grid[secondInput].OccupyingPiece != nullptr)
	{
		Piece secondPiece = *board.grid[secondInput].OccupyingPiece;
		if (firstPiece.getWhite() == secondPiece.getWhite())
		{
			return false;
		}
	}
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	if (secondInput / 8 == firstInput / 8) //same row
	{
		int horrizontalTower = 1;
		if (secondInput < firstInput)
		{
			while (firstInput - horrizontalTower != secondInput) //check in between current and dest
			{
				if (board.grid[firstInput - horrizontalTower].OccupyingPiece != nullptr)
				{
					return false;
				}
				horrizontalTower++;
			}
		}
		else
		{
			while (firstInput + horrizontalTower != secondInput) //check in between current and dest
			{
				if (board.grid[firstInput + horrizontalTower].OccupyingPiece != nullptr)
				{
					return false;
				}
				horrizontalTower++;
			}
		}
		if (board.grid[secondInput].OccupyingPiece == nullptr)
		{
			return true;
		}
		Piece secondPiece = *board.grid[secondInput].OccupyingPiece;
		if (firstPiece.getWhite() != secondPiece.getWhite())
		{
			return true;
		}
	}
	else if (secondInput % 8 == firstInput % 8) //same col
	{
		int verticalTower = 1;
		if (secondInput < firstInput)
		{
			while (firstInput - (verticalTower * 8) != secondInput) //check in between current and dest
			{
				if (board.grid[firstInput - (verticalTower * 8)].OccupyingPiece != nullptr)
				{
					return false;
				}
				verticalTower++;
			}
		}
		else
		{
			while (firstInput + (verticalTower * 8) != secondInput) //check in between current and dest
			{
				if (board.grid[firstInput + (verticalTower * 8)].OccupyingPiece != nullptr)
				{
					return false;
				}
				verticalTower++;
			}
		}
		if (board.grid[secondInput].OccupyingPiece == nullptr)
		{
			return true;
		}
		Piece secondPiece = *board.grid[secondInput].OccupyingPiece;
		if (firstPiece.getWhite() != secondPiece.getWhite())
		{
			return true;
		}
	}
	return false;
}

bool Rules::CheckBishop(int firstInput, int secondInput, Board board)
{
	Piece firstPiece = *board.grid[firstInput].OccupyingPiece;
	if (board.grid[secondInput].OccupyingPiece != nullptr)
	{
		Piece secondPiece = *board.grid[secondInput].OccupyingPiece;
		if (firstPiece.getWhite() == secondPiece.getWhite())
		{
			return false;
		}
	}
	if (secondInput < firstInput)
	{
		int rowsToMove = firstInput / 8 - secondInput / 8;
		if (firstInput % 8 == (secondInput % 8) + rowsToMove || (firstInput % 8) + rowsToMove == (secondInput % 8)) //check if its diagonal
		{
			if (secondInput % 8 < firstInput % 8)
			{
				for (int i = 1; i < rowsToMove; i++) //check all spaces in between current and dest
				{
					if (board.grid[firstInput - 7 * i].OccupyingPiece != nullptr)
					{
						return false;
					}
				}
			}
			else
			{
				for (int i = 1; i < rowsToMove; i++) //check all spaces in between current and dest
				{
					if (board.grid[firstInput - 9 * i].OccupyingPiece != nullptr)
					{
						return false;
					}
				}
			}
			return true;
		}
		return false;
	}
	else
	{
		int rowsToMove = secondInput / 8 - firstInput / 8;
		if (firstInput % 8 == (secondInput % 8) + rowsToMove || (firstInput % 8) + rowsToMove == (secondInput % 8))
		{
			if (secondInput % 8 < firstInput % 8)
			{
				for (int i = 1; i < rowsToMove; i++) //check all spaces in between current and dest
				{
					if (board.grid[firstInput + 7 * i].OccupyingPiece != nullptr)
					{
						return false;
					}
				}
			}
			else
			{
				for (int i = 1; i < rowsToMove; i++) //check all spaces in between current and dest
				{
					if (board.grid[firstInput + 9 * i].OccupyingPiece != nullptr)
					{
						return false;
					}
				}
			}
			return true;
		}
		return false;
	}
}

bool Rules::CheckKnight(int firstInput, int secondInput, Board board)
{
	Piece firstPiece = *board.grid[firstInput].OccupyingPiece;
	if (board.grid[secondInput].OccupyingPiece != nullptr)
	{
		Piece secondPiece = *board.grid[secondInput].OccupyingPiece;
		if (firstPiece.getWhite() == secondPiece.getWhite())
		{
			return false;
		}
	}
	if (secondInput % 8 == 1 + firstInput % 8 || 1 + secondInput % 8 == firstInput % 8) //dest is one to either side
	{
		if (2 + secondInput / 8 == firstInput / 8 || 2 + firstInput / 8 == secondInput / 8) //dest is two up or down
		{
			return true;
		}
	}
	else if (1 + secondInput / 8 == firstInput / 8 || 1 + firstInput / 8 == secondInput / 8) //dest is one up or down
	{
		if (secondInput % 8 == 2 + firstInput % 8 || 2 + secondInput % 8 == firstInput % 8) //dest is two to either side
		{
			return true;
		}
	}
	return false;
}

bool Rules::CheckKing(int firstInput, int secondInput, Board board)
{
	Piece firstPiece = *board.grid[firstInput].OccupyingPiece;
	if (board.grid[secondInput].OccupyingPiece != nullptr)
	{
		Piece secondPiece = *board.grid[secondInput].OccupyingPiece;
		if (firstPiece.getWhite() == secondPiece.getWhite())
		{
			return false;
		}
	}
	if ((secondInput == firstInput + 1 && firstInput % 8 < 7) //dest is one to the right
		|| (secondInput + 1 == firstInput && firstInput % 8 > 0) //dest is one to the left
		|| secondInput + 8 == firstInput //dest is one up
		|| secondInput == firstInput + 8 //dest is one down
		|| (secondInput == firstInput + 9 && firstInput % 8 < 7) //dest is diagonal down right
		|| (secondInput + 9 == firstInput && firstInput % 8 > 0) //dest is diagonal up left
		|| (secondInput == firstInput + 7 && firstInput % 8 > 0) //dest is diagonal down left
		|| (secondInput + 7 == firstInput && firstInput % 8 < 7)) //dest is diagonal up right
	{
		return true;
	}

	return false;
}

bool Rules::CheckQueen(int firstInput, int secondInput, Board board)
{
	if (CheckKing(firstInput, secondInput, board) || CheckTower(firstInput, secondInput, board) || CheckBishop(firstInput, secondInput, board)) //queens moveset is a combination of these three
	{
		return true;
	}
	return false;
}
