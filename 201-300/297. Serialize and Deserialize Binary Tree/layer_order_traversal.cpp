#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    TreeNode(int x, int y, int z) : val(x), left(new TreeNode(y)), right(new TreeNode(z)) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        string ret{};
        while (!q.empty()) {
            int size = q.size();
            string temp{};
            while (size-- > 0) {
                if (q.front()) {
                    temp += int2str(q.front()->val);
                    q.emplace(q.front()->left);
                    q.emplace(q.front()->right);
                } else {
                    temp += "null";
                }
                q.pop();
            }
            ret += temp;
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int dataIdx{4};
        TreeNode *root{str2Tree(data.substr(0, 4))};
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                if (q.front()) {
                    q.front()->left = str2Tree(data.substr(dataIdx, 4));
                    q.front()->right = str2Tree(data.substr(dataIdx+4, 4));
                    q.emplace(q.front()->left);
                    q.emplace(q.front()->right);
                    dataIdx += 8;
                }
                q.pop();
            }
        }
        return root;
    }

    string int2str(int i) {
        if (i < 0)
            i = 5000 - i;
        string ret{to_string(i)};
        ret.insert(0, 4-ret.size(), '0');
        return ret;
    }

    TreeNode *str2Tree(string &&s) {
        if (s == "null")
            return nullptr;
        int num{stoi(s)};
        return num > 1000 ? new TreeNode(5000-num) : new TreeNode(num);
    }
};

int main() {
    TreeNode *root = new TreeNode(-1,new TreeNode(-2),new TreeNode(-3,-4,-5));
    Codec ser, deser;
    string s = ser.serialize(root);
    for (char &ch: s) cout << (int) ch << " ";
    TreeNode *result = deser.deserialize(s);
    return 0;
}
