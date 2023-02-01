#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ret(numRows);

        ret[0].emplace_back(1);

        for (int i{1}; i < numRows; ++i) {
            int halfIdx{i / 2}, j{1};
            vector<int> temp(i + 1, 1);
            for (; j <= halfIdx; ++j) {
                temp[j] = ret[i  - 1][j - 1] + ret[i - 1][j];
                temp[i - j] = temp[j];
            }
            ret[i] = temp;
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> result = solution.generate(5);
    return 0;
}
