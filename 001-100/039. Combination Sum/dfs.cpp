#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> ret;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> count(candidates.size());
        dfs(candidates, 0, count, target);
        return ret;
    }

    void dfs(vector<int> &candi, int candiIdx, vector<int> &count, int tar) {
        if (tar == 0) {
            vector<int> valid;
            for (int i{}; i < candi.size(); ++i) {
                if (count[i] == 0)
                    continue;
                std::fill_n(std::back_inserter(valid), count[i], candi[i]);
            }
            ret.push_back(valid);
            return;
        }
        for (int i{candiIdx}; i < candi.size() && candi[i] <= tar; ++i) {
            count[i]++;
            dfs(candi, i, count, tar - candi[i]);
            count[i]--;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{2, 3, 5};
    vector<vector<int>> result = solution.combinationSum(nums, 8);
    return 0;
}