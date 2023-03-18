#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int ret{};
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        mergeSort(nums, 0, nums.size()-1);
        return ret;
    }

    void mergeSort(vector<int> &n, int sta, int end) {
        if (sta == end) return;
        int mid{(sta + end) / 2};
        int leftIdx{mid};
        int mergeL{}, mergeR{mid + 1 - sta};
        mergeSort(n, sta, mid);
        mergeSort(n, mid+1, end);
        vector<int> backup(n.begin()+sta, n.begin()+end+1);
        for (int i{sta}; i <= mid; ++i) {
            while (leftIdx+1 <= end && n[leftIdx+1] < n[i]) leftIdx++;
            ret += leftIdx - mid;
        }
        for (int i{sta}; i <= end; ++i) {
            int left{mergeL <= mid - sta ? backup[mergeL] : INT32_MAX};
            int right{mergeR <= end - sta ? backup[mergeR] : INT32_MAX};
            if (left < right) {
                n[i] = left;
                mergeL++;
            } else {
                n[i] = right;
                mergeR++;
            }
        }
    }
};

int main() {
    Solution solution;
    return 0;
}
