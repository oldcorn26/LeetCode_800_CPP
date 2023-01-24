#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {

        int mid = nums.size() / 2;
        int l = (nums.size() - 1) / 2, r = nums.size() - 1;
        int idx{0};
        vector<int> temp{nums};

        sort(temp.begin(), temp.end());
        for (int i{0}; i < mid; ++i) {
            nums[idx++] = temp[l--];
            nums[idx++] = temp[r--];
        }
        if (nums.size() % 2) nums[idx] = temp[0];
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,5,1,1,6,4};
    solution.wiggleSort(nums);
    return 0;
}
