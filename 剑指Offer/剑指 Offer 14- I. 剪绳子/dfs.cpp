#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo;
public:
    int cuttingRope(int n) {
        memo = vector<int>(n+1);
        memo[1] = 1;
        return dfs(n);
    }

    int dfs(int n) {
        if (memo[n] != 0) return memo[n];
        int maxNum{};
        for (int i{1}; i <= n/2; ++i) {
            int l{dfs(i)}, r{dfs(n-i)};
            maxNum = max(maxNum, max(l*r, max(i*r, max(l*(n-i), i*(n-i)))));
        }
        return memo[n] = maxNum;
    }
};

int main() {
    Solution solution;
    int result = solution.cuttingRope(8);
    cout << result;
    return 0;
}
