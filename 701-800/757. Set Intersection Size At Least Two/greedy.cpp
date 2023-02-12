#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals) {

        auto cmp = [](vector<int> &x, vector<int> &y) {
            if (x[1] != y[1]) return x[1] < y[1];
            else return x[0] > y[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);

        int size = intervals.size();
        int ret{0};
        vector<int> overlap(size, 2);

        for (int i{0}; i < size; ++i) {
            if (overlap[i] <= 0) continue;
            ret += overlap[i];
            for (int j{i + 1}; j < size; ++j) {
                if (intervals[j][0] > intervals[i][1]) break;
                overlap[j] -= min(overlap[i], intervals[i][1] - intervals[j][0] + 1);
            }
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals{{1,3},{1,4},{2,5},{3,5}};
    int result = solution.intersectionSizeTwo(intervals);
    cout << result;
    return 0;
}
