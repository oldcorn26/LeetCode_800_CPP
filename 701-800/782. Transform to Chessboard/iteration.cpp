#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int movesToChessboard(vector<vector<int>> &board) {
        if (board.size() == 1) return 0;
        int size = board.size();
        unordered_map<int, int> col, row;
        for (int i{}; i < size; ++i) {
            int tempC{}, tempR{};
            int oneNumC{}, oneNumR{};
            for (int j{}; j < size; ++j) {
                tempC = (tempC << 1) + board[i][j];
                tempR = (tempR << 1) + board[j][i];
                oneNumC += board[i][j];
                oneNumR += board[j][i];
            }
            if (abs(size - oneNumC*2) > 1 || abs(size - oneNumR*2) > 1) return -1;
            col[tempC]++;
            row[tempR]++;
        }
        if (col.size() != 2 || row.size() != 2) return -1;
        if (ifNumberInvalid(col) || ifNumberInvalid(row)) return -1;
        int cCount{}, rCount{};
        int Cst{(*col.begin()).first}, Rst{(*row.begin()).first};
        for (int i{}; i < size; ++i) {
            cCount += (1 & (Cst >> i)) != (i % 2);
            rCount += (1 & (Rst >> i)) != (i % 2);
        }
        return size % 2 ? ((cCount%2 ? size-cCount : cCount)+(rCount%2 ? size-rCount : rCount))/2 : (min(cCount, size-cCount)+min(rCount, size-rCount))/2;
    }

    bool ifNumberInvalid(unordered_map<int, int> &um) {
        int baseSize{(*um.begin()).second};
        for (auto &iter: um)
            if (abs(iter.second - baseSize) > 1) return true;
        return false;
    }
};

int main() {
    Solution solution;
    return 0;
}
