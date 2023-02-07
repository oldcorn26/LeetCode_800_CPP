#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        int size = nums.size();
        int ret{0};

        sort(nums.begin(), nums.end());
        for (int i{0}; i < size; ++i) {
            int k{i + 1};
            for (int j{i + 1}; j < size; ++j) {
                while (k + 1 < size && nums[k + 1] < nums[i] + nums[j]) ++k;
                ret += k - j > 0 ? k - j : 0;
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{0,1,3,3};
    int result = solution.triangleNumber(nums);
    cout << result;
    return 0;
}
