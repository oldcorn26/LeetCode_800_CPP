#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {

        int ret{0};

        for (int i{0}; i < 32 && n > 0; ++i) {
            ret += n & 1;
            n >>= 1;
        }

        return ret;
    }
};

int main() {
    Solution solution;
    uint32_t result = solution.hammingWeight(0b00000010100101000001111010011100);
    cout << result;
    return 0;
}
