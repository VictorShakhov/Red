#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>

// #include "profiler.h"

using namespace std;

class Learner {
 private:
  set<string> dict;

 public:
    int Learn(const vector<string>& words) {
        int newWords = dict.size();
        for (const auto& word : words) {
            dict.insert(word);
        }
        newWords = dict.size() - newWords;
        return newWords;
    }

    vector<string> KnownWords() const {
        vector<string> result;
        for(const auto& word : dict) {
            result.push_back(word);
        }
        return result;
    }
};

// int main() {
//     Learner learner;
//     vector<string> words;
//     for(int i = 1; i < 1000; ++i) {
//         for(int j = 0; j < 1000; ++j) {
//             words.push_back("a");
//         }
//     }
//     {
//         LOG_DURATION("Learn");
//         cout << learner.Learn(words) << endl;
//     }
//     cout << "=== known words ===\n";
//     {
//         LOG_DURATION("KnownWords");
//         words = learner.KnownWords();
//     }
//     for (auto word : words) {
//         cout << word << "\n";
//     }
// }
