#pragma once
#include "ReadFiles.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Day {
public:

	Day(string fileName) {
		lines = FileLibrary::ReadFiles::readFile(fileName);
	};

	void printVector() {
		for (string x : lines) {
			cout << x << endl;
		}
	};

	virtual void part1() = 0;
	virtual void part2() = 0;

	void execute() {
		cout << "=== PART ONE ===" << endl;
		part1();
		cout << "================" << endl;
		cout << "\n=== PART TWO ===" << endl;
		part2();
		cout << "================" << endl;
	}

protected:
	vector<string> lines;
};

