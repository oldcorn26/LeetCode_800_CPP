#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        int ret{};
        vector<vector<int>> dp(n, vector<int>(5));
        dp[0] = {1,1,1,1,1};
        for (int i{1}; i < n; ++i) {
            int sum{};
            for (int j{}; j < 5; ++j) {
                sum += dp[i-1][j];
                dp[i][j] = sum;
            }
        }
        return dp[n-1][0]+dp[n-1][1]+dp[n-1][2]+dp[n-1][3]+dp[n-1][4];
    }
};

int main() {
    vector<string> words{"cd", "f", "kl"};
    vector<char> q{'a','b','c','d','e','f','g','h','i','j','k','l'};
    StreamChecker sc(words);
    for (char &ch: q) {
        cout << ch << " " << sc.query(ch) << endl;
    }
    return 0;
}
