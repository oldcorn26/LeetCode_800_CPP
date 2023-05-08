#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int one{}, two{};
        vector<int> unfinished1(4);
        vector<int> unfinished2(4);
        unordered_map<char, int> match{{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        for (char &ch: croakOfFrogs) {
            int idx{match[ch]};
            if (idx == 0) {
                if (one > 0) {
                    one--;
                    unfinished2[0]++;
                } else {
                    unfinished1[0]++;
                }
            } else if (idx == 4) {
                if (unfinished1[3] > 0) {
                    unfinished1[3]--;
                    one++;
                } else {
                    if (--unfinished2[3] < 0)
                        return -1;
                    two++;
                }
            } else {
                if (unfinished1[idx - 1] > 0) {
                    unfinished1[idx - 1]--;
                    unfinished1[idx]++;
                } else {
                    if (--unfinished2[idx - 1] < 0)
                        return -1;
                    unfinished2[idx]++;
                }
            }
        }
        for (int i{}; i < 4; ++i)
            if (unfinished1[i] != 0 || unfinished2[i] != 0)
                return -1;
        return one + two;
    }
};

int main() {
    Solution solution;
    int result = solution.minNumberOfFrogs("aoocrrackk");
    cout << result;
    return 0;
}
