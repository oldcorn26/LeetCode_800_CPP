#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    string b;
    unordered_map<string, int> map;

    int dfs(string &a, int cur) {

        int n = a.length();
        int ans{0x3f3f3f3f};
        char pre{0};

        if (n == 0) return 0;
        if (map.count(a + to_string(cur))) return map[a + to_string(cur)];

        //遍历手中球
        for (int i{0}; i < b.size(); ++i) {
            //如果当前球已经被取过，则跳过该球
            if (((cur >> i) & 1) == 1 || (pre && pre == b[i])) continue;
            pre = b[i];
            //遍历插入球位置
            for (int j{0}; j <= n; ++j) {
                //剪枝
                bool cutFlag{true};
                if (j > 0 && j < n && a[j] == a[j - 1] && a[j - 1] != b[i]) cutFlag = false;
                else if (j < n && a[j] == b[i]) cutFlag = false;
                if (cutFlag) continue;

                string s{};
                s += a.substr(0, j) + b[i];
                if (j != n) s += a.substr(j);

                //中心扩散搜索法删除
                int k{j};
                while (0 <= k && k < s.length()) {
                    char c{s[k]};
                    int l{k}, r{k};
                    while (l >= 0 && s[l] == c) l--;
                    while (r < s.length() && s[r] == c) r++;
                    if (r - l - 1 >= 3) {
                        s.erase(l + 1, r - l - 1);
                        k = l >= 0 ? l : r;
                    } else {
                        break;
                    }
                }

                ans = min(ans, dfs(s, (1 << i) | cur) + 1);
            }
        }
        map[a + to_string(cur)] = ans;

        return ans;
    }
    
public:
    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());
        b = hand;
        int ans{dfs(board, 1 << hand.size())};
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};

int main() {
    Solution solution;
    int result = solution.findMinStep("YRRYYRYRY", "RYRRR");
    cout << result;
    return 0;
}
