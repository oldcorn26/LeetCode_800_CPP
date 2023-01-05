#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int resIdx{0};
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> settled(k);
        res = vector<vector<int>>(C(n, k), vector<int>(k));
        dfs(settled, 0, n, 1);
        return res;
    }

    void dfs(vector<int> &settled, int &&stlIdx, int &n, int &&crt) {
        if (stlIdx == settled.size()) {
            res[resIdx++] = settled;
            return;
        }
        for (int i{crt}; i <= n; ++i) {
            settled[stlIdx] = i;
            dfs(settled, stlIdx + 1, n, i + 1);
        }
    }

    int C(int n, int m){
        int ans{1};
        m = min(m, n - m);
        for(int i{1}; i <= m; ++i){
            ans = ans * (n - m + i) / i;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> result = solution.combine(4, 2);
    return 0;
}