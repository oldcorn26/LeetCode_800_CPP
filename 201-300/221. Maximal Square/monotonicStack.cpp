#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    int max = 0;
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> blocks(n + 2);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') ++blocks[j + 1];
                else blocks[j + 1] = 0;
            }
            maximalSquareHelper(blocks);
        }

        return max * max;
    }

    void maximalSquareHelper(vector<int> &blc) {
        int size = blc.size();
        stack<int> unchecked; unchecked.push(0);

        for (int i = 1; i < size; ++i) {

            while (blc[unchecked.top()] > blc[i]) {
                int &top = unchecked.top(); unchecked.pop();
                int &&temp = i - unchecked.top() - 1 > blc[top] ? blc[top] : i - unchecked.top() - 1;
                max = temp > max ? temp : max;
            }
            unchecked.push(i);
        }
    }
};

int main() {
    Solution solution;
    vector<vector<char>> matrix{{'1','0','1','0'},{'1','0','1','1'},{'1','0','1','1'},{'1','1','1','1'}};
    int result = solution.maximalSquare(matrix);
    cout << result;
    return 0;
}
