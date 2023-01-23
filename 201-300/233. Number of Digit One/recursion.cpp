#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {

        if (n == 0) return 0;
        else if (n <= 9) return 1;

        int highBit{n}, bitNum{1};
        while (highBit > 9) {
            ++bitNum;
            highBit /= 10;
        }
        int &&power{powerOfTen(bitNum)};
        int &&restNum{n - highBit * power};
        int temp{highBit > 1 ? power : restNum + 1};

        return highBit * countDigitOne(power - 1) + countDigitOne(restNum) + temp;
    }

    int powerOfTen(int powerNum) {
        int ret{1};
        while (--powerNum) {
            ret *= 10;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    int result = solution.countDigitOne(213);
    cout << result;
    return 0;
}
