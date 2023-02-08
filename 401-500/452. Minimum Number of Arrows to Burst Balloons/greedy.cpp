#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {

        sort(points.begin(), points.end(), [](vector<int> &x, vector<int> &y) { return x[1] < y[1]; });
        int size = points.size();
        int ret{1}, right{points[0][1]};

        for (int i{1}; i < size; ++i) {
            if (points[i][0] <= right) continue;
            ++ret;
            right = points[i][1];
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points{{10,16},{2,8},{1,6},{7,12}};
    int result = solution.findMinArrowShots(points);
    cout << result;
    return 0;
}
