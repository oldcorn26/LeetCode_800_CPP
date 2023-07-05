#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int maxLen{};
        unordered_map<int, int> edge;
        for (int i: nums) {
            if (edge.find(i) != edge.end())
                continue;
            int left = edge.find(i-1) != edge.end() ? edge[i-1] : 0;
            int right = edge.find(i+1) != edge.end() ? edge[i+1] : 0;
            int len{left + right + 1};
            edge[i] = -1;
            edge[i-left] = len;
            edge[i+right] = len;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

int main() {
    Solution solution;
    vector<int> nums{100,4,200,1,3,2};
    int result = solution.longestConsecutive(nums);
    cout << result;
    return 0;
}
