#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        int noDup{};
        string nStr{to_string(n)};
        vector<int> flag(10);
        int digitLen{static_cast<int>(nStr.size())};
        for (int i{1}; i < digitLen; ++i)
            noDup += 9 * A(9, i-1);
        for (int i{}; i < digitLen; ++i) {
            int iDigit = nStr[i] - '0';
            int freeNum{freeNumberLessThanN(flag, iDigit)};
            if (i == 0) freeNum--;
            for (int j{1}; j <= freeNum; ++j)
                noDup += A(9-i, digitLen-i-1);
            if (flag[iDigit]) break;
            flag[iDigit] = 1;
        }
        int nValid{freeNumberLessThanN(flag, 10) == 10 - digitLen};
        return n-noDup-nValid;
    }

    int freeNumberLessThanN(vector<int> &flag, int N) {
        int ret{};
        while (--N >= 0)
            ret += flag[N] == 0;
        return ret;
    }

    int A (int n, int i) {
        int ret{1};
        while (--i >= 0)
            ret *= n-i;
        return ret;
    }
};

int main() {
    Solution solution;
    int result = solution.numDupDigitsAtMostN(999);
    cout << result;
    return 0;
}
