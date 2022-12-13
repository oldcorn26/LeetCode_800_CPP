#include <iostream>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        int n = s1.size();
        bool f[n][n][n+1];

        for (int i{0}; i < n; ++i) {
            for (int j{0}; j < n; ++j) {
                f[i][j][1] = s1[i] == s2[j];
            }
        }

        for (int len{2}; len <= n; ++len) {
            for (int i{0}; i + len <= n; ++i) {
                for (int j{0}; j + len <= n; ++j) {
                    f[i][j][len] = false;
                    for (int k = 1; k < len; k++) {
                        bool &&case1 = f[i][j][k] && f[i+k][j+k][len-k];
                        bool &&case2 = f[i][j+len-k][k] && f[i+k][j][len-k];
                        if (case1 || case2) f[i][j][len] = true;
                    }
                }
            }
        }
        return f[0][0][n];
    }
};

int main() {
    Solution solution;
    bool result = solution.isScramble("abcdbdacbdac","bdacabcdbdac");
    cout << result;
    return 0;
}