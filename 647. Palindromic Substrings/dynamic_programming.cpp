#include <iostream>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size();
        int res{size};
        bool dp1[size], dp2[size];
        bool *pre{dp1}, *crt{dp2}, *temp;
        for (int j = 0; j < size; ++j) {
            for (int i = 0; i < j; ++i) {
                if (s[i] == s[j] && (i + 1 == j || pre[i + 1])) {
                    crt[i] = true;
                    ++res;
                } else crt[i] = false;
            }
            crt[j] = true;
            temp = crt;
            crt = pre;
            pre = temp;
        }
        return res;
    }
};

int main() {
    Solution solution;
    int result = solution.countSubstrings("aaa");
    cout << result;
    return 0;
}