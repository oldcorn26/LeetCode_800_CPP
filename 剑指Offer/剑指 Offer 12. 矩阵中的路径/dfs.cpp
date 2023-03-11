#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int m, n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for (int i{}; i < m; ++i) {
            for (int j{}; j < n; ++j) {
                if (board[i][j] != word[0]) continue;
                if (dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, int x, int y, string &word, int idx) {
        if (idx == word.size()) return true;
        else if (idx+1 == word.size()) return word[idx] == board[x][y];
        if (board[x][y] != word[idx]) return false;
        char cache{board[x][y]};
        board[x][y] = 0;
        if (x+1 < m && board[x+1][y] != 0 && dfs(board, x+1, y, word, idx+1)) return true;
        if (y+1 < n && board[x][y+1] != 0 && dfs(board, x, y+1, word, idx+1)) return true;
        if (x-1 >= 0 && board[x-1][y] != 0 && dfs(board, x-1, y, word, idx+1)) return true;
        if (y-1 >= 0 && board[x][y-1] != 0 && dfs(board, x, y-1, word, idx+1)) return true;
        board[x][y] = cache;
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board{{'a','b'}};
    bool result = solution.exist(board, "a");
    return 0;
}
