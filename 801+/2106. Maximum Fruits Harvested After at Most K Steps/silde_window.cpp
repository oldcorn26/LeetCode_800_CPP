#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {

        auto cmp = [](const auto &a, int b) {
            return a[0] < b;
        };

        int size = fruits.size();
        int left = lower_bound(fruits.begin(), fruits.end(), startPos - k, cmp) - fruits.begin();
        int right{left}, sum{};
        for (; right < size && fruits[right][0] <= startPos; ++right)
            sum += fruits[right][1];
        int ret{sum};
        for (; right < size && fruits[right][0] <= startPos + k; ++right) {
            sum += fruits[right][1];
            while (fruits[right][0] * 2 - fruits[left][0] - startPos > k &&
                   fruits[right][0] - fruits[left][0] * 2 + startPos > k)
                sum -= fruits[left++][1];
            ret = max(ret, sum);
        }
        return ret;
    }
};

int main() {
    Solution solution;
    return 0;
}
