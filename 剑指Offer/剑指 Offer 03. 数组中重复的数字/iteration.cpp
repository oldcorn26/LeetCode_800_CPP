#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> us;
        for (int &i: nums) {
            if (us.find(i) != us.end()) return i;
            us.emplace(i);
        }
        return 0;
    }
};

int main() {
    Solution solution;
    return 0;
}
