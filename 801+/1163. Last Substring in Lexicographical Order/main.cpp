#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        int size = s.size();
        int maxIdx{}, i{1};
        while (i < size) {
            int j{};
            while (i + j < size) {
                if (s[maxIdx + j] == s[i + j])
                    j++;
                else {
                    s[maxIdx + j] > s[i + j] ? i = i + j + 1 : maxIdx += j + 1;
                    if (maxIdx >= i)
                        i = maxIdx + 1;
                    break;
                }
            }
            if (i + j == size)
                break;
        }
        return s.substr(maxIdx);
    }
};

int main() {
    Solution solution;
    string result = solution.lastSubstring("abab");
    cout << result;
    return 0;
}
