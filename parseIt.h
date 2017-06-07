#include <string>
#include <vector>
#include <iostream>
#include <map>


class ParseCsv {
	private:
		std::string filePath;
		std::vector<std::string> headerRow;
	public:
		void setFilePath(std::string path);
		std::vector<std::vector<std::string> > parser();

		std::vector<std::string> singleCol(std::vector<std::vector<std::string> > &fullFile, int colNum);
		std::vector<std::string> singleCol(std::vector<std::vector<std::string> > &fullFile, std::string colName, std::vector<std::string> &header);

		bool containsUnique(std::vector<std::string> &col);
		std::map<std::string, int> counter(std::vector<std::string> &col);
		std::vector<std::pair<std::string, int> > sortCounts(std::map<std::string, int> &countMap);
		static bool comparison(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b);
		static int elementIndex(std::vector<std::string> &myVec, std::string myElem);
		std::vector<std::string> getHeader(std::vector<std::vector<std::string> > &fullFile);
};