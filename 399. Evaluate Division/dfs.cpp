#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<string, int> visitedNode;
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        int eqlSize = equations.size(), qrySize = queries.size();
        unordered_multimap<string, pair<string, double>> hashMap;
        vector<double> res(qrySize);
        for (int i = 0; i < eqlSize; ++i) {
            hashMap.emplace(equations[i][0], make_pair(equations[i][1], values[i]));
            hashMap.emplace(equations[i][1], make_pair(equations[i][0], 1 / values[i]));
        }
        for (int i = 0; i < qrySize; ++i) {
            visitedNode.clear();
            res[i] = dfs(hashMap, queries[i][0], queries[i][1]);
        }
        return res;
    }

    double dfs(unordered_multimap<string, pair<string, double>> &map, string &sta, string &end) {
        auto [iter1, iter2] = map.equal_range(sta);
        if (sta == end && iter1 != iter2) return 1.0;
        if (visitedNode[sta]) return -1.0;
        visitedNode[sta] = 1;
        for (; iter1 != iter2; ++iter1) {
            double &iSS = iter1->second.second;
            if (iter1->second.first == end) return iSS;
            double &&temp = dfs(map, iter1->second.first, end);
            if (temp != -1.0) return temp * iSS;
        }
        return -1.0;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> equations{{"a","b"}, {"b","c"}};
    vector<double> values{2.0, 3.0};
    vector<vector<string>> queries{{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    vector<double> result = solution.calcEquation(equations, values, queries);
    return 0;
}