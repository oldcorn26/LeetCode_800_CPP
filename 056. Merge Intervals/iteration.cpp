#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int flag = 0, idx;
        map<int, int> map;
        vector<vector<int>> res;

        for (auto &vec: intervals) {
            //one left equals 1, one right equals -1.
            ++map[vec[0]];
            --map[vec[1]];
        }

        for (auto &&iter = map.begin(); iter != map.end(); ++iter) {
            if (!flag) idx = iter->first;
            flag += iter->second;
            if (!flag) res.push_back({idx, iter->first});
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> nums{{1,3}, {2, 6}, {8, 10}};
    vector<vector<int>> result = solution.merge(nums);
    return 0;
}