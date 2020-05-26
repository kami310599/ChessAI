
/*
Name : Ahmad Jamal Shaikh
Title : Chess AI
Description : A chess playing AI made with MinMax Algorithm and Alpha Beta Pruning
*/
#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <climits>

#define PAWN 0
#define ROOK 1
#define KNIGHT 2
#define BISHOP 3
#define QUEEN 4
#define KING 5

using namespace std;

enum PieceColor {
	White, Black
};
enum PieceType {
	pawn, rook, bishop, knight, queen, king
};

class Piece {
public:
	virtual void print() = 0;
	PieceColor get_color() {
		return color;
	}
	PieceType get_type() {
		return type;
	}
	static const short int eval_value;
protected:
	PieceType type;
	PieceColor color;
};

class Pawn: public Piece {
public:
	Pawn(PieceColor color) {
		this->type = pawn;
		this->color = color;
	}
	static const short int eval_value = 100;
	void print() {
		if (get_color() == White) {
			//wcout << "♙ ";
			cout << "WP\t";
		} else if (get_color() == Black) {
			cout << "BP\t";
			//wcout << "♟ ";
		}
	}
};
class Rook: public Piece {
public:
	Rook(PieceColor color) {
		this->type = rook;
		this->color = color;
	}
	static const short int eval_value = 500;
	void print() {
		if (get_color() == White) {
			//wcout << "♖ ";
			cout<< "WR\t";
		} else if (get_color() == Black) {
			//wcout << "♜ ";
			cout<<"BR\t";
		}
	}
};
class Bishop: public Piece {
public:
	Bishop(PieceColor color) {
		this->type = bishop;
		this->color = color;
	}
	static const short int eval_value = 325;
	void print() {
		if (get_color() == White) {
			//wcout << "♗ ";
			cout << "WB\t";
		} else if (get_color() == Black) {
			//wcout << "♝ ";
			cout << "BB\t";
		}
	}
};
class Knight: public Piece {
public:
	Knight(PieceColor color) {
		this->type = knight;
		this->color = color;
	}
	static const short int eval_value = 300;
	void print() {
		if (get_color() == White) {
			cout << "WN\t";
			//wcout << "♘ ";
		} else if (get_color() == Black) {
			cout << "BN\t";
			//wcout << "♞ ";
		}
	}
};
class Queen: public Piece {
public:
	Queen(PieceColor color) {
		this->type = queen;
		this->color = color;
	}
	static const short int eval_value = 900;
	void print() {
		if (get_color() == White) {
			cout << "WQ\t";
			//wcout << "♕ ";
		} else if (get_color() == Black) {
			cout << "BQ\t";
			//wcout << "♛ ";
		}
	}
};
class King: public Piece {
public:
	King(PieceColor color) {
		this->type = king;
		this->color = color;
	}
	static const short int eval_value = SHRT_MAX;
	void print() {
		if (get_color() == White) {
			cout << "WK\t";
			//wcout << "♔ ";
		} else if (get_color() == Black) {
			cout << "BK\t";
			//wcout << "♚ ";
		}
	}

};

#endif