#include <iostream>
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

    bool search(string word) {
        Trie *temp = this;
        for (char &ch: word) {
            if (!temp->next[ch - 'a']) return false;
            temp = temp->next[ch - 'a'];
        }
        return temp->isEnd;
    }

    bool startsWith(string prefix) {
        Trie *temp = this;
        for (char &ch: prefix) {
            if (!temp->next[ch - 'a']) return false;
            temp = temp->next[ch - 'a'];
        }
        return true;
    }
};

int main() {
    Trie* obj = new Trie();
    obj->insert("word");
    bool param_2 = obj->search("word");
    bool param_3 = obj->startsWith("wor");
    bool param_4 = obj->search("apple");
    cout << param_2 << " " << param_3 << " " << param_4;
    return 0;
}
