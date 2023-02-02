#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int m, n;
    vector<int> memo;
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        m = dungeon.size(), n = dungeon[0].size();
        memo = vector<int>(m * n);
        return calculateMinHelper(dungeon, 0, 0);
    }

    int calculateMinHelper(vector<vector<int>> &dun, int x, int y) {

        int idx{x * n + y};
        int sideMin{INT32_MAX};

        if (memo[idx]) return memo[idx];
        if (y + 1 < n) sideMin = min(sideMin, calculateMinHelper(dun, x, y + 1));
        if (x + 1 < m) sideMin = min(sideMin, calculateMinHelper(dun, x + 1, y));
        int ret{(sideMin != INT32_MAX ? sideMin : 1) - dun[x][y]};

        return memo[idx] = ret > 1 ? ret : 1;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> dungeon{{-2,-3,3},{-5,-10,1},{10,30,-5}};
    int result = solution.calculateMinimumHP(dungeon);
    cout << result;
    return 0;
}
