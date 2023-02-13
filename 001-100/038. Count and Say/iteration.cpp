#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        else if (n == 2) return "11";
        else if (n == 3) return "21";
        else if (n == 4) return "1211";

        string ret{""};
        string &&pre{countAndSay(n - 1)};
        for (int i{0}; i < pre.size(); ++i) {
            int left{i};
            while (i + 1 < pre.size() && pre[i] == pre[i + 1]) ++i;
            ret += to_string(i - left + 1) + pre[i];
        }

        return ret;
    }
};

int main() {
    Solution solution;
    string result = solution.countAndSay(5);
    cout << result;
    return 0;
}
