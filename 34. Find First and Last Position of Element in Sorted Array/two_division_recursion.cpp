#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int &&head = searchRangeHelper(nums, 0, nums.size() - 1, target);
        if (head == -1) return {-1, -1};

        int bottom = head;
        while(head - 1 >= 0 && nums[head - 1] == target) head--;
        while(bottom + 1 < nums.size() && nums[bottom + 1] == target) bottom++;

        return {head, bottom};
    }

    int searchRangeHelper(vector<int> &nums, int &&head, int &&bottom, int &tar) {
        int &&mid = (head + bottom) / 2;
        if (nums[bottom] == tar) return bottom;
        else if (nums[head] == tar) return head;
        else if (nums[mid] == tar) return mid;
        else if (bottom - head <= 2 || nums[head] > tar || nums[bottom] < tar)  return -1;

        if (nums[mid] > tar) return searchRangeHelper(nums, head + 1, move(mid), tar);
        else return searchRangeHelper(nums, mid + 1, bottom - 1, tar);
    }
};

int main() {
    Solution solution;
    vector<int> nums{0,1,2,3,4,4,4};
    vector<int> result = solution.searchRange(nums, 2);
    cout << result[0] << "," << result[1] << endl;
    return 0;
}