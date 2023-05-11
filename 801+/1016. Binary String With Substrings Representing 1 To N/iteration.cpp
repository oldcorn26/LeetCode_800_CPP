#include <iostream>
#include <unordered_set>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool queryString(string s, int n) {
        int size = s.size();
        unordered_set<int> count;
        for (int i{}; i < size; ++i) {
            if (s[i] == '0')
                continue;
            for (int j{i}; j < size && j - i + 1 <= 30; ++j)
                count.emplace(stoi(s.substr(i, j - i + 1), nullptr, 2));
        }
        for (int i{1}; i <= n; ++i)
            if (count.find(i) == count.end())
                return false;
        return true;
    }
};

int main() {
    Solution solution;
    string s = "0110";
    bool result = solution.queryString(s, 4);
    cout << result;
    return 0;
}
