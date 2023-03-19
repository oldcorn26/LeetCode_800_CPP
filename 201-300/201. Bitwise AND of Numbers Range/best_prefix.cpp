#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift{};
        while (m < n) {
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        return m << shift;
    }
};

int main() {
    Solution solution;
    return 0;
}
