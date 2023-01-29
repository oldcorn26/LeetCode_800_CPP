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
    int findCircleNum(vector<vector<int>> &isConnected) {

        int ret{0};
        vector<char> state(isConnected.size());
        UnionFind uf(isConnected.size());

        for (int i{0}; i < isConnected.size(); ++i) {
            for (int j{0}; j < isConnected.size(); ++j) {
                if (i != j && isConnected[i][j] == 1) uf.toUnion(i, j);
            }
        }
        for (int i{0}; i < isConnected.size(); ++i) {
            int parent{uf.find(i)};
            if (state[parent] == 0) ret += (state[parent] = 1);
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> nums{{1,1,0},{1,1,0},{0,0,1}};
    int result = solution.findCircleNum(nums);
    cout << result;
    return 0;
}
