#include "Day.h"
#include <algorithm>
using namespace std;

class Day9 : public Day {
public:
	Day9() : Day("inputFiles/day9.txt") {}

	int badIndex = 0;
	long long targetNumber = 0;

	void part1() {

		vector<long long> numbers;

		for (string x : lines) {
			numbers.emplace_back(stoll(x));
		}

		for (int i = 25; i < numbers.size(); i++) {
			bool correct = false;
			for (int j = i - 25; j < i; j++) {
				for (int k = j + 1; k < i; k++) {
					if (numbers.at(j) + numbers.at(k) == numbers.at(i)) {
						correct = true;
					}
				}
			}

			if (!correct) {
				cout << numbers.at(i) << endl;
				badIndex = i;
				targetNumber = numbers.at(i);
				return;
			}
		}

	}

	void part2() {

		vector<long long> numbers;

		for (string x : lines) {
			numbers.emplace_back(stoll(x));
		}


		for (int i = 0; i < numbers.size(); i++) {

			long long sum = numbers.at(i);

			for (int j = i + 1; j < numbers.size(); j++) {

				sum += numbers.at(j);

				if (sum == targetNumber) {

					auto minmax = minmax_element(numbers.begin() + i, numbers.begin() + j + 1);

					cout << *minmax.first << " + " << *minmax.second << " = " << *minmax.first + *minmax.second << endl;

					return;
				}
				else if (sum > targetNumber) {
					break;
				}
			}
		}
	}

};