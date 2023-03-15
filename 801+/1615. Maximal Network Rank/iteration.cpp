#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<unordered_set<int>> edges;
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxNum{};
        edges = vector<unordered_set<int>>(n);
        for (auto  &iter: roads) {
            edges[iter[0]].emplace(iter[1]);
            edges[iter[1]].emplace(iter[0]);
        }
        for (int i{}; i < n; ++i) {
            for (int j{i+1}; j < n; ++j) {
                int temp = edges[i].size() + edges[j].size() - (edges[i].find(j) != edges[i].end());
                maxNum = max(maxNum, temp);
            }
        }
        return maxNum;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> roads{{0,1},{0,3},{1,2},{1,3}};
    int result = solution.maximalNetworkRank(4, roads);
    cout << result;
    return 0;
}
