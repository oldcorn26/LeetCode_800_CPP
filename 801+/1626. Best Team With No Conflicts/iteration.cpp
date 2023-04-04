#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int size = scores.size();
        int ret{};
        vector<vector<int>> pairs(size);
        map<int, int> sorted;
        for (int i{}; i < size; ++i)
            pairs[i] = {ages[i], scores[i]};
        sort(pairs.begin(), pairs.end());
        for (auto &vec: pairs) {
            int maxSum{};
            for (auto &iter: sorted) {
                if (iter.first > vec[1])
                    break;
                maxSum = max(maxSum, iter.second);
            }
            sorted[vec[1]] = vec[1] + maxSum;
        }
        for (auto &iter: sorted)
            ret = max(ret, iter.second);
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> scores{1,2,3,5};
    vector<int> ages{8,9,10,1};
    int result = solution.bestTeamScore(scores, ages);
    cout << result;
    return 0;
}
