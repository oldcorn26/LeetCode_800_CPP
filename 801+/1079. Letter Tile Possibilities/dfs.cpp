#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int len{};
    int finalState{};
    unordered_set<string> us;
public:
    int numTilePossibilities(string tiles) {
        char str[8];
        len = tiles.size();
        finalState = (1 << len) - 1;
        dfs(tiles, 0, str, 0);
        return us.size();
    }

    void dfs(string &tiles, int state, char *str, int sIdx) {
        if (state == finalState)
            return;
        for (int i{}; i < len; ++i) {
            if (state & (1 << i))
                continue;
            str[sIdx] = tiles[i];
            us.emplace(string(&str[0], &str[sIdx + 1]));
            dfs(tiles, state | (1 << i), str, sIdx + 1);
        }
    }
};

int main() {
    Solution solution;
    return 0;
}
