#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> ret(k);
        for (int i{0}; i <= k; ++i) {
            if (nums1.size() < i || nums2.size() < k-i) continue;
            vector<int> &&mono1{monotonicStack(nums1, i)};
            vector<int> &&mono2{monotonicStack(nums2, k - i)};
            mergeVec(ret, mono1, mono2);
        }
        return ret;
    }

    void mergeVec(vector<int> &ret, vector<int> &nums1, vector<int> &nums2) {
        char flag{};
        int i1{0}, i2{0};
        for (int i{0}; i < ret.size(); ++i) {
            int comFlag{compare(nums1, i1, nums2, i2)};
            int max{comFlag > 0 ? nums1[i1++] : nums2[i2++]};
            if (flag) ret[i] = max;
            else if (ret[i] > max) return;
            else if (ret[i] < max) {
                ret[i] = max;
                flag = 1;
            }
        }
    }

    int compare(vector<int> &one, int index1, vector<int> &two, int index2) {
        int size1 = one.size(), size2 = two.size();
        while (index1 < size1 && index2 < size2) {
            int tag{one[index1++] - two[index2++]};
            if (tag != 0) return tag;
        }
        return (size1 - index1) - (size2 - index2);
    }

    vector<int> monotonicStack(vector<int> &num, int len) {
        if (len == 0) return {};
        else if (len == num.size()) return num;
        int deleteNum = num.size() - len;
        int retIdx{1};
        vector<int> ret(len);
        ret[0] = num[0];
        for (int i{1}; i < num.size(); ++i) {
            while (retIdx && deleteNum > 0 && ret[retIdx-1] < num[i]) {
                deleteNum--;
                retIdx--;
            }
            if (retIdx < len) ret[retIdx++] = num[i];
            else deleteNum--;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums1{2,5,6,4,4,0};
    vector<int> nums2{7,3,8,0,6,5,7,6,2};
    vector<int> result = solution.maxNumber(nums1, nums2, 15);
    return 0;
}