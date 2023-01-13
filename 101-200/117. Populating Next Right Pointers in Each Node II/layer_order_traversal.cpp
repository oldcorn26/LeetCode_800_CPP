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

        pair<Node *, int> &&fatherNode{getNext({root, 0})};
        Node *&&crtSon{getNode(fatherNode)};
        while (crtSon) {
            Node *tempHead{crtSon};
            pair<Node *, int> &&fatherNxt{getNext(fatherNode)};
            Node *&&nextSon = getNode(fatherNxt);
            while (nextSon) {
                crtSon->next = nextSon;
                fatherNxt = getNext(fatherNxt);
                fatherNode = getNext(fatherNode);
                nextSon = getNode(fatherNxt);
                crtSon = getNode(fatherNode);
            }
            fatherNode = getNext({tempHead, 0});
            crtSon = getNode(fatherNode);
        }
        return root;
    }

    Node *getNode(const pair<Node *, int> &crt) {
        if (!crt.first) return nullptr;
        if (crt.second == 1) return crt.first->left;
        else return crt.first->right;
    }

    pair<Node *, int> getNext(pair<Node *, int> crt) {
        int &idx{crt.second};
        Node *&pNode{crt.first};
        if (!pNode) return {nullptr, 0};
        if (idx == 0) {
            if (pNode->left) return {pNode, 1};
            else idx = 1;
        }
        if (idx == 1) {
            if (pNode->right) return {pNode, 2};
            else return getNext({pNode->next, 0});
        }
        return getNext({pNode->next, 0});
    }
};

int main() {
    Solution solution;
    return 0;
}
