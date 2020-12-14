#include "Day.h"
#include <map>
#include <iterator>
#include <bitset>
using namespace std;

class Day14 : public Day {
public:
	Day14() : Day("inputFiles/day14.txt") {}

	void part1() {
		applyMask();
	}

	void part2() {
		applyMask(true);
	}

	void applyMask(bool part2 = false) {
		string mask = "";
		string maskToken = "mask = ";
		map<unsigned long long, unsigned long long> memory;

		for (string x : lines) {
			if (x.substr(0, 3) == "mas") {
				mask = x.substr(x.find(maskToken) + maskToken.length());
			}
			else {
				// Get Key and Value Locations
				int keyBegin, keyEnd, valueBegin;
				string keyToken = "mem[";
				string valueToken = " = ";

				keyBegin = x.find(keyToken) + keyToken.length();
				keyEnd = x.find("]");
				valueBegin = x.find(valueToken) + valueToken.length();

				if (!part2) {
					// Key and Value Values
					int key = stoi(x.substr(keyBegin, keyEnd - keyBegin));
					string valueBinary = bitset<36>(stoi(x.substr(valueBegin))).to_string();

					// Apply Mask
					for (int i = 0; i < mask.length(); i++) {
						if (mask.at(i) != 'X') {
							valueBinary[i] = mask.at(i);
						}
					}

					unsigned long long value = bitset<36>(valueBinary).to_ullong();

					// If it isn't in the memory, put it in, otherwise overwrite existing value in map
					if (memory.find(key) != memory.end()) {
						memory.find(key)->second = value;
					}
					else {
						memory.insert(pair<unsigned long long, unsigned long long>(key, value));
					}
				}
				else {
					// Key and Value
					string key = bitset<36>(stoi(x.substr(keyBegin, keyEnd - keyBegin))).to_string();
					int value = stoi(x.substr(valueBegin));

					// Find out number of X (for max number of possible combinations)
					int numberofx = 0;
					for (char c : mask) {
						if (c == 'X') {
							numberofx++;
						}
					}

					// Go through each character in the mask, if it's an X or a 1, replace the Key
					for (int i = 0; i < mask.length(); i++) {
						if (mask.at(i) == 'X' || mask.at(i) == '1') {
							key[i] = mask.at(i);
						}
					}

					vector<string> allCombos;
					combinations(numberofx, allCombos, 0); // Get all possible combinations and add them to the allCombos vector

					for (int i = 0; i < allCombos.size(); i++) {
						// Make a copy of key to avoid editing original
						string newAddress = key;
						int xCount = 0;

						// Replace the X in the address with the corresponding digits from the combinations vector
						for (int j = 0; j < newAddress.length(); j++) {
							if (newAddress.at(j) == 'X') {
								newAddress.at(j) = allCombos.at(i).at(xCount);
								xCount++;
							}
						}

						long long int newAddressDec = bitset<36>(newAddress).to_ullong();

						// If it isn't in the memory, put it in, otherwise overwrite existing value in map
						if (memory.find(newAddressDec) != memory.end()) {
							memory.find(newAddressDec)->second = value;
						}
						else {
							memory.insert(pair<long long int, unsigned long long>(newAddressDec, value));
						}
					}
				}
			}
		}

		// Sum them up and print them out!
		map<unsigned long long, unsigned long long>::iterator it;
		unsigned long long total = 0;

		for (it = memory.begin(); it != memory.end(); it++) {
			total += it->second;
		}

		cout << total << endl;

	}

	void combinations(int n, vector<string> &all, int i, string current = "") {
		if (i == n) {
			all.emplace_back(current);
			return;
		}

		current.append("0");
		combinations(n, all, i + 1, current);

		current.at(i) = '1';
		combinations(n, all, i + 1, current);
	}
};