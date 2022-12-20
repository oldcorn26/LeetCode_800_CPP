#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int deleteNum{k}, &&resNum{static_cast<int>(num.size() - k)};
        char res[resNum + 1];
        if (k >= num.size()) return "0";

        stack<char> monStack;
        for (char &ch: num) {
            while (!monStack.empty() && monStack.top() > ch && deleteNum > 0) {
                --deleteNum;
                monStack.pop();
            }
            monStack.emplace(ch);
        }
        while (monStack.size() > resNum) monStack.pop();
        for (int &&i = resNum - 1; i >= 0; --i) {
            res[i] = monStack.top();
            monStack.pop();
        }
        int headIdx{-1};
        while (res[++headIdx] == '0' && headIdx < resNum - 1);
        return string(&res[headIdx], &res[resNum]);
    }
};

int main() {
    Solution solution;
    string result = solution.removeKdigits("100200", 1);
    cout << result;
    return 0;
}