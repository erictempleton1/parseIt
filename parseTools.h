#include <string>
#include <vector>
#include <iostream>
#include <map>


class ParseTools {
	public:
		void printCol(std::vector<std::string> &col);
		void displayCounts(std::map<std::string, int> &countMap);
		void printSorted(std::vector<std::pair<std::string, int> > &sortedVecPair);
};