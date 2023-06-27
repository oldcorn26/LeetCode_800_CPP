#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int idx{1};
        int maxArea{};
        stack<int> s{{0}};
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        while (idx < heights.size()) {
            while (heights[s.top()] > heights[idx]) {
                int h{heights[s.top()]};
                s.pop();
                maxArea = max(maxArea, h * (idx - s.top() - 1));
            }
            s.push(idx);
            idx++;
        }
        return maxArea;
    }
};

int main() {
    Solution solution;
    vector<int> heights{2,1,5,6,2,3};
    int result = solution.largestRectangleArea(heights);
    cout << result;
    return 0;
}