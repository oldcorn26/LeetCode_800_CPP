#include <iostream>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int ret{10}, crt{9};
        for (int i{1}; i < n; ++i) {
            crt *= 10 - i;
            ret += crt;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    int result = solution.countNumbersWithUniqueDigits(5);
    cout << result;
    return 0;
}
