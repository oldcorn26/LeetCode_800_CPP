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
        int sizeSq{size * size};
        UnionFind uf(sizeSq);
        vector<pair<int, int>> hRec(sizeSq);

        for (int i{0}; i < size; ++i) {
            for (int j{0}; j < size; ++j) {
                hRec[grid[i][j]] = {i,j};
            }
        }

        for (int i{0}; i < sizeSq; ++i) {
            int &x{hRec[i].first}, &y{hRec[i].second};
            int &&idx{x * size + y};
            if (x > 0 && grid[x - 1][y] < grid[x][y]) uf.toUnion(idx, idx - size);
            if (y > 0 && grid[x][y - 1] < grid[x][y]) uf.toUnion(idx, idx - 1);
            if (x + 1 < size && grid[x + 1][y] < grid[x][y]) uf.toUnion(idx, idx + size);
            if (y + 1 < size && grid[x][y + 1] < grid[x][y]) uf.toUnion(idx, idx + 1);
            if (uf.find(0) == uf.find(sizeSq - 1)) return i;
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
