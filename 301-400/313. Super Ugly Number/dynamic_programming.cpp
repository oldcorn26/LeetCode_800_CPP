#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {

        int priSize = primes.size();
        vector<int> p(priSize);
        vector<int> dp(n);
        vector<int> tempRes(priSize);

        dp[0] = 1;

        for (int i{1}; i < n; ++i) {
            int minRes{INT32_MAX};
            for (int j{0}; j < priSize; ++j) {
                long long ll = (long long) dp[p[j]] * primes[j];
                if (ll > INT32_MAX) continue;
                tempRes[j] = (int) ll;
                minRes = min(minRes, tempRes[j]);
            }
            for (int j{0}; j < priSize; ++j) {
                if (tempRes[j] == minRes) ++p[j];
            }
            dp[i] = minRes;
        }

        return dp[n - 1];
    }
};

int main() {
    Solution solution;
    vector<int> primes{2,3,5,7};
    int result = solution.nthSuperUglyNumber(5911, primes);
    cout << result;
    return 0;
}
