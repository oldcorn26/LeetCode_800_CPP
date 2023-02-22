#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class WordDictionary {
private:
    bool isEnd;
    WordDictionary *next[26];
public:
    WordDictionary(): isEnd{false} {
        memset(next, 0, sizeof(next));
    }

    void addWord(string word) {
        WordDictionary *temp = this;
        for (char &ch: word) {
            if (!temp->next[ch - 'a']) temp->next[ch - 'a'] = new WordDictionary();
            temp = temp->next[ch - 'a'];
        }
        temp->isEnd = true;
    }

    bool search(const string word) {
        WordDictionary *temp = this;
        for (int i{0}; i < word.size(); ++i) {
            if (word[i] == '.') return dfs(temp, word, i);
            if (!temp->next[word[i] - 'a']) return false;
            temp = temp->next[word[i] - 'a'];
        }
        return temp->isEnd;
    }

    bool dfs(WordDictionary *head, const string &word, int idx) {
        if (!head) return false;
        if (idx == word.size()) return head->isEnd;
        if (word[idx] != '.') return dfs(head->next[word[idx] - 'a'], word, idx + 1);
        for (int i{0}; i < 26; ++i) {
            if (!head->next[i]) continue;
            if (dfs(head->next[i], word, idx + 1)) return true;
        }
        return false;
    }
};

int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("a");
    wordDictionary.addWord("a");
    wordDictionary.addWord("mad");
    cout << wordDictionary.search(".") << endl; // 返回 1
    cout << wordDictionary.search("a") << endl; // 返回 1
    cout << wordDictionary.search("aa") << endl; // 返回 0
    cout << wordDictionary.search("a") << endl; // 返回 1
    cout << wordDictionary.search(".a") << endl; // 返回 0
    cout << wordDictionary.search("a.") << endl; // 返回 0
    return 0;
}
