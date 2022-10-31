#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int max = 0;
        int height = matrix.size(), width = matrix[0].size();

        vector<int> dp(width, -1);
        vector<int> heights(width + 2);

        for (int i = 0; i < height + 1; ++i) {
            for (int j = 0; j < width; ++j) {
                heights[j + 1] = i - dp[j] - 1;
                if (i < height && matrix[i][j] == '0') dp[j] = i;
            }
            int &&temp = largestRectangleArea(heights);
            max = temp > max ? temp : max;
        }

        return max;
    }

    int largestRectangleArea(vector<int> &heights) {
        int max = 0, size = heights.size();
        stack<int> monStack;
        monStack.push(0);

        for (int i = 1; i < size; ++i) {

            while (heights[monStack.top()] > heights[i]) {
                int &top = monStack.top();
                monStack.pop();
                int &&temp = heights[top] * (i - monStack.top() - 1);
                max = temp > max ? temp : max;
            }

            monStack.push(i);
        }
        return max;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> matrix{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    int result = solution.maximalRectangle(matrix);
    cout << result;
    return 0;
}