#include "Day.h"
using namespace std;

class Day7 : public Day {
public:
	Day7() : Day("inputFiles/day7.txt") {}

	// For part 1
	vector<string> triedBags;

	void part1() {

		triedBags.clear();

		int count = getRules("shiny gold");

		cout << count << endl;

	}

	void part2() {
		int count = getBags("shiny gold");

		cout << count << endl;
	}

	int getRules(string bag) {

		int count = 0;

		// Find rules containing bag
		for (string x : lines) {
			int position = x.find(bag);
			if ((position != string::npos) && (position != 0)) {

				string potBag = x.substr(0, x.find(" bags contain")); // get container bag

				bool bagFound = false; // check if container bag has already been tried
				for (string y : triedBags) {
					if (y == potBag) {
						bagFound = true;
					}
				}

				if (bagFound) {
					// bag has been tried before
					continue;
				}

				count++; // if bag hasn't been found
				triedBags.emplace_back(potBag); // place bag on tried bags list
				count += getRules(potBag);
			}
		}

		return count;
	}

	int getBags(string bag) {
		int count = 0;

		string phrase = " bags contain";

		for (string x : lines) {

			if (x.substr(0, x.find(phrase)) == bag) { // finds rule pertaining to bag

				if (x.find("contain no other bags") != string::npos) { // if contains no other bags, return 1
					return 0;
				}

				vector<string> children; // else find all children bags

				string l = x + ',';
				int start = x.find(phrase) + phrase.length();
				int end = 0;

				while (start != l.length() - 1) {
					end = l.find(',', start + 1);
					children.emplace_back(l.substr(start, end - start));
					start = end;
				}

				// go through children
				for (string x : children) {
					// if find a number
					for (char c : x) {
						if (isdigit(c) != 0) {
							int digitPos = x.find(c);
							string childBag = x.substr(digitPos + 2, x.find(" bag") - (digitPos + 2));
							int numberOfBags = stoi(x.substr(digitPos, x.find(" ", digitPos)));

							count += numberOfBags + (numberOfBags * getBags(childBag));
						}
					}
				}


			}
		}
		return count;
	}
};