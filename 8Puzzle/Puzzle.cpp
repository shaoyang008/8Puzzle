#include "Puzzle.h"

Puzzle::Puzzle()
{
	_board[0][0] = 1;
	_board[0][1] = 2;
	_board[0][2] = 3;
	_board[1][0] = 4;
	_board[1][1] = 5;
	_board[1][2] = 6;
	_board[2][0] = 7;
	_board[2][1] = 8;
	_board[2][2] = 0;
}

Puzzle::Puzzle(const Puzzle& p)
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			_board[i][j] = p._board[i][j];
		}
	}
}

Puzzle::Puzzle(int array[9])
{
	for (int i = 0; i < 9; ++i) _board[i / 3][i % 3] = array[i];
}


Puzzle::Puzzle(int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9)
{
	_board[0][0] = i1;
	_board[0][1] = i2;
	_board[0][2] = i3;
	_board[1][0] = i4;
	_board[1][1] = i5;
	_board[1][2] = i6;
	_board[2][0] = i7;
	_board[2][1] = i8;
	_board[2][2] = i9;
}

Puzzle::~Puzzle()
{
}

void Puzzle::print() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << _board[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

Puzzle& Puzzle::operator=(const Puzzle& rhs) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			_board[i][j] = rhs._board[i][j];
		}
	}
	return *this;
}

// Try to move the tile and return the tile on success
// Return 0 otherwise
int Puzzle::try_move_tile(MOVE_DIR dir)
{
	// find the position of current zero
	int zero_x, zero_y;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!_board[i][j]) {
				zero_x = i;
				zero_y = j;
			}
		}
	}
	
	// decide if the direction is valid, which is not moving outside the board
	int candidate_x, candidate_y;
	switch (dir) {
		case MOVE_DIR::UP:
			if (zero_x == 0) return 0;
			else {
				candidate_x = zero_x - 1;
				candidate_y = zero_y;
			}
			break;
		case MOVE_DIR::DOWN:
			if (zero_x == 2) return 0;
			else {
				candidate_x = zero_x + 1;
				candidate_y = zero_y;
			}
			break;
		case MOVE_DIR::LEFT:
			if (zero_y == 0) return 0;
			else {
				candidate_x = zero_x;
				candidate_y = zero_y - 1;
			}
			break;
		case MOVE_DIR::RIGHT:
			if (zero_y == 2) return 0;
			else {
				candidate_x = zero_x;
				candidate_y = zero_y + 1;
			}
			break;
		default:
			return 0;
	}

	int moved = _board[candidate_x][candidate_y];
	_board[zero_x][zero_y] = moved;
	_board[candidate_x][candidate_y] = 0;
	return moved;
}