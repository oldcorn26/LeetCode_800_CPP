#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            auto iter = map.find(target - nums[i]);

            if (iter != map.end()) {
                return {iter->second, i};
            } else {
                map.insert(pair<int, int>(nums[i], i));
            }
        }
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> input{50000000, 3, 2, 4, 50000000};
    vector<int> result = solution.twoSum(input, 100000000);

    for (auto i = result.begin(); i < result.end(); i++) {
        cout << *i << " ";
    }
}
