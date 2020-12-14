#include "Day.h"
using namespace std;

class Day2 : public Day {
public:
	Day2() : Day("inputFiles/day2.txt") {};

	void part1() {

		int numberOfCorrect = 0;

		for (string v : lines) {
			int firstNum = stoi(v.substr(0, v.find("-")));
			int secondNumStartIndex = (v.find("-") + 1);
			int secondNum = stoi(v.substr(secondNumStartIndex, v.find_first_of(' ') - secondNumStartIndex));
			char letter = v.at(v.find_first_of(' ') + 1);
			string password = v.substr(v.find(':') + 2);

			int count = 0;

			for (int i = 0; i < password.length(); ++i) {
				if (password.at(i) == letter) {
					count++;
				}
			}


			if (count >= firstNum && count <= secondNum) {
				numberOfCorrect++;
			}
		}

		cout << "Numer of Correct: " << numberOfCorrect << endl;
	}

	void part2() {

		int numberOfCorrect = 0;

		for (string v : lines) {
			int firstNum = stoi(v.substr(0, v.find("-")));
			int secondNumStartIndex = (v.find("-") + 1);
			int secondNum = stoi(v.substr(secondNumStartIndex, v.find_first_of(' ') - secondNumStartIndex));
			char letter = v.at(v.find_first_of(' ') + 1);
			string password = v.substr(v.find(':') + 2);

			if ((password.at(firstNum - 1) == letter && password.at(secondNum - 1) != letter) || (password.at(firstNum - 1) != letter && password.at(secondNum - 1) == letter)) {
				numberOfCorrect++;
			}
		}

		cout << "Numer of Correct: " << numberOfCorrect << endl;
	}

};