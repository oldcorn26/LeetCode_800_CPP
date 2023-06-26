#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int left{}, right{};
        int validNum{};
        int minLen{INT32_MAX}, minIdx{};
        unordered_map<char, int> tCount;
        unordered_map<char, int> winCount;
        for (char ch: t)
            tCount[ch]++;
        while (right < s.size()) {
            while (validNum < tCount.size() && right < s.size()) {
                if (tCount.find(s[right]) != tCount.end())
                    if (++winCount[s[right]] == tCount[s[right]])
                        validNum++;
                right++;
            }
            if (validNum != tCount.size())
                break;
            while (left < right && validNum == tCount.size()) {
                if (tCount.find(s[left]) != tCount.end())
                    if (winCount[s[left]]-- == tCount[s[left]])
                        validNum--;
                left++;
            }
            if (validNum < tCount.size() && minLen > right-left+1) {
                minLen = right-left+1;
                minIdx = left-1;
            }
        }
        return minLen != INT32_MAX ? s.substr(minIdx, minLen) : "";
    }
};

int main() {
    Solution solution;
    string s = "a";
    string t = "aa";
    string result = solution.minWindow(s, t);
    cout << result;
    return 0;
}