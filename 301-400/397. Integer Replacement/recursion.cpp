#include <iostream>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if (n < 4) return n - 1;
        if (n % 2) {
            int plus = integerReplacement(n / 2 + 1) + 2;
            int subtract = integerReplacement(n / 2) + 2;
            return plus > subtract ? subtract : plus;
        } else return integerReplacement(n / 2) + 1;
    }
};

int main() {
    Solution solution;
    int result = solution.integerReplacement(7);
    cout << result;
    return 0;
}