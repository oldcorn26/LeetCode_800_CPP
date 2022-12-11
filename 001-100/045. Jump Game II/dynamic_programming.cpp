#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int min{0}, max{0}, step{0};
        while (max + 1 < nums.size()) {
            int i{min}, preMax{max};
            for (; i <= preMax; ++i) {
                max = i + nums[i] > max ? i + nums[i] : max;
            }
            min = preMax + 1;
            ++step;
        }
        return step;
    }
};

int main() {
    Solution solution;
    vector<int> nums{2,3,1,1,4};
    int result = solution.jump(nums);
    cout << result;
    return 0;
}