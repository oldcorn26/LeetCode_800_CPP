#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res = 1;
        int &&totalNum = m + n - 2;
        int &&selectedNum = std::min(m, n) - 1;

        for (int i = 1; i <= selectedNum; ++i) {
            res = res * (totalNum - selectedNum + i) / i;
        }

        return (int) res;
    }
};

int main() {
    Solution solution;
    int m = 3, n = 7;
    cout << solution.uniquePaths(m, n);
    return 0;
}
