#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size(), n = board[0].size();
        int &&size{n * m};

        for (int i{0}; i < n; ++i) {
            if (board[i / n][i % n] == 'O') bfs(board, i);
            int &&temp{size - 1 - i};
            if (board[temp / n][temp % n] == 'O') bfs(board, temp);
        }
        for (int i{0}; i < m; ++i) {
            int &&temp1{i * n}, &&temp2{temp1 + n - 1};
            if (board[temp1 / n][temp1 % n] == 'O') bfs(board, temp1);
            if (board[temp2 / n][temp2 % n] == 'O') bfs(board, temp2);
        }

        for (int i{0}; i < m; ++i) {
            for (int j{0}; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }

    void bfs(vector<vector<char>> &board, int idx) {
        int n = board[0].size();
        forward_list<int> check;

        auto tail{check.emplace_after(check.before_begin(), idx)};
        board[idx / n][idx % n] = 'A';

        for (int &i: check) {
            unsigned int &&x = i / n, &&y = i % n;
            if (x > 0 && board[x - 1][y] == 'O') {
                board[x - 1][y] = 'A';
                tail = check.emplace_after(tail, i - n);
            }
            if (x + 1 < board.size() && board[x + 1][y] == 'O') {
                board[x + 1][y] = 'A';
                tail = check.emplace_after(tail, i + n);
            }
            if (y > 0 && board[x][y - 1] == 'O') {
                board[x][y - 1] = 'A';
                tail = check.emplace_after(tail, i - 1);
            }
            if (y + 1 < n && board[x][y + 1] == 'O') {
                board[x][y + 1] = 'A';
                tail = check.emplace_after(tail, i + 1);
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
