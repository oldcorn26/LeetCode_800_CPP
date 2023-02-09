#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int> &nums) {
        int ret{0};
        sort(nums.begin(), nums.end());
        for (int i{0}; i < nums.size(); i += 2) {
            ret += min(nums[i], nums[i + 1]);
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{6,2,6,5,1,2};
    int result = solution.arrayPairSum(nums);
    cout << result;
    return 0;
}
