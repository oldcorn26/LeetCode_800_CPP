#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>> &nums) {

        int minPre{0}, maxQue{0};
        int resL{0}, resR{0}, minLen{INT32_MAX};
        int attributeNum{static_cast<int>(nums.size())}, lackIdx{0};
        vector<int> attribute(nums.size(), 1);
        vector<int> idx(nums.size(), 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

        for (int i{0}; i < nums.size(); ++i) {
            maxQue = max(maxQue, nums[i][0]);
            q.emplace(nums[i][0], i);
        }

        while (true) {
            while (attributeNum == nums.size()) {
                if (--attribute[q.top().second] == 0) {
                    minPre = q.top().first, lackIdx = q.top().second;
                    attributeNum--;
                }
                q.pop();
            }
            if (maxQue - minPre < minLen) {
                minLen = maxQue - minPre;
                resL = minPre, resR = maxQue;
            }
            if (idx[lackIdx] == nums[lackIdx].size()) break;
            int &tempMIn{nums[lackIdx][idx[lackIdx]]};
            for (int i{0}; i < nums.size(); ++i) {
                if (idx[i] == nums[i].size()) continue;
                while (idx[i] < nums[i].size() && nums[i][idx[i]] <= tempMIn) {
                    q.emplace(nums[i][idx[i]], i);
                    maxQue = max(maxQue, nums[i][idx[i]]);
                    ++idx[i], ++attribute[i];
                }
            }
            ++attributeNum;
        }

        return {resL, resR};
    }
};

int main() {
    Solution solution;
    vector<vector<int>> nums{{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
    vector<int> result = solution.smallestRange(nums);

    return 0;
}
