#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int result = 0, temp = 0;

        while (i < j) {
            temp = height[i] < height[j] ? (j - i) * height[i++] : (j - i) * height[j--];
            result = result > temp ? result : temp;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> height{0,1,2,3,4}
    int result = solution.maxArea(height);
    cout << result;
    return 0;
}
