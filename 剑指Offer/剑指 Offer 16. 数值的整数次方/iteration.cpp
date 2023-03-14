#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1) return 1;
        else if (n < 0) return myPow(1/x, -(n+1)) / x;
        double ret{x}, temp{1};
        while (n / 2) {
            if (n % 2) temp *= ret;
            n >>= 1;
            ret *= ret;
        }
        return ret * temp;
    }
};

int main() {
    Solution solution;
    return 0;
}
