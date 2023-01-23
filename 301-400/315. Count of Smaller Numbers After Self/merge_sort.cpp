#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> ret;
public:
    vector<int> countSmaller(vector<int> &nums) {

        int size = nums.size();
        vector<pair<int, int>> unordered(size);

        ret = vector<int>(size);
        for (int i{0}; i < size; ++i) unordered[i] = {nums[i], i};
        mergeSort(unordered, 0, nums.size() - 1);

        return ret;
    }

    void mergeSort(vector<pair<int, int>> &unordered, int sta, int end) {
        if (sta == end) return;

        int &&mid{(sta + end) / 2};
        int lIdx{mid - sta}, rIdx{end - sta}, unoIdx{end};

        mergeSort(unordered, sta, mid);
        mergeSort(unordered, mid + 1, end);
        vector<pair<int, int>> backup(unordered.begin() + sta, unordered.begin() + end + 1);
        while (unoIdx >= sta) {
            int lNum{lIdx >= 0 ? backup[lIdx].first : INT32_MIN};
            int rNum{rIdx > mid - sta ? backup[rIdx].first : INT32_MIN};
            pair<int, int> &max{lNum > rNum ? backup[lIdx--] : backup[rIdx--]};
            ret[max.second] += lNum > rNum ? rIdx - mid + sta : 0;
            unordered[unoIdx--] = max;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{-1,-1};
    vector<int> result = solution.countSmaller(nums);
    return 0;
}
