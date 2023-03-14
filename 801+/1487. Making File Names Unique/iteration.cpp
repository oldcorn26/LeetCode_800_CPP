#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        int size = names.size();
        vector<string> ret(size);
        unordered_map<string, int> um;
        for (int i{0}; i < size; ++i) {
            auto iter{um.find(names[i])};
            if (iter == um.end()) {
                ret[i] = names[i];
                um.emplace(names[i], 0);
            } else {
                string temp{names[i] + "(" + to_string(++iter->second) + ")"};
                while (um.find(temp) != um.end()) {
                    temp = names[i] + "(" + to_string(++iter->second) + ")";
                }
                ret[i] = temp;
                um.emplace(ret[i], 0);
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<string> names{"kaido","kaido(1)","kaido","kaido(1)"};
    vector<string> result = solution.getFolderNames(names);
    return 0;
}
