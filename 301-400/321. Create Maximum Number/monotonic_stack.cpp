#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> res;
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int &&deleteNum = nums1.size() + nums2.size() - k;
        int i = deleteNum <= nums2.size() ? 0 : deleteNum - nums2.size();
        res.resize(k);
        for (; i <= deleteNum && i <= nums1.size(); ++i) {
            vector<int> &&temp1 = removeKdigits(nums1, i);
            vector<int> &&temp2 = removeKdigits(nums2, deleteNum - i);
            findLargeNumber(res, temp1, temp2);
        }
        return res;
    }

    vector<int> removeKdigits(const vector<int> &nums, int k) {
        if (!k) return nums;

        int deleteNum{k}, &&resNum{static_cast<int>(nums.size() - k)};
        vector<int> res(resNum);
        if (k >= nums.size()) return {};

        stack<char> monStack;
        for (const int &i: nums) {
            while (!monStack.empty() && monStack.top() < i && deleteNum > 0) {
                --deleteNum;
                monStack.pop();
            }
            monStack.emplace(i);
        }
        while (monStack.size() > resNum) monStack.pop();
        for (int &&i = resNum - 1; i >= 0; --i) {
            res[i] = monStack.top();
            monStack.pop();
        }
        return res;
    }

    void findLargeNumber(vector<int> &res, vector<int> &candi1, vector<int> &candi2) {
        char flag{0};
        int resIdx{0}, candiIdx1{0}, candiIdx2{0};
        while (resIdx < res.size()) {
            int max;
            if (compare(candi1, candiIdx1, candi2, candiIdx2) > 0) max = candi1[candiIdx1++];
            else max = candi2[candiIdx2++];
            if (flag) res[resIdx] = max;
            else {
                if (res[resIdx] > max) return;
                else if (max > res[resIdx]) {
                    flag = 1;
                    res[resIdx] = max;
                }
            }
            ++resIdx;
        }
    }

    int compare(vector<int>& subsequence1, int index1, vector<int>& subsequence2, int index2) {
        int x = subsequence1.size(), y = subsequence2.size();
        while (index1 < x && index2 < y) {
            int difference = subsequence1[index1] - subsequence2[index2];
            if (difference != 0) {
                return difference;
            }
            index1++;
            index2++;
        }
        return (x - index1) - (y - index2);
    }
};

int main() {
    Solution solution;
    vector<int> nums1{2,5,6,4,4,0};
    vector<int> nums2{7,3,8,0,6,5,7,6,2};
    vector<int> result = solution.maxNumber(nums1, nums2, 15);
    return 0;
}