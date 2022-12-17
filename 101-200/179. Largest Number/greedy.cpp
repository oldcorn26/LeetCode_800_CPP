#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int length{1}, idx{-1};
        vector<string> strings(nums.size());
        for(int i{0}; i < nums.size(); ++i) {
            strings[i] = to_string(nums[i]);
            length += strings[i].size();
        }

        auto cmp = [](string left, string right) {
            return left + right > right + left;
        };

        sort(strings.begin(),strings.end(), cmp);
        char ans[length];
        for(string &str: strings) {
            for (char &ch: str) {
                ans[++idx] = ch;
            }
        }
        return ans[0] == '0' ? "0" : string(&ans[0], &ans[length - 1]);
    }
};

int main() {
    Solution solution;
    vector<string> str{"3","32","30","34","39","5","9"};
    sort(str.begin(), str.end());
    return 0;
}