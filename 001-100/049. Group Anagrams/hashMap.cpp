#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, int> map;
        for (int i{}; i < strs.size(); ++i) {
            string str{strs[i]};
            sort(str.begin(), str.end());
            if (map.find(str) == map.end()) {
                ret.push_back({strs[i]});
                map[str] = ret.size() - 1;
            } else {
                ret[map[str]].push_back(strs[i]);
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);
    return 0;
}