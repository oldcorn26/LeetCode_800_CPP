#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {

        auto cmp = [](vector<int> &x, vector<int> &y) {
            if (x[1] != y[1]) return x[1] < y[1];
            else return x[0] > y[0];
        };
        sort(pairs.begin(), pairs.end(), cmp);

        int tail{pairs[0][1]}, ret{1};

        for (int i{1}; i < pairs.size(); ++i) {
            if (pairs[i][0] > tail) {
                ++ret;
                tail = pairs[i][1];
            }
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> pairs{{-10,-8},{8,9},{-5,0},{6,10},{-6,-4},{1,7},{9,10},{-4,7}};
    int result = solution.findLongestChain(pairs);
    cout << result;
    return 0;
}
