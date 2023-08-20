#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        vector<vector<int>> ret(people.size());
        sort(people.begin(), people.end());
        for (auto &vec: people) {
            int emptyNum{};
            for (int i{}; i < ret.size(); ++i) {
                if (ret[i].empty() && emptyNum >= vec[1]) {
                    ret[i] = std::move(vec);
                    break;
                } else if (ret[i].empty() || ret[i][0] == vec[0]) {
                    emptyNum++;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> people{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> result = solution.reconstructQueue(people);
    return 0;
}
