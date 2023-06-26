#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int m, n;
public:
    bool exist(vector<vector<char>> &board, string word) {
        m = board.size(), n = board[0].size();
        for (int i{}; i < m; ++i) {
            for (int j{}; j < n; ++j) {
                if (word[0] != board[i][j])
                    continue;
                if (dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, int x, int y, string &word, int wIdx) {
        if (wIdx == word.size())
            return true;
        if (x >= m || y >= n || x < 0 || y < 0 || word[wIdx] != board[x][y])
            return false;
        char backUp{board[x][y]};
        board[x][y] = 0;
        if (dfs(board, x + 1, y, word, wIdx + 1) || dfs(board, x, y + 1, word, wIdx + 1) ||
            dfs(board, x - 1, y, word, wIdx + 1) || dfs(board, x, y - 1, word, wIdx + 1))
            return true;
        board[x][y] = backUp;
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
//    vector<vector<char>> board{{'A'}};
    string word = "ABCCEDS";
    bool result = solution.exist(board, word);
    cout << (bool) result << endl;
    return 0;
}
