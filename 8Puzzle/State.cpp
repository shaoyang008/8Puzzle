#include "State.h"

State::State(): puzzle(Puzzle()), cost(0), move(0), g(0)
{

}

State::State(Puzzle p) : puzzle(p), cost(0), move(0), g(0)
{

}

State::~State()
{
}

void State::Update(int moved)
{
	move = moved;
	path.push_back(moved);
	g += 1;
}


// Calculate the distance of current state and given state
int State::Distance(State s)
{
	int temp = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			for (int m = 0;m < 3;m++) {
				for (int n = 0;n < 3;n++) {
					if (!s.puzzle[i][j]) break;
					else if (s.puzzle[i][j] == puzzle[m][n]) {
						temp = temp + fabs(m - i) + fabs(n - j);
					}
				}
			}
		}
	}
	return temp;
}