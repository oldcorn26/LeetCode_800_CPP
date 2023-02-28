#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int ret{0};
    int wSize;
    vector<int> wScore;
    vector<vector<int>> wCount;
public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
        vector<int> count(26);
        wScore = vector<int>(words.size());
        wCount = vector<vector<int>>(words.size(), vector<int>(26));
        wSize = words.size();
        for (char &ch: letters) count[ch - 'a']++;
        for (int i{0}; i < words.size(); ++i) {
            for (char &ch: words[i]) {
                wCount[i][ch - 'a']++;
                wScore[i] += score[ch - 'a'];
            }
        }
        dfs(0, count, 0);
        return ret;
    }

    void dfs(int idx, vector<int> &rest, int crtScore) {
        for (int i{idx}; i < wSize; ++i) {
            if (!subVec(rest, wCount[i])) continue;
            dfs(i + 1, rest, crtScore + wScore[i]);
            addVec(rest, wCount[i]);
        }
        ret = max(ret, crtScore);
    }

    bool subVec(vector<int> &rest, vector<int> &crt) {
        for (int i{0}; i < 26; ++i) if (rest[i] < crt[i]) return false;
        for (int i{0}; i < 26; ++i) rest[i] -= crt[i];
        return true;
    }

    void addVec(vector<int> &rest, const vector<int> &crt) {
        for (int i{0}; i < 26; ++i) rest[i] += crt[i];
    }
};

int main() {
    Solution solution;
    vector<string> words{"dog","cat","dad","good"};
    vector<char> letters{'a','a','c','d','d','d','g','o','o'};
    vector<int> score{1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    int result = solution.maxScoreWords(words, letters, score);
    cout << result;
    return 0;
}
