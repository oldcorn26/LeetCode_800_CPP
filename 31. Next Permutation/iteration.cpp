#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        bool flag = false;
        int temp, i;
        for (i = nums.size() - 2; i >= 0; i--) {
            temp = nums[i];
            for (int j = nums.size() - 1; j > i; j--)
                if (nums[j] > temp) {
                    nums[i] = nums[j];
                    nums[j] = temp;
                    flag = true;
                    break;
                }
            if (flag) break;
        }

        i++;
        for (int j = nums.size() - 1; i < j; i++, j--) {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 3, 2};
    solution.nextPermutation(nums);
    return 0;
}
