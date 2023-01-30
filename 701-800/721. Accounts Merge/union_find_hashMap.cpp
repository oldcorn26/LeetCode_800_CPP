#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {

        int retSize{0};
        UnionFind uf(accounts.size());
        unordered_map<string, int> um;
        vector<vector<string>> tempRet(accounts.size());

        for (int i{0}; i < accounts.size(); ++i) {
            for (int j{1}; j < accounts[i].size(); ++j) {
                auto iter = um.find(accounts[i][j]);
                if (iter == um.end()) {
                    um.emplace(accounts[i][j], i);
                } else {
                    uf.toUnion(i, iter->second);
                }
            }
        }
        for (auto &iter: um) {
            int idx{uf.find(iter.second)};
            if (tempRet[idx].empty()) {
                tempRet[idx] = {accounts[idx][0]};
                ++retSize;
            }
            tempRet[idx].emplace_back(iter.first);
        }
        vector<vector<string>> ret(retSize);
        for (auto &vec: tempRet) {
            if (vec.empty()) continue;
            sort(vec.begin() + 1, vec.end());
            ret[--retSize] = vec;
        }

        return ret;
    }
};

int main() {
    Solution solution;
    return 0;
}
