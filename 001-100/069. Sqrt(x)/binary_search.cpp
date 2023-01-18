#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int sta{1}, end{x - 1 < 46340 ? x - 1 : 46340};

        while (sta < end) {
            int &&mid{(sta + end) / 2}, &&sqt{mid * mid};
            if (sqt == x) return mid;
            else if (sqt > x) end = mid - 1;
            else sta = mid + 1;
        }

        return sta * sta > x ? sta - 1 : sta;
    }
};

int main() {
    Solution solution;
    cout << solution.mySqrt(15);
    return 0;
}
