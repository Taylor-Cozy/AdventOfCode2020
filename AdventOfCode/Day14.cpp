#include "Day.h"
#include <map>
#include <iterator>
#include <bitset>
using namespace std;

class Day14 : public Day {
public:
	Day14() : Day("inputFiles/day14.txt") {}

	void part1() {

		string mask = "";
		string maskToken = "mask = ";
		map<int, unsigned long long> memory;

		for (string x : lines) {
			if (x.substr(0, 3) == "mas") {
				mask = x.substr(x.find(maskToken) + maskToken.length());
			}
			else {
				int keyBegin, keyEnd, valueBegin;
				string keyToken = "mem[";
				string valueToken = " = ";

				keyBegin = x.find(keyToken) + keyToken.length();
				keyEnd = x.find("]");
				valueBegin = x.find(valueToken) + valueToken.length();

				int key = stoi(x.substr(keyBegin, keyEnd - keyBegin));
				string valueBinary = bitset<36>(stoi(x.substr(valueBegin))).to_string();

				// apply mask

				for (int i = 0; i < mask.length(); i++) {
					if (mask.at(i) != 'X') {
						valueBinary[i] = mask.at(i);
					}
				}

				unsigned long long value = bitset<36>(valueBinary).to_ullong();
				cout << value << endl;

				if (memory.find(key) != memory.end()) {
					memory.find(key)->second = value;
				}
				else {
					memory.insert(pair<int, unsigned long long>(key, value));
				}

			}
		}

		map<int, unsigned long long>::iterator it;

		unsigned long long total = 0;

		for (it = memory.begin(); it != memory.end(); it++) {
			total += it->second;
		}

		cout << total << endl;
		
	}

	void part2() {
	}
};