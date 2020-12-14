#include "Day.h"
using namespace std;

class Day4 : public Day {
public:
	Day4() : Day("inputFiles/day4.txt") {};

	void part1() {
		int validPassports = validPassportsCheck(false);
		cout << validPassports << endl;
	}

	void part2() {
		int validPassports = validPassportsCheck(true);

		cout << validPassports << endl;
	}

	int validPassportsCheck(bool part2) {

		int validPassports = 0;
		vector<string> passport;
		int expected = 8;

		for (string x : lines) {
			if (x == "") {
				if (passport.size() == expected) {
					if (part2) {
						if (validCheck(passport)) {
							validPassports++;
						}
					}
					else {
						validPassports++;
					}
				}
				else if (passport.size() == (expected - 1)) {
					bool invalid = false;
					for (string x : passport) {
						if (x.find("cid") != string::npos) {
							invalid = true;
							break;
						}
					}

					if (!invalid) {
						if (part2) {
							if (validCheck(passport)) {
								validPassports++;
							}
						}
						else {
							validPassports++;
						}
					}
				}
				passport.clear();
			}
			else {
				string l = x + ' ';
				int start = 0;
				int end = 0;

				while (start != l.length() - 1) {
					end = l.find(' ', start + 1);
					passport.push_back(l.substr(start, end - start));
					start = end;
				}
			}
		}

		return validPassports;
	}

	bool validCheck(vector<string> passport) {
		for (string x : passport) {
			string check = x.substr(x.find(':') - 3, 3);
			string value = x.substr(x.find(':') + 1);

			if (check == "byr") { if (stoi(value) < 1920 || stoi(value) > 2002) { return false; } }
			if (check == "iyr") { if (stoi(value) < 2010 || stoi(value) > 2020) { return false; } }
			if (check == "eyr") { if (stoi(value) < 2020 || stoi(value) > 2030) { return false; } }
			if (check == "hgt") {
				if (value.find("cm") != string::npos) {
					int num = stoi(value.substr(0, (value.length() - 2)));
					if (num < 150 || num > 193) {
						return false;
					}
				}
				else if (value.find("in") != string::npos) {
					int num = stoi(value.substr(0, (value.length() - 2)));
					if (num < 59 || num > 76) {
						return false;
					}
				}
				else {
					return false;
				}
			}
			if (check == "hcl") {
				if (value.length() != 7 && value.at(0) != '#') {
					return false;
				}
				for (char x : value.substr(1)) {
					if (!isxdigit(x)) {
						return false;
					}
				}
			}
			if (check == "ecl") {
				if (!(value == "amb" || value == "blu" || value == "brn" || value == "gry" || value == "grn" || value == "hzl" || value == "oth")) {
					return false;
				}
			}
			if (check == "pid") {
				if (value.length() != 9) {
					return false;
				}

				for (char x : value) {
					if (!isdigit(x)) {
						return false;
					}
				}
			}
		}
		return true;
	}
};