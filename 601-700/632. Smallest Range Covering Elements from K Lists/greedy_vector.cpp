#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int totalSize{0};
    vector<pair<int,int>> sorted;
public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        int left{0}, right{0};
        int minL{0}, minR{0}, minLen{INT32_MAX};
        int attributeNum{0};
        vector<int> attribute(nums.size());
        iniSortedList(nums);

        while (right < totalSize) {
            while (attributeNum < nums.size() && right < totalSize) {
                if (++attribute[sorted[right].second] == 1) attributeNum++;
                ++right;
            }
            if (attributeNum != nums.size()) break;
            while (attributeNum == nums.size() && left < right) {
                if (--attribute[sorted[left].second] == 0) attributeNum--;
                ++left;
            }
            if (sorted[right - 1].first - sorted[left - 1].first < minLen) {
                minLen = sorted[right - 1].first - sorted[left - 1].first;
                minL = left - 1, minR = right - 1;
            }
        }

        return {sorted[minL].first, sorted[minR].first};
    }

    void iniSortedList(vector<vector<int>> &nums) {
        vector<int> idx(nums.size());
        for (vector<int> &vec:nums) totalSize += vec.size();
        sorted = vector<pair<int, int>>(totalSize);
        for (int i{0}; i < totalSize; ++i) {
            int min{INT32_MAX}, minIdx{0};
            for (int j{0}; j < nums.size(); ++j) {
                if (idx[j] < nums[j].size() && nums[j][idx[j]] < min) {
                    min = nums[j][idx[j]];
                    minIdx = j;
                }
            }
            idx[minIdx]++;
            sorted[i].first = min, sorted[i].second = minIdx;
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> nums{{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
    vector<int> result = solution.smallestRange(nums);
    return 0;
}
