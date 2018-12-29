#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

using std::map;
using std::vector;
using std::string;

map<string, int> countWords(vector<string> words)
{
	map<string, int> wordCount;
	int count;
	for(string word: words)
	{
		auto it = wordCount.find(word);
		count = 0;
		if (it != wordCount.end())
		{
			count = it->second;
		}
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

int main(int argc, char* argv[])
{
	if(argc < 4) // TODO const
	{
		std::cerr << "Usage: " << argv[0] << " <frequent_words> <unknown_text>";
		std::cerr << " <writer_text> [writer_text...]" << std::endl;
		return 1;
	}

	vector<string> commonWords = readWords(argv[1]); // TODO const
	vector<string> unknownTextWords = readWords(argv[2]);
	map<string, int> unkownTextCount = countWords(unknownTextWords);
/*	for(auto const &word: unknownTextWords)
	{
		std::cout << word << " ";
	}
	std::cout << std::endl;
*/
	for(auto const &pair: unkownTextCount)
	{
		std::cout << pair.first << " " << pair.second << std::endl;
	}

	return 0;
}
