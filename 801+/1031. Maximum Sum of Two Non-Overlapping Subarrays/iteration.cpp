#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int size = nums.size();
        int ret{INT32_MIN};
        vector<int> vec1(size - firstLen + 1);
        for (int i{}, sum{}; i < size; ++i) {
            while (i + 1 < firstLen)
                sum += nums[i++];
            sum += nums[i] - (i - firstLen >= 0 ? nums[i - firstLen] : 0);
            vec1[i - firstLen + 1] = sum;
        }
        ret = findMaxSum(vec1, nums, firstLen, secondLen);
        reverse(vec1.begin(), vec1.end());
        reverse(nums.begin(), nums.end());
        ret = max(ret, findMaxSum(vec1, nums, firstLen, secondLen));
        return ret;
    }

    int findMaxSum(vector<int> &vec1, vector<int> &nums, int firstLen, int secondLen) {
        int ret{INT32_MIN};
        int maxFirst{INT32_MIN};
        for (int i{firstLen}, sum{}; i < nums.size(); ++i) {
            while (i + 1 < firstLen + secondLen)
                sum += nums[i++];
            sum += nums[i] - (i != firstLen + secondLen - 1 ? nums[i - secondLen] : 0);
            maxFirst = max(maxFirst, vec1[i - firstLen - secondLen + 1]);
            ret = max(ret, maxFirst + sum);
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{3,8,1,3,2,1,8,9,0};
    int result = solution.maxSumTwoNoOverlap(nums, 3, 2);
    cout << result;
    return 0;
}
