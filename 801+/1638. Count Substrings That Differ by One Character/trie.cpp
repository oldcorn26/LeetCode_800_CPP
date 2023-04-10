class Trie {
public:
    Trie() {
        memset(next, 0, sizeof(next));
    }

    void addSubstring(string &word) {
        Trie *temp{this};
        for (char &ch: word) {
            Trie* &nxt{temp->next[ch-'a']};
            if (!nxt)
                nxt = new Trie();
            temp = nxt;
            temp->count++;
        }
    }

    Trie *getChild(char ch) const {
        return next[ch - 'a'] ? next[ch - 'a'] : nullptr;
    }

    int getCount() const {
        return count;
    }
private:
    int count{};
    Trie *next[26];
};

class Solution {
private:
    int ret{};
    Trie *sTrie;
    Trie *tTrie;
public:
    int countSubstrings(string s, string t) {
        sTrie = new Trie();
        tTrie = new Trie();
        for (int i{}; i < s.size(); ++i) {
            string &&temp{s.substr(i)};
            sTrie->addSubstring(temp);
        }
        for (int i{}; i < t.size(); ++i) {
            string &&temp{t.substr(i)};
            tTrie->addSubstring(temp);
        }
        dfs(sTrie, tTrie, false);
        return ret;
    }

    void dfs(const Trie *s, const Trie *t, bool mustSame) {
        vector<Trie*> sChild(26);
        vector<Trie*> tChild(26);
        for (int i{}; i < 26; ++i) {
            sChild[i] = s->getChild(i + 'a');
            tChild[i] = t->getChild(i + 'a');
            if (!sChild[i] || !tChild[i]) continue;
            if (mustSame) ret += sChild[i]->getCount() * tChild[i]->getCount();
            dfs(sChild[i], tChild[i], mustSame);
        }
        if (!mustSame) {
            for (int i{}; i < 26; ++i) {
                if (!sChild[i]) continue;
                for (int j{}; j < 26; ++j) {
                    if (i == j || !tChild[j]) continue;
                    ret += sChild[i]->getCount() * tChild[j]->getCount();
                    dfs(sChild[i], tChild[j], true);
                }
            }
        }
    }
};
