#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string fillWords(vector<string> &words, int bg, int ed, int maxWidth, bool lastLine = false) {
        int wordCount = ed - bg + 1;
        int spaceCount = maxWidth + 1 - wordCount;
        for (int i = bg; i <= ed; i++) {
            spaceCount -= words[i].size();
        }

        int spaceSuffix = 1;
        int spaceAvg = (wordCount == 1) ? 1 : spaceCount / (wordCount - 1);
        int spaceExtra = (wordCount == 1) ? 0 : spaceCount % (wordCount - 1);

        string ans;
        for (int i = bg; i < ed; i++) {
            ans += words[i];
            if (lastLine) {
                fill_n(back_inserter(ans), 1, ' ');
                continue;
            }
            fill_n(back_inserter(ans), spaceSuffix + spaceAvg + ((i - bg) < spaceExtra), ' ');
        }
        ans += words[ed];
        fill_n(back_inserter(ans), maxWidth - ans.size(), ' ');
        return ans;
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> ans;
        int cnt = 0;
        int bg = 0;
        for (int i = 0; i < words.size(); i++) {
            cnt += words[i].size() + 1;

            if (i + 1 == words.size() || cnt + words[i + 1].size() > maxWidth) {
                ans.push_back(fillWords(words, bg, i, maxWidth, i + 1 == words.size()));
                bg = i + 1;
                cnt = 0;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> words{"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> result = solution.fullJustify(words, 8);
    return 0;
}
