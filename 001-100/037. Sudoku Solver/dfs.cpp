#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
private:
    vector<bitset<9>> rows, cols, cells;
public:
    void solveSudoku(vector<vector<char>> &board) {
        int &&settledNum{initialState(board)};
        dfs(board, settledNum);
    }

    bool dfs(vector<vector<char>> &board, int stlNum) {
        if (stlNum == 81) return true;

        vector<int> &&next{getNext(board)};
        bitset<9> &&bits{getPossibleStatus(next[0], next[1])};
        for (int idx{0}; idx < 9; ++idx) {
            if (!bits.test(idx)) continue;
            fillNum(next[0], next[1], idx, true);
            board[next[0]][next[1]] = idx + '1';
            if (dfs(board, stlNum + 1)) return true;
            board[next[0]][next[1]] = '.';
            fillNum(next[0], next[1], idx, false);
        }
        return false;
    }

    bitset<9> getPossibleStatus(int x, int y) {
        return ~(rows[x] | cols[y] | cells[x / 3 * 3 + y / 3]);
    }

    vector<int> getNext(vector<vector<char>> &board) {
        int minCnt{10};
        vector<int> res(2);
        for (int i{0}; i < 9; ++i) {
            for (int j{0}; j < 9; ++j) {
                if (board[i][j] != '.') continue;
                bitset<9> &&crt{getPossibleStatus(i, j)};
                if (crt.count() >= minCnt) continue;
                res[0] = i, res[1] = j;
                minCnt = crt.count();
            }
        }
        return res;
    }

    void fillNum(int x, int y, int n, bool fillFlag) {
        rows[x][n] = cols[y][n] = cells[x / 3 * 3 + y / 3][n] = fillFlag ? 1 : 0;
    }

    int initialState(vector<vector<char>> &board) {
        int stlNum{0};
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<bitset<9>>(9, bitset<9>());
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                int idx{board[i][j] - '1'};
                if (idx >= 0) {
                    rows[i][idx] = cols[j][idx] = 1;
                    cells[i / 3 * 3 + j / 3][idx] = 1;
                    ++stlNum;
                }
            }
        }
        return stlNum;
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