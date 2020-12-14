#include "ReadFiles.h"
using namespace std;

vector<string> FileLibrary::ReadFiles::readFile(string filename)
{
	string line;
	ifstream file(filename);
	vector<string> lines;
	if (file.is_open()) {
		while (getline(file, line)) {
			lines.push_back(line);
		}
	}
	file.close();

	return lines;
}
