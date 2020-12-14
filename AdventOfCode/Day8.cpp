#include "Day.h"
using namespace std;

class Day8 : public Day {
public:
	Day8() : Day("inputFiles/day8.txt") {}

	vector<int> executedInstructions;

	void part1() {

		int accumulator = 0;
		int x = checkLoop(accumulator);
		cout << accumulator << endl;

	}

	void part2() {

		int accumulator = 0;
		int x = checkLoop(accumulator);

		vector<int> instructionsToChange = executedInstructions;

		for (int i = instructionsToChange.size() - 1; i >= 0; i--) {
			string instruction = lines.at(instructionsToChange.at(i)).substr(0, 3);

			if (instruction == "jmp") {
				lines.at(instructionsToChange.at(i)) = "nop" + lines.at(instructionsToChange.at(i)).substr(3);
			}
			else if (instruction == "nop") {
				lines.at(instructionsToChange.at(i)) = "jmp" + lines.at(instructionsToChange.at(i)).substr(3);
			}
			else {
				continue;
			}

			accumulator = 0;
			x = checkLoop(accumulator);

			if (x != -1) {
				if (instruction == "jmp") {
					lines.at(instructionsToChange.at(i)) = "jmp" + lines.at(instructionsToChange.at(i)).substr(3);
				}
				else if (instruction == "nop") {
					lines.at(instructionsToChange.at(i)) = "nop" + lines.at(instructionsToChange.at(i)).substr(3);
				}
			}
			else {
				cout << accumulator << endl;
				break;
			}
		}
	}

	int checkLoop(int& accumulator) {

		executedInstructions.clear();

		for (int i = 0; i < lines.size();) {

			for (int x : executedInstructions) { // Loop found
				if (i == x) {
					return i;
				}
			}

			executedInstructions.emplace_back(i);

			string instructionType = lines.at(i).substr(0, 3);
			int instructionValue = stoi(lines.at(i).substr(5));

			if (lines.at(i).at(4) == '-') {
				instructionValue *= -1;
			}
			if (instructionType == "nop") {
				i++;
				continue;
			}
			if (instructionType == "acc") {
				accumulator += instructionValue;
				i++;
				continue;
			}
			if (instructionType == "jmp") {
				i += instructionValue;
				continue;
			}

		}

		return -1; // Successfully got through all instructions
	}
};