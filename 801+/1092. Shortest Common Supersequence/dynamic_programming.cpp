#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string ret{};
        int size1 = str1.size(), size2 = str2.size();
        vector<string> dp(size2);
        for (int j{}; j < size2; ++j) {
            dp[j] = str1[0] == str2[j] ? string{str1[0]} : (j ? dp[j-1] : "");
        }
        for (int i{1}; i < size1; ++i) {
            vector<string> backUp{dp};
            dp[0] = str1[i] == str2[0] ? string{str2[0]} : (i ? backUp[0] : "");
            for (int j{1}; j < size2; ++j) {
                if (str1[i] == str2[j])
                    dp[j] = backUp[j-1] + str1[i];
                else {
                    int len1 = dp[j-1].size(), len2 = backUp[j].size(), len3 = backUp[j-1].size();
                    if (len1 >= max(len2, len3))
                        dp[j] = dp[j-1];
                    else if (len2 >= max(len1, len3))
                        dp[j] = backUp[j];
                    else
                        dp[j] = backUp[j-1];
                }
            }
        }
        string &same{dp[size2-1]};
        int sameIdx{}, idx1{}, idx2{};
        while (sameIdx < same.size()) {
            while (idx1 < size1 && str1[idx1] != same[sameIdx])
                ret += str1[idx1++];
            while (idx2 < size2 && str2[idx2] != same[sameIdx])
                ret += str2[idx2++];
            ret += same[sameIdx++];
            idx1++, idx2++;
        }
        ret += (idx1 < size1 ? str1.substr(idx1) : "") + (idx2 < size2 ? str2.substr(idx2) : "");
        return ret;
    }
};

int main() {
    Solution solution;
    return 0;
}
