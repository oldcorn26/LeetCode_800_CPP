#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int left{intervals[0][0]}, right{intervals[0][1]};
        vector<vector<int>> ret;
        for (auto &vec: intervals) {
            if (vec[0] > right) {
                ret.push_back({left, right});
                left = vec[0];
                right = vec[1];
            } else {
                right = max(right, vec[1]);
            }
        }
        ret.push_back({left, right});
        return ret;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> nums{{1,3}, {2, 6}, {8, 10}};
    vector<vector<int>> result = solution.merge(nums);
    return 0;
}