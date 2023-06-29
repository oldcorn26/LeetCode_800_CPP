#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo{1, 1};
public:
    int numTrees(int n) {
        if (n < memo.size())
            return memo[n];
        int ret{};
        for (int i{}; i < n; ++i) {
            ret += numTrees(i) * numTrees(n - i - 1);
        }
        memo.push_back(ret);
        return ret;
    }
};

int main() {
    Solution solution;
    int result = solution.numTrees(3);
    cout << result;
    return 0;
}
