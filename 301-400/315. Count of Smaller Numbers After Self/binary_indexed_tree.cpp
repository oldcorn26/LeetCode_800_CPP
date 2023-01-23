#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int lowBit(int x) {
        return x & (-x);
    }

    void update(int i, vector<int> &C) {
        while (i < C.size()) {
            C[i]++;
            i += lowBit(i);
        }
    }

    int query(int i, vector<int> &C) {
        int ret{0};
        while (i > 0) {
            ret += C[i];
            i -= lowBit(i);
        }
        return ret;
    }

    vector<int> countSmaller(vector<int> &nums) {

        vector<int> ret(nums.size());
        vector<int> N(nums);

        // Sort and unique
        sort(N.begin(), N.end());
        N.erase(unique(N.begin(), N.end()), N.end());

        // key: number, value: i
        map<int, int> m;
        for (int j = 1; j < 1 + N.size(); ++j) {
            m[N[j - 1]] = j;
        }

        // traverse
        vector<int> C(N.size() + 1); //  C[i] is necessary, but A[i] not
        int i;
        for (int j = nums.size() - 1; j >= 0; --j) {
            i = m[nums[j]];
            update(i, C);
            if (i != 1) {
                ret[j] = query(i - 1, C);
            } else {
                ret[j] = 0;
            }
        }

        return ret;
    }
};


int main() {
    Solution solution;
    vector<int> nums{-1, -1};
    vector<int> result = solution.countSmaller(nums);
    return 0;
}
