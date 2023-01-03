#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int size;
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        this->size = n;
        vector<bool> leftFlag(2 * n - 1), rightFlag(2 * n - 1);
        vector<int> selected(n, -1);
        dfs(0, selected, leftFlag, rightFlag);
        return res;
    }

    void dfs(int idx, vector<int> &selected, vector<bool> &leftFlag, vector<bool> &rightFlag) {
        if (idx == size) {
            pushElement(selected);
        }
        for (int j{0}; j < size; ++j) {
            if (selected[j] != -1) continue;
            bool left = reverseLeftDiagonalState(leftFlag, idx, j);
            bool right = reverseRightDiagonalState(rightFlag, idx, j);
            if (!left && !right) {
                selected[j] = idx;
                dfs(idx + 1, selected, leftFlag, rightFlag);
            }
            selected[j] = -1;
            reverseLeftDiagonalState(leftFlag, idx, j);
            reverseRightDiagonalState(rightFlag, idx, j);
        }
    }

    void pushElement(vector<int> selected) {
        char str[size + 1];
        vector<string> element(size);
        for (int i{0}; i < size; ++i) {
            for (int j{0}; j < size; ++j) {
                str[j] = '.';
            }
            str[i] = 'Q';
            element[selected[i]] = string(&str[0], &str[size]);
        }
        res.push_back(element);
    }

    bool reverseLeftDiagonalState(vector<bool> &leftFlag, int i, int j) {
        int &&layerNum{static_cast<int>(leftFlag.size() / 2)};
        bool temp = leftFlag[layerNum - i + j];
        leftFlag[layerNum - i + j] = !temp;
        return temp;
    }

    bool reverseRightDiagonalState(vector<bool> &rightFlag, int i, int j) {
        bool temp = rightFlag[i + j];
        rightFlag[i + j] = !temp;
        return temp;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> result = solution.solveNQueens(4);
    return 0;
}