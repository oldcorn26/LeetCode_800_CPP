#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_set<string> us;
    int arrLen;
    char *arr;
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftInvalid = 0, rightInvalid = 0;
        for (char &ch: s) {
            if (ch == '(') ++leftInvalid;
            else if (ch == ')') leftInvalid > 0 ? --leftInvalid : ++rightInvalid;
        }
        arrLen = s.length() - leftInvalid - rightInvalid;
        arr = new char[arrLen + 1];
        generatePrth(s, 0, 0, 0, leftInvalid, rightInvalid);
        return vector<string>(us.begin(), us.end());
    }

    void generatePrth(string &s, int sIdx, int aIdx, int flag, int lIvd, int rIvd) {
        if (flag < 0 || s.length() < sIdx + lIvd + rIvd) return;
        if (aIdx == arrLen) {
            if (!flag) us.insert(string(&arr[0], &arr[aIdx]));
            return;
        }

        char &ch = s[sIdx], temp = arr[aIdx];
        arr[aIdx] = ch;
        if (ch == '(') {
            if (lIvd > 0) generatePrth(s, sIdx + 1, aIdx, flag, lIvd - 1, rIvd);
            generatePrth(s, sIdx + 1, aIdx + 1, flag + 1, lIvd, rIvd);
        } else if (ch == ')') {
            if (rIvd > 0) generatePrth(s, sIdx + 1, aIdx, flag, lIvd, rIvd - 1);
            generatePrth(s, sIdx + 1, aIdx + 1, flag - 1, lIvd, rIvd);
        } else {
            generatePrth(s, sIdx + 1, aIdx + 1, flag, lIvd, rIvd);
        }
        arr[aIdx] = temp;
    }
};

int main() {
    Solution solution;
    vector<string> result = solution.removeInvalidParentheses("()())()");
    return 0;
}