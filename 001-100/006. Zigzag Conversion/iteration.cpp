#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 && numRows >= s.size()) return s;

        bool flag{true};
        int size = s.size();
        int sIdx{0};
        string ret{""};
        vector<vector<char>> table(numRows, vector<char>(size));
        vector<int> idx(numRows);
        while (flag) {
            for (int i{0}; i < numRows && flag; ++i) {
                if (sIdx < size) table[i][idx[i]++] = s[sIdx++];
                else flag = false;
            }
            for (int i{numRows - 2}; i > 0 && flag; --i) {
                if (sIdx < size) table[i][idx[i]++] = s[sIdx++];
                else flag = false;
            }
        }
        for (int i{0}; i < numRows; ++i) {
            ret += string(table[i].begin(), table[i].begin() + idx[i]);
        }

        return ret;
    }
};

int main() {
    Solution solution;
    string result = solution.convert("PAYPALISHIRING", 4);
    cout << result;
    return 0;
}
