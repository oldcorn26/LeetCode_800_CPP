#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int m, n;
    vector<vector<int>> ret;
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        m = rowSum.size(), n = colSum.size();
        ret = vector<vector<int>>(m, vector<int>(n));
        vector<pair<int, int>> sortedRow(m);
        for (int i{}; i < m; ++i)
            sortedRow[i] = {rowSum[i], i};
        sort(sortedRow.begin(), sortedRow.end());
        dfs(sortedRow, 0, colSum);
        return ret;
    }

    void dfs(vector<pair<int, int>> &sorted, int sortIdx, vector<int> &col) {
        if (sortIdx == sorted.size()) return;
        auto [sum, i] = sorted[sortIdx];
        for (int j{}; j < n; ++j) {
            int temp = min(sum, col[j]);
            sum -= temp, col[j] -= temp;
            ret[i][j] = temp;
        }
        dfs(sorted, sortIdx+1, col);
    }
};

int main() {
    Solution solution;
    return 0;
}
