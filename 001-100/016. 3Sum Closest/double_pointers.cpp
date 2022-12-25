#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int res, minDis{INT32_MAX};
        sort(nums.begin(), nums.end());

        for (int i{0}; i + 2 < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int &&l{i + 1}, &&r = nums.size() - 1;
            while (l < r) {
                int &&sum{nums[l] + nums[r] + nums[i]};
                if (abs(sum - target) < minDis) {
                    res = sum;
                    minDis = abs(sum - target);
                }
                if (sum > target) {
                    r--;
                } else if (sum < target){
                    l++;
                } else {
                    return target;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,1,1,0};
    int result = solution.threeSumClosest(nums, -100);
    cout << result;
    return 0;
}