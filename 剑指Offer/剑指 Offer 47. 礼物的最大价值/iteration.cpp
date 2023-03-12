#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int dp1[n], dp2[n];
        int *crt{dp1}, *pre{dp2}, *temp;
        pre[0] = grid[0][0];
        for (int i{1}; i < n; ++i) {
            pre[i] = pre[i-1] + grid[0][i];
        }
        for (int i{1}; i < m; ++i) {
            crt[0] = pre[0] + grid[i][0];
            for (int j{1}; j < n; ++j) {
                crt[j] = grid[i][j] + max(crt[j-1], pre[j]);
            }
            temp = crt;
            crt = pre;
            pre = temp;
        }
        return pre[n-1];
    }
};

int main() {
    Solution solution;
    return 0;
}
