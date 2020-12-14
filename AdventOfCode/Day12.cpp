#include "Day.h"
using namespace std;

class Day12 : public Day {
public:
	Day12() : Day("inputFiles/day12.txt") {}

	void part1() {
		navigate();
	}

	void part2() {
		navigate(true);
	}

	void navigate(bool part2 = false) {
		int direction = 90; // East
		int xPos = 0; // Ship Positions
		int yPos = 0;
		int xWay = 10; // Waypoint Positions
		int yWay = 1;

		for (string x : lines) {
			char action = x.at(0);
			int amount = stoi(x.substr(1));

			switch (action) {
			case('N'):
				part2 ? yWay += amount : yPos += amount;
				break;
			case('S'):
				part2 ? yWay -= amount : yPos -= amount;
				break;
			case('E'):
				part2 ? xWay += amount : xPos += amount;
				break;
			case('W'):
				part2 ? xWay -= amount : xPos -= amount;
				break;
			case('L'):
				if (part2) {
					for (int i = 0; i < (amount / 90); i++) {
						int temp = xWay;
						xWay = -yWay;
						yWay = temp;
					}
				}
				else {
					direction = (direction + (360 - amount)) % 360;
				}
				break;
			case('R'):
				if (part2) {
					for (int i = 0; i < (amount / 90); i++) {
						int temp = yWay;
						yWay = -xWay;
						xWay = temp;
					}
				}
				else {
					direction = (direction + amount) % 360;
				}
				break;
			case('F'):
				if (part2) {
					xPos += abs(amount * xWay) * (xWay < 0 ? -1 : 1);
					yPos += abs(amount * yWay) * (yWay < 0 ? -1 : 1);
				}
				else {
					int dir = direction / 90; // 0 = N , 1 = E , 2 = S , 3 = W
					dir % 2 == 0 ? (dir == 0 ? yPos += amount : yPos -= amount) : (dir == 1 ? xPos += amount : xPos -= amount);
				}
				break;
			}
		}
		cout << "Answer: " << abs(xPos) + abs(yPos) << endl;
	}
};