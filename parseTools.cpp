#include "parseTools.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


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

bool ParseTools::vectorContains(std::vector<std::string> &myVec, std::string myElem) {
	if (std::find(myVec.begin(), myVec.end(), myElem) != myVec.end()) {
		return true;
	}
	return false;
}