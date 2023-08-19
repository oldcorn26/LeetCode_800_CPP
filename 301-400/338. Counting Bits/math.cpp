#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n+1);
        for (int i{1}; i <= n; ++i) {
            ret[i] = i % 2 ? ret[i-1] + 1 : ret[i/2];
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> result = solution.countBits(25);
    return 0;
}