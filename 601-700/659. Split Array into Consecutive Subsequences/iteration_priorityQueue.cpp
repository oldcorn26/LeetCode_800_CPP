#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &nums) {

        auto cmp = [](const pair<int, priority_queue<int, vector<int>, greater<>>> &iter) {
            if (iter.second.size()) return iter.second.top() >= 3;
            return true;
        };

        unordered_map<int, priority_queue<int, vector<int>, greater<>>> um;
        for (int &i: nums) {
            int pushNum{1};
            auto iter = um.find(i - 1);
            if (iter != um.end() && iter->second.size()) {
                pushNum += iter->second.top();
                iter->second.pop();
            }
            um[i].emplace(pushNum);
        }

        return all_of(um.begin(), um.end(), cmp);
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,2,3,3,4,5};
    bool result = solution.isPossible(nums);
    cout << result;
    return 0;
}
