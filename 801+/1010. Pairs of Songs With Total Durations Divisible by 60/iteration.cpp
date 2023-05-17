#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ret{};
        vector<int> count(60);
        for (int i: time)
            count[i % 60]++;
        ret += (long long) count[0] * (count[0] - 1) / 2 + (long long) count[30] * (count[30] - 1) / 2;
        for (int i{1}; i < 30; ++i)
            ret += count[i] * count[60 - i];
        return ret;
    }
};

int main() {
    Solution solution;
    return 0;
}
