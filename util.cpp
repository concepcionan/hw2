#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    std::set<std::string> keywords;
    string word = " "; 

    int itr = 0;
    while (!rawWords.empty() && itr <= (int)rawWords.size() - 1){
      trim(rawWords);
      char c = rawWords[itr];
      if ((!isalpha(c) || isspace(c)) && itr < (int)rawWords.size()){
          word = rawWords.substr(0, rawWords.find(c));
          rawWords.erase(0, rawWords.find(c) + 1);
          if (word.size() > 1){
               keywords.insert(word);
          }
          itr = 0;
       }
       else {
         itr++;
       }
    }
    if (!rawWords.empty()){
         keywords.insert(rawWords);
       }

  return keywords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
      std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}


// //temp test function
// int main (int argc, char* argv[]) {
//     string sent1 = "AAA BBB CCC DDD";
//     set<string> words1; 

//     string sent2 = "CCC DDD EEE FFF";
//     set<string> words2; 

//     words1 = parseStringToWords(sent1);
//     words2 = parseStringToWords(sent2);

//     cout << "Words 1 are... " << "\n--------" << endl;
//     for (auto itr = words1.begin(); itr != words1.end(); itr++){
//         cout << *itr << endl;
//     }
//     cout << "Words 2 are... " << "\n--------" << endl;
//     for (auto itr = words2.begin(); itr != words2.end(); itr++){
//         cout << *itr << endl;
//     }

//     set<string> unifiedSets;
//     unifiedSets = setUnion(words1, words2);

//     cout << "The Unified Set is... " << "\n--------" << endl;
//     for (auto itr = unifiedSets.begin(); itr != unifiedSets.end(); itr++){
//         cout << *itr << endl;
//     }

//     set<string> intersectedSets;
//     intersectedSets = setIntersection(words1, words2);

//     cout << "The Intersected Set is... " << "\n--------" << endl;
//     for (auto itr = intersectedSets.begin(); itr != intersectedSets.end(); itr++){
//         cout << *itr << endl;
//     }
// }