#include <iostream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int idx1{0}, idx2{0};
        while (idx1 < version1.size() || idx2 < version2.size()) {
            int next1{idx1 + 1}, next2{idx2 + 1};
            while (next1 < version1.size() && version1[next1] != '.') ++next1;
            while (next2 < version2.size() && version2[next2] != '.') ++next2;
            int i1{idx1 < version1.size() ? stoi(version1.substr(idx1, next1 - idx1)) : 0};
            int i2{idx2 < version2.size() ? stoi(version2.substr(idx2, next2 - idx2)) : 0};
            if (i1 != i2) return i1 < i2 ? -1 : 1;
            idx1 = next1 + 1, idx2 = next2 + 1;
        }
        return 0;
    }
};

int main() {
    Solution solution;
    int result = solution.compareVersion("1.0","1.0.0");
    cout << result;
    return 0;
}
