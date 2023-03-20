#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xOR{};
        for (int &i: nums)
            xOR ^= i;
        int mask{1};
        while ((mask & xOR) == 0)
            mask <<= 1;
        int left{}, right{};
        for (int &i: nums) {
            if (i & mask)
                left ^= i;
            else
                right ^= i;
        }
        return {left, right};
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,1,2,2,3,5};
    vector<int> result = solution.singleNumber(nums);
    return 0;
}
