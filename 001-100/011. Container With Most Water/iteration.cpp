#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i;
        int max = 0;
        int result = 0;
        int heightNum = height.size();
        int bucketMaxH;

        for (i = 0; i < heightNum; ++i) {
            max = max < height[i] ? height[i] : max;
        }

        for (i = heightNum - 2; i >= 0; --i) {
            bucketMaxH = 0;
            for (int j = 0; j + i + 1< heightNum; ++j) {
                int bucketHeight = height[j] < height[j + i + 1] ? height[j] : height[j + i + 1];
                bucketMaxH = bucketHeight > bucketMaxH ? bucketHeight : bucketMaxH;
            }
            result = result > (i + 1) * bucketMaxH ? result : (i + 1) * bucketMaxH;
            if (max * (i + 1) < result) break;
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> height{0,1,2,3,4,5,6,7,8};
    int result = solution.maxArea(height);
    cout << result;
    return 0;
}
