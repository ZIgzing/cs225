/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>
#include <iostream>

#include "cartalk_puzzle.h"

using namespace std;
using std::cout;
using std::endl;


/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of (string, string, string) tuples
 * Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<std::tuple<std::string, std::string, std::string>> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    vector<std::tuple<std::string, std::string, std::string>> ret;

    ifstream wordsFile(word_list_fname);
    string word;
    string firstl;
    string wofirstl;
    string wo2;

    if (wordsFile.is_open()) {
    /* Reads a line from `wordsFile` into `word` until the file ends. */

    while (getline(wordsFile, word)) {
      if (word.length() == 5) {
        firstl = word.substr(0, 1);
        wofirstl = word.substr(1, word.length()-1);
        wo2 = word.substr(2, word.length()-2);
        string temp = firstl + wo2;
        if (d.homophones(word, wofirstl) == true && d.homophones(word, temp) == true) {
          ret.push_back(tuple<std::string, std::string, std::string> (word, wofirstl, temp));
        }
      }
    }
}

    /* Your code goes here! */

    return ret;
}
