#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        if (nums.size() % 2 == 0) 
            return true;
        int XOR{};
        for (int num : nums) {
            XOR ^= num;
        }
        return XOR == 0;
    }
};

int main() {
    Solution solution;
    return 0;
}
