#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
        if (p.empty())  return s.empty();
        bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
        // *前字符重复>=1次 || *前字符重复0次（不出现）
        if (p.size() >= 2 && p[1] == '*')
            return (first_match && isMatch(s.substr(1), p)) || isMatch(s, p.substr(2));
            // 不是*，剪去已经匹配成功的头部，继续比较
        else
            return first_match && isMatch(s.substr(1), p.substr(1));
    }
};

int main() {
    Solution solution;
    return 0;
}
