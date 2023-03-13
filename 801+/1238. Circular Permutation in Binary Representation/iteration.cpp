#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int staIdx{0};
        vector<int> ret(1 << n);
        for (int i{1}; i < ret.size(); ++i) {
            ret[i] = ret[i - 1] ^ 1;
            if (ret[i] == start) staIdx = i;
            if (++i < ret.size()) {
                int idx{0};
                while (!(1 & (ret[i - 1] >> idx))) ++idx;
                ret[i] = ret[i - 1] ^ (1 << (idx + 1));
                if (ret[i] == start) staIdx = i;
            }
        }
        vector<int> final(ret.begin() + staIdx, ret.end());
        final.insert(final.end(), ret.begin(), ret.begin() + staIdx);
        return final;
    }
};

int main() {
    Solution solution;
    vector<int> result = solution.circularPermutation(4, 1);
    return 0;
}
