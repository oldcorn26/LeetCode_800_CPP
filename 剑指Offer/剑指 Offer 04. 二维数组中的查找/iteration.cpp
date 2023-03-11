#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size(), n = matrix[0].size();
        for (int i{}; i < m; ++i) {
            if (matrix[i][0] > target) break;
            if (matrix[i][n-1] < target) continue;
            int sta{}, end{n-1};
            while (sta < end) {
                int mid{(sta + end) >> 1};
                if (matrix[i][mid] == target) return true;
                else if (matrix[i][mid] > target) end = mid;
                else sta = mid + 1;
            }
            if (matrix[i][sta] == target) return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    return 0;
}
