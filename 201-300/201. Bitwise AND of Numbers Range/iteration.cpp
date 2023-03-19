#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (right - left >= INT32_MAX) return 0;
        int ret{};
        long long crtPer{1};
        int interval{right - left + 1};
        for (int i{}; i < 32; ++i) {
            int mask{1 << i};
            if (crtPer >= interval && left & mask && right & mask) ret |= mask;
            crtPer *= 2;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    return 0;
}
