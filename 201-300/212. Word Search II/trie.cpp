#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Trie {
private:
    bool isEnd;
    Trie *next[26];
public:
    Trie() : isEnd(false) {
        memset(next, 0, sizeof(next));
    }

    void insert(string word) {
        Trie *temp = this;
        for (char &ch: word) {
            if (!temp->next[ch - 'a']) temp->next[ch - 'a'] = new Trie();
            temp = temp->next[ch - 'a'];
        }
        temp->isEnd = true;
    }

    Trie *getNext(char ch) {
        return next[ch - 'a'];
    }

    bool ifEndState() {
        return isEnd;
    }

    void turnIsEnd() {
        isEnd = !isEnd;
    }
};

class Solution {
private:
    int m, n;
    char s[12];
    vector<string> ret;
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        m = board.size(), n = board[0].size();
        Trie t;
        for (string &str: words) t.insert(str);
        for (int i{0}; i < m; ++i) {
            for (int j{0}; j < n; ++j) {
               if (t.getNext(board[i][j])) dfs(board, i, j, &t, 0);
            }
        }
        return ret;
    }

    void dfs(vector<vector<char>> &board, int x, int y, Trie *t, int idx) {
        Trie *nxt{t->getNext(board[x][y])};
        if (nxt) {
            s[idx] = board[x][y];
            if (nxt->ifEndState()) {
                nxt->turnIsEnd();
                ret.emplace_back(&s[0], &s[idx + 1]);
            }
            board[x][y] = 0;
            if (x > 0 && board[x - 1][y]) dfs(board, x - 1, y, t->getNext(s[idx]), idx + 1);
            if (y > 0 && board[x][y - 1]) dfs(board, x, y - 1, t->getNext(s[idx]), idx + 1);
            if (x + 1 < m && board[x + 1][y]) dfs(board, x + 1, y, t->getNext(s[idx]), idx + 1);
            if (y + 1 < n && board[x][y + 1]) dfs(board, x, y + 1, t->getNext(s[idx]), idx + 1);
            board[x][y] = s[idx];
        }
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board{{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words{"oath","pea","eat","rain"};
    vector<string> result = solution.findWords(board, words);
    return 0;
}
