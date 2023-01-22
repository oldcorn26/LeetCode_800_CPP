#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left{0}, right{static_cast<int>(numbers.size()) - 1};

        while (left < right) {
            int &&sum{numbers[left] + numbers[right]};
            if (sum == target) break;
            else if (sum > target) --right;
            else ++left;
        }

        return {left + 1, right + 1};
    }
};

int main() {
    Solution solution;
    vector<int> numbers{2,3,4};
    vector<int> result = solution.twoSum(numbers, 6);
    return 0;
}
