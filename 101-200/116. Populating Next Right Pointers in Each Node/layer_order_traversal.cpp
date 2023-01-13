#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        if (!root) return nullptr;

        Node *fatherNode{root}, *nextLayer{root->left};
        while (nextLayer) {
            fatherNode->left->next = fatherNode->right;
            while (fatherNode->next) {
                Node *&fatherNxt{fatherNode->next};
                fatherNode->right->next = fatherNxt->left;
                fatherNxt->left->next = fatherNxt->right;
                fatherNode = fatherNxt;
            }
            fatherNode = nextLayer;
            nextLayer = fatherNode->left;
        }
        return root;
    }
};

int main() {
    Solution solution;
    return 0;
}
