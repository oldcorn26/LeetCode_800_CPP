#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int> &nums) {
        int sum{};
        for (int i: nums)
            sum += i;
        sort(nums.begin(), nums.end());
        for (int i{1}; i <= nums.size() / 2; ++i) {
            if (sum * i % nums.size()) continue;
            if (findSum(nums, 0, 0, i, sum*i/nums.size())) return true;
        }
        return false;
    }

    bool findSum(vector<int> &nums, int staIdx, int state, int restSize, int restSum) {
        if (restSize == 0) return restSum == 0;
        for (int i{staIdx}; i < nums.size(); ++i) {
            if (nums[i] > restSum)
                break;
            if (findSum(nums, i+1, state|(1<<i), restSize-1, restSum-nums[i]))
                return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums{2,0,5,6,16,12,15,12,4};
    int result = solution.splitArraySameAverage(nums);
    cout << result;
    return 0;
}
