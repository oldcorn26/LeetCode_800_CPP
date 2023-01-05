#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int bitNum;
public:
    vector<int> grayCode(int n) {
        int &&resNum{1 << n};
        vector<int> res(resNum), state(resNum, -1);
        bitNum = n;
        state[0] = 0;

        dfs(state, 0);
        for (int i{0}; i < resNum; ++i) {
            res[state[i]] = i;
        }

        return res;
    }

    bool dfs(vector<int> &sta, int pre) {

        if (sta[pre] + 1 == sta.size()) {
            return true;
        }

        for (int i{0}; i < bitNum; ++i) {
            int crt{pre ^ (1 << i)};
            if (sta[crt] != -1) continue;
            sta[crt] = sta[pre] + 1;
            if (dfs(sta, crt)) return true;
            sta[crt] = -1;
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> result = solution.grayCode(2);
    return 0;
}