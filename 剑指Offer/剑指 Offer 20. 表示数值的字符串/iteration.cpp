#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int k = 0, spot = 0;
        while (s[k] == ' ')k++;
        if (!isNum(s, k, spot) || spot > 1)return false;//判断前面的数是否合理
        if (s[k] == 'e' || s[k] == 'E') {
            k++;
            int temp = spot;
            if (!isNum(s, k, spot) || spot != temp)return false;//整数判断
        }
        while (s[k] == ' ')k++;
        return k == s.size();//若出现不满足条件的字符，k会卡在某个关节无法进行
    }

    bool isNum(string &s, int &k, int &spot) {
        if (s[k] == '+' || s[k] == '-')k++;
        bool num = false;
        while ('0' <= s[k] && s[k] <= '9' || s[k] == '.') {
            if (s[k] == '.')spot++;
            else num = true;
            k++;
        }
        return num;
    }
};

int main() {
    Solution solution;
    vector<string> s{" ",".","+100", "5e2", "-123", "3.1416", "-1E-16", "0123"};
    for (string &str: s) {
        cout << str << " " << solution.isNumber(str) << endl;
    }
    return 0;
}
