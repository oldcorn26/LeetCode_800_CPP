#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int vecLen = height.size(), temp = 0, res = 0;
        int leftIter[vecLen];

        for (int i = 0; i < vecLen; i++) {
            temp = height[i] > temp ? height[i] : temp;
            leftIter[i] = temp;
        }

        temp = 0;
        for (int i = vecLen - 1; i >= 0; i--) {
            temp = height[i] > temp ? height[i] : temp;
            temp = leftIter[i] < temp ? leftIter[i] : temp;
            res += temp - height[i];
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> height{4,2,0,3,2,5};
    int result = solution.trap(height);
    cout << result;
    return 0;
}
