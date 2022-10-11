#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void findCombination(const unordered_map<int, int> &two, const unordered_map<int, int> &one,
                         vector<vector<int>> &result);

    vector<vector<int>> threeSum(vector<int> &nums) {
        int zeroNum = 0;
        unordered_map<int, int> negNum, posNum;
        vector<vector<int>> res;

        for (int i : nums) {
            if (i > 0) ++posNum[i];
            else if (i < 0) ++negNum[i];
            else ++zeroNum;
        }

        findCombination(negNum, posNum, res);
        findCombination(posNum, negNum, res);

        if (zeroNum) {
            for (auto i = negNum.begin(); i != negNum.end(); ++i) {
                auto iter = posNum.find(- i->first);
                if (iter != posNum.end()) res.push_back(vector<int>{i->first, 0, iter->first});
            }
            if (zeroNum > 2) res.push_back(vector<int>{0, 0, 0});
        }

        return res;
    }
};

/**
 * Find 2 different elements from "two" and 1 from "one", these elements plus together equals zero.
 * @param two is the map we take 2 element from.
 * @param one is the map we take 1 element from.
 * @param result is the result we want.
 */
void Solution::findCombination(const unordered_map<int, int> &two, const unordered_map<int, int> &one,
                               vector<vector<int>> &result) {
    for (auto i = two.begin(); i != two.end(); ++i) {
        auto j = i;
        for (++j; j != two.end(); ++j) {
            auto iter = one.find(- i ->first - j->first);
            if (iter != one.end()) result.push_back(vector<int>{i->first, j->first, iter->first});
        }
        if (i->second > 1) {
            j = one.find(- i->first - i->first);
            if (j != one.end()) result.push_back(vector<int>{i->first, i->first, j->first});
        }
    }
}

int main() {
    Solution solution;
    vector<int> input{0, 0, 0};
    vector<vector<int>> result = solution.threeSum(input);
    return 0;
}
