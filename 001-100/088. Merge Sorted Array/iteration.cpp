#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i{static_cast<int>(nums1.size()) - 1};
        --m;
        while (--n >= 0) {
            while (m >= 0 && nums1[m] > nums2[n]) {
                swap(nums1[i--], nums1[m--]);
            }
            swap(nums1[i--], nums2[n]);
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums1{1,2,3,0,0,0};
    vector<int> nums2{2,5,6};
    solution.merge(nums1, 3, nums2, 3);
    return 0;
}