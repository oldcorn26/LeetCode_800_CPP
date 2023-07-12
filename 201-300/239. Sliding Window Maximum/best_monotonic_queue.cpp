#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> monoS{0};
        vector<int> ret;
        for (int i{1}; i < k; ++i) {
            while (!monoS.empty() && nums[monoS.back()] < nums[i])
                monoS.pop_back();
            monoS.emplace_back(i);
        }
        ret.emplace_back(nums[monoS.front()]);
        for (int i{k}; i < nums.size(); ++i) {
            while (!monoS.empty() && nums[monoS.back()] < nums[i])
                monoS.pop_back();
            monoS.emplace_back(i);
            while (monoS.front() < i - k + 1)
                monoS.pop_front();
            ret.emplace_back(nums[monoS.front()]);
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    vector<int> result = solution.maxSlidingWindow(nums, 3);
    return 0;
}
