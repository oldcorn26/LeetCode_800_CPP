#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k == 1)
            return 1;
        int ret{1};
        int sumRem{1 % k}, preRem{1 % k};
        unordered_set<int> old;
        while (old.find(sumRem) == old.end()) {
            old.emplace(sumRem);
            ret++;
            preRem = preRem * 10 % k;
            sumRem = (sumRem + preRem) % k;
            if (sumRem == 0)
                return ret;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    int result = solution.smallestRepunitDivByK(3);
    cout << result;
    return 0;
}
