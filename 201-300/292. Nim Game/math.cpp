#include <iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main() {
    Solution solution;
    bool result = solution.canWinNim(500);
    cout << result;
    return 0;
}
