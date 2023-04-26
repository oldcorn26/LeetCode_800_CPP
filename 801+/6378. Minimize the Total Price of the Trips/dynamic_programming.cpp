#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {

        vector<vector<int>> ways(n);
        vector<int> count(n);

        function<bool(int, int, int)> dfs = [&](int sn, int sta, int end) {
            if (sn == end) {
                count[sn]++;
                return true;
            }
            bool ret{false};
            for (int i: ways[sn]) {
                if (i == sta)
                    continue;
                ret = dfs(i, sn, end);
                if (ret)
                    break;
            }
            if (ret)
                count[sn]++;
            return ret;
        };

        function<pair<int, int>(int, int)> dp = [&](int crt, int p) -> pair<int, int> {
            if (ways[crt].size() == 1 && ways[crt][0] == p)
                return {count[crt]*price[crt], count[crt]*price[crt]/2};
            int crtNum{count[crt]*price[crt]};
            pair<int, int> ret{crtNum, crtNum/2};
            for (int i: ways[crt]) {
                if (i == p)
                    continue;
                auto nxt{dp(i, crt)};
                ret.first += min(nxt.first, nxt.second);
                ret.second += nxt.first;
            }
            return ret;
        };

        for (auto &edge: edges) {
            ways[edge[0]].emplace_back(edge[1]);
            ways[edge[1]].emplace_back(edge[0]);
        }

        for (auto &trip: trips)
            dfs(trip[0], -1, trip[1]);

        auto result{dp(0, -1)};

        return min(result.first, result.second);
    }
};

int main() {
    Solution solution;
    vector<vector<int>> edges{{0,1}, {1,2}, {1,3}};
    vector<int> prices{2,2,10,6};
    vector<vector<int>> trips{{0,3},{2,1},{2,3}};
    int result = solution.minimumTotalPrice(4, edges, prices, trips);
    cout << result;
    return 0;
}
