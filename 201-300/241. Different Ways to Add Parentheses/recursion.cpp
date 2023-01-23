#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return diffWaysToComputeHelper(expression, 0, expression.size() - 1);
    }

    vector<int> diffWaysToComputeHelper(string &s, int sta, int end) {

        vector<int> ret;
        for (int i{sta}; i <= end; ++i) {
            if (s[i] >= '0') continue;
            vector<int> &&left{diffWaysToComputeHelper(s, sta, i - 1)};
            vector<int> &&right{diffWaysToComputeHelper(s, i + 1, end)};
            for (int &j: left) {
                for (int &k: right) {
                    if (s[i] == '+') ret.emplace_back(j + k);
                    else if (s[i] == '-') ret.emplace_back(j - k);
                    else if (s[i] == '*') ret.emplace_back(j * k);
                }
            }
        }
        if (ret.size() == 0) {
            int ans{s[sta] - '0'};
            while (sta++ != end) ans = ans * 10 + s[sta] - '0';
            return {ans};
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> result = solution.diffWaysToCompute("2-1-1");
    return 0;
}
