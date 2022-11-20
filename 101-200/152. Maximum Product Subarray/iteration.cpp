#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        char flag = 0;
        int size = nums.size(), max = INT32_MIN, head = -1;

        for (int i = 0; i < size; ++i) {
            if (!nums[i]) {
                int &&temp = maxProductHelper(nums, head + 1, i - 1);
                max = temp > max ? temp : max;
                head = i; flag = 1;
            }
        }
        int &&temp = maxProductHelper(nums, head + 1, size - 1);
        max = temp > max ? temp : max;
        if (max < 0 && flag) return 0;

        return max;
    }

    int maxProductHelper(vector<int> &nums, int &&head, int &&bottom) {
        if (head > bottom) return 0;
        else if (head == bottom) return nums[head];

        int res, temp = 1, minusNum = 0;
        for (int i = head; i <= bottom; ++i) {
            if (nums[i] < 0 && ++minusNum % 2) res = temp;
            temp *= nums[i];
        }
        if (minusNum % 2) {
            int res2, temp2 = 1; minusNum = 0;
            for (int i = bottom; i >= head; --i) {
                if (nums[i] < 0 && ++minusNum % 2) res2 = temp2;
                temp2 *= nums[i];
            }
            res = res2 > res ? res2 : res;
        } else res = temp;

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{-2, 0, -1};
    int result = solution.maxProduct(nums);
    cout << result;
    return 0;
}
