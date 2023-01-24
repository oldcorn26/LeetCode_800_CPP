#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int MOD{1337};
public:
    int superPow(int a, vector<int> &b) {
        return dfs(a, b, b.size() - 1);
    }

    int dfs(int &a, vector<int> &b, int end) {
        if (end == 0) return myPow(a, b[0]);
        return myPow(dfs(a, b, end - 1), 10) * myPow(a, b[end]) % MOD;
    }

    int myPow(int x, int n) {
        if (n == 0 || x == 1) return 1;
        int ans = 1;
        x %= MOD;
        while (n) {
            if (n & 1) ans = ans * x % MOD;
            x = x * x % MOD;
            n >>= 1;
        }
        return ans;
    }
};


int main() {
    Solution solution;
    vector<int> nums{2,0,0};
    int result = solution.superPow(2147483647, nums);
    cout << result;
    return 0;
}
