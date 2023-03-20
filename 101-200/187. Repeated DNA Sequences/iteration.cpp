#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> um;
        vector<string> ret;
        for (int i{9}; i < s.size(); ++i) {
            um[s.substr(i-9, 10)]++;
        }
        for (auto &iter: um) {
            if (iter.second > 1) ret.emplace_back(iter.first);
        }
        return ret;
    }
};


int main() {
    Solution solution;
    return 0;
}
