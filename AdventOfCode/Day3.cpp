#include "Day.h"
using namespace std;

class Day3 : public Day {
public:
	Day3() : Day("inputFiles/day3.txt") {};

	void part1() {

		int xPos = 0;
		int xJump = 3;
		int yJump = 1;
		int numOfTrees = 0;

		for (int yPos = yJump; yPos < lines.size(); yPos += yJump) {

			xPos += xJump;

			if (lines.at(yPos).at(xPos % lines.at(yPos).length()) == '#') {
				numOfTrees++;
			}
		}

		cout << numOfTrees << endl;
	}

	void part2() {

		long long int run1 = tobogganRun(1, 1, lines);
		long long int run2 = tobogganRun(3, 1, lines);
		long long int run3 = tobogganRun(5, 1, lines);
		long long int run4 = tobogganRun(7, 1, lines);
		long long int run5 = tobogganRun(1, 2, lines);

		long long int result = run1 * run2 * run3 * run4 * run5;

		cout << result << endl;
	}

	int tobogganRun(int xJump, int yJump, vector<string> lines) {
		int xPos = 0;
		int numOfTrees = 0;

		for (int yPos = yJump; yPos < lines.size(); yPos += yJump) {

			xPos += xJump;

			if (lines.at(yPos).at(xPos % lines.at(yPos).length()) == '#') {
				numOfTrees++;
			}
		}

		cout << numOfTrees << endl;
		return numOfTrees;
	}

};