#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    string str;
    vector<string> ret;
public:
    vector<string> restoreIpAddresses(string s) {
        str = s;
        vector<int> partition(4);
        dfs(partition, 0, str.size());
        return ret;
    }

    void dfs(vector<int> &part, int idx, int restNum) {
        if (idx == 3) {
            if (restNum > 3) return;
            part[3] = restNum;
            pushValidElement(part);
            return;
        }
        for (int i{1}; i < 4 && i < restNum; ++i) {
            part[idx] = i;
            dfs(part, idx + 1, restNum - i);
        }
    }

    void pushValidElement(vector<int> &part) {
        int headIdx{0}, elementIdx{0};
        char element[str.size() + 4];
        for (int i = 0; i < 4; ++i) {
            string &&temp{str.substr(headIdx, part[i])};
            if (!checkIfValid(temp)) return;
            for (char &c: temp) {
                element[elementIdx++] = c;
            }
            headIdx += part[i];
            if (i != 3) element[elementIdx++] = '.';
        }
        ret.emplace_back(string(&element[0], &element[elementIdx]));
    }

    bool checkIfValid(string &s) {
        if (s[0] == '0' && s.size() > 1) return false;
        int num{0};
        for (int i{0}; i < s.size(); ++i) {
            num = num * 10 + s[i] - '0';
        }
        return num <= 255;
    }
};

int main() {
    Solution solution;
    vector<string> result = solution.restoreIpAddresses("25525511135");
    return 0;
}