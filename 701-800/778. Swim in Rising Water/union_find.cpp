#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    int *parent;
public:
    UnionFind(int maxSize) {
        parent = (int *) malloc(sizeof(int) * maxSize);
        while (--maxSize >= 0) parent[maxSize] = maxSize;
    }

    int find(int x) {
        return x == parent[x] ? x : (parent[x] = find(parent[x]));
    }

    void toUnion(int x1, int x2) {
        parent[find(x1)] = find(x2);
    }

    bool isSame(int x1, int x2) {
        return find(x1) == find(x2);
    }

    void reset(int maxSize) {
        free(parent);
        parent = (int *) malloc(sizeof(int) * maxSize);
        while (--maxSize >= 0) parent[maxSize] = maxSize;
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>> &grid) {

        int size = grid.size();
        UnionFind uf(size * size);
        int ret{max(2 * size - 2, max(grid[0][0], grid[size - 1][size - 1])) - 1};

        while (++ret) {
            for (int i{0}; i < size; ++i) {
                for (int j{0}; j < size; ++j) {
                    if (grid[i][j] < 0 || grid[i][j] > ret) continue;
                    int idx{i * size + j};
                    if (i > 0 && grid[i - 1][j] < grid[i][j]) uf.toUnion(idx, idx - size);
                    if (j > 0 && grid[i][j - 1] < grid[i][j]) uf.toUnion(idx, idx - 1);
                    if (i + 1 < size && grid[i + 1][j] < grid[i][j]) uf.toUnion(idx, idx + size);
                    if (j + 1 < size && grid[i][j + 1] < grid[i][j]) uf.toUnion(idx, idx + 1);
                    if (uf.find(0) == uf.find(size * size - 1)) return ret;
                    grid[i][j] = -1;
                }
            }
        }

        return 0;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid{{0,3},{1,2}};
    int result = solution.swimInWater(grid);
    cout << result;
    return 0;
}
