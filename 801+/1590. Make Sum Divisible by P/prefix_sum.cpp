#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int> &nums, int p) {

        int size = nums.size();
        int sumRem{}, prefixRem{};
        int ret{INT32_MAX};
        unordered_map<int, int> remIdx;

        for (int i{}; i < size; ++i)
            sumRem = (sumRem + nums[i]) % p;
        if (sumRem == 0) return 0;

        remIdx[0] = -1;
        for (int i{}; i < size; ++i) {
            prefixRem = (prefixRem + nums[i]) % p;
            auto iter = remIdx.find((prefixRem - sumRem + p) % p);
            if (iter != remIdx.end()) ret = min(ret, i - iter->second);
            remIdx[prefixRem] = i;
        }

        return ret == nums.size() ? -1 : ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,2,3};
    int result = solution.minSubarray(nums, 7);
    cout << result;
    return 0;
}
