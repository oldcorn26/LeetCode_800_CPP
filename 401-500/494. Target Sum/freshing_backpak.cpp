#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        unordered_map<int, int> map1, map2;
        map2.emplace(0, 1);
        unordered_map<int, int> *pCountMap = &map1, *pPreMap = &map2, *temp;
        for (int &i: nums) {
            for (auto iter = (*pPreMap).begin(); iter != (*pPreMap).end(); ++iter) {
                (*pCountMap)[iter->first + i] += iter->second;
                (*pCountMap)[iter->first - i] += iter->second;
            }
            temp = pCountMap;
            pCountMap = pPreMap;
            pPreMap = temp;
            pCountMap->clear();
        }
        return (*pPreMap)[target];
    }
};

int main() {
    Solution solution;
    vector<int> nums{0,0,0,0,0,0,0,0,1};
    int result = solution.findTargetSumWays(nums, 1);
    cout << result << endl;
    return 0;
}