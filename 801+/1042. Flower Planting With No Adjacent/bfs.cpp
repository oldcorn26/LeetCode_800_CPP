#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> edges(n+1);
        vector<int> ret(n);
        queue<int> que;
        for (int i{}; i < paths.size(); ++i) {
            edges[paths[i][0]].emplace_back(paths[i][1]);
            edges[paths[i][1]].emplace_back(paths[i][0]);
        }
        for (int i{}; i < n; ++i) {
            if (ret[i] != 0)
                continue;
            que.emplace(i+1);
            while (!que.empty()) {
                int state{1};
                vector<int> &neighbors{edges[que.front()]};
                for (int &iter: neighbors) {
                    if (ret[iter-1] == 0) {
                        que.emplace(iter);
                        continue;
                    }
                    state |= (1 << ret[iter-1]);
                }
                int crt{1};
                while ((state >> crt) & 1)
                    crt++;
                ret[que.front() - 1] = crt;
                que.pop();
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    return 0;
}
