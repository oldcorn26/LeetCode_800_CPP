#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        vector<int> res;
        for (int i = 0; i < size; ++i) {
            if (nums[i] != i + 1 && nums[i] != 0) {
                int temp = nums[i];
                nums[i] = 0;
                while (temp && nums[temp - 1] != temp) {
                    int temp1 = nums[temp - 1];
                    nums[temp - 1] = temp;
                    temp = temp1;
                }
            }
        }
        for (int i = 0; i < size; ++i){
            if (!nums[i]) res.emplace_back(i + 1);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums{4,3,2,7,8,2,3,1};
    vector<int> result = solution.findDisappearedNumbers(nums);
    return 0;
}