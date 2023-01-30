#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int m, n;
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {

        m = grid.size(), n = grid[0].size();
        int maxArea{0};

        for (int i{0}; i < m; ++i) {
            for (int j{0}; j < n; ++j) {
                if (grid[i][j]) maxArea = max(maxArea, dfs(grid, i, j));
            }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>> &grid, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || !grid[x][y]) return 0;

        if (grid[x][y]) {
            grid[x][y] = 0;
            return 1 + dfs(grid, x + 1, y) + dfs(grid, x - 1, y) + dfs(grid, x, y + 1) + dfs(grid, x, y - 1);
        }
        return 0;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> nums{{0,0,0,1,0},{0,0,0,1,0},{0,1,0,0,0}};
    int result = solution.maxAreaOfIsland(nums);
    cout << result;
    return 0;
}
