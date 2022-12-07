#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxLen{0};
        vector<int> countMap(26);
        for (char &i: tasks) {
            maxLen = ++countMap[i - 'A'] > maxLen ? countMap[i - 'A'] : maxLen;
        }
        int blankNum{(n + 1) * (maxLen - 1)};
        for (int &i: countMap) {
            blankNum -= i < maxLen ? i : maxLen - 1;
        }
        return blankNum > 0 ? tasks.size() + blankNum : tasks.size();
    }
};

int main() {
    Solution solution;
//    vector<char> tasks{'A','A','A','A','A','A','B','C','D','E','F','G'};
    vector<char> tasks{'A','A','A','B','B','B'};
    int result = solution.leastInterval(tasks, 0);
    cout << result;
    return 0;
}