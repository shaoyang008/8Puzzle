#include <iostream>
#include <vector>
#include <queue>
#include "State.h"

using namespace std;

State gFinishedState(Puzzle(1, 2, 3, 8, 0, 4, 7, 6, 5));
/*---------
1 2 3
8 0 4
7 6 5
-----------*/

MOVE_DIR gDirections[4] = { MOVE_DIR::DOWN, MOVE_DIR::UP, MOVE_DIR::RIGHT, MOVE_DIR::LEFT };

class CompareState {
public:
	bool operator()(State& a, State& b) const { return a.cost > b.cost; }
};

void AStar(int input[9])
{
	priority_queue<State, vector<State>, CompareState> pq;
	State next_state, current_state(input);
	
	current_state.cost = current_state.Distance(gFinishedState);

	while (current_state.Distance(gFinishedState))
	{
		int moved;
		for (int i = 0; i < 4; i++) {
			next_state = current_state;
			// Try if move is valid
			moved = next_state.puzzle.try_move_tile(gDirections[i]);

			// Avoid moving back and forth
			if (moved > 0 && current_state.move != moved)
			{
				// Update data of potential next state if move is successful and queue them
				next_state.Update(moved);
				next_state.cost = next_state.Distance(gFinishedState) + next_state.g;
				pq.push(next_state);
			}
		}
		
		// Move to next state
		current_state = pq.top();
		pq.pop();
	}

	cout << "The number of steps is " << current_state.path.size() << endl;
	current_state.PrintPath();
}


int main(int argc, char** argv)
{
	int input[9] = { 5, 6, 7, 4, 0, 8, 3, 2, 1 };
	/*---------
	5 6 7
	4 0 8
	3 2 1
	-----------*/
	AStar(input);
}
