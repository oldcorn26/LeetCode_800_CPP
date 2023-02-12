#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {

        int count{0};
        vector<int> ret;
        unordered_set<char> us;
        vector<int> strCount(26);

        for (char &ch: s) ++strCount[ch - 'a'];
        for (char &ch: s) {
            ++count;
            if (--strCount[ch - 'a'] > 0) {
                us.emplace(ch);
            } else {
                us.erase(ch);
            }
            if (us.empty()) {
                ret.emplace_back(count);
                count = 0;
            }
        }

        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> result = solution.partitionLabels("ababcbacadefegdehijhklij");
    return 0;
}
