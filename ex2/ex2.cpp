/**
 * @file ex2.cpp
 * @author Aviad Nissel <aviad.nissel@mail.huji.ac.il>
 *
 * A script to find the most likely author of an unknown text.
 */


/* --- Includes --- */

#include <iostream>
#include <numeric>
#include <map>
#include <math.h>
#include <vector>
#include <fstream>
#include <utility>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>


/* --- Using --- */

using std::map;
using std::vector;
using std::string;


/* --- Constants --- */

#define COMMON_WORDS_ARGUMENT 1
#define UNKNOWN_TEXT_ARGUMENT 2
#define KNOWN_TEXTS_START_ARGUMENT 3

#define READ_WORD_SEPARATOR "\";:! ,\r\n"


/* --- Functions --- */

/**
 * Counts how many times each word appears in the given vector.
 *
 * @param words The words vector to count.
 * @return A map between words and the number of their appearences.
 */
map<string, int> countWords(vector<string> words)
{
	map<string, int> wordCount;
	for(string word: words)
	{
		wordCount[word] += 1;
	}
	return wordCount;
}

/**
 * Reads the word from the given file.
 *
 * @param filepath The path of the file to read.
 * @return A vector of the words from the file.
 */
vector<string> readWords(const string &filepath)
{
	std::ifstream inFile;
	vector<string> words;
	inFile.open(filepath);
	if(!inFile)
	{
		return words;
	}
	string line;
	string word;
	boost::char_separator<char> sep(READ_WORD_SEPARATOR);

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

/**
 * Creates a vector of word count.
 * The order is the same order as the given common words vector.
 * Each cell is how many times thsi common word appeared in the given text.
 *
 * @param textCount A map of words and the number of their appearences.
 * @param commonWords A vector of the common words.
 * @return A vector of the word count with the order described above.
 */
vector<int> createCommonWordsCountVector(const map<string, int> textCount, const vector<string> commonWords)
{
	vector<int> wordVector;
	for(string word: commonWords)
	{
		auto it = textCount.find(word);
		int count = 0;
		if (it != textCount.end())
		{
			count = it->second;
		}
		wordVector.push_back(count);
	}
	return wordVector;
		
}

/**
 * A util function that calculates the angle between the two given vectors.
 *
 * @param wordVector1 The first vector.
 * @param wordVector2 The second vector.
 * @return The angle between them. If one of them is a zero vector, returns 0.
 */
double calculateAngle(vector<int> wordVector1, vector<int> wordVector2)
{
	double product = inner_product(wordVector1.begin(), wordVector1.end(), wordVector2.begin(), 0);
	double norm1 = sqrt(inner_product(wordVector1.begin(), wordVector1.end(), wordVector1.begin(), 0)) ;
	double norm2 = sqrt(inner_product(wordVector2.begin(), wordVector2.end(), wordVector2.begin(), 0));
	double norm = norm1 * norm2;
	if (norm == 0)
	{
		return 0;
	}
	return product / norm;
}


/**
 * Reads from the given filepath, and returns a vector of word count.
 *
 * @param filepath The file to read.
 * @param commonWords A vector of the common words.
 * @return A vector of filepath's word count.
 * 	   See createCommonWordsCountVector for more info.
 */
vector<int> getTextVector(string filepath, vector<string> commonWords)
{
	vector<string> textWords = readWords(filepath);
	map<string, int> textCount = countWords(textWords);
	return createCommonWordsCountVector(textCount, commonWords);
}


/* --- Main --- */

/**
 *
 * Main function.
 *
 * @param argc The number of arguments passed
 * @param argv An array of the arguments passed.
 * @return 0 on success, else on failure.
 */
int main(int argc, char* argv[])
{
	if(argc < KNOWN_TEXTS_START_ARGUMENT + 1)
	{
		std::cerr << "Usage: " << argv[0] << " <frequent_words> <unknown_text>";
		std::cerr << " <writer_text> [writer_text...]" << std::endl;
		return 1;
	}

	vector<string> commonWords = readWords(argv[COMMON_WORDS_ARGUMENT]);
	vector<int> unknownTextVector = getTextVector(argv[UNKNOWN_TEXT_ARGUMENT], commonWords);

	std::pair<string, double> highestAngle = std::make_pair("start", -1);
	for(int i = KNOWN_TEXTS_START_ARGUMENT; i < argc; i++)
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
