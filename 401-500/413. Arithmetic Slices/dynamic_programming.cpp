#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        if (nums.size() < 3) return 0;
        int ret{0};
        int preDP{1}, preInter{nums[1] - nums[0]};
        for (int i{2}; i < nums.size(); ++i) {
            if (nums[i] - nums[i-1] != preInter) {
                ret += getAns(preDP);
                preDP = 1;
                preInter = nums[i] - nums[i-1];
            }
            else preDP++;
        }
        return ret + getAns(preDP);
    }

    int getAns(int n) {
        if (n < 2) return 0;
        int ret{0};
        while (--n >= 1) ret += n;
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,2,3,4,5,6};
    int result = solution.numberOfArithmeticSlices(nums);
    cout << result;
    return 0;
}
