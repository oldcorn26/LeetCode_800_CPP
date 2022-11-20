#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), &&y = matrix[0].size() - 1, x = 0;

        while (x < m && y >= 0) {
            if (matrix[x][y] == target) return true;
            if (matrix[x][y] > target) --y;
            else ++x;
        }
        return false;
    }
};

int main() {
    Solution solution;
    return 0;
}
