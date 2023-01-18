#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {

        if (n == 1) return true;
        else if (n == 0 || n % 2) return false;

        if (n % 4) return isPowerOfTwo(n / 2);
        else return isPowerOfTwo(n / 4);
    }
};

int main() {
    Solution solution;
    bool result = solution.isPowerOfTwo(8);
    cout << result;
    return 0;
}
