#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        else return !(n & (n - 1));
    }
};

int main() {
    Solution solution;
    bool result = solution.isPowerOfTwo(-16);
    cout << result;
    return 0;
}
