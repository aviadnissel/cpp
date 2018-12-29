#include <iostream>
#include <map>
#include <vector>
#include <fstream>

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
        it->second = count + 1;
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
    string word;
    while(inFile >> word)
    {
        words.push_back(word);
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
    for(auto const &pair: unkownTextCount)
    {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}