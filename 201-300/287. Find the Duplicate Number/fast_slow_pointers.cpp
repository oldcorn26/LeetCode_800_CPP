#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;

        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);
        slow = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }

        return fast;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,3,4,2,2};
    int result = solution.findDuplicate(nums);
    cout << result;
    return 0;
}
