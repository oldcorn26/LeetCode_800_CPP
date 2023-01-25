#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int result{0};
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {

        int m = matrix.size(), n = matrix[0].size();
        vector<int> state(m * n);

        for (int i{0}; i < m; ++i) {
            for (int j{0}; j < n; ++j) {
                dfs(matrix, i, j, state);
            }
        }

        return result;
    }

    int dfs(vector<vector<int>> &mat, int x, int y, vector<int> &state) {

        int ret{0};
        int staIdx = x * mat[0].size() + y;

        if (state[staIdx] != 0) return state[staIdx];
        if (x >= 1 && mat[x - 1][y] < mat[x][y]) {
            ret = max(ret, dfs(mat, x - 1, y, state));
        }
        if (x + 1 < mat.size() && mat[x + 1][y] < mat[x][y]) {
            ret = max(ret, dfs(mat, x + 1, y, state));
        }
        if (y >= 1 && mat[x][y - 1] < mat[x][y]) {
            ret = max(ret, dfs(mat, x, y - 1, state));
        }
        if (y + 1 < mat[0].size() && mat[x][y + 1] < mat[x][y]) {
            ret = max(ret, dfs(mat, x, y + 1, state));
        }
        state[staIdx] = ++ret;
        result = max(result, ret);

        return ret;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix{{9,9,4},{6,6,8},{2,1,1}};
    int result = solution.longestIncreasingPath(matrix);
    cout << result;
    return 0;
}
