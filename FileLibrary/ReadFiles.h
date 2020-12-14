#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

namespace FileLibrary {
	using namespace std;
	class ReadFiles {
	public:
		static vector<string> readFile(string filename);
	};
}