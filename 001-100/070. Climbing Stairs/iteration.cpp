#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int res = 0;
        for (int i = 0; i <= n / 2; ++i) {
            long long temp = 1;
            int selectedNum = min(i, n - i - i);
            for (int j = 1; j <= selectedNum; ++j) temp = temp * (n - i - selectedNum + j) / j;
            res += (int) temp;
        }
        return res;
    }

    int C(int n, int m) {
        long long res = 1;
        for (int i = 1; i <= m; ++i) res = res * (n - m + i) / i;
        return (int) res;
    }
};

int main() {
    Solution solution;
    int n = 3;
    int result = solution.climbStairs(n);
    cout << result;
    return 0;
}