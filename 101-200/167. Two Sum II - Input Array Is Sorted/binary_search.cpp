#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int endIdx{static_cast<int>(numbers.size()) - 1};
        vector<int> ret(2, 1);

        for (int i{0}; i < endIdx; ++i) {
            int searchIdx{binarySearch(numbers, i + 1, endIdx, target - numbers[i])};
            if (searchIdx != -1) {
                ret[0] += i;
                ret[1] += searchIdx;
                break;
            }
        }

        return ret;
    }

    int binarySearch(vector<int> &nums, int sta, int end, int &&tar) {
        int l{sta}, r{end};
        while (l < r) {
            int &&m{(l + r) / 2};
            if (nums[m] == tar) return m;
            else if (nums[m] < tar) l = m + 1;
            else r = m - 1;
        }
        return nums[l] == tar ? l : -1;
    }
};

int main() {
    Solution solution;
    vector<int> numbers{2,3,4};
    vector<int> result = solution.twoSum(numbers, 6);
    return 0;
}
