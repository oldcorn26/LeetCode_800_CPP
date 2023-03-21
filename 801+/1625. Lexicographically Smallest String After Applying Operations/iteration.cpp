#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        queue<string> q{{s}};
        unordered_set<string> vis{{s}};
        string ret{s};
        while (!q.empty()) {
            s = q.front();
            q.pop();
            ret = min(ret, s);
            string t1{s};
            for (int i{1}; i < n; i += 2)
                t1[i] = (t1[i] - '0' + a) % 10 + '0';
            string &&t2{s.substr(n - b) + s.substr(0, n - b)};
            for (auto &t: {t1, t2}) {
                if (!vis.count(t)) {
                    vis.insert(t);
                    q.emplace(t);
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    return 0;
}
