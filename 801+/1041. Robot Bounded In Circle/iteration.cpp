#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dirIdx{};
        vector<int> finalVec(2);
        vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (char c: instructions) {
            switch (c) {
                case 'G':
                    finalVec[0] += directions[dirIdx][0];
                    finalVec[1] += directions[dirIdx][1];
                    break;
                case 'L':
                    dirIdx = dirIdx == 0 ? 3 : dirIdx-1;
                    break;
                case 'R':
                    dirIdx = dirIdx == 3 ? 0 : dirIdx+1;
                    break;
                default:
                    break;
            }
        }
        return dirIdx != 0 || (finalVec[0] == 0 && finalVec[1] == 0);
    }
};

int main() {
    Solution solution;
    return 0;
}
