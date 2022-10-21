#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (size1 > size2) return findMedianSortedArrays(nums2, nums1);
        int pivot1, pivot2;
        int flag1 = -1;
        int flag2 = -1;
        int mode = (size1 + size2) % 2;
        int deleteNum = (size1 + size2) / 2 - !mode;

        if (!size1) {
            if (mode) return nums2[size2 / 2];
            else return (double) (nums2[size2 / 2 - 1] + nums2[size2 / 2]) / 2.0;
        }

        while (deleteNum > 0) {
            if (flag1 == size1 - 1) {
                flag2 += deleteNum;
                break;
            }
            pivot1 = flag1 + (deleteNum + 1) / 2 < size1 ? flag1 + (deleteNum + 1) / 2 : size1 - 1;
            pivot2 = deleteNum == 1 ? flag2 + 1 : flag2 + deleteNum - pivot1 + flag1;

            if (nums1[pivot1] > nums2[pivot2]) {
                deleteNum -= pivot2 - flag2;
                flag2 = pivot2;
            } else {
                deleteNum -= pivot1 - flag1;
                flag1 = pivot1;
            }
        }

        if (mode) {
            if (flag1 < size1 - 1) {
                return (double) nums1[flag1 + 1] < nums2[flag2 + 1] ? nums1[flag1 + 1] : nums2[flag2 + 1];
            } else {
                return (double) nums2[flag2 + 1];
            }
        } else {
            double result = 0;
            size1 = size1 - flag1 - 1;
            size2 = size2 - flag2 - 1;
            for (int i = 0; i < 2; ++i) {
                if (size1 && size2) {
                    if (nums1[flag1 + 1] < nums2[flag2 + 1]) {
                        result += nums1[flag1 + 1];
                        --size1;
                        ++flag1;
                    } else {
                        result += nums2[flag2 + 1];
                        --size2;
                        ++flag2;
                    }
                } else if (!size1) {
                    result += nums2[flag2 + 1];
                    --size2;
                    ++flag2;
                } else {
                    result += nums1[flag1 + 1];
                    --size1;
                    ++flag1;
                }
            }
            return result / 2.0;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums1{3, 4};
    vector<int> nums2{1, 2, 5, 6, 7};
    double output = solution.findMedianSortedArrays(nums1, nums2);
    cout << output << endl;
}
