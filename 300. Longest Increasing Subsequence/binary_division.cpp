#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0;
        int tails[n];

        for (int &num: nums) {
            int i = 0, j = res;
            while (i < j) {
                int &&m = (i + j) / 2;
                if (tails[m] < num) i = m + 1;
                else j = m;
            }
            tails[i] = num;
            if (res == j) ++res;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{3,5,6,2,5,4,19,5,6,7,12};
    int result = solution.lengthOfLIS(nums);
    cout << result;
    return 0;
}
