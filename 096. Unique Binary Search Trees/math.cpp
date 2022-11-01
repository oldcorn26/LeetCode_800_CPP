#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        long long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};

int main() {
    Solution solution;
    int result = solution.numTrees(3);
    cout << result;
    return 0;
}
