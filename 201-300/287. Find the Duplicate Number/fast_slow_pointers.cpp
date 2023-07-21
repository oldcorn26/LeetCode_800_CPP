#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow{nums[0]}, fast{nums[nums[0]]};
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,3,4,2,2};
    int result = solution.findDuplicate(nums);
    cout << result;
    return 0;
}
