#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() / 2; i++) {
            rotateHelper(matrix, i, matrix.size() - 1 - i * 2);
        }
    }

    void rotateHelper(vector<vector<int>> &mat, int &pos, int &&move) {
        int temp;
        for (int i = 0; i < move; i++) {
            temp = mat[pos + i][pos + move];
            mat[pos + i][pos + move] = mat[pos][pos + i];
            mat[pos][pos + i] = mat[pos + move - i][pos];
            mat[pos + move - i][pos] = mat[pos + move][pos + move - i];
            mat[pos + move][pos + move - i] = temp;
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix{{5,  1,  9,  11},
                               {2,  4,  8,  10},
                               {13, 3,  6,  7},
                               {15, 14, 12, 16}};
    solution.rotate(matrix);
    return 0;
}