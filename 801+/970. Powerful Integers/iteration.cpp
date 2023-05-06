#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int xPower{1};
        unordered_set<int> s;
        while (xPower < bound) {
            int yPower{1};
            while (xPower + yPower <= bound) {
                s.emplace(xPower + yPower);
                if (y == 1)
                    break;
                yPower *= y;
            }
            if (x == 1)
                break;
            xPower *= x;
        }
        return vector<int>(s.begin(), s.end());
    }
};

int main() {
    Solution solution;
    vector result = solution.powerfulIntegers(2, 1, 10);
    return 0;
}
