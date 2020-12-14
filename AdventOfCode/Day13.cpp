#include "Day.h"
#include <chrono>
using namespace std;

class Day13 : public Day {
public:
	Day13() : Day("inputFiles/day13.txt") {}

	void part1() {
		vector<int> buses;

		int start = 0;
		int end = 0;
		string cur;

		while (end != string::npos) {
			end = lines.at(1).find(',', start);
			cur = lines.at(1).substr(start, end - start);
			start = end + 1;

			if (cur != "x") {
				buses.emplace_back(stoi(cur));
			}
		}

		int curTime = stoi(lines.at(0));
		int lowest = buses.at(0);

		for (int i : buses) {
			if ((i - curTime % i) < (lowest - (curTime % lowest))) {
				lowest = i;
			}
		}

		cout << lowest * (lowest - curTime % lowest) << endl;
	}

	void part2() {
		cout << "Starting. This may take a short while..." << endl;
		chrono::steady_clock::time_point timeStart = chrono::steady_clock::now();
		vector<string> buses;

		int start = 0;
		int end = 0;
		string cur;

		while (end != string::npos) {
			end = lines.at(1).find(',', start);
			cur = lines.at(1).substr(start, end - start);
			start = end + 1;
			buses.emplace_back(cur);
		}

		int highest = 0;
		int index = 0;
		vector<int> values;
		vector<int> temp;

		for (int i = 0; i < buses.size(); i++) {
			int count = 0;
			temp.clear();
			if (buses.at(i) != "x") {
				for (int j = 0; j < buses.size(); j++) {
					if (buses.at(j) != "x") {
						if (abs(i - j) == stoi(buses.at(j))) {
							temp.emplace_back(stoi(buses.at(j)));
							count++;
						}
					}
				}
			}
			if (count > highest) {
				highest = count;
				index = i;
				values = temp;
			}
		}

		long long int stepSize = stoi(buses.at(index));
		for (int x : values) {
			stepSize *= x;
		}

		int offset = index;

		for (long long int i = 0;; i += stepSize) {
			bool found = true;
			for (int j = 0; j < buses.size(); j++) {
				if (buses.at(j) != "x") {
					if (((i - offset) + j) % stoi(buses.at(j)) != 0) {
						found = false;
						break;
					}
				}
			}
			if (found) {
				cout << "Answer: " << i - offset << endl;
				break;
			}
		}

		chrono::steady_clock::time_point timeEnd = chrono::steady_clock::now();
		cout << "Time Taken: " << chrono::duration_cast<chrono::milliseconds>(timeEnd - timeStart).count() / 1000 << "." << chrono::duration_cast<chrono::milliseconds>(timeEnd - timeStart).count() % 1000 << " seconds" << endl;
	}
};