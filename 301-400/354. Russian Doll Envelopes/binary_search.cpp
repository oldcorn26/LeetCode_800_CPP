#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {

        auto cmp = [](vector<int> &x, vector<int> &y) {
            return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0];
        };

        int size = envelopes.size();
        int ret{0};
        int tails[size];

        sort(envelopes.begin(), envelopes.end(), cmp);
        for (vector<int> &env: envelopes) {
            int i{0}, j{ret};
            while (i < j) {
                int &&m{(i + j) / 2};
                if (tails[m] < env[1]) i = m + 1;
                else j = m;
            }
            tails[i] = env[1];
            if (ret == j) ++ret;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> envelopes{{3,5},{7,8},{3,6},{3,10},{7,20},{17,3},{17,45}};
    int result = solution.maxEnvelopes(envelopes);
    cout << result;
    return 0;
}
