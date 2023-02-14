#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int eIdx{0};
        for (char &ch: s) {
            if (ch == 'e' || ch == 'E') break;
            ++eIdx;
        }
        if (eIdx == s.size()) return s != "+" && s != "-" && isDecimal(s);
        else if (eIdx == 0 || eIdx == s.size() - 1) return false;
        else {
            string &&left{s.substr(0, eIdx)};
            string &&right{s.substr(eIdx + 1, s.size() - eIdx - 1)};
            if (right == "+" || right == "-" || left == "+" || left == "-") return false;
            return isDecimal(left) && isInteger(right);
        }
    }

    bool isInteger(string s) {
        int idx{0};
        if (s[idx] == '+' || s[idx] == '-') ++idx;
        while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') ++idx;
        return idx == s.size();
    }

    bool isUnsignedInteger(string s) {
        for (char &ch: s) {
            if (ch < '0' || ch > '9') return false;
        }
        return true;
    }

    bool isDecimal(string s) {
        int pointIdx{0};
        for (char &ch: s) {
            if (ch == '.') break;
            ++pointIdx;
        }
        if (pointIdx == s.size()) return isInteger(s);
        string left{pointIdx ? s.substr(0, pointIdx) : ""};
        string right{pointIdx == s.size() - 1 ? "" : s.substr(pointIdx + 1, s.size() - pointIdx - 1)};
        if (left.empty() && right.empty()) return false;
        else if (left.empty()) return isUnsignedInteger(right);
        else if (right.empty()) return left != "+" && left != "-" && isInteger(left);
        return isInteger(left) && isUnsignedInteger(right);
    }
};

int main() {
    Solution solution;
    vector<string> nums{"40", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};
    for (string &str: nums) {
        bool result = solution.isNumber(str);
        cout << result << endl;
    }
    return 0;
}
