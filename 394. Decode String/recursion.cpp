#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int totalLen = 0, i = 0;
        string &&editedStr = "1[" + s;
        forward_list<string> tempList;
        auto iter = tempList.before_begin();
        decodeStringHelper(tempList, iter, editedStr, i);
        for (string &str: tempList) {
            totalLen += str.length();
        }
        char res[totalLen + 1];
        for (string &str: tempList) {
            for (char &ch: str) res[i++] = ch;
        }
        return string(&res[0], &res[totalLen]);
    }

    int decodeStringHelper(forward_list<string> &addedList, _Fwd_list_iterator<string> &alIter, string &s, int &idx) {
        int strLen = s.size(), &&i = idx - 1, times = 0;
        forward_list<string> tempList;
        _Fwd_list_iterator<string> iter = tempList.before_begin();
        while (s[++i] < 58) times = times * 10 + s[i] - '0';
        for (++i; i < strLen; ++i) {
            if (s[i] < 58) i = decodeStringHelper(tempList, iter, s, i);
            else if (s[i] == ']') break;
            else {
                int temp = i;
                while (s[++temp] > 96) {}
                iter = tempList.insert_after(iter, string(&s[i], &s[temp]));
                i = temp - 1;
            }
        }
        for (; times > 0; --times) alIter = addedList.insert_after(alIter, tempList.begin(), tempList.end());
        return i;
    }
};

int main() {
    Solution solution;
    string result = solution.decodeString("2[abc]3[cd]ef");
    cout << result;
    return 0;
}