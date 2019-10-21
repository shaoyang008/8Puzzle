#pragma once
#include "Puzzle.h"
#include <vector>
#include <cmath>

class State
{
public:
	State();
	State(Puzzle);
	~State();

	void Update(int);

	int Distance(State);
	void PrintPath() { for (int i = 0; i < path.size(); i++) std::cout << path[i] << " " << std::endl; }

	int move;              // tile that is moved to reach current state
	int cost;              // estimated cost = distance+g
	int g;				   // count of steps to current state
	Puzzle puzzle;         // puzzle
	std::vector<int> path; // Path to current state
};

