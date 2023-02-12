#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {

        int count{0}, farIdx{0};
        vector<int> ret;
        unordered_set<char> us;
        vector<int> end(26);

        for (int i{0}; i < s.size(); ++i) end[s[i] - 'a'] = i;
        for (int i{0}; i < s.size(); ++i) {
            ++count;
            farIdx = max(end[s[i] - 'a'], farIdx);
            if (farIdx == i) {
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
