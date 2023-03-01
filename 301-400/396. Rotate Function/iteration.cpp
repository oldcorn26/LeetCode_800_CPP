#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int> &nums) {
        int size = nums.size();
        long long ret{0};
        int sum{0};
        int crt{0}, max{INT32_MIN};
        for (int i{0}; i < size; ++i) {
            ret += i * nums[i];
            sum += nums[i];
        }
        for (int i{0}; i < size; ++i) {
            crt += size * nums[i] - sum;
            if (crt < max) continue;
            max = crt;
        }
        return ret + max;
    }
};

int main() {
    Solution solution;
    vector<int> nums{4,3,2,6};
    int result = solution.maxRotateFunction(nums);
    cout << result;
    return 0;
}
