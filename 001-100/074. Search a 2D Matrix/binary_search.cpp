#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size(), n = matrix[0].size();
        if (matrix[0][0] > target || matrix[m - 1][n - 1] < target) return false;
        vector<int> mVec(m);
        for (int i{0}; i < m; ++i) mVec[i] = matrix[i][0];
        int mIdx{binarySearch(mVec, target)};
        vector<int> nVec(matrix[mIdx]);
        int nIdx{binarySearch(nVec, target)};

        return matrix[mIdx][nIdx] == target;
    }

    int binarySearch(vector<int> &nums, int target) {
        int sta{0}, end{static_cast<int>(nums.size()) - 1};

        while (sta < end) {
            int &&mid{(sta + end) / 2};
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) end = mid - 1;
            else sta = mid + 1;
        }
        return nums[sta] <= target? sta : sta - 1;
    }
};

int main() {
    Solution solution;
    return 0;
}
