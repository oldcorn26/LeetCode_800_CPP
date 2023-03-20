#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ret{};
        for (int i{}; i < 32; ++i) {
            int count{};
            for (int j{}; j < nums.size(); ++j) {
                count = (count + ((nums[j] >> i) & 1)) % 3;
            }
            if (count) ret |= (1 << i);
        }
        return ret;
    }
};

int main() {
    Solution solution;
    return 0;
}
