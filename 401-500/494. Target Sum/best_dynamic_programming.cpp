#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = 0;
        for (int &i: nums) sum += i;
        if (sum < target || (sum - target) % 2) return 0;
        int &&neg = (sum - target) / 2;
        vector<int> vec1(neg + 1), vec2(neg + 1);
        vec2[0] = 1;
        if (nums[0] <= neg) vec2[nums[0]] += 1;
        vector<int> *pCrt = &vec1, *pPre = &vec2, *temp;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= neg; ++j) {
                (*pCrt)[j] = (*pPre)[j] + (j - nums[i] < 0 ? 0 : (*pPre)[j - nums[i]]);
            }
            temp = pPre;
            pPre = pCrt;
            pCrt = temp;
        }
        return (*pPre)[neg];
    }
};

int main() {
    Solution solution;
    vector<int> nums{7,9,3,8,0,2,4,8,3,9};
    int result = solution.findTargetSumWays(nums, 0);
    cout << result << endl;
    return 0;
}