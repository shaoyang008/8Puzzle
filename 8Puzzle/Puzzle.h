#pragma once
#include <iostream>

typedef int row[3];

enum class MOVE_DIR {
	UP,
	DOWN,
	RIGHT,
	LEFT
};

class Puzzle
{
public:
	Puzzle();
	Puzzle(const Puzzle&);
	Puzzle(int[9]);
	Puzzle(int, int, int, int, int, int, int, int, int);
	~Puzzle();

	// to access the tiles of puzzle
	row& operator[](const int i) { return _board[i]; }
	const row& operator[](const int i) const { return _board[i]; }

	int try_move_tile(MOVE_DIR);
	void print();

	Puzzle& operator= (const Puzzle&);
	row _board[3];
};

