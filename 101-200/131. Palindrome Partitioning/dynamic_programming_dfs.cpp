#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<bool>> dp;
    vector<vector<string>> ret;
public:
    vector<vector<string>> partition(string s) {
        int size = s.size();
        dp = vector<vector<bool>>(size, vector<bool>(size));
        vector<string> settled(16);

        for (int i{size - 1}; i >= 0; --i) {
            dp[i][i] = true;
            for (int j{i + 1}; j < size; ++j) {
                dp[i][j] = s[i] == s[j] && (i + 2 > j || dp[i + 1][j - 1]);
            }
        }

        dfs(s, 0, settled, 0);

        return ret;
    }

    void dfs(string &s, int sIdx, vector<string> &stl, int stlIdx) {
        if (sIdx == s.size()) {
            ret.emplace_back(stl.begin(), stl.begin() + stlIdx);
        }
        for (int i{sIdx}; i < s.size(); ++i) {
            if (!dp[sIdx][i]) continue;
            stl[stlIdx] = s.substr(sIdx, i - sIdx + 1);
            dfs(s, i + 1, stl, stlIdx + 1);
        }
    }
};

int main() {
    Solution solution;
    vector<vector<string>> result = solution.partition("aab");
    return 0;
}
