#include "Day.h"
using namespace std;

class Day1 : public Day {
public:
	Day1() : Day("inputFiles/day1.txt") {}

	void part1() {
		vector<int> numbers;

		for (string x : lines) {
			numbers.emplace_back(stoi(x));
		}

		for (int i = 0; i < numbers.size(); i++) {
			for (int j = i + 1; j < numbers.size(); j++) {
				if (numbers.at(i) + numbers.at(j) == 2020) {
					cout << numbers.at(i) << " * " << numbers.at(j) << " = " << numbers.at(i) * numbers.at(j) << endl;
				}
			}
		}
	}

	void part2() {

		vector<int> numbers;

		for (string x : lines) {
			numbers.emplace_back(stoi(x));
		}

		for (int i = 0; i < numbers.size(); i++) {
			for (int j = i + 1; j < numbers.size(); j++) {
				for (int k = j + 1; k < numbers.size(); k++) {
					if (numbers.at(i) + numbers.at(j) + numbers.at(k) == 2020) {
						cout << numbers.at(i) << " * " << numbers.at(j) << " * " << numbers.at(k) << " = " << numbers.at(i) * numbers.at(j) * numbers.at(k) << endl;
					}
				}
			}
		}
	}

};

