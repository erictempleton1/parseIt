#include "parseIt.h"
#include "parseTools.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stdexcept>


void ParseCsv::setFilePath(std::string path) {
	filePath = path;
}

std::vector<std::string> ParseCsv::getHeader(std::vector<std::vector<std::string> > &fullFile) {
	std::vector<std::string> headerRow;
	for (int i = 0; i < fullFile[0].size(); i++) {
		headerRow.push_back(fullFile[0][i]);
	}
	return headerRow;
}

std::vector<std::vector<std::string> > ParseCsv::parser() {
	std::ifstream file(filePath.c_str());
	std::string line;
	std::vector<std::vector<std::string> > fullList;
	while (std::getline(file, line)) {
		std::istringstream s(line);
		std::string field;
		std::vector<std::string> fullLine;
		while (std::getline(s, field, ',')) {
			fullLine.push_back(field);
		}
		fullList.push_back(fullLine);
	}
	return fullList;
}

int ParseCsv::elementIndex(std::vector<std::string> &myVec, std::string myElem) {
	return std::find(myVec.begin(), myVec.end(), myElem) - myVec.begin();
}

std::vector<std::string> ParseCsv::singleCol(std::vector<std::vector<std::string> > &fullFile, int colNum) {
	std::vector<std::string> col;
	for (int i = 0; i < fullFile.size(); i++) {
		col.push_back(fullFile[i][colNum]);
	}
	return col;
}

std::vector<std::string> ParseCsv::singleCol(std::vector<std::vector<std::string> > &fullFile, std::string colName, std::vector<std::string> &header) {
	int elemIndex = elementIndex(header, colName);
	std::vector<std::string> col;
	if (elemIndex <= header.size()) {
		for (int i = 0; i < fullFile.size(); i++) {
			col.push_back(fullFile[i][elemIndex]);
		}
		return col;
	}
	throw std::length_error("error");
}

bool ParseCsv::containsUnique(std::vector<std::string> &col) {
	std::sort(col.begin(), col.end());
	for (int i = 0; i < col.size(); i++) {
		// ensure we aren't outside of vector
		if (i + 1 <= col.size()) {
			// since we're sorted, check next element for equality
			if (col[i] == col[i + 1]) {
				return false;
			}
		}
	}
	return true;
}

std::map<std::string, int> ParseCsv::counter(std::vector<std::string> &col) {
	std::map<std::string, int> count;
	for (int i = 0; i < col.size(); i++) {
		if (count.find(col[i]) == count.end()) {
			count[col[i]] = 0;
			count[col[i]] += 1;
		} else {
			count[col[i]] += 1;
		}
	}
	return count;
}

bool ParseCsv::comparison(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
	return (a.second > b.second);
}

std::vector<std::pair<std::string, int> > ParseCsv::sortCounts(std::map<std::string, int> &countMap) {
	// sort vector of pairs where second value is an int
	std::vector<std::pair<std::string, int> > pairs;
	std::map<std::string, int>::iterator it;
	for (it = countMap.begin(); it != countMap.end(); it++) {
		pairs.push_back(std::make_pair(it->first, it->second));
	}

	std::sort(pairs.begin(), pairs.end(), comparison);
	return pairs;
}