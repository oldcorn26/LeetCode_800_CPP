#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> selected(51);
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, selected, target);
        return res;
    }

    void dfs(vector<int> &candi, int idx, vector<int> &sel, int tar) {
        if (tar == 0) {
            pushAnswer(sel);
            return;
        }
        int pre{INT32_MIN};
        for (int i{idx}; i < candi.size() && candi[i] <= tar; ++i) {
            if (pre == candi[i]) continue;
            ++sel[candi[i]];
            dfs(candi, i + 1, sel, tar - candi[i]);
            --sel[candi[i]];
            pre = candi[i];
        }
    }

    void pushAnswer(vector<int> &sel) {
        vector<int> answer;
        for (int i{1}; i < 51; ++i) {
            int times{sel[i]};
            while (times--) {
                answer.push_back(i);
            }
        }
        res.push_back(answer);
    }
};

int main() {
    Solution solution;
    vector<int> candidates{10,1,2,7,6,1,5};
    vector<vector<int>> result = solution.combinationSum2(candidates, 8);
    return 0;
}