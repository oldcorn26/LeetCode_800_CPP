#include <iostream>
#include <vector>

using namespace std;

class StreamChecker {
private:
    int wordSize;
    vector<string> words;
    vector<vector<int>> next;
    vector<int> prefix;
public:
    StreamChecker(vector<string> &words) : wordSize(words.size()), words(words) {
        next.resize(wordSize);
        prefix.resize(wordSize);
        for (int i{}; i < wordSize; ++i) {
            string &str{words[i]};
            next[i] = vector<int>(str.size());
            for (int j{1}, k{}; j < str.size(); ++j) {
                while (k > 0 && str[j] != str[k])
                    k = next[i][k - 1];
                if (str[j] == str[k])
                    k++;
                next[i][j] = k;
            }
        }
    }

    bool query(char letter) {
        bool ret{false};
        for (int i{}; i < wordSize; ++i) {
            int &pref{prefix[i]};
            string &str{words[i]};
            vector<int> &nxt{next[i]};
            while (pref > 0 && letter != str[pref])
                pref = nxt[pref-1];
            if (letter == str[pref])
                pref++;
            if (pref == str.size()) {
                ret = true;
                pref = pref > 2 ? nxt[pref-2] : 0;
                while (pref > 0 && letter != str[pref])
                    pref = nxt[pref-1];
                if (letter == str[pref])
                    pref++;
            }
        }
        return ret;
    }
};

int main() {
    vector<string> words{"cd", "f", "kl"};
    vector<char> q{'a','b','c','d','e','f','g','h','i','j','k','l'};
    StreamChecker sc(words);
    for (char &ch: q) {
        cout << ch << " " << sc.query(ch) << endl;
    }
    return 0;
}
