#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int splitArray(vector<int> &nums, int m) {

        int size = nums.size();
        vector<vector<long long>> f(size + 1, vector<long long>(m + 1, LLONG_MAX));
        vector<long long> sub(size + 1);

        for (int i = 0; i < size; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }

        f[0][0] = 0;
        for (int i{1}; i <= size; ++i) {
            for (int j{1}; j <= min(i, m); ++j) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return (int)f[size][m];
    }
};

int main() {
    Solution solution;
    vector<int> nums{7,2,5,10,8};
    int result = solution.splitArray(nums, 2);
    cout << result;
    return 0;
}
