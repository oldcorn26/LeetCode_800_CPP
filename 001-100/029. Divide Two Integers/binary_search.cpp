#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT32_MIN && abs(divisor) == 1) return divisor == 1 ? INT32_MIN : INT32_MAX;
        else if (divisor == INT32_MIN) return dividend == INT32_MIN ? 1 : 0;
        int flag{1}, ret{}, halfMin{INT32_MIN >> 1};
        if (dividend > 0) flag = -flag, dividend = -dividend;
        if (divisor > 0) flag = -flag, divisor = -divisor;
        if (dividend == 0 || dividend > divisor) return 0;
        while (dividend <= divisor) {
            int tempDiv{divisor};
            int moveBit{};
            while (tempDiv > halfMin && tempDiv + tempDiv >= dividend) {
                moveBit++;
                tempDiv += tempDiv;
            }
            dividend -= tempDiv;
            ret += 1 << moveBit;
        }
        return flag * ret;
    }
};

int main() {
    Solution solution;
    int result = solution.divide(10, 3);
    cout << result;
    return 0;
}
