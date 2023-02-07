#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {

        long long sta{0}, end{0};

        for (int &i : nums) {
            end += i;
            sta = i > sta ? i : sta;
        }
        
        while (sta < end) {
            long long mid{(sta + end) >> 1};
            if (check(nums, mid, m)) {
                end = mid;
            } else {
                sta = mid + 1;
            }
        }

        return sta;
    }

    bool check(vector<int> &nums, int x, int m) {
        long long sum = 0;
        int cnt = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum + nums[i] > x) {
                ++cnt;
                sum = 0;
            }
            sum += nums[i];
        }
        return cnt <= m;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,4,4};
    int result = solution.splitArray(nums, 3);
    cout << result;
    return 0;
}
