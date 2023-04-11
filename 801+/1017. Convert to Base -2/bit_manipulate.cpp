#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0)
            return "0";
        int flag{1};
        string ans{};
        while (n) {
            if (n % 2) {
                ans.push_back('1');
                n -= flag;
            } else {
                ans.push_back('0');
            }
            flag *= -1;
            n >>= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution solution;
    string result = solution.baseNeg2(6);
    cout << result;
    return 0;
}
