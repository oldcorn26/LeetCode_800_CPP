#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    vector<vector<string>> ret;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        int resLen{1}, flag{1}, endIdx{-1};
        queue<pair<string, int>> buffer;
        vector<vector<int>> checked(wordList.size());

        for (int i{0}; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                buffer.emplace(beginWord, -1);
                endIdx = i;
            } else if (wordList[i] == beginWord) checked[i].emplace_back(500);
        }
        if (endIdx < 0) return {};

        while (buffer.size() && flag) {
            vector<pair<int, int>> temp;
            for (int i = buffer.size(); i > 0; --i) {
                string &topStr = buffer.front().first;
                for (int j{0}; j < wordList.size(); ++j) {
                    if (checked[j].size()) continue;
                    if (distanceEqualsOne(topStr, wordList[j])) {
                        if (endWord == wordList[j]) flag = 0;
                        temp.emplace_back(j, buffer.front().second);
                        buffer.emplace(wordList[j], j);
                    }
                }
                buffer.pop();
            }
            changeState(checked, temp);
            ++resLen;
        }

        if (flag) return {};
        vector<string> settled(resLen);
        settled[0] = beginWord, settled[resLen - 1]  = endWord;
        dfs(wordList, settled, resLen - 2, checked, endIdx);

        return ret;
    }

    void dfs(vector<string> &words, vector<string> &stl, int stlIdx, vector<vector<int>> &list, int listIdx) {
        if (stlIdx == 0) {
            ret.push_back(stl);
            return;
        }
        int pre{INT32_MIN};
        for (int &i: list[listIdx]) {
            if (pre == i) continue;
            stl[stlIdx] = words[i];
            dfs(words, stl, stlIdx - 1, list, i);
            pre = i;
        }
    }

    void changeState(vector<vector<int>> &checked, vector<pair<int, int>> &temp) {
        for (pair<int, int> &iter: temp) {
            checked[iter.first].emplace_back(iter.second);
        }
    }

    bool distanceEqualsOne(const string &word1, string &word2) {
        int ret{0};
        for (int i{0}; i < word1.size(); ++i) {
            if (word1[i] != word2[i] && ++ret > 1) return false;
        }
        return ret == 1;
    }
};

int main() {
    Solution solution;
    vector<string> wordList{"hot","dog"};
    vector<vector<string>> result = solution.findLadders("hot", "dog", wordList);
    return 0;
}
