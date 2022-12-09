#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int res{0}, sum{0};
        unordered_map<int, int> prefix;
        prefix.emplace(0, 1);
        for (int &i: nums) {
            sum += i;
            auto iter = prefix.find(sum - k);
            if (iter != prefix.end()) res += iter->second;
            ++prefix[sum];
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,2,3};
    int result = solution.subarraySum(nums, 3);
    cout << result;
    return 0;
}