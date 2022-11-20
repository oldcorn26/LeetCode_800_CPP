#include <iostream>
#include <string>
#include <vector>

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
private:
    int maxLayer = 0;
    int nodeNum = 0;
    vector<vector<int>> layerOrder;
    void layerOrderTraversal(TreeNode *root, int &&idx) {
        ++nodeNum;
        if (!root) {
            if (layerOrder.size() <= idx) layerOrder.push_back({10000});
            else layerOrder[idx].push_back(10000);
            return;
        }

        if (layerOrder.size() <= idx) layerOrder.push_back({root->val});
        else layerOrder[idx].push_back(root->val);
        layerOrderTraversal(root->left, idx + 1);
        layerOrderTraversal(root->right, idx + 1);
    }
    void serializeTree(char *treeString) {
        treeString[0] = maxLayer / 100, treeString[1] = maxLayer % 100;
        int idx = 1;
        char minusFlag;
        for (vector<int> &vec: layerOrder) {
            treeString[++idx] = (char) (vec.size() / 100 + 40), treeString[++idx] = vec.size() % 100;
            for (int &i: vec) {
                if (i == 10000) {
                    treeString[++idx] = 'n', treeString[++idx] = '\0';
                    continue;
                }
                i < 0 ? (i = -i, minusFlag = 1) : minusFlag = 0;
                treeString[++idx] = i / 100 + minusFlag * 20;
                treeString[++idx] = i % 100;
            }
        }
    }
    void correctTraversal() {
        nodeNum -= layerOrder[layerOrder.size() - 1].size();
        layerOrder.erase(layerOrder.end() - 1);
    }
    void readString(string &str) {
        int idx = 1;
        maxLayer = str[0] * 100 + str[1];
        layerOrder.resize(maxLayer);
        for (int i = 0; i < maxLayer; ++i) {
            layerOrder[i].resize((str[++idx] - 40) * 100 + str[++idx]);
            for (int &iter: layerOrder[i]) {
                ++idx;
                if (str[idx] == 'n') iter = 10000, ++idx;
                else if (str[idx] >= 20) iter = -(str[idx] - 20) * 100 - str[++idx];
                else iter = str[idx] * 100 + str[++idx];
            }
        }
    }
    TreeNode *generateTree(int &&idx, vector<int> &layerIdx) {
        if (idx >= maxLayer) return nullptr;
        int &refer = layerOrder[idx][layerIdx[idx]++];
        if (refer == 10000) return nullptr;
        TreeNode *res = new TreeNode(refer);
        res->left = generateTree(idx + 1, layerIdx);
        res->right = generateTree(idx + 1, layerIdx);
        return res;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        layerOrderTraversal(root, 0), correctTraversal();
        maxLayer = layerOrder.size();
        int &&strLen = (nodeNum + maxLayer + 1) * 2;
        char res[strLen + 1];
        serializeTree(res);
        return string(&res[0], &res[strLen]);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        readString(data);
        vector<int> layerIdx(maxLayer);
        return generateTree(0, layerIdx);
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
