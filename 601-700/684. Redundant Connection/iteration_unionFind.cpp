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
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {

        int size = edges.size();
        UnionFind uf(size);

        for (int i{0}; i < size; ++i) {
            int p1{uf.find(edges[i][0] - 1)}, p2{uf.find(edges[i][1] - 1)};
            if (p1 == p2) return {edges[i][0], edges[i][1]};
            uf.toUnion(edges[i][0] - 1, p2);
        }

        return {};
    }
};

int main() {
    Solution solution;
    vector<vector<int>> nums{{1,2},{1,3},{2,3}};
    vector<int> result = solution.findRedundantConnection(nums);
    return 0;
}
