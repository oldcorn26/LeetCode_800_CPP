#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        stack<int> tree;
        vector<vector<int>> result;
        int &&index = candidates.size() - 1;

        sort(candidates.begin(), candidates.end());
        while (index >= 0 && candidates[index] > target) index--;
        if (index < 0) return {};

        dfs(tree, move(target), move(index), candidates, result);
        return result;
    }

    void dfs(stack<int> &tree, int &&tar, int &&idx, const vector<int> &candi, vector<vector<int>> &res) {
        if (tar < 0) return;
        else if (!tar) {
            stack<int> temp(tree);
            vector<int> element(temp.size());
            for (int &i : element) {i = temp.top(); temp.pop();}
            res.push_back(element);
            return;
        }

        for (int i = idx; i >= 0; i--) {
            tree.push(candi[i]);
            dfs(tree, tar - candi[i], move(i), candi, res);
            tree.pop();
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{2, 3, 5};
    vector<vector<int>> result = solution.combinationSum(nums, 8);
    return 0;
}