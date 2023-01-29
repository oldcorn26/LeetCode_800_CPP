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
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {

        bool twoParent{false};
        int size = edges.size();
        vector<int> possible;
        UnionFind uf(size);

        for (int i{0}; i < size; ++i) {
            int p1{uf.find(edges[i][0] - 1)}, p2{uf.find(edges[i][1] - 1)};
            if (p1 != p2 && p2 != edges[i][1] - 1) {
                twoParent = true;
                possible = edges[i];
                break;
            }
            uf.toUnion(edges[i][1] - 1, p1);
        }
        uf.reset(size);
        for (int i{0}; i < size; ++i) {
            int p1{uf.find(edges[i][0] - 1)}, p2{uf.find(edges[i][1] - 1)};
            if (p1 == p2) {
                if (!twoParent) return edges[i];
                while (i >= 0) {
                    if (edges[i][1] == possible[1] && edges[i][0] != possible[0]) return edges[i];
                    --i;
                }
            } else if (p2 != edges[i][1] - 1) continue;
            uf.toUnion(edges[i][1] - 1, p1);
        }

        return possible;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> nums{{5,2},{5,1},{3,1},{3,4},{3,5}};
    vector<int> result = solution.findRedundantDirectedConnection(nums);
    return 0;
}
