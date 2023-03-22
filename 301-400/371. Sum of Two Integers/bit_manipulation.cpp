#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int carry = (unsigned int) (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};

int main() {
    Solution solution;
    int result = solution.getSum(-2, 1);
    cout << result;
    return 0;
}
