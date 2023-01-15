#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1.0) return 1;
        else if (n < 0) return 1 / (myPow(x,-(n + 1)) * x);

        double &&temp{myPow(x, n / 2)};
        if (n % 2) return x * temp * temp;
        else return temp * temp;
    }
};

int main() {
    Solution solution;
    double result = solution.myPow(1.00000, -2147483648);
    cout << result;
    return 0;
}
