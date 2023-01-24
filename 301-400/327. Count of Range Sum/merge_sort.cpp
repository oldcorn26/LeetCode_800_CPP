#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {

        int size = nums.size();
        long sum{0};
        vector<long> sums(size + 1);

        for (int i{1}; i <= size; ++i) {
            sum += nums[i - 1];
            sums[i] = sum;
        }

        return mergeSortHelper(sums, lower, upper, 0, size);
    }

    int mergeSortHelper(vector<long> &sums, int lo, int up, int sta, int end) {

        if (sta == end) return 0;

        int &&mid{(sta + end) / 2};
        int jL{mid + 1}, jR{mid + 1};
        int ret{mergeSortHelper(sums, lo, up, sta, mid) +
                mergeSortHelper(sums, lo, up, mid + 1, end)};

        for (int i{sta}; i <= mid; ++i) {
            while (jL <= end && sums[jL] - sums[i] < lo) ++jL;
            jR = jR > jL ? jR : jL;
            while (jR <= end && sums[jR] - sums[i] <= up) ++jR;
            ret += jR - jL;
        }

        // Merge Sort
        int left{0}, right{mid + 1};
        vector<long> backup(sums.begin() + sta, sums.begin() + mid + 1);
        for (int i{sta}; i <= end; ++i) {
            if (right > end || (left < backup.size() && backup[left] < sums[right])) sums[i] = backup[left++];
            else sums[i] = sums[right++];
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{-2,5,-1};
    int result = solution.countRangeSum(nums, -2, 2);
    cout << result;
    return 0;
}
