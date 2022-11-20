#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int res = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') ++res;
                if (grid[i][j]) dfs(grid, move(i), move(j));
            }
        }

        return res;
    }

    void dfs(vector<vector<char>> &grid, int &&x, int &&y) {
        if (x < 0 || x >= m || y < 0 || y >= n || !grid[x][y]) return;

        if (grid[x][y] == '1') {
            grid[x][y] = 0;
            dfs(grid, x + 1, move(y)); dfs(grid, x - 1, move(y));
            dfs(grid, move(x), y + 1); dfs(grid, move(x), y - 1);
        } else grid[x][y] = 0;
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
