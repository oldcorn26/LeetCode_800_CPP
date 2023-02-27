#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int stlNum{0};
    vector<int> col{0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> row{0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> bloc{0, 0, 0, 0, 0, 0, 0, 0, 0};
public:
    void solveSudoku(vector<vector<char>> &board) {
        for (int i{0}; i < 9; ++i) {
            for (int j{0}; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int blcIdx{i / 3 * 3 + j / 3};
                int mask{1 << (board[i][j] - '1')};
                row[i] |= mask, col[j] |= mask, bloc[blcIdx] |= mask;
                stlNum++;
            }
        }
        dfs(board, 0, 0);
    }

    bool dfs(vector<vector<char>> &board, int x, int y) {
        if (x == 9) return stlNum == 81;
        if (y == 9) return dfs(board, x + 1, 0);
        if (board[x][y] != '.') return dfs(board, x, y + 1);

        int blcIdx{x / 3 * 3 + y / 3};
        for (int k{0}; k < 9; ++k) {
            int mask{1 << k};
            if (row[x] & mask || col[y] & mask || bloc[blcIdx] & mask) continue;
            board[x][y] = k + '1';
            row[x] |= mask, col[y] |= mask, bloc[blcIdx] |= mask;
            stlNum++;
            if (dfs(board, x, y + 1)) return true;
            board[x][y] = '.';
            row[x] ^= mask, col[y] ^= mask, bloc[blcIdx] ^= mask;
            stlNum--;
        }

        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solution.solveSudoku(board);
    return 0;
}
