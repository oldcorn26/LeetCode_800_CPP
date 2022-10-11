#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        unordered_map<int, int> map;
        vector<vector<int>> res;

        for (int i : nums) {++map[i];}
        auto end = map.end();

        for (auto i = map.begin(); i != end; ++i) {
            auto j = i;
            for (++j; j != end; ++j) {
                auto k = j;
                for (++k; k != end; ++k) {
                    if (i->first + j->first + k->first == 0)
                        res.push_back(vector<int>{i->first, j->first, k->first});
                }

                if (i->second >= 2 || j->second >= 2) {
                    if (i->first * 2 + j->first == 0 && i->second >=2) res.push_back(vector<int>{i->first, i->first, j->first});
                    else if (i->first + j->first * 2 == 0 && j->second >=2) res.push_back(vector<int>{i->first, j->first, j->first});
                }
            }
        }

        if (map[0] >= 3) res.push_back(vector<int>(3, 0));

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> input{-4,-2,-2,0,1,2,2};
    vector<vector<int>> result = solution.threeSum(input);
    return 0;
}
