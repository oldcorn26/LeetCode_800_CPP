#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        int height = board.size(); int width = board[0].size();
        stack<char> tree;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (dfs(tree, i * width + j, board, 0, word)) return true;
            }
        }
        return false;
    }

    bool dfs(stack<char> &tree, int &&boardIdx, vector<vector<char>> &board, int &&wordIdx, const string &word) {
        static int height = board.size(); static int width = board[0].size();
        int &&x = boardIdx / width, &&y = boardIdx % width;

        if (board[x][y] != word[wordIdx]) return false;
        if (wordIdx == word.size() - 1) return true;
        else {
            if (x && board[x - 1][y]) {
                tree.push(board[x][y]);
                board[x][y] = 0;
                bool &&temp = dfs(tree, boardIdx - width, board, wordIdx + 1, word);
                if (temp) return true;
                else {board[x][y] = tree.top(); tree.pop();}
            }
            if (y != width - 1 && board[x][y + 1]) {
                tree.push(board[x][y]);
                board[x][y] = 0;
                bool &&temp = dfs(tree, boardIdx + 1, board, wordIdx + 1, word);
                if (temp) return true;
                else {board[x][y] = tree.top(); tree.pop();}
            }
            if (x != height - 1 && board[x + 1][y]) {
                tree.push(board[x][y]);
                board[x][y] = 0;
                bool &&temp = dfs(tree, boardIdx + width, board, wordIdx + 1, word);
                if (temp) return true;
                else {board[x][y] = tree.top(); tree.pop();}
            }
            if (y && board[x][y - 1]) {
                tree.push(board[x][y]);
                board[x][y] = 0;
                bool &&temp = dfs(tree, boardIdx - 1, board, wordIdx + 1, word);
                if (temp) return true;
                else {board[x][y] = tree.top(); tree.pop();}
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCB";
    bool result = solution.exist(board, word);
    cout << (bool) result << endl;
    return 0;
}
