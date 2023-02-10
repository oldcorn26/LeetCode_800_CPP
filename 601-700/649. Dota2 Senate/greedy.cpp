#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int ban[2]{0, 0};
        queue<int> q;

        for (char &ch: senate) {
            if (ch == 'R') q.emplace(0);
            else q.emplace(1);
        }

        while (q.size()) {
            int size = q.size();
            for (int i{0}; i < size; ++i) {
                int attr{q.front()};
                if (ban[attr] > 0) --ban[attr];
                else {
                    q.emplace(attr);
                    ++ban[!attr];
                }
                q.pop();
            }
            if (q.size() == size) break;
        }

        return q.front() ? "Dire" : "Radiant";
    }
};

int main() {
    Solution solution;
    string result = solution.predictPartyVictory("DRRD");
    cout << result;
    return 0;
}
