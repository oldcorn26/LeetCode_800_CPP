#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int size = triangle.size();
        int dp1[size], dp2[size];
        int *pre{dp1}, *crt{dp2}, *temp;
        int ret{INT32_MAX};

        pre[0] = triangle[0][0];

        for (int i{1}; i < size; ++i) {
            for (int j{0}; j <= i; ++j) {
                int left{j ? pre[j - 1] : INT32_MAX};
                int right{j < i ? pre[j] : INT32_MAX};
                crt[j] = triangle[i][j] + min(left, right);
            }
            temp = crt;
            crt = pre;
            pre = temp;
        }

        for (int i{0}; i < size; ++i) ret = min(ret, pre[i]);
        return ret;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> triangle{{-10}};
    int result = solution.minimumTotal(triangle);
    cout << result;
    return 0;
}
