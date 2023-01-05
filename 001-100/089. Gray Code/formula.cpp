#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int &&retSize{1 << n};
        vector<int> ret(retSize);
        for (int i = 0; i < retSize; ++i) {
            ret[i] = (i >> 1) ^ i;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> result = solution.grayCode(2);
    cout << ((0 >> 1) ^ 0);
    return 0;
}