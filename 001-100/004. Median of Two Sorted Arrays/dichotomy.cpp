#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);

        int deleteNum{(m + n + 1) / 2};
        if (deleteNum == 0) return 0;
        if (m == 0) return n%2 ? nums2[deleteNum-1] : (nums2[deleteNum-1]+nums2[deleteNum])*0.5;
        int sta{}, end{m - 1};
        while (sta < end) {
            int idx1{(sta + end + 1) / 2};
            int idx2{deleteNum - idx1 - 2};
            int L1{nums1[idx1]};
            int R2{nums2[idx2+1]};
            if (L1 > R2) end = idx1 - 1;
            else sta = idx1;
        }
        int idx2{deleteNum - sta - 2};
        if (sta == 0 && nums1[0] > nums2[idx2+1])
            sta--, idx2++;
        int LMax{max(sta >= 0 ? nums1[sta] : INT32_MIN, idx2 >= 0 ? nums2[idx2] : INT32_MIN)};
        int RMin{min(sta+1 == m ? INT32_MAX : nums1[sta+1], idx2+1 == n ? INT32_MAX : nums2[idx2+1])};
        if ((m+n) % 2) return LMax;
        else return (LMax+RMin) * 0.5;
    }
};

int main() {
    Solution solution;
    vector<int> nums1{3, 4};
    vector<int> nums2{1, 2, 5, 6, 7};
    double output = solution.findMedianSortedArrays(nums1, nums2);
    cout << output << endl;
}
