#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int size = s.size();
        vector<int> next(size);
        for (int i{1}, j{}; i < size; ++i) {
            while (j > 0 && s[i] != s[j])
                j = next[j-1];
            if (s[i] == s[j])
                j++;
            next[i] = j;
        }
        int length{next[size-1]};
        return s.substr(0, length);
    }
};

int main() {
    Solution solution;
    return 0;
}
