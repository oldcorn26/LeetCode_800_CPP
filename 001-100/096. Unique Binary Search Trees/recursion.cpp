#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (!n || n == 1) return 1;
        else if (n == 2) return 2;
        else if (n == 3) return 5;

        int res = 0;
        for (int i = 0; i < n / 2; ++i) {
            res += numTrees(i) * numTrees(n - i  - 1);
        }

        if (n % 2) {int &&temp = numTrees(n / 2); return res * 2 + temp * temp;}
        else return res * 2;
    }
};

int main() {
    Solution solution;
    int result = solution.numTrees(3);
    cout << result;
    return 0;
}
