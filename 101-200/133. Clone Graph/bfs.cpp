#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if (!node) return nullptr;

        queue<Node *> list;
        vector<Node *> settled(101);
        Node *ret{new Node(node->val)};

        list.push(node);
        settled[node->val] = ret;

        while (list.size()) {
            Node *crtNode{list.front()};
            list.pop();
            for (Node *&n: crtNode->neighbors) {
                if (!settled[n->val]) {
                    settled[n->val] = new Node(n->val);
                    list.push(n);
                }
                settled[crtNode->val]->neighbors.emplace_back(settled[n->val]);
            }
        }

        return ret;
    }
};

int main() {
    Solution solution;
    Node *a{new Node(1)}, *b{new Node(2)}, *c{new Node(3)}, *d{new Node(4)};
    a->neighbors.emplace_back(b);
    b->neighbors.emplace_back(a), b->neighbors.emplace_back(c);
    c->neighbors.emplace_back(b), c->neighbors.emplace_back(d);
    d->neighbors.emplace_back(c);
    Node *result = solution.cloneGraph(a);
    return 0;
}
