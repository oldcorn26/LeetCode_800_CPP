#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

        int ret{2};
        queue<string> beginBuffer, endBuffer;
        unordered_set<int> beginChecked, endChecked;

        for (int i{0}; i <= wordList.size(); ++i) {
            if (i == wordList.size()) return 0;
            if (wordList[i] == endWord) {
                endChecked.emplace(i);
                break;
            }
        }
        beginBuffer.emplace(beginWord), endBuffer.emplace(endWord);

        while (beginBuffer.size() && endBuffer.size()) {
            bool &&temp{beginBuffer.size() > endBuffer.size()};
            queue<string> &smallQue{temp ? endBuffer : beginBuffer};
            unordered_set<int> &oppChecked{temp ? beginChecked : endChecked};
            unordered_set<int> &smallChecked{temp ? endChecked : beginChecked};
            for (int i = smallQue.size(); i > 0; --i) {
                string &topStr = smallQue.front();
                for (int j{0}; j < wordList.size(); ++j) {
                    if (smallChecked.find(j) != smallChecked.end()) continue;
                    if (distanceEqualsOne(topStr, wordList[j])) {
                        if (oppChecked.find(j) != oppChecked.end()) return ret;
                        smallChecked.emplace(j);
                        smallQue.emplace(wordList[j]);
                    }
                }
                smallQue.pop();
            }
            ++ret;
        }

        return 0;
    }

    bool distanceEqualsOne(string &word1, string &word2) {
        int ret{0};
        for (int i{0}; i < word1.size(); ++i) {
            if (word1[i] != word2[i] && ++ret > 1) return false;
        }
        return ret == 1;
    }
};

int main() {
    Solution solution;
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};
    int result = solution.ladderLength("hit", "cog", wordList);
    cout << result;
    return 0;
}
