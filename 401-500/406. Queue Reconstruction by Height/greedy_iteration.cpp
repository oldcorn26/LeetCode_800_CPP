#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        map<int, set<int>> sortedH;
        vector<vector<int>> res(people.size());
        for (vector<int> &vec: people) {
            sortedH[vec[0]].emplace(vec[1]);
        }
        for (auto iter = sortedH.begin(); iter != sortedH.end(); ++iter) {
            int unfilledNum = -1, i = -1;
            for (const int &idx: iter->second) {
                while (unfilledNum != idx) {
                    if (res[i + 1].empty()) ++unfilledNum;
                    ++i;
                }
                res[i].resize(2);
                res[i][0] = iter->first, res[i][1] = idx;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> people{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> result = solution.reconstructQueue(people);
    return 0;
}