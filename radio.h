#pragma once
#include <vector>
#include<string>
#include<stack>
#include <algorithm>
#include <cctype>

using namespace std;

class radioCar{
public:
	struct cell {
		size_t row = 0, column = 0;
		cell();
		cell(size_t row, size_t column)
			: row(row), column(column)
		{ }
	};
	const char WALL = '*';
	const char START = 'S';
	char PATH = '>';
	const char GROUND = ' ';
	bool isItSolved;
	enum cordoned {
		north,
		west,
		east,
		south
	};

	string changeToUpperCase(string inputSting);

	//objects
	size_t rows = 0, cols = 0;
	//vector
	vector<string> grid;
	vector<string>be;
	//Path constructor
	radioCar(size_t rows, size_t cols);

	//methods
	void movePath(string inmatningPath);
	
	void print();

};