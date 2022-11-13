#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size() - k + 1;
        vector<int> res(size);
        priority_queue<pair<int, int>> pq;

        for (int j = 0; j < k; ++j) pq.emplace(nums[j], j);
        res[0] = pq.top().first;

        for (int i = 1; i < size; ++i) {
            pq.emplace(nums[i + k - 1], i + k - 1);
            while (pq.top().second < i) pq.pop();
            res[i] = pq.top().first;
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
