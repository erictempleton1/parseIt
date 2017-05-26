#include "parseTools.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>


void ParseTools::printCol(std::vector<std::string> &col) {
	for (int i = 0; i < col.size(); i++) {
		std::cout << col[i] << std::endl;
	}
}

void ParseTools::displayCounts(std::map<std::string, int> &countMap) {
	std::map < std::string, int>::iterator it;
	for (it = countMap.begin(); it != countMap.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}
}

void ParseTools::printSorted(std::vector<std::pair<std::string, int> > &sortedVecPair) {
	for (int i = 0; i < sortedVecPair.size(); i++) {
		std::cout << sortedVecPair[i].first << " " << sortedVecPair[i].second << std::endl;
	}
}