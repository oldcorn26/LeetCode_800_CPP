#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {

        int ret{0};
        int size = intervals.size();

        if (size == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &x, vector<int> &y) { return x[1] < y[1]; });

        int right{intervals[0][1]};
        for (int i{1}; i < size; ++i) {
            if (intervals[i][0] >= right) {
                right = intervals[i][1];
            } else ++ret;
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals{{{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}}};
    int result = solution.eraseOverlapIntervals(intervals);
    cout << result;
    return 0;
}
