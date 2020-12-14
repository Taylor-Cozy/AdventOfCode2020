#include "Day.h"
#include <algorithm>
#include <set>
using namespace std;

class Day10 : public Day {
public:
	Day10() : Day("inputFiles/day10.txt") {}

	vector<int> numbers;

	void part1() {

		numbers.emplace_back(0);

		for (string x : lines) {
			numbers.emplace_back(stoi(x));
		}

		sort(numbers.begin(), numbers.end());

		numbers.emplace_back((numbers.at(numbers.size() - 1) + 3));

		int threeJolt = 0;
		int oneJolt = 0;

		for (int i = 1; i < numbers.size(); i++) {
			int difference = 0;

			if ((numbers.at(i) - numbers.at(i - 1)) == 3) {
				threeJolt++;
			}
			else if ((numbers.at(i) - numbers.at(i - 1)) == 1) {
				oneJolt++;
			}
		}

		cout << (threeJolt) * (oneJolt) << endl;
	}



	void part2() {

		vector<int> gaps; // Index positions of gaps
		gaps.emplace_back(0); // Add 0 to the front
		for (int i = 1; i < numbers.size(); i++) {
			if (numbers.at(i) - numbers.at(i - 1) == 3) { // If number gap is 3, BOTH must stay
				gaps.emplace_back(i - 1);
				gaps.emplace_back(i);
			}
		}
		gaps.emplace_back(numbers.size() - 1); // Add device (+3) to back
		gaps.erase(unique(gaps.begin(), gaps.end()), gaps.end()); // Remove duplicates

		long long int total = 1;

		for (int i = 1; i < gaps.size(); i++) {
			int gapSize = gaps.at(i) - gaps.at(i - 1) - 1; // Find gap Size
			total *= pow(2, gapSize) - ((gapSize) / 3); // Formula for working out permutations is { 2^n - (n/3) } where (n/3) is a floored whole number
		}

		cout << total << endl;
	}

};