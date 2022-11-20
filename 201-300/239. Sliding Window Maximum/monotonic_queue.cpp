#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size() - k + 1;
        vector<int> res(size);
        deque<int> dec;

        for (int i = 0; i < k; ++i) {
            while (!dec.empty() && nums[i] >= nums[dec.back()]) dec.pop_back();
            dec.push_back(i);
        }
        res[0] = nums[dec.front()];

        for (int i = 1; i < size; ++i) {
            while (!dec.empty() && nums[i + k - 1] >= nums[dec.back()]) dec.pop_back();
            dec.push_back(i + k - 1);
            while (dec.front() < i) dec.pop_front();
            res[i] = nums[dec.front()];
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    vector<int> result = solution.maxSlidingWindow(nums, 3);
    return 0;
}
