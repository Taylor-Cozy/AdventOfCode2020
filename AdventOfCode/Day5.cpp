#include <algorithm>
#include "Day.h"
using namespace std;

class Day5 : public Day {
public:
	Day5() : Day("inputFiles/day5.txt") {}

	void part1() {

		vector<int> seats = getSeats();

		cout << seats.at(seats.size() - 1) << endl;

	}

	void part2() {

		vector<int> seats = getSeats();

		for (int i = 0; i < seats.size() - 1; i++) {
			if (seats.at(i + 1) - seats.at(i) > 1) {
				cout << (seats.at(i) + seats.at(i + 1)) / 2 << endl;
			}
		}
	}

	vector<int> getSeats() {

		vector<int> seats;

		for (string x : lines) {

			int rowHigher = 127;
			int rowLower = 0;

			int columnHigher = 7;
			int columnLower = 0;

			string rowChar = x.substr(0, 7);
			string columnChar = x.substr(7);

			for (char c : rowChar) {
				int range = rowHigher - rowLower;

				if (c == 'F') {
					rowHigher -= (range + 1) / 2;
				}
				else {
					rowLower += (range + 1) / 2;
				}
			}

			for (char c : columnChar) {
				int range = columnHigher - columnLower;

				if (c == 'L') {
					columnHigher -= (range + 1) / 2;
				}
				else {
					columnLower += (range + 1) / 2;
				}
			}

			int seatID = (rowLower * 8) + columnLower;
			seats.emplace_back(seatID);

		}

		sort(seats.begin(), seats.end());

		return seats;
	}
};