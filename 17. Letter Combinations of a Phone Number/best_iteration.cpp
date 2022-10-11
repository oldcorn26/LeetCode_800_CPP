#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();

        int vecNum = 1;
        for (char i : digits) {
            if (i == '7' || i == '9') vecNum *= 4;
            else vecNum *= 3;
        }
        int strLen;
        int repeatNum = vecNum;
        string button[8] = {"abc", "def", "ghi", "jkl",
                            "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res(vecNum);

        for (char i : digits) {
            int tempFlag = (int) i - 50;
            strLen = button[tempFlag].length();
            repeatNum /= strLen;

            for (int j = 0; j < vecNum / repeatNum / strLen; ++j) {
                for (int k = 0; k < strLen; ++k) {
                    for (int r = 0; r < repeatNum; ++r) {
                        res[repeatNum * (j * strLen + k) + r] += button[tempFlag][k];
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    string digits = "";
    vector<string> result = solution.letterCombinations(digits);
    return 0;
}
