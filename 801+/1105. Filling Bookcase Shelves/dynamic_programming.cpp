#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        for (int i{}; i < n; ++i) {
            int maxH = 0, curW = 0;
            for (int j{i}; j >= 0; --j) {
                curW += books[j][0];
                if (curW > shelfWidth)
                    break;
                maxH = max(maxH, books[j][1]);
                dp[i + 1] = min(dp[i + 1], dp[j] + maxH);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    return 0;
}
