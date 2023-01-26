#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node *construct(vector<vector<int>> &grid) {
        return constructHelper(grid, 0, 0, grid[0].size());
    }

    Node *constructHelper(vector<vector<int>> &grid, int x, int y, int size) {

        if (ifSame(grid, x, y, size)) return new Node(grid[x][y], true);

        int halfSize{size / 2};
        Node *topLeft = constructHelper(grid, x, y, halfSize);
        Node *topRight = constructHelper(grid, x, y + halfSize, halfSize);
        Node *bottomLeft = constructHelper(grid, x + halfSize, y, halfSize);
        Node *bottomRight = constructHelper(grid, x + halfSize, y + halfSize, halfSize);
        
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    bool ifSame(vector<vector<int>> &grid, int x, int y, int size) {
        int flag{grid[x][y]};
        for (int i{0}; i < size; ++i) {
            for (int j{0}; j < size; ++j) {
                if (grid[x + i][y + j] != flag) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    return 0;
}
