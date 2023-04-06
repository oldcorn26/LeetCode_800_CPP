#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int size;
    int interval;
    vector<int> prefix;
    vector<vector<vector<int>>> dp;
public:
    int mergeStones(vector<int> &stones, int k) {
        size = stones.size();
        if ((size-1) % (k-1))
            return -1;
        prefix.resize(size+1);
        interval = k;
        dp = vector<vector<vector<int>>>(size, vector<vector<int>>(size, vector<int>(k+1, -1)));
        for (int i{1}; i <= size; ++i)
            prefix[i] = prefix[i-1] + stones[i-1];
        return dfs(0, size-1, 1);
    }

    int dfs(int sta, int end, int pile) {
        int &ref{dp[sta][end][pile]};
        if (ref != -1)
            return ref;
        if (pile == 1)
            return sta == end ? 0 : dfs(sta, end, interval) + prefix[end+1] - prefix[sta];
        ref = INT32_MAX;
        for (int m{sta}; m < end; m += interval-1)
            ref = min(ref, dfs(sta, m, 1) + dfs(m+1, end, pile-1));
        return ref;
    }
};


int main() {
    Solution solution;
    vector<int> nums{3,2,4,1};
    int result = solution.mergeStones(nums, 2);
    cout << result;
    return 0;
}
