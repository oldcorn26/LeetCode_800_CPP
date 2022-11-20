#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return searchHelper(nums, 0, nums.size() - 1, target);
    }

    int searchHelper(vector<int> &nums, int &&head, int &&bottom, int &target) {
        int &&middle = (head + bottom) / 2;
        if (nums[head] > target && nums[bottom] < target) return -1;
        if (nums[bottom] == target) return bottom;
        else if (nums[head] == target) return head;
        else if (nums[middle] == target) return middle;
        else if (bottom - head <= 2)  return -1;

        if (nums[head] < nums[bottom]) {
            if (nums[middle] < target) return searchHelper(nums, middle + 1, bottom - 1, target);
            else return searchHelper(nums, head + 1, move(middle), target);
        } else {
            bool &&flag = nums[head] > nums[middle];
            int &&con1 = flag ? middle + 1 : head + 1, &&con2 = flag ? bottom - 1 : middle;
            int &&dis1 = flag ? head + 1 : middle + 1, &&dis2 = flag ? middle : bottom - 1;

            if (nums[con1] <= target && nums[con2] >= target)
                return searchHelper(nums, move(con1), move(con2), target);
            else if (nums[dis1] > target && nums[dis2] < target) return -1;
            else return searchHelper(nums, move(dis1), move(dis2), target);
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{4,5,6,7,0,1,2};
    for (int i = 0; i < 8; i++) {
        int result = solution.search(nums, i);
        cout << result <<" ";
    }
    return 0;
}
