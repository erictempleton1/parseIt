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
	std::vector<std::string> dateCol = parseCsv.singleCol(parsed, 4);

	// map and display count
	std::map<std::string, int> myCounts = parseCsv.counter(dateCol);

	// show count sorted
	std::vector<std::pair<std::string, int> > sortedCol = parseCsv.sortCounts(myCounts);
	parseTools.printSorted(sortedCol);

	// check if header contains a value
	std::vector<std::string> headerRow = parseCsv.getHeader();
	std::cout << parseTools.vectorContains(headerRow, "CrimeDate") << std::endl;
}