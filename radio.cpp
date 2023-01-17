#include "radio.h"
#include <iostream>
string radioCar::changeToUpperCase(string inputSting)
{
	transform(inputSting.begin(), inputSting.end(), inputSting.begin(), ::toupper);
	return inputSting;
}
radioCar::radioCar(size_t rows, size_t cols)
	:rows(rows), cols(cols)
{
	grid.resize(rows);
	for (int i = 0; i < rows; i++)
	{
		grid[i].resize(cols);
		
		for (int j = 0; j < cols -2; j++)
		{
			if (i == 0 || i == cols - 1) {
				grid[i][j] = WALL;
			}
			else {
				grid[i][j] = GROUND;
			}
			
		}
		grid[i][0] = WALL;
		grid[i][cols -1] = WALL;
	}
}
radioCar::cell::cell()
{
}

void radioCar::movePath(string inmatningPath)
{
	grid[1][1] = START;
	stack<cell> s;
	cell cc;
	cc = { 1, 1 };
	cordoned pathCordoned = east;
	s.push(cc);
	int pos = 0;
	for (auto &path : inmatningPath) {
		switch (path)
		{
		case 'F': {
			if (pathCordoned == east) {
				cc.row;
				cc.column ++;
			}
			else if (pathCordoned == south) {
				cc.row++;
				cc.column;
			}
			else if (pathCordoned == west){
				cc.row;
				cc.column--;
			}
			else if (pathCordoned == north){
				cc.row--;
				cc.column;
			}

			break;
		}case 'R':{
			pos++;
			if (pos == 0) {
				pathCordoned = east;
				PATH = '>';
				break;
			}
			if (pos == 1) {
				pathCordoned = south ;
				PATH = '!';
				break;
			}
			if (pos == 2) {
				pathCordoned = west;
				PATH = '<';
				break;
			}
			if (pos == 3) {
				pathCordoned = north;
				PATH = '^';
				break;
			}
			if (pos < 0 || pos > 3) {
				pos = 0;
			}
		}
		case 'B': {
			if (pathCordoned == east) {
				cc.row;
				cc.column--;
			}
			else if (pathCordoned == south) {
				cc.row--;
				cc.column;
			}
			else if (pathCordoned == west) {
				cc.row;
				cc.column++;
			}
			else if (pathCordoned == north) {
				cc.row++;
				cc.column;
			}
			break;
		}
		case 'L': {
			pos--;
			if (pos == 0) {
				pathCordoned = east;
				PATH = '>';
				break;
			}
			if (pos == 1) {
				pathCordoned = south;
				PATH = '!';
				break;
			}
			if (pos == 2) {
				pathCordoned = west;
				PATH = '<';
				break;
			}
			if (pos == 3) {
				pathCordoned = north;
				PATH = '^';
				break;
			}
			if (pos < 0 || pos > 3) {
				pos = 0;
			}
		}
		default:
			break;
		}

		if (grid[cc.row][cc.column] != WALL) {
			grid[cc.row][cc.column] = PATH;
			s.push(cc);
			isItSolved = false;
		}
		else {
			isItSolved = true;
			return;
		}
	}
	
}


void radioCar::print()
{
	
	cout << endl;

	for (size_t r = 0; r < grid.size(); r++)
	{
		cout << grid[r] << endl;
	}
}


