#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        ++n;
        int countFlag = 1, idx = 0;
        vector<int> res(n);
        for (int i = 1; i < n; ++i) {
            res[i] = 1 + res[idx];
            if (++idx == countFlag) {
                countFlag *= 2;
                idx = 0;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> result = solution.countBits(25);
    return 0;
}