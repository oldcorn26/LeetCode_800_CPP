#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        int ret{};
        m = grid.size(), n = grid[0].size();
        for (int i{}; i < m; ++i) {
            for (int j{}; j < n; ++j) {
                if (grid[i][j] == '0')
                    continue;
                dfs(grid, i, j);
                ret++;
            }
        }
        return ret;
    }

    void dfs(vector<vector<char>> &grid, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        dfs(grid, x-1, y);
        dfs(grid, x, y-1);
        dfs(grid, x+1, y);
        dfs(grid, x, y+1);
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid{{'1', '0', '1', '1', '1'},
                              {'1', '0', '1', '0', '1'},
                              {'1', '1', '1', '0', '1'}};
    int result = solution.numIslands(grid);
    cout << result;
    return 0;
}
