#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxArea{};
        vector<int> dp(n+2);
        for (int i{}; i < m; ++i) {
            for (int j{}; j < n; ++j)
                dp[j+1] = matrix[i][j] == '0' ? 0 : dp[j+1] + 1;
            maxArea = max(maxArea, monoStack(dp));
        }
        return maxArea;
    }

    int monoStack(vector<int> &nums) {
        int idx{1};
        int maxArea{};
        stack<int> s{{0}};
        while (idx < nums.size()) {
            while (nums[s.top()] > nums[idx]) {
                int h{nums[s.top()]};
                s.pop();
                maxArea = max(maxArea, h * (idx - s.top() - 1));
            }
            s.push(idx);
            idx++;
        }
        return maxArea;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> matrix{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    int result = solution.maximalRectangle(matrix);
    cout << result;
    return 0;
}
