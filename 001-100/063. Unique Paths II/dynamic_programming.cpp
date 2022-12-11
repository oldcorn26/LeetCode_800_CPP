#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int mSize = obstacleGrid.size(), nSize = obstacleGrid[0].size();
        if (obstacleGrid[mSize - 1][nSize - 1]) return 0;
        unsigned dp1[nSize], dp2[nSize];
        unsigned *pre{dp1}, *crt{dp2}, *temp;

        pre[nSize - 1] = 1;
        for (int &&j = nSize - 2; j >= 0; --j) {
            if (obstacleGrid[mSize - 1][j]) pre[j] = 0;
            else pre[j] = pre[j + 1];
        }

        for (int &&i = mSize - 2; i >= 0; --i) {
            crt[nSize - 1] = obstacleGrid[i][nSize - 1] ? 0 : pre[nSize - 1];
            for (int &&j = nSize - 2; j >= 0; --j) {
                if (obstacleGrid[i][j]) crt[j] = 0;
                else crt[j] = pre[j] + crt[j + 1];
            }
            temp = pre;
            pre = crt;
            crt = temp;
        }
        return pre[0];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> obstacleGrid{{0,0,0},{0,1,0},{0,0,0}};
    int result = solution.uniquePathsWithObstacles(obstacleGrid);
    cout << result;
    return 0;
}