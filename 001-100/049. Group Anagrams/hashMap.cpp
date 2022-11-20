#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        if (strs.size() <= 1) return {strs};

        unordered_map<string, int> hashmap;
        vector<vector<string>> res;

        for (string &s: strs) {
            string temp = s;
            sort(temp.begin(), temp.end());

            if (hashmap.find(temp) == hashmap.end()) {
                hashmap[temp] = hashmap.size();
                res.push_back(vector<string>{});
            }
            res[hashmap[temp]].push_back(s);
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);
    return 0;
}