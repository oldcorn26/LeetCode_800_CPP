#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int &&xOR{x ^ y};
        int res = 0;
        while (xOR) {
            ++res;
            xOR &= xOR - 1;
        }
        return res;
    }
};

int main() {
    Solution solution;
    int result = solution.hammingDistance(3, 1);
    cout << result;
    return 0;
}