#include "Day.h"
#include <iterator>
#include <algorithm>
#include <chrono>
#include <map>
#include <unordered_map>
using namespace std;

class Day15 : public Day {
public:
	Day15() : Day("inputFiles/day15.txt") {}

	

	void part1() {
		int result = version1({ 1,20,11,6,12,0 }, 2020);
		cout << result << endl;
	}

	void part2() {
		//int result = version2({ 1,20,11,6,12,0 }, 2020);
		int result = version2({ 1,20,11,6,12,0 }, 30000000);
		cout << result << endl;
	}

	int version1(vector<int> numbers, int stop) {
		chrono::steady_clock::time_point timeStart = chrono::steady_clock::now();

		for (int i = numbers.size() - 1; i < stop-1; i++) {
			int numConsider = numbers.at(i);
			int foundIndex = find(numbers.rbegin() + 1, numbers.rend(), numConsider) - numbers.rbegin(); // find last occurence

			if (foundIndex != (i + 1)) { // in already (i+1) as rend is one past the beginning of the vector
				numbers.emplace_back(foundIndex);
			}
			else { // not in
				numbers.emplace_back(0);
			}
		}
		chrono::steady_clock::time_point timeEnd = chrono::steady_clock::now();
		cout << "Time Taken: " << chrono::duration_cast<chrono::milliseconds>(timeEnd - timeStart).count() / 1000 << "." << chrono::duration_cast<chrono::milliseconds>(timeEnd - timeStart).count() % 1000 << " seconds" << endl;

		return numbers.at(numbers.size() - 1);
	}

	int version2(vector<int> numbers, int stop) {
		
		unordered_map<int, int> numberMap{}; // Using a map to store last item (basically replacing find with a map)
		numberMap.reserve(stop);
		for (int i = 0; i < numbers.size() - 1; i++) {
			numberMap[numbers[i]] = i;
		}

		chrono::steady_clock::time_point timeStart = chrono::steady_clock::now();

		int numConsider = numbers.at(numbers.size() - 1);
		int temp = 0;

		for (int i = numbers.size() - 1; i < stop-1; i++) {

			auto foundIndex = numberMap.find(numConsider); // find last occurence
			temp = foundIndex != numberMap.end() ? i - foundIndex->second : 0; // Get Distance
			numberMap[numConsider] = i;
			numConsider = temp; // Set Next Number
		}

		chrono::steady_clock::time_point timeEnd = chrono::steady_clock::now();
		cout << "Time Taken: " << chrono::duration_cast<chrono::milliseconds>(timeEnd - timeStart).count() / 1000 << "." << chrono::duration_cast<chrono::milliseconds>(timeEnd - timeStart).count() % 1000 << " seconds" << endl;;
		
		//return numbers.at(numbers.size() - 1);
		return numConsider;
	}

};