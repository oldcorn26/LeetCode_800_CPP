#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size(), n = board[0].size();
        vector<int> boardState(m * n);

        for (int i{0}; i < m; ++i) {
            int &&temp{i * n};
            boardState[temp] = 2;
            boardState[temp + n - 1] = 2;
        }
        for (int i{0}; i < n; ++i) {
            boardState[i] = 2;
            boardState[boardState.size() - 1 - i] = 2;
        }

        for (int i{0}; i < m; ++i) {
            for (int j{0}; j < n; ++j) {
                if (boardState[i * n + j] % 2) continue;
                if (board[i][j] == 'X') {
                    ++boardState[i * n + j];
                    continue;
                }
                bfs(board, boardState, i * n + j);
            }
        }
    }

    void bfs(vector<vector<char>> &board, vector<int> &state, int idx) {
        bool flag{true};
        int n = board[0].size();
        forward_list<int> check;

        auto tail{check.emplace_after(check.before_begin(), idx)};
        ++state[idx];

        for (int &i: check) {
            unsigned int &&x = i / n, &&y = i % n;
            if (state[i] == 3) flag = false;
            if (x > 0 && board[x - 1][y] == 'O' && !(state[i - n] % 2)) {
                ++state[i - n];
                tail = check.emplace_after(tail, i - n);
            }
            if (x + 1 < board.size() && board[x + 1][y] == 'O' && !(state[i + n] % 2)) {
                ++state[i + n];
                tail = check.emplace_after(tail, i + n);
            }
            if (y > 0 && board[x][y - 1] == 'O' && !(state[i - 1] % 2)) {
                ++state[i - 1];
                tail = check.emplace_after(tail, i - 1);
            }
            if (y + 1 < n && board[x][y + 1] == 'O' && !(state[i + 1] % 2)) {
                ++state[i + 1];
                tail = check.emplace_after(tail, i + 1);
            }
        }

        if (flag) {
            for (int &i: check) {
                int &&x = i / n, &&y = i % n;
                board[x][y] = 'X';
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board{{'O','O'},{'O','O'}};
    solution.solve(board);
    return 0;
}
