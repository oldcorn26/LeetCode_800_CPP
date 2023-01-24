#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {

        int j{5000};
        int size = nums.size();
        vector<int> bucket(5001);
        for (int &i: nums) ++bucket[i];

        for (int i{1}; i < size; i += 2) {
            while (bucket[j] == 0) --j;
            nums[i] = j;
            --bucket[j];
        }
        for (int i{0}; i < size; i += 2) {
            while (bucket[j] == 0) --j;
            nums[i] = j;
            --bucket[j];
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,5,1,1,6,4};
    solution.wiggleSort(nums);
    return 0;
}
