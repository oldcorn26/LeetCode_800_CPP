#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t ret = 0;

        for (int i = 0; i < 32 && n > 0; ++i) {
            ret |= (n & 1) << (31 - i);
            n >>= 1;
        }

        return ret;
    }
};

int main() {
    Solution solution;
    uint32_t result = solution.reverseBits(0b00000010100101000001111010011100);
    cout << result;
    return 0;
}
