#include <iostream>
#include <numeric>
#include <unordered_map>
#include <math.h>
#include <vector>
#include <fstream>
#include <utility>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

using std::unordered_map;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::pair;

int getCountOrZero(unordered_map<string, int> countMap, string toSearch)
{
	auto it = countMap.find(toSearch);
	if (it != countMap.end())
	{
		return it->second;
	}
	return 0;
}
unordered_map<string, int> countWords(vector<string> words)
{
	unordered_map<string, int> wordCount;
	int count;
	for(string word: words)
	{
		count = getCountOrZero(wordCount, word);
		wordCount[word] = count + 1;
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
	boost::char_separator<char> sep("{.\" ,\n\r!;:'}");

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

unordered_map<string, int> readAndCountWords(const string &filename)
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
        boost::char_separator<char> sep("{.\" ,\n\r!;:'}");

        boost::tokenizer<boost::char_separator<char>>::iterator tok_iter;
	unordered_map<string, int> wordCount;
        while(getline(inFile, line))
        {
                boost::tokenizer<boost::char_separator<char>> tokens(line, sep);
                for(tok_iter = tokens.begin(); tok_iter != tokens.end(); tok_iter++)
                {
                        word = boost::algorithm::to_lower_copy(*tok_iter);
	                wordCount[word] = getCountOrZero(wordCount, word) + 1;
                }
        }
        return wordCount;

}
vector<int> createVector(const unordered_map<string, int> textCount, const vector<string> commonWords) // TODO rename
{
	vector<int> wordVector;
	for(string word: commonWords)
	{
		wordVector.push_back(getCountOrZero(textCount, word));
	}
	return wordVector;
		
}


double calculateAngle(vector<int> wordVector1, vector<int> wordVector2)
{
	double product = inner_product(wordVector1.begin(), wordVector1.end(), wordVector2.begin(), 0);
	cout << product << endl;
	double norm = sqrt(inner_product(wordVector1.begin(), wordVector1.end(), wordVector1.begin(), 0)) * sqrt(inner_product(wordVector2.begin(), wordVector2.end(), wordVector2.begin(), 0));
	cout << norm << endl;
	return product / norm;
}

vector<int> getTextVector(string fileName, vector<string> commonWords)
{
/*        vector<string> textWords = readWords(fileName);
        unordered_map<string, int> textCount = countWords(textWords);*/
	unordered_map<string, int> textCount = readAndCountWords(fileName);
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

	pair<string, double> highestAngle = std::make_pair("start", -1);
	for(int i = 3; i < argc; i++)
	{
		string fileName = argv[i];
		vector<int> textVector = getTextVector(fileName, commonWords);
		double textAngle = calculateAngle(textVector, unknownTextVector);
		cout << fileName << " " << textAngle << endl;
		if (textAngle >= highestAngle.second)
		{
			highestAngle = make_pair(fileName, textAngle);
		}
	}
	cout << "Best matching author is " << highestAngle.first << " score " << highestAngle.second << endl;
	return 0;
}
