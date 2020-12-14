#include "Day.h"
#include <chrono>
using namespace std;

class Day11 : public Day {
public:
	Day11() : Day("inputFiles/day11.txt") {}

	void part1() {
		cellularAutomata(false);
	}

	void part2() {
		cellularAutomata(true);
	}

	void cellularAutomata(bool part2) {
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		int iterations = 0;

		vector<string> currentStep = lines;
		vector<string> nextStep;

		//cout << "Working";

		while (true) {
			iterations++;

			for (int y = 0; y < currentStep.size(); y++) { // for each line in the input
				string currentLine = "";

				for (int x = 0; x < currentStep.at(y).length(); x++) { // for each character in that line
					if (currentStep.at(y).at(x) == 'L') { // If seat is empty
						bool occupied = false;

						for (int i : {-1, 0, 1}) { // For all 8 directions
							for (int j : {-1, 0, 1}) {
								if (part2) {
									for (int length = 1;; length++) { // Keep going along that direction until fall off end
										if ((y + (i * length)) < 0 || (y + (i * length)) >= lines.size() || (x + (j * length)) < 0 || (x + (j * length)) >= lines.at(0).length()) { break; }

										char consider = currentStep.at(y + (i * length)).at(x + (j * length));

										if (consider == '#') {
											occupied = true;
											break;
										}
										else if (consider == 'L') {
											break;
										}
									}
								}
								else {

									if ((y + i) < 0 || (y + i) >= lines.size() || (x + j) < 0 || (x + j) >= lines.at(0).length()) { continue; }

									if (currentStep.at(y + i).at(x + j) == '#') {
										occupied = true;
									}
								}
							}
						}

						if (!occupied) {
							currentLine += '#';
						}
						else {
							currentLine += 'L';
						}
					}

					else if (currentStep.at(y).at(x) == '#') {
						int occupied = 0;

						for (int i : {-1, 0, 1}) {
							for (int j : {-1, 0, 1}) {
								if (part2) {
									for (int length = 1;; length++) {

										if ((y + (i * length)) < 0 || (y + (i * length)) >= lines.size() || (x + (j * length)) < 0 || (x + (j * length)) >= lines.at(0).length()) { break; }

										char consider = currentStep.at(y + (i * length)).at(x + (j * length));

										if (consider == '#') {
											occupied++;
											break;
										}
										else if (consider == 'L') {
											break;
										}
									}
								}
								else {
									if ((y + i) < 0 || (y + i) >= lines.size() || (x + j) < 0 || (x + j) >= lines.at(0).length()) { continue; }

									if (currentStep.at(y + i).at(x + j) == '#') {
										occupied++;
									}
								}
							}
						}

						if ((occupied > 5 && part2) || (occupied > 4 && !part2)) { // 5 or more AROUND ITSELF, however original cell is also #, so 6 or more in reality
							currentLine += 'L';
						}
						else {
							currentLine += '#';
						}
					}
					else {
						currentLine += '.';
					}
				}
				nextStep.emplace_back(currentLine);
			}

			if (currentStep == nextStep) {
				break;
			}
			else {
				currentStep = nextStep;
				nextStep.clear();
			}
		}

		chrono::steady_clock::time_point end = chrono::steady_clock::now();

		cout << "Done! (" << chrono::duration_cast<chrono::milliseconds>(end - begin).count() / 1000 << "." << chrono::duration_cast<chrono::milliseconds>(end - begin).count() % 1000 << "s)" << endl;
		cout << "Iterations: " << iterations << endl;

		int numberOfOccupied = 0;
		for (string y : nextStep) {
			for (char x : y) {
				if (x == '#') {
					numberOfOccupied++;
				}
			}
		}

		cout << "Answer: " << numberOfOccupied << endl;
	}
};