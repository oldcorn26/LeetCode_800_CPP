#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto get = [](vector<int> &vec, int i) {
            if (i < 0)
                return INT32_MIN;
            else if (i >= vec.size())
                return INT32_MAX;
            else
                return vec[i];
        };
        int l1 = 0, l2 = 0;
        int r1 = nums1.size()-1, r2 = nums2.size()-1;
        int deleteNum = (nums1.size() + nums2.size() - 1) / 2;
        while (deleteNum > 0) {
            int crtDelete = (deleteNum + 1) / 2;
            int lNum1 = get(nums1, l1 + crtDelete - 1), lNum2 = get(nums2, l2 + crtDelete - 1);
            int rNum1 = get(nums1, r1 - crtDelete + 1), rNum2 = get(nums2, r2 - crtDelete + 1);
            if (lNum1 < lNum2) {
                int lDel1 = min(static_cast<int>(nums1.size()-l1), crtDelete);
                l1 += lDel1;
                l2 += crtDelete - lDel1;
            } else {
                int lDel2 = min(static_cast<int>(nums2.size()-l2), crtDelete);
                l1 += crtDelete - lDel2;
                l2 += lDel2;
            }
            if (rNum1 > rNum2) {
                int rDel1 = min(r1+1, crtDelete);
                r1 -= rDel1;
                r2 -= crtDelete - rDel1;
            } else {
                int rDel2 = min(r2+1, crtDelete);
                r1 -= crtDelete - rDel2;
                r2 -= rDel2;
            }
            deleteNum -= crtDelete;
        }
        return (double) (min(get(nums1, l1), get(nums2, l2)) + max(get(nums1, r1), get(nums2, r2))) / 2;
    }
};

int main() {
    Solution solution;
    vector<int> nums1{3, 4};
    vector<int> nums2{1, 2, 5, 6, 7};
    double output = solution.findMedianSortedArrays(nums1, nums2);
    cout << output << endl;
}
