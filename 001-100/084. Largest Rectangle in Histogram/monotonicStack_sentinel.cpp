#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max = 0;
        stack<int> monStack;
        vector<int> heights1(heights.size() + 2);
        monStack.push(0);
        for (int i = 0; i < heights.size(); ++i) heights1[i + 1] = heights[i];

        for (int i = 1; i < heights1.size(); ++i) {
            while (heights1[monStack.top()] > heights1[i]) {
                int &top = monStack.top();
                monStack.pop();
                int &&temp = heights1[top] * (i - monStack.top() - 1);
                max = temp > max ? temp : max;
            }
            monStack.push(i);
        }

        return max;
    }
};

int main() {
    Solution solution;
    vector<int> heights{2,1,5,6,2,3};
    int result = solution.largestRectangleArea(heights);
    cout << result;
    return 0;
}