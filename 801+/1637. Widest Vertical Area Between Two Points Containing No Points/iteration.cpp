#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ret{};
        sort(points.begin(), points.end());
        for (int i{1}; i < points.size(); ++i) {
            ret = max(ret, points[i][0] - points[i-1][0]);
        }
        return ret;
    }
};

int main() {
    Solution solution;
    return 0;
}
