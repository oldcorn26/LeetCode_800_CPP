#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int res{0};
public:
    int totalNQueens(int n) {
        vector<bool> leftFlag(2 * n - 1), rightFlag(2 * n - 1), selected(n);
        dfs(n - 1, selected, leftFlag, rightFlag);
        return res;
    }

    void dfs(int idx, vector<bool> &selected, vector<bool> &leftFlag, vector<bool> &rightFlag) {
        if (idx == -1) {
            ++res;
        }
        for (int j{0}; j < selected.size(); ++j) {
            if (selected[j]) continue;
            if (reverseDiagonalState(leftFlag, rightFlag, idx, j)) {
                selected[j] = true;
                dfs(idx - 1, selected, leftFlag, rightFlag);
            }
            selected[j] = false;
            reverseDiagonalState(leftFlag, rightFlag, idx, j);
        }
    }

    // Return true if both previous states are false.
    bool reverseDiagonalState(vector<bool> &leftFlag, vector<bool> &rightFlag, int i, int j) {
        int &&leftIdx{static_cast<int>(leftFlag.size() / 2) - i + j};
        leftFlag[leftIdx] = !leftFlag[leftIdx];
        rightFlag[i + j] = !rightFlag[i + j];
        return leftFlag[leftIdx] && rightFlag[i + j];
    }
};

int main() {
    Solution solution;
    int result = solution.totalNQueens(9);
    cout << result;
    return 0;
}