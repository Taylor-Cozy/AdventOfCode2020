#include "Day.h"
#include <algorithm>
using namespace std;

class Day6 : public Day {
public:

	Day6() : Day("inputFiles/day6.txt") {}

	void part1() {
		string unique = "";
		int count = 0;

		for (string x : lines) {
			if (x == "") {
				count += unique.length();
				unique = "";
			}
			else {
				for (char c : x) {

					if (unique.find(c) == string::npos) {
						unique += c;
					}
				}
			}
		}

		cout << count << endl;
	}

	void part2() {

		string unique = "";
		int count = 0;
		int groupSize = 0;

		for (string x : lines) {
			if (x == "") {
				sort(unique.begin(), unique.end());

				char currentChar = '-';

				for (char c : unique) {
					if (c == currentChar) {
						continue;
					}
					else {
						currentChar = c;
						if (unique.find_last_of(c) - unique.find_first_of(c) == (groupSize - 1)) {
							count++;
						}
					}
				}

				unique = "";
				groupSize = 0;
			}
			else {
				unique += x;
				groupSize += 1;
			}
		}

		cout << count << endl;
	}
};