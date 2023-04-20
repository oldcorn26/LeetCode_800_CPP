#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people) {
        unordered_map<string, int> sid;
        int m = req_skills.size();
        for (int i = 0; i < m; ++i)
            sid[req_skills[i]] = i; // 字符串映射到下标

        int n = people.size(), u = 1 << m;
        long long f[u];
        fill(f, f + u, (1LL << n) - 1);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            int mask = 0;
            for (auto &s: people[i]) // 把 people[i] 压缩成一个二进制数 mask[i]
                mask |= 1 << sid[s];
            for (int j = u - 1; j; --j) {
                auto r1 = f[j]; // 不选 mask
                auto r2 = f[j & ~mask] | (1L << i); // 选 mask
                f[j] = __builtin_popcountll(r1) < __builtin_popcountll(r2) ? r1 : r2;
            }
        }
        auto res = f[u - 1];

        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if ((res >> i) & 1)
                ans.push_back(i); // 所有在 res 中的下标
        return ans;
    }
};

int main() {
    return 0;
}
