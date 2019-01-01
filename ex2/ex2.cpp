
#include <iostream>
#include <numeric>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
#include <utility>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

using std::map;
using std::vector;
using std::string;

map<string, int> countWords(vector<string> words)
{
	map<string, int> wordCount;
	for(string word: words)
	{
		wordCount[word] += 1;
	}
	return wordCount;
}

vector<string> readWords(const string &filename)
{
	std::ifstream inFile;
	vector<string> words;
	inFile.open(filename);
	if(!inFile)
	{
		throw(std::runtime_error("Problem opening file")); // TODO More specific one?
	}
	string line;
	string word;
	boost::char_separator<char> sep("\";:! ,\r\n");

	boost::tokenizer<boost::char_separator<char>>::iterator tok_iter;
	while(getline(inFile, line))
	{
		boost::tokenizer<boost::char_separator<char>> tokens(line, sep);
		for(tok_iter = tokens.begin(); tok_iter != tokens.end(); tok_iter++)
		{
			word = boost::algorithm::to_lower_copy(*tok_iter);
			words.push_back(word);
		}
	}
	return words;
}

vector<int> createVector(const map<string, int> textCount, const vector<string> commonWords) // TODO rename
{
	vector<int> wordVector;
	for(string word: commonWords)
	{
		auto it = textCount.find(word);
		int count = 0;
		if (it != textCount.end()) {
			count = it->second;
		}
		wordVector.push_back(count);
	}
	return wordVector;
		
}

double calculateAngle(vector<int> wordVector1, vector<int> wordVector2)
{
	double product = inner_product(wordVector1.begin(), wordVector1.end(), wordVector2.begin(), 0);
	double norm = sqrt(inner_product(wordVector1.begin(), wordVector1.end(), wordVector1.begin(), 0)) * sqrt(inner_product(wordVector2.begin(), wordVector2.end(), wordVector2.begin(), 0));
	return product / norm;
}

vector<int> getTextVector(string fileName, vector<string> commonWords)
{
        vector<string> textWords = readWords(fileName);
        map<string, int> textCount = countWords(textWords);
        return createVector(textCount, commonWords);
}

int main(int argc, char* argv[])
{
	if(argc < 4) // TODO const
	{
		std::cerr << "Usage: " << argv[0] << " <frequent_words> <unknown_text>";
		std::cerr << " <writer_text> [writer_text...]" << std::endl;
		return 1;
	}

	vector<string> commonWords = readWords(argv[1]); // TODO const
	vector<int> unknownTextVector = getTextVector(argv[2], commonWords);

	std::pair<string, double> highestAngle = std::make_pair("start", -1);
	for(int i = 3; i < argc; i++)
	{
		string fileName = argv[i];
		vector<int> textVector = getTextVector(fileName, commonWords);
		double textAngle = calculateAngle(textVector, unknownTextVector);
		std::cout << fileName << " " << textAngle << std::endl;
		if (textAngle >= highestAngle.second)
		{
			highestAngle = std::make_pair(fileName, textAngle);
		}
	}
	std::cout << "Best matching author is " << highestAngle.first << " score " << highestAngle.second << std::endl;
	return 0;
}
