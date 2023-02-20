#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> memo;
public:
    int getMoneyAmount(int n) {
        memo = vector<vector<int>>(n, vector<int>(n));
        return dfs(1, n);
    }

    int dfs(int i, int j) {
        if (i + 2 == j) return i + 1;
        else if (i + 1 == j) return i;
        else if (i == j) return 0;
        if (memo[i - 1][j - 1] != 0) return memo[i - 1][j - 1];
        int ret{INT32_MAX};
        for (int k{i + 1}; k < j; ++k) {
            ret = min(ret, k + max(dfs(i, k - 1), dfs(k + 1, j)));
        }
        return memo[i - 1][j - 1] = ret;
    }
};

int main() {
    Solution solution;
    int result = solution.getMoneyAmount(7);
    cout << result;
    return 0;
}
