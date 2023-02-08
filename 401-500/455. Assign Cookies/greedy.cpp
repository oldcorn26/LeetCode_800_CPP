#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {

        int ret{0}, sIdx{0};
        int gSize = g.size(), sSize = s.size();

        if (sSize == 0) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i{0}; i < gSize; ++i) {
            while (sIdx < sSize && g[i] > s[sIdx]) ++sIdx;
            if (sIdx == sSize) return ret + (g[i] == s[sIdx - 1]);
            ++ret, ++sIdx;
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> g{1,2,3};
    vector<int> s{3};
    int result = solution.findContentChildren(g, s);
    cout << result;
    return 0;
}
