#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxEdge = 0;
        int m = matrix.size(), n = matrix[0].size();
        int dp[m][n];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    if (!i || !j) dp[i][j] = 1;
                    else {
                        int &temp = dp[i - 1][j] > dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j];
                        dp[i][j] = (temp > dp[i - 1][j - 1] ? dp[i - 1][j - 1] : temp) + 1;
                    }
                    maxEdge = dp[i][j] > maxEdge ? dp[i][j] : maxEdge;
                } else dp[i][j] = 0;
            }
        }

        return maxEdge * maxEdge;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> matrix{{'1','0','1','0'},{'1','0','1','1'},{'1','0','1','1'},{'1','1','1','1'}};
    int result = solution.maximalSquare(matrix);
    cout << result;
    return 0;
}
