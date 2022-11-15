#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n < 4) return n;

        int &&sq = sqrt(n), minStep = 0;
        vector<int> sqNum(sq);
        for (int i = 1; i <= sq; ++i) sqNum[sq - i] = i * i;
        queue<int> restNum;
        restNum.emplace(n);
        while(1) {
            int lastSize = restNum.size();
            ++minStep;
            for (; lastSize > 0; --lastSize) {
                int temp = restNum.front();
                restNum.pop();
                for (int &i: sqNum) {
                    if (temp > i) restNum.emplace(temp - i);
                    else if (temp == i) return minStep;
                }
            }
        }
    }
};

int main() {
    Solution solution;
    int result = solution.numSquares(4);
    cout << result;
    return 0;
}
