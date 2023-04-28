#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestStrChain(vector<string> &words) {
        int size = words.size();
        int ret{};
        unordered_map<string, int> um;
        sort(words.begin(), words.end(), [](string &s1, string &s2) { return s1.size() < s2.size(); });
        for (int i{}; i < size; ++i) {
            string &str{words[i]};
            um[str] = 1;
            for (int j{}; j < str.size(); ++j) {
                string &&temp{str.substr(0, j) + str.substr(j + 1)};
                auto iter = um.find(temp);
                if (iter != um.end())
                    um[words[i]] = max(um[str], iter->second + 1);
            }
            ret = max(um[str], ret);
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<string> words{"xbc","pcxbcf","xb","cxbc","pcxbc"};
    int result = solution.longestStrChain(words);
    cout << result;
    return 0;
}
