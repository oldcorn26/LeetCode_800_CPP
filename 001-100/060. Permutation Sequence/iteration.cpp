#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    char ret[10];
public:
    string getPermutation(int n, int k) {

        int permutation{1}, discardNum{k - 1};
        vector<bool> candi(10);

        for (int i{2}; i < n; ++i) {
            permutation *= i;
        }

        for (int i{0}; i < n; ++i) {
            int candiIdx{0};
            int &&idx{discardNum/ permutation};
            discardNum %= permutation;
            while (idx >= 0) {
                if (!candi[++candiIdx]) --idx;
            }
            ret[i] = candiIdx + '0';
            candi[candiIdx] = true;
            if (i != n - 1) permutation /= (n - 1 - i);
        }

        return string(&ret[0], &ret[n]);
    }
};

int main() {
    Solution solution;
    string result = solution.getPermutation(4, 9);
    cout << result << endl;
    return 0;
}
