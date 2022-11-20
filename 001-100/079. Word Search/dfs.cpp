#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int height, width;
public:
    bool exist(vector<vector<char>> &board, string word) {
        height = board.size(); width = board[0].size();
        if (word.size() > height * width) return false;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (board[i][j] != word[0]) continue;
                if (dfs(i * width + j, board, 0, word)) return true;
            }
        }

        return false;
    }

    bool dfs(int &&boardIdx, vector<vector<char>> &board, int &&wordIdx, const string &word) {
        int &&x = boardIdx / width, &&y = boardIdx % width;

        if (board[x][y] != word[wordIdx]) return false;
        if (wordIdx == word.size() - 1) return true;
        else {
            if (x && board[x - 1][y] == word[wordIdx + 1]) {
                board[x][y] -= 60;
                bool &&temp = dfs(boardIdx - width, board, wordIdx + 1, word);
                if (temp) return true;
                else board[x][y] +=60;
            }
            if (y != width - 1 && board[x][y + 1] == word[wordIdx + 1]) {
                board[x][y] -= 60;
                bool &&temp = dfs(boardIdx + 1, board, wordIdx + 1, word);
                if (temp) return true;
                else board[x][y] +=60;
            }
            if (x != height - 1 && board[x + 1][y] == word[wordIdx + 1]) {
                board[x][y] -= 60;
                bool &&temp = dfs(boardIdx + width, board, wordIdx + 1, word);
                if (temp) return true;
                else board[x][y] += 60;
            }
            if (y && board[x][y - 1] == word[wordIdx + 1]) {
                board[x][y] -= 60;
                bool &&temp = dfs(boardIdx - 1, board, wordIdx + 1, word);
                if (temp) return true;
                else board[x][y] += 60;
            }
        }
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
