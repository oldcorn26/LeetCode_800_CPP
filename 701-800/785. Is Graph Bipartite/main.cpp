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
    bool isBipartite(vector<vector<int>> &graph) {

        vector<int> state(graph.size());
        UnionFind uf(graph.size() + 2);

        for (int i{0}; i < graph.size(); ++i) {
            if (graph[i].empty() || state[i]) continue;

            int sideFlag{0};
            vector<int> candi{graph[i]};

            state[i] = 1;
            while (candi.size()) {
                vector<int> temp;
                for (int &j: candi) {
                    uf.toUnion(j + 2, sideFlag % 2);
                    if (state[j]) continue;
                    state[j] = 1;
                    temp.insert(temp.end(), graph[j].begin(), graph[j].end());
                }
                candi = temp;
                ++sideFlag;
            }
            
            if (uf.find(0) == uf.find(1)) return false;
        }

        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> graph{{1,3},{0,2},{1,3},{0,2}};
    bool result = solution.isBipartite(graph);
    cout << result;
    return 0;
}
