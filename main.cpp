#include "parseIt.h"
#include "parseTools.h"
#include <vector>


int main() {
	ParseTools parseTools;

	// instantiate and set file path
	ParseCsv parseCsv;
	parseCsv.setFilePath("data.csv");

	// parse file and select certain column
	std::vector<std::vector<std::string> > parsed = parseCsv.parser();
	std::vector<std::vector<std::string> > &fullFile = parsed;

	std::vector<std::string> headerRow = parseCsv.getHeader(fullFile);
	std::vector<std::string> &header = headerRow;

	//std::vector<std::string> singleCol = parseCsv.singleCol(fullFile, 4);
	//std::vector<std::string> &myCol = singleCol;

	std::vector<std::string> singleColByString = parseCsv.singleCol(fullFile, "Location", headerRow);
	std::vector<std::string> singleCol = singleColByString;



	// map and display count
	std::map<std::string, int> myCounts = parseCsv.counter(singleCol);
	std::map<std::string, int> &counts = myCounts;

	// show count sorted
	std::vector<std::pair<std::string, int> > sortedCol = parseCsv.sortCounts(counts);
	std::vector<std::pair<std::string, int> > &sorted = sortedCol;

	parseTools.printSorted(sorted);
}