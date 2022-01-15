#pragma once
class Position
{
private:
	char piece;
public:
	virtual bool canPlay() = 0;
	static const char EMPTY = ' ';
	static const char BLACK = 'B';
	static const char WHITE = 'W';
	void setPiece(char pieceValue);
	char getPiece();
};

