#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> um;
        for (int i{}; i < n; ++i)
            um[manager[i]].emplace_back(i);
        return dfs(um, -1, informTime);
    }

    int dfs(unordered_map<int, vector<int>> &um, int idx, vector<int> &time) {
        if (um[idx].empty())
            return 0;
        int nxt{};
        vector<int> &child{um[idx]};
        for (int i{}; i < child.size(); ++i)
            nxt = max(nxt, dfs(um, child[i], time));
        return (idx >= 0 ? time[idx] : 0) + nxt;
    }
};

int main() {
    Solution solution;
    vector<int> manager{1,2,3,4,5,6,-1};
    vector<int> informTime{0,6,5,4,3,2,1};
    int result = solution.numOfMinutes(7, 6, manager, informTime);
    cout << result;
    return 0;
}
